# ⚙️ RTOS Smart Motor Health Monitoring System

An intelligent **Real-Time Embedded System** designed to monitor the health and safety of a DC motor using **STM32F446RE**, **FreeRTOS**, and multiple sensors. The system continuously monitors motor current, temperature, obstacle detection, and fire conditions while providing real-time status updates through an OLED display and UART communication.

The project demonstrates how **Real-Time Operating Systems (RTOS)** can efficiently manage multiple concurrent tasks in industrial motor monitoring applications, ensuring improved reliability, safety, and fault protection.

---

# 📌 Project Overview

The **RTOS Smart Motor Health Monitoring System** is developed as an industrial embedded solution for continuously monitoring a DC motor's operating condition. The system utilizes the **STM32F446RE ARM Cortex-M4 microcontroller** running **FreeRTOS** to perform multiple monitoring tasks simultaneously.

The motor is controlled through a **TB6612 Motor Driver** using PWM signals, while an **INA219 Current Sensor** measures motor current consumption. An **NTC Thermistor** continuously monitors motor temperature, and both **IR Obstacle Sensor** and **Flame Sensor** provide additional safety protection.

Whenever any abnormal condition such as overcurrent, overheating, flame detection, or obstacle detection occurs, the Safety Supervisor Task immediately stops the motor, activates the buzzer, updates the OLED display, and transmits diagnostic information through UART.

---

# 🚀 Features

## ⚙️ Motor Control Module

- STM32F446RE based motor control
- PWM speed control using Timer 3
- TB6612 Motor Driver interfacing
- Motor Start/Stop control
- Real-time motor status monitoring

---

## 📊 Power Monitoring Module

- INA219 Current Sensor interfacing
- Real-time motor current measurement
- Current filtering for stable readings
- Overcurrent detection
- Current monitoring through I2C communication

---

## 🌡 Temperature Monitoring Module

- NTC Thermistor temperature sensing
- ADC-based temperature measurement
- Steinhart-Hart equation implementation
- Real-time motor temperature monitoring
- Overtemperature protection

---

## 🔥 Safety Monitoring Module

- Flame detection using Flame Sensor
- IR obstacle detection
- Automatic emergency motor shutdown
- Safety Supervisor Task
- Buzzer alarm indication
- Fault status management

---

## 📺 OLED Display Module

- SSD1306 OLED Display
- Real-time temperature display
- Motor current display
- Motor ON/OFF status
- Safety status indication
- Live system monitoring

---

## 💻 UART Logging Module

- Serial communication with PC
- Real-time diagnostic logging
- Temperature monitoring logs
- Motor current logs
- Motor state transmission
- Fault reporting

---

## ⏱ FreeRTOS Multitasking

- Motor Control Task
- Power Monitoring Task
- Temperature Monitoring Task
- Safety Supervisor Task
- OLED Display Task
- UART Logging Task
- Concurrent task execution
- Priority-based scheduling

---

# 🏗 System Workflow

```text
Power ON

      |

STM32 Initialization

      |

FreeRTOS Scheduler Starts

      |

Motor Control Task Starts

      |

------------------------------

|      |      |      |      |

Current Temperature IR Flame Display

Sensor Sensor Sensor Sensor OLED

|      |      |      |      |

------ Safety Supervisor ------

              |

Fault Detected?

      |

   Yes ---------------- No

    |                  |

Motor OFF         Motor Running

    |

Buzzer ON

    |

OLED Warning

    |

UART Logging
```

---

# 🖥 System Architecture

```text
                   STM32F446RE

                        |

 -------------------------------------------------

 |         |          |          |               |

ADC       I2C        GPIO       PWM            UART

 |         |          |          |               |

NTC     INA219      IR       TB6612         Serial

Thermistor Current  Flame     Driver       Monitor

                     Sensor

 |         |          |          |               |

 ---------------- Safety Supervisor -------------

                        |

                  Motor Protection

                        |

                  OLED Display

                        |

                     Buzzer
```

---

# 🛠 Technologies Used

## Hardware

