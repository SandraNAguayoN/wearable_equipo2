//Carga de librerias 
#include <WiFi.h>
//libreria para conectar a firebase
#include "FirebaseESP32.h"
//libreria para usar al buzzer
#include <EasyBuzzer.h>
//libreria Sensor de oxigenación
#include "MAX30105.h"
#include "heartRate.h"
//Pantalla oled
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//Sensor de temperatura y humedad
#include "DHTesp.h"
//Creación de objeto para el sensor de temperatura
DHTesp dht;


// Credenciales wifi
//#define WIFI_SSID "INFINITUM3B7D"
//#define WIFI_PASSWORD "3287828464"

//#define WIFI_SSID "No te doy"
//#define WIFI_PASSWORD "AgNddRQ44Z"
#define WIFI_SSID "INFINITUM7385_2.4"
#define WIFI_PASSWORD "Xz6CtRYtL8"

// Credenciales Proyecto Firebase
#define FIREBASE_HOST "https://espprueba32-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "jRYN2ssXLsjvlL72nHPtzJ5N5eGgI7tXbL4hHhFW"


//Bandera que se usara para insertar los datos de los ultimos registros
int bandera = 1;

// Firebase Data object
FirebaseData firebaseData;

// variable para el nodo inicial
String nodo = "/sensores";

//Configuración para pantalla oled

//Ajuste de tamaño de pantalla
#define ANCHO_PANTALLA 128 
#define ALTO_PANTALLA  64

//Configuraciones basicas pantalla
#define OLED_RESET     -1 // Reset pin # 
#define DIRECCION_PANTALLA 0x3C 

