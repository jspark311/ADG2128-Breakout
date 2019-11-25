/*
File:   ADG2128.h
Author: J. Ian Lindsay
Date:   2014.03.10


Copyright (C) 2014 J. Ian Lindsay
All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef ADG2128_CROSSPOINT_H
#define ADG2128_CROSSPOINT_H

#include <inttypes.h>
#include <Arduino.h>
#include <stdlib.h>

#define ADG2128_DEFAULT_I2C_ADDR   0x70


enum class ADG2128_ERROR : int8_t {
  NO_ERROR           = 0,   // There was no error.
  ABSENT             = -1,  // The ADG2128 appears to not be connected to the bus.
  BUS                = -2,  // Something went wrong with the i2c bus.
  BAD_COLUMN         = -3,  // Column was out-of-bounds.
  BAD_ROW            = -4   // Row was out-of-bounds.
};


/*
* This class represents an Analog Devices ADG2128 8x12 analog cross-point switch. This switch is controlled via i2c.
* The 8-pin group are the columns, and the 12-pin group are rows.
*/
class ADG2128 {
  public:
    ADG2128(const uint8_t addr, const uint8_t rst_pin);
    ~ADG2128();

    void printDebug();

    ADG2128_ERROR init();      // Perform bus-related init tasks.
    ADG2128_ERROR reset();     // Resets the entire device.
    ADG2128_ERROR refresh();   // Forces a shadow refresh from hardware.

    /* Functions for manipulating individual switches. */
    ADG2128_ERROR changeRoute(uint8_t col, uint8_t row, bool sw_closed, bool defer);
    ADG2128_ERROR setRoute(uint8_t col, uint8_t row, bool defer = false);
    ADG2128_ERROR unsetRoute(uint8_t col, uint8_t row, bool defer = false);

    uint8_t getValue(uint8_t row);

    inline void preserveOnDestroy(bool x) {
      preserve_state_on_destroy = x;
    };

    static const char* const errorToStr(ADG2128_ERROR);


  private:
    const uint8_t _ADDR;      // The device address on the i2c bus
    const uint8_t _RESET_PIN;    // ADG2128 reset pin
    bool     many_c_per_r = true;   // Should 1<row>:many<cols> be allowed?
    bool     many_r_per_c = false;  // Should 1<col>:many<rows> be allowed?
    bool     dev_init     = false;
    bool     pins_confd   = false;
    bool     preserve_state_on_destroy = false;
    uint8_t _values[12];

    ADG2128_ERROR compose_first_byte(uint8_t col, uint8_t row, bool set, uint8_t* result);
    int8_t _ll_pin_init();
    int8_t _read_device();
    int8_t _write_device(uint8_t row, uint8_t conn);
};

#endif    // ADG2128_CROSSPOINT_H
