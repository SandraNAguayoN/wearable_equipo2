


 #include <WiFi.h>

#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include "DHTesp.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
DHTesp dht;
 
//Pantalla OLED configuración
#define ANCHO_PANTALLA 128 
#define ALTO_PANTALLA  64


#define OLED_RESET     -1 // Reset pin # 
#define DIRECCION_PANTALLA 0x3C 


Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, OLED_RESET);


#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

const char* WIFI_SSID = "No te doy";
const char*   WIFI_PASSWORD = "AgNddRQ44Z";

#define API_KEY "AIzaSyAKn5QMljnTfYagludM1KeexQd1xUoOngY"

#define USER_EMAIL "ramirot629@gmail.com"
#define USER_PASSWORD "12345678"


#define DATABASE_URL "https://gdexesp32-default-rtdb.firebaseio.com/"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;


String uid;

String databasePath;
String tempPath;
String humPath;




unsigned long sendDataPrevMillis = 0;
unsigned long timerDelay = 5000;



void initWiFi() {
   WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  Serial.println();
}

void sendFloat(String path, float value){
  if (Firebase.RTDB.setFloat(&fbdo, path.c_str(), value)){
   /*Serial.print("Writing value: ");
    Serial.print (value);
    Serial.print(" on the following path: ");
    Serial.println(path);
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());*/
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
}

void setup(){
  

  initWiFi();

  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);

  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  config.max_token_generation_retry = 5;

  Firebase.begin(&config, &auth);

  Serial.println("Getting User UID");
  while ((auth.token.uid) == "") {
    Serial.print('.');
    delay(1000);
  }
  uid = auth.token.uid.c_str();
  /*Serial.print("User UID: ");
  Serial.println(uid);
*/
  databasePath = "/UsersData/" + uid;

  tempPath = databasePath + "/temperature"; // --> UsersData/<user_uid>/temperature
  humPath = databasePath + "/humidity"; // --> UsersData/<user_uid>/humidity

 dht.setup(27,DHTesp::DHT11);
  Serial.begin(115200);
   if(!display.begin(SSD1306_SWITCHCAPVCC, DIRECCION_PANTALLA)) {
    Serial.println(F("FALLO EN LA ASIGNACIÓN DE SSD1306"));
    
  }
}

void loop(){
  if (Firebase.ready() && (millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();
   float temperature = dht.getTemperature();
  float humedad = dht.getHumidity();
 
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("humedad: ");
  Serial.println(humedad); 
  delay(2000);
  sendFloat(humPath, humedad);
  sendFloat(tempPath,  temperature);
   display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("TEMP: ");
  display.println(temperature); 
  display.print("HUME: ");
  display.println(humedad); 
  display.display();
  }
}
