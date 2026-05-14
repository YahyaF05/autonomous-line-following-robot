# Autonomous Line Following Robot

An autonomous robot designed to detect and follow a predefined path using infrared (IR) sensors and an Arduino-based control system. This project demonstrates the fundamentals of robotics, embedded systems, sensor integration, and motor control for autonomous navigation.

---

## 🚀 Features

- Autonomous line tracking using IR sensors
- Real-time motor speed adjustment
- Efficient path-following logic
- Arduino-based embedded control
- Lightweight and modular design
- Easy to customize and expand

---

## 🛠️ Technologies Used

- Arduino
- C/C++
- IR Sensors
- Motor Driver Module
- DC Motors
- Embedded Systems Programming

---

## 📦 Hardware Requirements

- Arduino Uno / Nano
- IR Sensor Array (2 or more sensors)
- L298N or L293D Motor Driver
- 2x DC Motors with wheels
- Robot chassis
- Battery pack
- Jumper wires
- Castor wheel

---

## ⚙️ How It Works

The robot continuously reads values from the IR sensors:

- When the robot detects the line in the center, it moves forward.
- If the line shifts left, the robot turns left.
- If the line shifts right, the robot turns right.
- Motor speeds are dynamically adjusted to maintain alignment with the path.

This enables the robot to autonomously navigate a track without human intervention.

---

## 🔌 Circuit Connections

| Component         | Arduino Pin |
| ----------------- | ------------ |
| Left IR Sensor    | A0           |
| Right IR Sensor   | A1           |
| Motor IN1         | D5           |
| Motor IN2         | D6           |
| Motor IN3         | D9           |
| Motor IN4         | D10          |

> Update the pin configuration according to your setup.

---

## ▶️ Installation & Setup

### 1. Clone the Repository

```bash
git clone https://github.com/YahyaF05/autonomous-line-following-robot.git
```

### 2. Open in Arduino IDE

Open the project files in the Arduino IDE.

### 3. Connect the Arduino Board

Connect your Arduino board to your computer using a USB cable.

### 4. Upload the Code

Select the correct board and COM port, then upload the code.

### 5. Run the Robot

Place the robot on the track and power it on.

---

## 🧪 Testing

- Use a black line on a white surface (or vice versa)
- Adjust sensor sensitivity if detection is unstable
- Tune motor speed values for smoother turning and better stability

---

## 🔮 Future Improvements

- PID control implementation
- Bluetooth/Wi-Fi control
- Speed optimization
- Maze-solving capability
- Camera-based line detection

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Open a pull request


---

## 👨‍💻 Author

**Yahya F**

GitHub:  
https://github.com/YahyaF05

Repository:  
https://github.com/YahyaF05/autonomous-line-following-robot
