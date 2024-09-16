# IoT-based Air Pollution Monitoring System

## Project Overview
This project focuses on developing an **IoT-based air pollution monitoring system** that uses drones to measure air quality at different levels in the atmosphere. The system is designed to be **portable, cost-effective, and highly efficient**, utilizing gas sensors such as **MQ-135, MQ-4, MQ-7, and MQ-2** to detect various pollutants, including particulate matter (PM), nitrogen dioxide (NO₂), ozone (O₃), and carbon monoxide (CO). The data collected is transmitted wirelessly via the **ESP8266 Wi-Fi module** to a cloud server, enabling remote monitoring and real-time analysis.

## Key Features
1. **Portability**: The lightweight system can be easily attached to drones, allowing for air quality monitoring at different heights and locations.
2. **Real-time Data Collection**: Sensors collect data continuously and send it to the cloud for instant access and analysis.
3. **Drone Integration**: Drones facilitate the monitoring of air quality at varying altitudes, providing a more comprehensive analysis of pollution levels in the atmosphere.
4. **Cost-Effectiveness**: The system is designed to be affordable, making it accessible for deployment in both urban and rural areas.
5. **Remote Monitoring**: Data can be accessed from anywhere, eliminating the need for on-site personnel.

## Technology Stack

### Hardware
- **Arduino Microcontroller**
- **ESP8266 Wi-Fi Module**
- **Gas Sensors**: MQ-135, MQ-4, MQ-7, MQ-2
- **Drone for mobility**

### Software
- **Arduino IDE**: Used for programming the microcontroller in C++.
- **IoT Cloud Platform**: For storing and visualizing real-time data.

## Use of C++ in the Project
C++ plays a key role in this project by powering the **logic** behind the system and handling data processing on the **Arduino microcontroller**. The **Arduino IDE** allows us to program the microcontroller to:
- Collect data from the gas sensors.
- Communicate with the **ESP8266 Wi-Fi module** to send data to the cloud.
- Manage periodic data transmission efficiently.

### Key C++ Contributions:
- **Efficient sensor data handling**: C++ enables optimized collection and processing of real-time sensor data.
- **Communication protocols**: The Wi-Fi module is programmed using C++ to establish reliable communication with the cloud server.
- **Modular Design**: C++'s modularity helps manage different components like sensors, the drone, and the microcontroller.

## IoT Cloud Integration
The **IoT Cloud** is the backbone of this project, providing storage and processing of real-time data transmitted by the sensors. Users can access the cloud to visualize trends, monitor pollutant levels, and configure alerts when pollution thresholds are exceeded.

### IoT Cloud Benefits:
- **Scalability**: Can easily scale to accommodate multiple sensors and locations.
- **Remote Access**: Users can monitor air quality data from any device with internet access.
- **Advanced Analytics**: Leverages cloud-based algorithms to detect patterns, identify pollution sources, and forecast air quality trends.

## Future Improvements
- Add support for more advanced sensors to detect additional types of pollutants.
- Enhance the cloud analytics to include machine learning models for better predictions.
- Expand the monitoring system to cover larger areas and integrate more drones for widespread data collection.

---

![Cloud DashBoard](https://github.com/user-attachments/assets/9188db2a-a775-49f8-9949-eae582249ba0)
![IMG20240608104958](https://github.com/user-attachments/assets/aed44677-7b0e-4314-9fe9-1c0d139e6b4f)

