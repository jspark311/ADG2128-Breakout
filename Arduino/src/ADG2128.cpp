/*
File:   ADG2128.cpp
Author: J. Ian Lindsay
Date:   2014.03.10

Copyright 2019 Manuvr, Inc

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include <Wire.h>
#include <ADG2128.h>


static const uint8_t readback_addr[12] = {
  0x34, 0x3c, 0x74, 0x7c, 0x35, 0x3d, 0x75, 0x7d, 0x36, 0x3e, 0x76, 0x7e
};


/*
* Constructor.
*/
ADG2128::ADG2128(const uint8_t i2c_addr, const uint8_t r_pin) : _ADDR(i2c_addr), _RESET_PIN(r_pin) {
  for (uint8_t i = 0; i < 12; i++) {
    _values[i] = 0;
  }
}

/*
* Destructor.
*/
ADG2128::~ADG2128() {
  if (255 != _RESET_PIN) {
    digitalWrite(_RESET_PIN, LOW);  // Leave the part in reset state.
  }
}


/*
*
*/
ADG2128_ERROR ADG2128::init() {
  if (!pins_confd) {
    _ll_pin_init();
  }
  return reset();
}


/*
* Opens all switches.
* Uses hardware reset if possible. Otherwise, will write each of the 96 switches
*   one by one. This will have a non-trivial time load unless it is re-worked.
*/
ADG2128_ERROR ADG2128::reset() {
  dev_init = false;
  if (255 != _RESET_PIN) {
    digitalWrite(_RESET_PIN, LOW);
    delay(10);
    digitalWrite(_RESET_PIN, HIGH);
    delay(10);
  }
  else {
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 8; j++) {
        // This will defer switch disconnect until the last write is completed.
        // So if reset fails, the part will be in an indeterminate state, but
        //   nothing will have changed in the switches.
        if (ADG2128_ERROR::NO_ERROR != unsetRoute(j, i, !((11 == i) && (7 == j)))) {
          return ADG2128_ERROR::BUS;
        }
      }
    }
  }

  ADG2128_ERROR ret = ADG2128_ERROR::BUS;
  if (0 == _read_device()) {
    dev_init = true;
    ret = ADG2128_ERROR::NO_ERROR;
  }
  return ret;
}


ADG2128_ERROR ADG2128::enforce_cardinality(uint8_t col, uint8_t row) {
  if (col > 7)  return ADG2128_ERROR::BAD_COLUMN;
  if (row > 11) return ADG2128_ERROR::BAD_ROW;
  if (!many_c_per_r) {
    // Check that the given row isn't already attached to a different col.
  }
  if (!many_r_per_c) {
    // Check that the given col isn't already attached to a different row.
  }
  return ADG2128_ERROR::NO_ERROR;
}


ADG2128_ERROR ADG2128::compose_first_byte(uint8_t col, uint8_t row, bool set, uint8_t* result) {
  if (col > 7)  return ADG2128_ERROR::BAD_COLUMN;
  if (row > 11) return ADG2128_ERROR::BAD_ROW;
  uint8_t temp = row;
  if (temp >= 6) temp = temp + 2; // Dance around the reserved range in the middle.
  *result = (temp << 3) + col + (set ? 0x80 : 0x00);
  return ADG2128_ERROR::NO_ERROR;
}


ADG2128_ERROR ADG2128::setRoute(uint8_t col, uint8_t row, bool defer) {
  ADG2128_ERROR return_value = enforce_cardinality(col, row);
  if (ADG2128_ERROR::NO_ERROR == return_value) {
    return_value = changeRoute(col, row, true, defer);
  }
  return return_value;
}


ADG2128_ERROR ADG2128::unsetRoute(uint8_t col, uint8_t row, bool defer) {
  return changeRoute(col, row, false, defer);
}


ADG2128_ERROR ADG2128::changeRoute(uint8_t col, uint8_t row, bool sw_closed, bool defer) {
  uint8_t temp;
  ADG2128_ERROR return_value = compose_first_byte(col, row, sw_closed, &temp);
  if (ADG2128_ERROR::NO_ERROR == return_value) {
    return_value = ADG2128_ERROR::BUS;
    if (0 == _write_device(temp, (defer ? 0 : 1))) {
      return_value = ADG2128_ERROR::NO_ERROR;
    }
  }
  return return_value;
}


ADG2128_ERROR ADG2128::refresh() {
  return (0 != _read_device()) ? ADG2128_ERROR::BUS : ADG2128_ERROR::NO_ERROR;
}


/*
* Readback on this part is organized by rows, with the return bits
*   being the state of the switches to the corresponding column.
* The readback address table is hard-coded in the readback_addr array.
*/
int8_t ADG2128::_read_device() {
  int8_t ret = 0;
  for (uint8_t row = 0; row < 12; row++) {
    Wire.beginTransmission(_ADDR);
    Wire.write(readback_addr[row]);
    Wire.write(0);
    if (0 == Wire.endTransmission()) {
      uint8_t bytes = Wire.requestFrom(_ADDR, (uint8_t) 2);
      if (2 == bytes) {
        bytes = Wire.receive();
        _values[row] = Wire.receive();
      }
      else {
        return -2;
      }
    }
    else {
      return -1;
    }
  }
  return ret;
}


uint8_t ADG2128::getValue(uint8_t row) {
  if (row > 11) return 0;
  return _values[row];
}


/*
* Setup the low-level pin details.
*/
int8_t ADG2128::_ll_pin_init() {
  if (255 != _RESET_PIN) {
    pinMode(_RESET_PIN, OUTPUT);
    digitalWrite(_RESET_PIN, LOW);  // Start part in reset state.
  }
  pins_confd = true;
  return 0;
}


int8_t ADG2128::_write_device(uint8_t row, uint8_t conn) {
  Wire.beginTransmission(_ADDR);
  Wire.write(row);
  Wire.write(conn);
  int8_t ret = Wire.endTransmission();
  if (0 == ret) {
    _values[row] = conn;
  }
  return ret;
}


/*
* Dump this item to the dev log.
*/
void ADG2128::printDebug() {
  Serial.println("ADG2128 8x12 cross-point switch\n--------------------------------------------\n");
  Serial.print("\tInitialized:    ");
  Serial.println(dev_init ? 'y' : 'n');
  Serial.print("\tmany_c_per_r:   ");
  Serial.println(many_c_per_r ? 'y' : 'n');
  Serial.print("\tmany_r_per_c:   ");
  Serial.println(many_r_per_c ? 'y' : 'n');
  Serial.print("\tRESET_PIN:      ");
  Serial.println(_RESET_PIN, DEC);
  if (dev_init) {
    for (int i = 0; i < 12; i++) {
      Serial.print("\tRow ");
      Serial.print(i, DEC);
      Serial.print("\t");
      Serial.println(_values[i], DEC);
    }
  }
  Serial.print("\n");
}
