| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- |

# _Sample project_

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)

## Overview
This ESP32 project demonstrates a real-time counter system utilizing FreeRTOS tasks and the General-Purpose Timer (GPTimer) module. The project showcases how to manage concurrent tasks and hardware timers for precise counting operations in an embedded system.

## Fetures
Two FreeRTOS tasks increment counters at different intervals.
GPTimer triggers a callback function, incrementing a counter every millisecond.
FreeRTOS tasks and GPTimer operate concurrently, demonstrating real-time synchronization.

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.
## 1.GPTimer Counters:
Two GPTimers are configured to generate periodic alarms at intervals of 500 ms and 1000 ms, respectively.
GPTimer 0 is associated with counter_0.
GPTimer 1 is associated with counter_1.
The GPTimer alarms increment their respective counters.
## 2.FreeRTOS Tasks:
Two FreeRTOS tasks (Task1 and Task2) increment counter_2 and counter_3 at intervals of 1000 ms and 500 ms, respectively.
## 3.Logging:
The counters' values are periodically printed to the console every second.