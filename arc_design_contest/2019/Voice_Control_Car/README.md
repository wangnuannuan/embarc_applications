# Voice Control Car
This application is designed to control car by voice. Extending to control anything we want by voice.

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
- [Introduction](#introduction)
    - [Function](#function)
    - [System Architecture](#system-architecture)
- [Hardware and Software Setup](#hardware-and-software-setup)
    - [Required Hardware](#required-hardware)
    - [Required Software](#required-software)
    - [Hardware Connection](#hardware-connection)
- [User Manual](#user-manual)
    - [Before Running This Application](#before-running-this-application)
    - [Run This Application](#run-this-application)
- [Demo Video](#demo-video)
 <!-- markdown-toc end -->

# Introduction
We can control the car by voice and pass the control message to the remote car.
## Function
## System Architecture
   - The **LD-3320** listens to user and recognize the voice to commend, and the pass to ARC.
   - The **ARC** receives the message and parse the message to PWM value for car.
   - The **esp8266** transmits the message to car by WiFi (Remote control).
   - The **Rpi3** gets the PWM value and pass to STM32 that don't have WiFi module.
   - The **STM32** outputs the PWM to the pair of wheel.
   ![image](https://github.com/siang0128/Voice_Control_Car/blob/master/picture/Architecture.JPG)
# Hardware and Software Setup
## Required Hardware   
   - 1 Voice recognition module (LD-3320)
   - 1 ARC iot Development Kit (ARC iotdk)
   - 1 WiFi module(ESP8266)
   - 1 Raspberry pi 3
   - 1 STM32 32-bit Arm Cortex MCUs (STM32F446RE)
   - 1 SD Card
   - 1 Edimax 5G dongle
   - 1 Motor driven (L298N)
   - 1 Boost converter (XL6009)
   - 2 Wheel

## Required Software
   - ARC GNU Toolchain
   - Serial port terminal, such as putty
   - System Workbench for STM32 (SW4STM32)
   - STM32CubeMX


## Hardware Connection
   
   
# User Manual
## Before Running This Application
  Download source code of Master Sign Language from github.
  - The hardware resources are allocated as following table.
  
| Hardware Resource  | Functioon                      |
| ------------------ | -----------------------------  |
| JY-901             | Acceleration and angle sensor  |
| Flex2.2            | Flex sensor                    |
| SYN6288            | Voice composite                |
| C3-470A            | position                       |
| SIM900A            | send messages                  |
  
## Run This Application
  Here take EMSK2.0 - ARC EM7D with GNU Toolset for example to show how to run this application.We need to use embARC bootloader to automatically load application binary for different EMSK and run. See embARC Secondary Bootloader Example for reference.
  * Modify emsk_init.c (/board/emsk/common/emsk_init.c)
 ```
line 107: change 
	set_pmod_mux(mux_regs, PM1_UR_UART_0 | PM1_LR_SPI_S	\
				| PM2_I2C_HRI			\
				| PM3_GPIO_AC			\
				| PM4_I2C_GPIO_D		\
				| PM5_UR_SPI_M1 | PM5_LR_GPIO_A	\
				| PM6_UR_SPI_M0 | PM6_LR_GPIO_A );
 to 
 	set_pmod_mux(mux_regs, PM1_UR_UART_0 | PM1_LR_GPIO_A	\
				| PM2_I2C_HRI			\
				| PM3_GPIO_AC			\
				| PM4_I2C_GPIO_D		\
				| PM5_UR_SPI_M1 |PM5_LR_SPI_M2	\
				| PM6_UR_SPI_M0 | PM6_LR_GPIO_A );
```
### Makefile
   - Target options about EMSK and toolchain

```
         BOARD ?= emsk
         BD_VER ?= 20
         CUR_CORE ?= arcem7d
         TOOLCHAIN ?= gnu
```
   - The relative series of the root directory, here the path of the Makefile is .\embARC\example\emsk\sign language/makefile:
```
         #
         # root dir of embARC
         #
         EMBARC_ROOT = ../../..
         MID_SEL = common u8glib
```  
  See [ embARC Example User Guide][40], "Options to Hard-Code in the Application Makefile" for more detailed information about Makefile Options
  
  - Driver<br/>
  Placing the drivers' source code in driver folder, you can see there are subfolders for data,judge,draw and gprs drivers. Placing the C source file and header file in the corresponding subfolder.

| folder/file      | Function                                           |
| ---------------- | -------------------------------------------------  |
| data             | get and deal with data from sensor                 |
| draw             | OLED driver                                        |
| gprs             | send position information                          |
| judge            | match the collected data with the sample database  |

# Demo Video
