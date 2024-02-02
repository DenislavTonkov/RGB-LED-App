# RGB-LED-App
This repository introduces an Arduino Bluetooth application, methodically developed for implementation with the HC05 module. It facilitates the manipulation of LEDs, allowing for meticulous control and signal transmission through an Android application. The project underscores a formal integration of Arduino and Bluetooth connectivity

## Hardware overview:
<p align='center'>
  <img src="https://github.com/DenislavTonkov/RGB-LED-App/assets/83066616/376a4b8f-4be7-420c-aa64-7672aa682d2d" width="800" height="450">
</p>

## Components Used
  * Arduino board (e.g., Arduino Uno)
  * RGB LED (common cathode or common anode)
  * Bluetooth module (e.g., HC-05 or HC-06)

## Wiring
**1. Connect the RGB LED to the following pins on the Arduino:**
  * White LED pin: Digital pin 12
  * Green LED pin: Digital pin 10
  * Red LED pin: Digital pin 11

**2. Connect the Bluetooth module to the following pins on the Arduino:**

  * RX (receive) pin: Digital pin 9
  * TX (transmit) pin: Digital pin 8

## Code Explanation
**1. SoftwareSerial Setup:**

We use the `SoftwareSerial` library to create a software serial port for communication with the Bluetooth module.
The RX and TX pins are defined as `rxPin` and `txPin`, respectively.

**2. LED Pins Setup:**

The LED pins (white, green, and red) are defined as output pins using `pinMode()`.

**3. Bluetooth Initialization:**

The Bluetooth module is initialized with a baud rate of 9600 using `BTSerial.begin(9600)`.

**4. Main Loop:**

  * The main loop continuously checks if there is data available from the Bluetooth module.
  * If data is available, it reads three integers representing the white, green, and red values (0 to 255).
  * If all values are zero, the LEDs turn off using the void function `ledsOff()`.
  * If all values are 255, the LEDs perform a fast color cycle using the `bgFlafFastCycle()`.
  * Otherwise, the LEDs are set to the specified RGB color `setColor()`.
    
**5. Helper Functions:**

  * `setColor(int white, int green, int red)`: Sets the LED colors based on the input values.
  * `ledsOff()`: Turns off all LEDs.
  * `serialFlush()`: Clears any remaining data in the Bluetooth buffer.
    
## Usage
* 1. Upload this sketch to your Arduino board.
* 2.  Pair your Bluetooth module with a compatible Android device using the DeniBTTest.apk app.
* 3.  Use a Bluetooth terminal app to send RGB values (0 to 255) to control the LED.

*Feel free to modify and experiment with the code to suit your specific project needs!*😀
