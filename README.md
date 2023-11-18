# ESP32 Multitasking and Timer Example

![ESP32 Logo](esp32_logo.png)

## Overview

This project demonstrates how to leverage the ESP32's multitasking capabilities and GPTimers to create a system with multiple counters and periodic tasks using FreeRTOS.

## Features

- **GPTimers Usage:** Utilizes GPTimers for precise timing intervals.
- **FreeRTOS Tasks:** Implements multiple FreeRTOS tasks to increment counters independently.
- **Example Timer Callback:** Demonstrates the use of a timer callback to increment a counter.

## Prerequisites

- [ESP-IDF (Espressif IoT Development Framework)](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)
- [ESP32 Development Board](https://www.espressif.com/en/products/socs/esp32)
- [PlatformIO](https://platformio.org/) or [ESP-IDF Command Line Tools](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started-cmake/index.html)

## Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/shakiltanvir/MultiTimer_ESP-IDF.git
    ```

2. Navigate to the project directory:

    ```bash
    cd esp32-multitasking-timer-example
    ```

3. Build and flash the project:

    ```bash
    # For PlatformIO
    pio run -t upload

    # For ESP-IDF
    idf.py build
    idf.py -p /dev/ttyUSB0 flash
    ```

4. Monitor the output:

    ```bash
    # For PlatformIO
    pio device monitor

    # For ESP-IDF
    idf.py -p /dev/ttyUSB0 monitor
    ```

## Project Structure

- `main/`: Contains the main source code.
  - `main.c`: ESP32 application code.
  - ...

## Contributing

Feel free to contribute to this project by opening issues or submitting pull requests. Your feedback is highly appreciated.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