//Asignación de configuraciones anteriores a pantalla
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, OLED_RESET);
//Se cargara un logo y se le da un tamaño
#define LOGO_WIDTH 60
#define LOGO_HEIGHT 25
//se carga el codigo de la imagen a usar
const unsigned char GDEX[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x07, 0x00, 0x00, 
  0x00, 0x7e, 0x00, 0x00, 0x3c, 0x0f, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00, 0x1e, 0x1e, 0x00, 0x00, 
  0x00, 0xf7, 0x9f, 0xc0, 0x1f, 0x3c, 0x00, 0x00, 0x01, 0xe3, 0x9f, 0xc0, 0x0f, 0xb8, 0x00, 0x00, 
  0x01, 0xc0, 0x1c, 0xe7, 0xc7, 0xf0, 0x00, 0x00, 0x01, 0xc7, 0x98, 0xef, 0xc3, 0xe0, 0x00, 0x00, 
  0x01, 0xe7, 0x98, 0xed, 0xe2, 0x60, 0x00, 0x00, 0x00, 0xe7, 0x98, 0xed, 0xc3, 0x70, 0x00, 0x00, 
  0x00, 0xff, 0x9f, 0xcf, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x7f, 0x9f, 0x87, 0x87, 0xfc, 0x00, 0x00, 
  0x00, 0x18, 0x80, 0x01, 0x0f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3c, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x0f, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
//Definir pines de sensor ultrasonico

#define TRIG_PIN 25 // ESP32 pin GIOP23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 26 // ESP32 pin GIOP22 connected to Ultrasonic Sensor's ECHO pin
float duration_us, distance_cm;


//Se crea el objeto del sensor de oxigenación
MAX30105 particleSensor;
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;


void setup() 
{
  //inicio de serial
  Serial.begin(115200);
  // Configuración del pin de sonido
  EasyBuzzer.setPin(23);
  
//ciclo para conectar a base de datos 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectado al Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

//Conexión a base de datos con firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
 
  // configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
  
   // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30102 was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");

  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
  
  //Se inicializa en el pin 27 el uso del sensor de temperatura humedad  
  dht.setup(27,DHTesp::DHT11);
  
  //Se asigna la pantalla oled
  if(!display.begin(SSD1306_SWITCHCAPVCC, DIRECCION_PANTALLA)) {
    Serial.println(F("FALLO EN LA ASIGNACIÓN DE SSD1306"));
    
  }
  
}


void loop() 
{
  //sensor de oxigenación
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
  //sensor ultrasonico
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 
 // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // Se calcula la distancia
  distance_cm = 0.017 * duration_us;
  
//Se optiene la temperatura y humedad
 float temperature = dht.getTemperature();
  float humedad = dht.getHumidity();

  Serial.println("Temperature: ");
  Serial.println(temperature);
  Serial.print("humedad: ");
  Serial.println(humedad); 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("TEMP: ");
  display.println(temperature); 
  display.print("HUME: ");
  display.println(humedad); 
  display.print("IR: ");
  display.println(irValue); 
  display.print("BPM: ");
  display.println(beatsPerMinute); 
  display.print("distancia: ");
  display.println(distance_cm); 
  display.println(" cm");
  display.print("Avg BPM: ");
  display.println(beatAvg); 
   Serial.print("distancia: ");
  Serial.println(distance_cm); 
  Serial.println(" cm");
  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);
  void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
  display.drawBitmap(((display.width() - LOGO_WIDTH )/2 )+25,((display.height() - LOGO_HEIGHT)/2)-18, GDEX, LOGO_WIDTH, LOGO_HEIGHT, WHITE);
  display.display();
   if (irValue < 50000)
    Serial.print(" No finger?");


  // push de datos
  Firebase.pushFloat(firebaseData, nodo+"/ultraSonic" + "/distancia", distance_cm);
  delay(100);
  Firebase.pushFloat(firebaseData, nodo+"/oxigeno" + "/BPM", beatsPerMinute);
  delay(100);
  Firebase.pushFloat(firebaseData, nodo+"/Temperatura" + "/temperatura", temperature);
  delay(100);
  Firebase.pushFloat(firebaseData, nodo+"/Temperatura"  + "/humedad", humedad);    
  delay(2000);


  
  //carga de datos para los ultimos 5 registros de temperatura
 Firebase.getFloat(firebaseData, nodo + "/Bandera"+"/val1");
 float valuno = firebaseData.floatData();
 Serial.println(valuno);
  Firebase.getFloat(firebaseData, nodo + "/Bandera"+"/val2");
 float val2 = firebaseData.floatData();
 Serial.println(val2);
  Firebase.getFloat(firebaseData, nodo + "/Bandera"+"/val3");
 float val3 = firebaseData.floatData();
 Serial.println(val3);
  Firebase.getFloat(firebaseData, nodo + "/Bandera"+"/val4");
 float val4 = firebaseData.floatData();
 Serial.println(val4);
  Firebase.getFloat(firebaseData, nodo + "/Bandera"+"/val5");
 float val5 = firebaseData.floatData();
  
if((valuno < 28) && (val2 <28) && (val3 <28) && (val4 <28) && (val5 <28)){
 Serial.println("Temperatura baja"); 
EasyBuzzer.singleBeep(1000, 1000);//Ejecutar sonido de buzzer si la temperatura es menor a 25 grados
delay(1000);
}else if((valuno >36) && (val2 >36) && (val3 >36) && (val4 >36) && (val5 >36)){
   Serial.println("Temperatura alta");
   EasyBuzzer.singleBeep(1000, 1000);//Ejecutar sonido de buzzer si la temperatura es mayor a 40 grados
delay(1000);
}else{
   Serial.println("Temperatura normal");
}
EasyBuzzer.stopBeep();// Detener sonido de buzzer


//inicio de if para actualizar el valor de los ultimos 5 registros de temperatura 
 if(bandera==1){
   Firebase.setInt(firebaseData, nodo + "/Bandera"+ "/val1", temperature);  
 }else if(bandera==2){
  Firebase.setInt(firebaseData, nodo + "/Bandera"+ "/val2", temperature);  
 }else if(bandera==3){
  Firebase.setInt(firebaseData, nodo + "/Bandera"+ "/val3", temperature);  
 }else if(bandera==4){
  Firebase.setInt(firebaseData, nodo + "/Bandera"+ "/val4", temperature);  
 }else if(bandera==5){
  Firebase.setInt(firebaseData, nodo + "/Bandera"+ "/val5", temperature);  
 }
 
 if(bandera==5){
  bandera = 1;
 }
 bandera++;//

  
  EasyBuzzer.update(); //función para poder mandar sonido con el buzzer
} // End Loop
