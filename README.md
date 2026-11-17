# CH32V003 RISC-V Bare-Metal Firmware

A bare-metal Embedded C project for the **WCH CH32V003J4M6 RISC-V microcontroller**, implementing LED blinking through direct memory-mapped register access without relying on a hardware abstraction layer (HAL).

Developed on Linux Mint using MounRiver Studio, RISC-V GCC, and an Arduino Uno R3 configured as an open-source SWIO programmer using ArduLink.

## Project Overview

The project explores low-level embedded firmware development, including direct peripheral configuration, GPIO control, timer operation, and firmware flashing.

### Key Features

- Bare-metal Embedded C programming
- Direct memory-mapped register access
- GPIO configuration and control
- TIM1-based timing implementation
- RISC-V GCC firmware compilation
- SWIO-based programming using Arduino Uno and ArduLink
- Linux-based embedded development workflow

## Hardware

| Component | Description |
|---|---|
| Target microcontroller | WCH CH32V003J4M6 |
| Programmer | Arduino Uno R3 |
| Programming interface | SWIO using ArduLink |
| LED output | PD6 |
| Development OS | Linux Mint |

### Arduino Uno Connections

| Arduino Uno pin | Function |
|---|---|
| Pin 8 (PB0) | SWIO communication |
| Pin 9 (PB1) | Target power control |

A 1 kΩ series resistor is recommended between Arduino pin 8 and the CH32V003 SWIO connection.

## Development Tools

- **IDE:** MounRiver Studio
- **Application compiler:** RISC-V GCC
- **Programmer firmware compiler:** AVR-GCC
- **Programmer firmware uploader:** AVRDUDE
- **CH32V003 flashing utility:** minichlink
- **Programming language:** Embedded C
- **Operating system:** Linux Mint

## Firmware Implementation

The application uses direct register-level programming to control the microcontroller peripherals.

- Enables peripheral clocks through RCC.
- Configures PD6 as a push-pull GPIO output.
- Configures TIM1 using its prescaler and auto-reload registers.
- Polls the timer update flag to generate periodic LED toggling.

## Hardware Demonstration

The LED-blinking application was successfully flashed and tested on physical CH32V003 hardware.

![CH32V003 LED blinking](docs/images/ch32v003-led-blink.jpeg)

[Watch the LED blinking demonstration](docs/videos/ch32v003-led-blink.mp4)

## Repository Contents

- `Core/` – RISC-V core support files
- `Ld/` – Linker script
- `Peripheral/` – Peripheral drivers and header files
- `Startup/` – Startup assembly
- `User/` – Application source code and system configuration
- `docs/` – Hardware demonstration and documentation
- `DEVELOPMENT_WORKFLOW.md` – Detailed development and flashing procedure

## Development Workflow

For the complete development procedure, including ArduLink setup, AVR-GCC compilation, MounRiver Studio configuration, and CH32V003 firmware flashing, see:

**[Development Workflow](DEVELOPMENT_WORKFLOW.md)**

## Learning Outcomes

- RISC-V microcontroller programming
- Bare-metal Embedded C development
- Memory-mapped register access
- GPIO and timer peripheral configuration
- AVR and RISC-V toolchains
- Firmware compilation and flashing
- SWIO communication and hardware debugging
- Linux-based embedded development

## References

- [WCH Official Website](https://www.wch-ic.com/)
- [ArduLink – Arduino CH32V003 SWIO Interface](https://gitlab.com/BlueSyncLine/arduino-ch32v003-swio)
- [ch32fun – CH32V Development Framework](https://github.com/cnlohr/ch32fun)
- [MounRiver Studio](http://www.mounriver.com/)

---

**Project Status:** Successfully compiled, flashed, and tested on physical CH32V003 hardware.
