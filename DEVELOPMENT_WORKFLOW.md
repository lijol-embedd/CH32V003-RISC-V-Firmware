# CH32V003 Development and Flashing Workflow

This document describes the development, compilation, programming and hardware verification process for the CH32V003J4M6 bare-metal firmware project.

The development was carried out on **Linux Mint**, using the RISC-V GCC toolchain, MounRiver Studio, Arduino Uno-based SWIO programming and the open-source `ch32fun` utilities.

## 1. Development Environment Setup

The following tools and resources were used:

| Tool / Resource | Purpose |
|---|---|
| Linux Mint | Development operating system |
| Arduino IDE | Programming the Arduino Uno |
| Arduino Uno | SWIO programmer interface |
| ArduLink | Arduino-based SWIO programming firmware |
| ch32fun | Open-source CH32 development utilities |
| minichlink | CH32V003 firmware flashing utility |
| MounRiver Studio | Embedded firmware development IDE |
| RISC-V GCC Toolchain | Firmware compilation |
| CH32V003 Datasheet and Reference Manual | Hardware and peripheral reference |

## 2. Setting Up the Arduino Uno as an SWIO Programmer

The Arduino Uno was configured to communicate with the CH32V003 through its Single-Wire Interface (SWIO).

The procedure was:

1. Downloaded the `ch32fun` repository from GitHub.
2. Installed Arduino IDE on Linux Mint.
3. Uploaded the ArduLink (Arduino SWIO) firmware to the Arduino Uno.
4. Built the `minichlink` utility from the `ch32fun` repository for Linux.
5. Connected the Arduino Uno to the CH32V003 using the SWIO programming interface.

The programmer was accessed through the Arduino's serial device, `/dev/ttyACM0`.

The following command was used to select the ArduLink interface and inspect the programmer/target:

```bash
./minichlink -C ardulink -c /dev/ttyACM0 -i
```

## 3. Bare-Metal Firmware Development

Before developing the application, the CH32V003 datasheet and reference manual were studied to understand the microcontroller architecture and peripheral operation.

The main topics investigated included:

- RISC-V core architecture
- Memory map and register addressing
- General Purpose Input/Output (GPIO)
- Reset and Clock Control (RCC)
- TIM1 peripheral and timer operation

An LED blinking application was developed using **bare-metal Embedded C and direct register programming**.

The application was implemented by configuring the required peripheral registers directly rather than relying on a high-level hardware abstraction layer.

The initial firmware was compiled and tested using a custom build environment.

## 4. MounRiver Studio Project Setup

MounRiver Studio and the RISC-V GCC Toolchain were installed on Linux Mint.

The existing bare-metal application was subsequently migrated into a new CH32V003J4M6 project in MounRiver Studio.

The project included:

- Application source code
- CH32V003 peripheral driver source and header files
- RISC-V core support files
- Startup assembly source
- Linker script
- Project configuration and debug launch files

The firmware was compiled using the MounRiver Studio build system, generating the executable and binary output files.

## 5. Firmware Flashing Using minichlink

The compiled firmware binary was programmed into the CH32V003 using `minichlink` and the Arduino Uno-based ArduLink programmer.

The generated binary was located in the MounRiver project output directory.

The following command was used for programming:

```bash
~/ch32fun/minichlink/minichlink \
-c /dev/ttyACM0 \
-w /path/to/CH32V003J4M.bin \
flash -b
```

Command parameters:

| Parameter | Description |
|---|---|
| `minichlink` | Firmware programming utility |
| `-c /dev/ttyACM0` | Arduino Uno serial interface |
| `-w` | Specifies the firmware file to write |
| `CH32V003J4M.bin` | Compiled firmware binary |
| `flash` | Selects the target flash memory region |
| `-b` | Reboots the microcontroller after programming |

The firmware was successfully flashed using this procedure.

## 6. Hardware Implementation and Verification

After programming, the CH32V003J4M6 was tested on a physical breadboard setup.

The hardware included:

- CH32V003J4M6 microcontroller
- Arduino Uno configured with ArduLink firmware
- SWIO programming connections
- External LED and current-limiting resistor
- Breadboard and connecting wires

Successful firmware execution was verified by observing the external LED blinking at the expected interval.

The hardware implementation photograph and demonstration video are available in:

- `docs/images/ch32v003-led-blink.jpeg`
- `docs/videos/ch32v003-led-blink.mp4`

## 7. Development Outcome

Successfully developed, compiled, programmed and tested a bare-metal LED blinking application on the CH32V003J4M6 RISC-V microcontroller.

The project involved direct peripheral register programming, understanding the microcontroller's hardware architecture, using an Arduino Uno as an SWIO programmer, and establishing a Linux-based embedded firmware development workflow.

The implementation demonstrates practical experience with:

- Bare-metal Embedded C
- RISC-V microcontroller development
- GPIO and peripheral register programming
- Timer and clock configuration
- Linux-based firmware development
- Open-source embedded development tools
- Hardware programming and debugging workflows
