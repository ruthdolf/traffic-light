# Traffic Light IoT Project

This project simulates and controls a traffic light system using the **ESP8266** microcontroller and a web-based interface. It demonstrates basic LED control, web server setup, and communication between client-side JavaScript and server-side code.


## Project Structure

| File | Description |
|------|--------------|
| `traffic_light.ino` | Simple Arduino sketch for blinking LEDs representing traffic lights. |
| `myHelloServer.ino` | ESP8266 web server program that serves the HTML interface and responds to HTTP requests to control LEDs. |
| `Ruth_traffic-light.html` | Web interface for the traffic light, stored on the ESP8266's SPIFFS filesystem. |


## Hardware Setup

| Component | ESP8266 Pin |
|------------|-------------|
| Red LED | D1 (GPIO 5) |
| Yellow LED | D4 (GPIO 2) |
| Green LED | D0 (GPIO 16) |

Use resistors in series with each LED (typically 220Ω–330Ω).


## How It Works

1. **Web Server (ESP8266)**
   - Connects to WiFi using the SSID and password defined in `myHelloServer.ino`.
   - Serves `Ruth_traffic-light.html` from SPIFFS.
   - Responds to `/red`, `/green`, `/yellowON`, and `/yellowOFF` requests to control LED states.

2. **Web Interface**
   - Clicking on a light sends a corresponding HTTP request to the ESP8266.
   - JavaScript handles the light transition logic and updates the UI.

3. **Arduino Sketch**
   - `traffic_light.ino` provides a standalone example of how LEDs can be toggled in sequence.


## Upload Instructions

1. Open **Arduino IDE**.
2. Install the **ESP8266 board package**.
3. Open `myHelloServer.ino`.
4. Go to **Tools > Board > NodeMCU 1.0 (ESP-12E Module)** (or equivalent).
5. Set your WiFi credentials in the code:
   ```cpp
   #define STASSID "YourNetworkName"
   #define STAPSK "YourPassword"
   ```
6. Upload `Ruth_traffic-light.html` to SPIFFS using the **ESP8266 Sketch Data Upload** tool.
7. Upload the `.ino` file to your ESP8266.
8. Open **Serial Monitor** (115200 baud) to see your device’s IP address.
9. Visit `http://<your-esp-ip>` in your browser.



## Example Output

When you open the web interface, you’ll see a black traffic light frame with three clickable lights:
- Clicking **Red** turns on the red LED after a short yellow transition.
- Clicking **Green** turns on the green LED after a short yellow transition.
- Yellow transitions are animated via JavaScript timing.



## Troubleshooting

- If the web page doesn’t load, ensure SPIFFS is properly formatted and uploaded.
- If the LEDs don’t light up:
  - Check pin connections.
  - Verify the correct pin numbers match your wiring.
  - Ensure the board is powered with sufficient current.


## License

This project is based on open-source examples and may be freely used and modified for educational purposes.
````
