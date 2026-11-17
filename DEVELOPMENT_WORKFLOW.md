# Development Workflow

This document describes the complete development process for the CH32V003 RISC-V bare-metal firmware project, from configuring the Arduino Uno SWIO programmer to flashing and testing the application on physical hardware.

The development environment used was Linux Mint.

## 1. Arduino Uno SWIO Programmer Setup

The Arduino Uno R3 was configured as a SWIO programmer using the ArduLink firmware.

### Step 1: Clone the ArduLink source

Downloaded the [Arduino CH32V003 SWIO interface](https://gitlab.com/BlueSyncLine/arduino-ch32v003-swio) source code from GitLab.

### Step 2: Install the AVR development toolchain

Installed the required AVR development tools:

- AVR-GCC
- AVR-libc
- AVR binutils
- AVRDUDE
- Make

### Step 3: Compile the ArduLink firmware

Used the provided Makefile and AVR-GCC to compile the firmware for the ATmega328P microcontroller operating at 16 MHz.

The compilation generated `main.elf`.

### Step 4: Flash the Arduino Uno

Used AVRDUDE to upload the compiled firmware to the Arduino Uno R3 through `/dev/ttyACM0`.

The Arduino Uno was now configured to function as a SWIO programmer.

### Step 5: Establish hardware connections

Connected the Arduino Uno to the CH32V003:

| Arduino Uno | Function |
|---|---|
| Pin 8 (PB0) | SWIO communication |
| Pin 9 (PB1) | Target power control |

A 1 kΩ series resistor was recommended between the SWIO connection and the target microcontroller.

## 2. Bare-Metal Application Development

### Step 1: Study the microcontroller documentation

Referenced the CH32V003 datasheet and reference manual to understand:

- Memory map
- Clock configuration
- RCC registers
- GPIO configuration registers
- TIM1 peripheral registers

### Step 2: Develop the bare-metal application

Implemented an LED-blinking application in Embedded C using direct memory-mapped register access without relying on a hardware abstraction layer.

The application configures GPIO and TIM1 to periodically toggle the LED connected to PD6.

### Step 3: Configure the development environment

Installed MounRiver Studio and its RISC-V GCC toolchain on Linux Mint.

### Step 4: Create the CH32V003 project

Created a new CH32V003J4M project in MounRiver Studio and integrated the bare-metal application code.

### Step 5: Build the firmware

Compiled the project using the RISC-V GCC toolchain to generate the executable (`.elf`) and binary (`.bin`) firmware outputs.

## 3. Firmware Flashing and Hardware Verification

### Step 1: Build minichlink

Cloned the [ch32fun repository](https://github.com/cnlohr/ch32fun) and built minichlink on Linux Mint.

### Step 2: Connect to the target

Connected the Arduino Uno running ArduLink to the host PC through USB.

Verified communication with the programmer using minichlink.

### Step 3: Flash the application

Used minichlink to write the generated CH32V003 binary to the target microcontroller's flash memory.

Example command:

```bash
~/ch32fun/minichlink/minichlink \
    -c /dev/ttyACM0 \
    -w /path/to/CH32V003J4M.bin flash -b
```

Replace `/path/to/CH32V003J4M.bin` with the actual location of the generated binary.

### Step 4: Verify hardware operation

Powered the target board and verified that the LED-blinking application operated successfully on the physical CH32V003 hardware.

## 4. Tools and Technologies

| Category | Tools / Technologies |
|---|---|
| Operating system | Linux Mint |
| Target microcontroller | WCH CH32V003J4M6 |
| Programmer hardware | Arduino Uno R3 |
| SWIO interface | ArduLink |
| AVR toolchain | AVR-GCC, AVR-libc, AVR binutils |
| AVR flashing utility | AVRDUDE |
| RISC-V toolchain | RISC-V GCC |
| IDE | MounRiver Studio |
| CH32 flashing utility | minichlink |
| Programming language | Embedded C |
| Programming approach | Bare-metal register-level programming |

## 5. Outcome

Successfully developed, compiled, flashed, and tested a bare-metal LED-blinking application on the CH32V003 microcontroller using direct register programming.

The project involved setting up an open-source SWIO programming solution using an Arduino Uno, configuring a RISC-V development environment, and programming the target microcontroller through minichlink on Linux Mint.
