/*
File:   ADG2128-Example.ino
Author: J. Ian Lindsay
Date:   2019.10.20
*/

#include <Wire.h>
#include <ADG2128.h>

#define TEST_PROG_VERSION "v1.0"


/*******************************************************************************
* Pin definitions and hardware constants.
*******************************************************************************/
#define SDA_PIN             18
#define SCL_PIN             19
#define RESET_PIN           10
#define LED0_PIN            13


/*******************************************************************************
* Globals
*******************************************************************************/
ADG2128 adg2128(ADG2128_DEFAULT_I2C_ADDR, RESET_PIN);
uint8_t selected_row = 0;
uint8_t selected_col = 0;
bool    row_col_opt  = false;

/*******************************************************************************
* Functions to output things to the console
*******************************************************************************/

void printHelp() {
  Serial.print("\nADG2128 Example ");
  Serial.print(TEST_PROG_VERSION);
  Serial.print("\n------------------------------------\n");
  Serial.print("?     This output\n");
  Serial.print("i     ADG2128 info\n");
  Serial.print("x     Refresh register shadows\n");
  Serial.print("I     Reinitialize\n");
  Serial.print("R     Reset\n");
  Serial.print("r     Close route between selected column and row.\n");
  Serial.print("u     Open route between selected column and row.\n");
  if (row_col_opt) {
    Serial.print("[0-B] Select row 0-11\n");
    Serial.print("s     switch to col mode\n\n");
  }
  else {
    Serial.print("[0-7] Select col 0-7\n");
    Serial.print("s     switch to row mode\n\n");
  }
}

void printUIState() {
  Serial.print("-----------------------\n");
  Serial.print("Mode:         ");
  Serial.println(row_col_opt ? "Rows (X)" : "Columns (Y)");
  Serial.print("Selected row: ");
  Serial.println(selected_row, DEC);
  Serial.print("Selected col: ");
  Serial.println(selected_col, DEC);
}


/*******************************************************************************
* Setup function
*******************************************************************************/

void setup() {
  Serial.begin(115200);
  Wire.setSDA(SDA_PIN);
  Wire.setSCL(SCL_PIN);
  Wire.begin();
  adg2128.init();
}


/*******************************************************************************
* Main loop
*******************************************************************************/

void loop() {
  ADG2128_ERROR ret = ADG2128_ERROR::NO_ERROR;
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case 'x':
        ret = adg2128.refresh();
        Serial.print("refresh() returns ");
        Serial.println(ADG2128::errorToStr(ret));
        break;
      case 'R':
        ret = adg2128.reset();
        Serial.print("reset() returns ");
        Serial.println(ADG2128::errorToStr(ret));
        break;
      case 'I':
        ret = adg2128.init();
        Serial.print("init() returns ");
        Serial.println(ADG2128::errorToStr(ret));
        break;
      case 'r':
        ret = adg2128.setRoute(selected_col, selected_row);
        Serial.print("setRoute() returns ");
        Serial.println(ADG2128::errorToStr(ret));
        break;
      case 'u':
        ret = adg2128.unsetRoute(selected_col, selected_row);
        Serial.print("unsetRoute() returns ");
        Serial.println(ADG2128::errorToStr(ret));
        break;
      case 's':
        row_col_opt = !row_col_opt;
        printUIState();
        break;

      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case 'A':
      case 'B':
        if (row_col_opt) {
          selected_row = (c < 'A') ? (c - 0x30) : (c - 0x37);
          printUIState();
        }
        else if (8 > (c - 0x30)) {
          selected_col = (c - 0x30);
          printUIState();
        }
        else {
          Serial.print("Invalid column.\n");
        }
        break;

      case 'i':  adg2128.printDebug();  break;
      case '?':  printHelp();           break;
    }
  }
}
