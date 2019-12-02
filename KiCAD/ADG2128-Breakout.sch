EESchema Schematic File Version 4
LIBS:ADG2128-Breakout-cache
EELAYER 26 0
EELAYER END
$Descr User 6299 5511
encoding utf-8
Sheet 1 1
Title "ADG2128 Breakout"
Date "2019-08-20"
Rev "3"
Comp "Manuvr, inc"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VianSonus2.0-parts:ADG2128 U1
U 1 1 5D183CD4
P 1650 2000
F 0 "U1" H 1600 2450 60  0000 C CNN
F 1 "ADG2128" H 1650 2350 60  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.65x3.65mm" H 1200 2750 60  0001 C CNN
F 3 "" H 1200 2750 60  0000 C CNN
F 4 "ADG2128BCPZ-REEL7CT-ND" H 1650 2000 50  0001 C CNN "Digikey_Number"
F 5 "ADG2128BCPZ-REEL7" H 1150 3000 50  0000 C CNN "Manu_Number"
F 6 "Analog Devices Inc." H 1650 2000 50  0001 C CNN "Manu_Name"
	1    1650 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D1C4FBF
P 2750 1450
F 0 "C1" H 2750 1550 39  0000 L CNN
F 1 "2.2uF" H 2750 1350 39  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2788 1300 50  0001 C CNN
F 3 "~" H 2750 1450 50  0001 C CNN
F 4 "1276-1040-1-ND" H 2750 1450 50  0001 C CNN "Digikey_Number"
F 5 "CL10A225KO8NNNC" H 2750 1450 50  0001 C CNN "Manu_Number"
F 6 "Samsung Electro-Mechanics" H 2750 1450 50  0001 C CNN "Manu_Name"
	1    2750 1450
	1    0    0    -1  
$EndComp
Text Label 3100 1650 0    39   ~ 0
ANAGND
Text Label 3100 1750 0    39   ~ 0
Vcc
Text Label 1500 2900 2    39   ~ 0
ANAGND
Wire Wire Line
	1550 2900 1550 2850
Text Label 1850 2900 0    39   ~ 0
GND
Text Label 1100 1350 2    39   ~ 0
SDA
Text Label 1100 1450 2    39   ~ 0
SCL
Text Label 1100 1200 2    39   ~ 0
~RESET
Text Label 4150 1300 0    39   ~ 0
~RESET
Text Label 1850 950  1    39   ~ 0
Vcc
Wire Wire Line
	1850 950  1850 1000
Text Label 1700 950  1    39   ~ 0
ANAVcc
Wire Wire Line
	1700 950  1700 1000
Text Label 4150 1200 0    39   ~ 0
SCL
Text Label 4150 1100 0    39   ~ 0
SDA
Text Label 4150 900  0    39   ~ 0
Vcc
Text Label 4150 1000 0    39   ~ 0
GND
Text Label 4750 1000 0    39   ~ 0
ANAGND
Text Label 4750 900  0    39   ~ 0
ANAVcc
Text Label 3100 1250 0    39   ~ 0
ANAVcc
Text Label 3100 2150 0    39   ~ 0
GND
$Comp
L Connector:Conn_01x14_Male J1
U 1 1 5F7D73BF
P 3950 1500
F 0 "J1" H 4056 2278 50  0000 C CNN
F 1 "Conn_01x14_Male" H 4056 2187 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical" H 3950 1500 50  0001 C CNN
F 3 "~" H 3950 1500 50  0001 C CNN
	1    3950 1500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x14_Male J2
U 1 1 5F7D7655
P 4550 1500
F 0 "J2" H 4656 2278 50  0000 C CNN
F 1 "Conn_01x14_Male" H 4656 2187 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical" H 4550 1500 50  0001 C CNN
F 3 "~" H 4550 1500 50  0001 C CNN
	1    4550 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2900 1550 2900
Wire Wire Line
	1550 2900 1650 2900
Wire Wire Line
	1650 2900 1650 2850
Connection ~ 1550 2900
Wire Wire Line
	1750 2850 1750 2900
Wire Wire Line
	1750 2900 1850 2900
Wire Wire Line
	2750 1250 2750 1300
Wire Wire Line
	2750 1250 2950 1250
Wire Wire Line
	2950 1250 2950 1300
Connection ~ 2950 1250
Wire Wire Line
	2950 1250 3100 1250
Wire Wire Line
	2750 1650 2750 1600
Wire Wire Line
	2750 1650 2950 1650
Wire Wire Line
	2950 1600 2950 1650
Connection ~ 2950 1650
Wire Wire Line
	2950 1650 3100 1650
Wire Wire Line
	2750 1750 2750 1800
Wire Wire Line
	2750 1750 2950 1750
Wire Wire Line
	2950 1750 2950 1800
Connection ~ 2950 1750
Wire Wire Line
	2950 1750 3100 1750
Wire Wire Line
	2750 2150 2750 2100
Wire Wire Line
	2750 2150 2950 2150
Wire Wire Line
	2950 2100 2950 2150
Connection ~ 2950 2150
Wire Wire Line
	2950 2150 3100 2150
$Comp
L Connector:Conn_01x03_Male J4
U 1 1 5D304CB1
P 4200 3050
F 0 "J4" H 4173 2980 50  0000 R CNN
F 1 "Conn_01x03_Male" H 4173 3071 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 4200 3050 50  0001 C CNN
F 3 "~" H 4200 3050 50  0001 C CNN
	1    4200 3050
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male J5
U 1 1 5D304DDC
P 4200 3400
F 0 "J5" H 4173 3330 50  0000 R CNN
F 1 "Conn_01x03_Male" H 4173 3421 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 4200 3400 50  0001 C CNN
F 3 "~" H 4200 3400 50  0001 C CNN
	1    4200 3400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5D304E20