- STM32F446RE Microcontroller
- TB6612 Motor Driver
- INA219 Current Sensor
- NTC Thermistor
- SSD1306 OLED Display
- IR Obstacle Sensor
- Flame Sensor
- DC Motor
- Buzzer

---

## Embedded Development

- Embedded C
- STM32CubeIDE
- STM32CubeMX
- STM32 HAL Library
- FreeRTOS (CMSIS-RTOS V2)
- PWM Programming
- ADC Programming
- GPIO Programming
- UART Communication
- I2C Communication
- Interrupt Programming

---

## RTOS Concepts

- Multitasking
- Task Scheduling
- Task Priorities
- Real-Time Monitoring
- Concurrent Execution
- System Synchronization

---

## Communication Protocols

- UART
- I2C
- ADC
- GPIO
- PWM

---

## Development Tools

- STM32CubeIDE
- STM32CubeMX
- VS Code
- Git
- GitHub

---

# 📂 Project Structure

```text
RTOS-Smart-Motor-Health-Monitoring-System/

│
├── Core/
│   ├── Src/
│   │   ├── main.c
│   │   ├── ssd1306.c
│   │   ├── fonts.c
│   │   └── stm32f4xx_it.c
│   │
│   └── Inc/
│       ├── main.h
│       ├── ssd1306.h
│       └── fonts.h
│
├── Drivers/
│
├── Middlewares/
│   └── FreeRTOS/
│
├── STM32CubeMX/
│   └── RTOS_Motor.ioc
│
├── README.md
│
└── LICENSE
```

---

# ⚙️ Installation & Setup

## 1. Clone Repository

```bash
git clone https://github.com/sanjayds4908/RTOS_Capstone2_SMH_446_in.git
```

---

## 2. Open Project

Open the project using **STM32CubeIDE**.

---

## 3. Configure Hardware

Connect

- STM32F446RE
- TB6612 Motor Driver
- INA219 Current Sensor
- NTC Thermistor
- IR Sensor
- Flame Sensor
- OLED Display
- Buzzer

---

## 4. Build Project

Compile the project.

---

## 5. Flash Program

Upload firmware to STM32 using ST-Link.

---

## 6. Run System

Power the board.

The system automatically:

- Starts FreeRTOS Scheduler
- Controls Motor
- Reads Sensors
- Displays Live Status
- Sends UART Logs
- Performs Safety Monitoring

---

# 📸 Screenshots

Add screenshots of:

- STM32CubeIDE Project
- STM32CubeMX Configuration
- OLED Display Output
- UART Serial Monitor
- Motor Running
- Overcurrent Detection
- Temperature Monitoring
- Flame Detection
- IR Obstacle Detection
- Complete Hardware Setup

---

# 🔮 Future Enhancements

- IoT Cloud Monitoring
- ESP32 Wi-Fi Integration
- Mobile Application
- MQTT Communication
- Data Logging to SD Card
- Predictive Maintenance using AI
- Vibration Sensor Integration
- Motor RPM Monitoring
- Remote Motor Control
- Industrial Dashboard

---

# 🎯 Project Objectives

The objective of this project is to develop an intelligent Real-Time Embedded Motor Monitoring System that:

- Continuously monitors motor health
- Detects abnormal operating conditions
- Prevents motor damage
- Improves industrial safety
- Demonstrates FreeRTOS multitasking
- Provides real-time fault detection
- Reduces maintenance cost
- Enhances motor reliability

---

# 📚 Key Learning Outcomes

- Embedded C Programming
- STM32 HAL Programming
- FreeRTOS Task Management
- PWM Motor Control
- ADC Sensor Interfacing
- I2C Communication
- UART Communication
- Interrupt Handling
- Industrial Safety Systems
- Real-Time Embedded System Design

---

# 👨‍💻 Developer

**Sanjay D S**

Electronics and Communication Engineering (ECE)

GitHub:

https://github.com/sanjayds4908

---

# ⭐ Support

If you found this project useful, please consider giving it a ⭐ on GitHub.
