Here's a `README.md` file for your project that you can copy and paste into your repository:

---

# ESP32 Access Point with HTTP Server

This project demonstrates how to set up an ESP32 microcontroller as a Wi-Fi Access Point (AP) with an integrated HTTP server. Users can connect to the ESP32's network and interact through a web interface to view connected devices or restart the ESP32.

---

## Features

- **Wi-Fi Access Point**: Creates a local Wi-Fi network with a configurable SSID and password.
- **HTTP Server**:
  - **Main Page**: Displays a welcome message to users connecting to the ESP32 network.
  - **Connected Devices**: Lists all devices connected to the ESP32 AP along with their MAC addresses.
  - **Restart Endpoint**: Allows restarting the ESP32 remotely via a web request.
- **Serial Monitoring**: Outputs network details and server status messages to the serial console.

---

## Hardware Requirements

- **ESP32 Development Board** (e.g., ESP32 DevKit, WROOM, or WROVER).
- **USB Cable**: For programming the ESP32 and powering it.
- **Computer**: To flash the code and monitor the serial output.

---

## Installation

1. **Clone the Repository**:
   ```bash
   git clone <repository_url>
   cd <repository_directory>
   ```

2. **Setup the ESP32 Board in Arduino IDE**:
   - Open Arduino IDE.
   - Go to **File > Preferences**.
   - Add the following URL to "Additional Board Manager URLs":
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Go to **Tools > Board > Board Manager**, search for `esp32`, and install the ESP32 package.

3. **Flash the Code**:
   - Open the provided `.ino` file in the Arduino IDE.
   - Select the correct ESP32 board under **Tools > Board**.
   - Select the correct serial port under **Tools > Port**.
   - Click the **Upload** button to flash the code to your ESP32.

---

## Usage

1. **Connect to the Wi-Fi Network**:
   - After flashing the code, the ESP32 will create a Wi-Fi network with the following credentials:
     - **SSID**: `ESP32_Test_Network`
     - **Password**: `password1234`
   - Connect your device to this Wi-Fi network.

2. **Access the Web Interface**:
   - Open a browser and navigate to the ESP32's IP address, which is displayed in the serial monitor (usually `192.168.4.1`).

3. **Available Pages**:
   - `/` : Displays the main welcome page.
   - `/devices` : Lists all connected devices with their MAC addresses.
   - `/restart` : Restarts the ESP32.

4. **Monitor Serial Output**:
   - Use the Arduino IDE's serial monitor (baud rate: `115200`) to view network status, connected devices, and debug information.

---

## Example Output

**Serial Monitor Output**:
```
Wi-Fi network created
Network name: ESP32_Test_Network
Password: password1234
IP Address: 192.168.4.1
HTTP server started
```

**Web Pages**:
- **Main Page**:  
  `Welcome to the ESP32 Network! ESP32 is operating as an access point.`
- **Devices Page**:  
  Displays a list of connected devices:
  ```
  Connected Devices:
  - 3A:4B:5C:6D:7E:8F
  - AA:BB:CC:DD:EE:FF
  ```
- **Restart Page**:  
  Displays: `Restarting ESP32...`

---

## Customization

- Modify the Wi-Fi credentials by changing the values of `ssid` and `password` in the code.
- Update the HTML content in the `handleRoot()` and `handleDevices()` functions to customize the web interface.

---

## License

This project is open-source and licensed under the MIT License. Feel free to use, modify, and distribute.

---

Let me know if you need further tweaks! 😊