P 4200 2700
F 0 "J3" H 4173 2630 50  0000 R CNN
F 1 "Conn_01x03_Male" H 4173 2721 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 4200 2700 50  0001 C CNN
F 3 "~" H 4200 2700 50  0001 C CNN
	1    4200 2700
	-1   0    0    1   
$EndComp
Text Label 1100 1700 2    39   ~ 0
A1
Text Label 1100 1600 2    39   ~ 0
A2
Text Label 4000 2700 2    39   ~ 0
A0
Text Label 4000 3050 2    39   ~ 0
A1
Text Label 4000 3400 2    39   ~ 0
A2
Text Label 4000 3300 2    39   ~ 0
Vcc
Text Label 4000 2950 2    39   ~ 0
Vcc
Text Label 4000 2600 2    39   ~ 0
Vcc
Text Label 4000 2800 2    39   ~ 0
GND
Text Label 4000 3150 2    39   ~ 0
GND
Text Label 4000 3500 2    39   ~ 0
GND
Text Label 1100 1800 2    39   ~ 0
A0
Text Label 4150 1500 0    39   ~ 0
Y0
Text Label 4150 1600 0    39   ~ 0
Y1
Text Label 4150 1700 0    39   ~ 0
Y2
Text Label 4150 1800 0    39   ~ 0
Y3
Text Label 4150 1900 0    39   ~ 0
Y4
Text Label 4150 2000 0    39   ~ 0
Y5
Text Label 4150 2100 0    39   ~ 0
Y6
Text Label 4150 2200 0    39   ~ 0
Y7
Text Label 4750 1100 0    39   ~ 0
X0
Text Label 4750 1200 0    39   ~ 0
X1
Text Label 4750 1300 0    39   ~ 0
X2
Text Label 4750 1400 0    39   ~ 0
X3
Text Label 4750 1500 0    39   ~ 0
X4
Text Label 4750 1600 0    39   ~ 0
X5
Text Label 4750 1700 0    39   ~ 0
X6
Text Label 4750 1800 0    39   ~ 0
X7
Text Label 4750 1900 0    39   ~ 0
X8
Text Label 4750 2000 0    39   ~ 0
X9
Text Label 4750 2100 0    39   ~ 0
X10
Text Label 4750 2200 0    39   ~ 0
X11
Text Label 2200 1250 0    39   ~ 0
X0
Text Label 2200 1350 0    39   ~ 0
X1
Text Label 2200 1450 0    39   ~ 0
X2
Text Label 2200 1550 0    39   ~ 0
X3
Text Label 2200 1650 0    39   ~ 0
X4
Text Label 2200 1750 0    39   ~ 0
X5
Text Label 2200 1850 0    39   ~ 0
X6
Text Label 2200 1950 0    39   ~ 0
X7
Text Label 2200 2050 0    39   ~ 0
X8
Text Label 2200 2150 0    39   ~ 0
X9
Text Label 2200 2250 0    39   ~ 0
X10
Text Label 2200 2350 0    39   ~ 0
X11
Text Label 1100 2000 2    39   ~ 0
Y0
Text Label 1100 2100 2    39   ~ 0
Y1
Text Label 1100 2200 2    39   ~ 0
Y2
Text Label 1100 2300 2    39   ~ 0
Y3
Text Label 1100 2400 2    39   ~ 0
Y4
Text Label 1100 2500 2    39   ~ 0
Y5
Text Label 1100 2600 2    39   ~ 0
Y6
Text Label 1100 2700 2    39   ~ 0
Y7
Text Label 4150 1400 0    39   ~ 0
GND
$Comp
L Device:C C3
U 1 1 5DE4C8F6
P 2950 1450
F 0 "C3" H 2950 1550 39  0000 L CNN
F 1 "2.2uF" H 2950 1350 39  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2988 1300 50  0001 C CNN
F 3 "~" H 2950 1450 50  0001 C CNN
F 4 "1276-1040-1-ND" H 2950 1450 50  0001 C CNN "Digikey_Number"
F 5 "CL10A225KO8NNNC" H 2950 1450 50  0001 C CNN "Manu_Number"
F 6 "Samsung Electro-Mechanics" H 2950 1450 50  0001 C CNN "Manu_Name"
	1    2950 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5DE4C95D
P 2750 1950
F 0 "C2" H 2750 2050 39  0000 L CNN
F 1 "2.2uF" H 2750 1850 39  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2788 1800 50  0001 C CNN
F 3 "~" H 2750 1950 50  0001 C CNN
F 4 "1276-1040-1-ND" H 2750 1950 50  0001 C CNN "Digikey_Number"
F 5 "CL10A225KO8NNNC" H 2750 1950 50  0001 C CNN "Manu_Number"
F 6 "Samsung Electro-Mechanics" H 2750 1950 50  0001 C CNN "Manu_Name"
	1    2750 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5DE4C995
P 2950 1950
F 0 "C4" H 2950 2050 39  0000 L CNN
F 1 "2.2uF" H 2950 1850 39  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2988 1800 50  0001 C CNN
F 3 "~" H 2950 1950 50  0001 C CNN
F 4 "1276-1040-1-ND" H 2950 1950 50  0001 C CNN "Digikey_Number"
F 5 "CL10A225KO8NNNC" H 2950 1950 50  0001 C CNN "Manu_Number"
F 6 "Samsung Electro-Mechanics" H 2950 1950 50  0001 C CNN "Manu_Name"
	1    2950 1950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
