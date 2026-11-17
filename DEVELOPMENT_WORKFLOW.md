# Development Workflow

This project was developed on **Linux Mint** using an Arduino Uno R3 as a SWIO programmer for the WCH CH32V003 microcontroller.

## 1. Arduino Uno SWIO Programmer Setup

1. **Clone the ArduLink source code**

   Downloaded the [Arduino CH32V003 SWIO interface](https://gitlab.com/BlueSyncLine/arduino-ch32v003-swio) source code from GitLab.

2. **Install the AVR development toolchain**

   Installed AVR-GCC, AVR-libc, AVR binutils, AVRDUDE, and Make.

3. **Compile the ArduLink firmware**

   Used the provided Makefile and AVR-GCC to compile the firmware for the ATmega328P microcontroller operating at 16 MHz. This generated `main.elf`.

4. **Flash the Arduino Uno**

   Used AVRDUDE to upload the compiled firmware to the Arduino Uno R3 through `/dev/ttyACM0`, configuring it to function as a SWIO programmer.

5. **Establish hardware connections**

   Connected Arduino pin 8 (PB0) to the CH32V003 SWIO pin, with a 1 kΩ series resistor recommended by the ArduLink project. Arduino pin 9 (PB1) was used for target power control.

## 2. Bare-Metal Application Development

1. **Study the microcontroller documentation**

   Referenced the CH32V003 datasheet and reference manual to understand its memory map, clock configuration, GPIO registers, and timer peripherals.

2. **Develop the bare-metal application**

   Implemented an LED-blinking program in Embedded C using direct memory-mapped register access, without relying on a hardware abstraction layer.

3. **Configure the development environment**

   Installed MounRiver Studio and its RISC-V GCC toolchain on Linux Mint.

4. **Create the CH32V003 project**

   Created a new CH32V003J4M project in MounRiver Studio and integrated the bare-metal application code.

5. **Build the firmware**

   Compiled the project using the RISC-V GCC toolchain to generate the executable (`.elf`) and binary (`.bin`) firmware outputs.

## 3. Firmware Flashing and Hardware Verification

1. **Configure minichlink**

   Built `minichlink` from the [ch32fun repository](https://github.com/cnlohr/ch32fun) on Linux Mint.

2. **Connect to the target**

   Used the Arduino Uno running ArduLink as the SWIO interface. Verified programmer communication through minichlink.

3. **Flash the application**

   Used minichlink to write the generated CH32V003 binary to the target microcontroller's flash memory.

   Example command:

   ```bash
   ~/ch32fun/minichlink/minichlink \
       -c /dev/ttyACM0 \
       -w /path/to/CH32V003J4M.bin flash -b
   ```

4. **Verify hardware operation**

   Powered the target board and verified the LED-blinking application on the physical CH32V003 hardware.

## 4. Tools and Technologies

- **Operating System:** Linux Mint
- **Microcontroller:** WCH CH32V003J4M6
- **Programmer Hardware:** Arduino Uno R3
- **SWIO Interface:** ArduLink
- **AVR Toolchain:** AVR-GCC, AVR-libc, AVRDUDE, Make
- **RISC-V Toolchain:** RISC-V GCC
- **IDE:** MounRiver Studio
- **Flashing Utility:** minichlink
- **Programming Language:** Embedded C
- **Programming Approach:** Bare-metal register-level programming

## 5. Outcome

Successfully developed, compiled, flashed, and tested a bare-metal LED-blinking application on the CH32V003 microcontroller using direct register programming. The development process involved setting up an open-source SWIO programming solution using an Arduino Uno, configuring the RISC-V development environment, and programming the target through minichlink on Linux Mint.
