/////////Commit 1 /////////////////////////

#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial   ///input libbrary
#include <BlynkSimpleEsp8266.h>

// Network SSID
const char* ssid = "DREV";
const char* pass = "ojoomong";

//Kode Blynk
const char* auth = "QX9MEi97X5FBlmAJk18US94Mw_X-Izk_";

#define sensormq2 A0     /// Sensor pin a0
#define sensorflame D3
#define indikator D2  /// Indikator speaker
 
void setup() {
  
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  delay(10);
  
  ////////////////////////////////////////////////////Connect WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.hostname("AyukIreng");
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Print the IP address
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  //////////////////////////////////////////////////////////

  /////Sensor MQ 2 /////////////////////////////////////////
  pinMode(sensormq2, INPUT);   /// sensor sebagai input
  pinMode(indikator, OUTPUT); ///indikator speaker sebagai output
  /////////////////////////////////////////////////////////

  /////Sensor Flame /////////////////////////////////////////
  pinMode(sensorflame, INPUT);   /// sensor sebagai input
  pinMode(indikator, OUTPUT); ///indikator speaker sebagai output
  /////////////////////////////////////////////////////////
}
 
void loop() {
int nilaimq2=(analogRead(sensormq2));


Serial.print("Nilai analog sensor GAS: ");
Serial.println(nilaimq2);
delay (1000);
  
  if(nilaimq2>350)                                  // sensor on
  {
    digitalWrite(indikator, HIGH);                    //Speaker On
    Blynk.notify("LAPOR Boss... ADA gas bocorrr ^_^");  //send notify blynk
    Blynk.virtualWrite(V0, 255);
  }
  else
  {
    digitalWrite(indikator, LOW);            ///speaker off
  }

  
int nilaiflame=digitalRead(sensorflame);
  
Serial.print("Nilai analog sensor API: ");
Serial.println(nilaiflame);
delay (1000);
  
  if(nilaiflame==0)                                  // sensor on
  {
    digitalWrite(indikator, HIGH);                    //Speaker On
    Blynk.notify("LAPOR Boss... Ada API ^_^");  //send notify blynk
    Blynk.virtualWrite(V0, 255);
  }
  else
  {
    digitalWrite(indikator, LOW);            ///speaker off
  }
  
  Blynk.run();
  }
