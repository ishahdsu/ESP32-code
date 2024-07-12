# ESP32-code
This Task involves an ESP32 microcontroller that connects to WiFi and periodically sends HTTP GET requests to a specified URL. The response from the server is used to control the onboard LED of the ESP32. The server response can be a single letter or a word indicating different actions for the LED.

 ## Components
 
1. **ESP32 Microcontroller**: A versatile microcontroller with built-in WiFi capabilities.
2. **WiFi Connection**: The ESP32 connects to the internet via WiFi.
3. **HTTP Client**: The ESP32 uses an HTTP client to fetch data from a server.
4. **Onboard LED**: The LED built into the ESP32 DevKit is used to indicate different actions based on the server response.

**LED Control Based on Response**:
   - Depending on the response (`S`, `F`, `B`, `R`, `L` or their corresponding words), the onboard LED performs different actions:
     - **"S" or "stop"**: Turn the LED off.
     - **"F" or "forward"**: Turn the LED on.
     - **"B" or "backward"**: Blink the LED five times.
     - **"R" or "right"**: Blink the LED rapidly ten times.
     - **"L" or "left"**: Blink the LED slowly three times.
   - Any unknown command is printed to the serial monitor without affecting the LED.

**Note**:
the code works perfectly in these URls: https://s-m.com.sa/r2/test/retrieve.php, https://s-m.com.sa/f.html...etc. But for some reason when I tried to use it with my webpage http://df65-2001-16a2-c0e3-da8-adcd-7af2-1bd8-ee2.ngrok-free.app/fetch_last_move.php 
it did not work and it has an error 307 Temporary Redirect, I tried to solve it but i did not find any solution to my problem..
