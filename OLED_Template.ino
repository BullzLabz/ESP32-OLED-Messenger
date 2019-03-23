// Please inspect Notes_Credits tab for references to this work
#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>


String form =                                             // String form to sent to the client-browser
  "<p>"
  "<center>"
  "<h1>Welcome to ESP8266 server! </h1>"
  "<img src='https://pbs.twimg.com/profile_images/378800000574444883/0303ac84ee73177d4239d9d17af10d83.jpeg'>"
  "<form action='msg'><p>Type something here <input type='text' name='msg' size=50 autofocus> <input type='submit' value='Send'></form>"
  "</center>";

long period;
#define SSID "*******"                                   // insert your SSID
#define PASS "*******"                                   // insert your password

// Instantiate server class                               // See tab Network for #include
ESP8266WebServer server(80);                              // HTTP server will listen at port 80


void setup(void) 
{
  //ESP.wdtDisable();                                     // used to debug, disable wachdog timer,
  Serial.begin(115200);                                   // full speed to monitor
  Wire.begin(0, 2);                                       // Initialize I2C and OLED Display
  init_OLED();                                            // Ray Burnette: added OLED, see Notes_Credits tab
  reset_display();
  WiFi.begin(SSID, PASS);                                 // Connect to WiFi network

  while (WiFi.status() != WL_CONNECTED) {                 // Wait for connection
    delay(500);
    Serial.print(".");
    SendChar('.');
  }

  // Set up the endpoints for HTTP server,  Endpoints can be written as inline functions: