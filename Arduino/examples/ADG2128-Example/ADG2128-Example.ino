#include <Wire.h>
#include <ADG2128.h>


ADG2128Opts switch_opts(
  0x27,    // i2c address
  13,      // Use this pin for reset
  true,    // Allow many columns to connect to a single row
  false    // Disallow many rows from connecting to a single column
);

ADG2128 adg2128(&switch_opts);


void setup() {
  Serial.begin(115200);
  Wire.setSDA(18);
  Wire.setSCL(19);
  Wire.begin();
  adg2128.init();
}


void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case 'x':
        if (ADG2128_ERROR::NO_ERROR == adg2128.init()) {
          Serial.println("Device initialized.");
        }
        break;
      case 'R':
        if (ADG2128_ERROR::NO_ERROR == adg2128.reset()) {
          Serial.println("Device reset.");
        }
        break;
      case 'i':
        adg2128.printDebug();
        break;
    }
  }
}
