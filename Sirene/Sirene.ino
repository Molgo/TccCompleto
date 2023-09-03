#include <virtuabotixRTC.h>  
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "EEPROM.h"

#define   clk   15
#define   dat   4
#define   rst   23

#define   segL        0
#define   minL       49
#define   horL       19
#define   d_semL      1
#define   d_mesL      8
#define   mesL        1
#define   anoL     2023

#define EEPROM_SIZE 160

const char* ssid = "Miguel";
const char* password = "**********";

const char * Hostname = "sirenetcc.shop";
String URI = "/setup.json";
const uint16_t port = 80; 

unsigned long int tempoAnterior = 0;
unsigned long int tempoAnterior2 = 0;

int meiaNoite = 24;

String hora_0;  String minuto_0;
String hora_1;  String minuto_1;
String hora_2;  String minuto_2;
String hora_3;  String minuto_3;
String hora_4;  String minuto_4;
String hora_5;  String minuto_5;
String hora_6;  String minuto_6;
String hora_7;  String minuto_7;
String hora_8;  String minuto_8;
String hora_9;  String minuto_9;
String hora_10; String minuto_10;
String hora_11; String minuto_11;
String hora_12; String minuto_12;
String hora_13; String minuto_13;
String hora_14; String minuto_14;

virtuabotixRTC   myRTC(clk, dat, rst);      //declara objeto para o RTC

void DS1302();
void week(int dayW);

void setup() {

  pinMode(2,OUTPUT);

  EEPROM.begin(EEPROM_SIZE);
  
  //myRTC.setDS1302Time(segL, minL, horL, d_semL, d_mesL, mesL, anoL);

  Serial.begin(115200);
  while (!Serial) continue;
  wifi_connect();

  load_json();
  
}

void sirene()
{
 
 digitalWrite(2,1);
 Serial.println("Alarme ON");
 delay(EEPROM.read(31) * 1000);
 digitalWrite(2,0);
 Serial.println("Alarme OFF");
 
}

void DS1302()
{
  
  myRTC.updateTime();         //faz leitura do DS1302
 
 week(myRTC.dayofweek);
 Serial.print(" | ");
 Serial.print(myRTC.dayofmonth);
 Serial.print("/");
 Serial.print(myRTC.month);
 Serial.print("/");
 Serial.print(myRTC.year);
 Serial.print(" | ");
 if(myRTC.hours < 10) Serial.print("0");
 Serial.print(myRTC.hours);
 Serial.print(":");
 if(myRTC.minutes < 10) Serial.print("0");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 if(myRTC.seconds < 10) Serial.print("0");
 Serial.println(myRTC.seconds);
 Serial.println(WiFi.localIP());
 delay(1000);
  
}

  void wifi_connect()
{
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

  void load_json(){

WiFiClient client;
  client.setTimeout(10000);
  
  if (!client.connect(Hostname, port)) {
    Serial.println(F("Connection failed"));
    return;
  }

  Serial.println(F("Connected!"));

  // Send HTTP request
  client.println("GET " + URI + " HTTP/1.0");
  client.println("Host: " + (String)Hostname);
  client.println("Connection: close");
  if (client.println() == 0) {
    Serial.println("Failed to send request");
    client.stop();
    return;
  }

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.0 200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    client.stop();
    return;   
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));  
    client.stop();
    return;
  }

  // Allocate the JSON document
  StaticJsonDocument<768> doc;

  DeserializationError error = deserializeJson(doc, client);

  if (error) {
  Serial.print("deserializeJson() failed: ");
  Serial.println(error.c_str());
  return;
  }  

  String horario0 = doc["horario0"];
  String horario1 = doc["horario1"];
  String horario2 = doc["horario2"];
  String horario3 = doc["horario3"];
  String horario4 = doc["horario4"];
  String horario5 = doc["horario5"];
  String horario6 = doc["horario6"];
  String horario7 = doc["horario7"];
  String horario8 = doc["horario8"];
  String horario9 = doc["horario9"];
  String horario10 = doc["horario10"];
  String horario11 = doc["horario11"];
  String horario12 = doc["horario12"];
  String horario13 = doc["horario13"];
  String horario14 = doc["horario14"];
  String config_version = doc["config_version"];
  String duration = doc["duration"];

  hora_0 = horario0.substring(0,2);  
  minuto_0 = horario0.substring(3,5);     
  hora_1 = horario1.substring(0,2);  
  minuto_1 = horario1.substring(3,5);     
  hora_2 = horario2.substring(0,2);
  minuto_2 = horario2.substring(3,5); 
  hora_3 = horario3.substring(0,2); 
  minuto_3 = horario3.substring(3,5); 
  hora_4 = horario4.substring(0,2);    
  minuto_4 = horario4.substring(3,5); 
  hora_5 = horario5.substring(0,2);    
  minuto_5 = horario5.substring(3,5);   
  hora_6 = horario6.substring(0,2);    
  minuto_6 = horario6.substring(3,5);     
  hora_7 = horario7.substring(0,2);   
  minuto_7 = horario7.substring(3,5);  
  hora_8 = horario8.substring(0,2);    
  minuto_8 = horario8.substring(3,5); 
  hora_9 = horario9.substring(0,2); 
  minuto_9 = horario9.substring(3,5);   
  hora_10 = horario10.substring(0,2);
  minuto_10 = horario10.substring(3,5);  
  hora_11 = horario11.substring(0,2);
  minuto_11 = horario11.substring(3,5);   
  hora_12 = horario12.substring(0,2);  
  minuto_12 = horario12.substring(3,5);                                          
  hora_13 = horario13.substring(0,2);   
  minuto_13 = horario13.substring(3,5); 
  hora_14 = horario14.substring(0,2);   
  minuto_14 = horario14.substring(3,5);                                                                                   
  int hora_0INT = hora_0.toInt(); 
  int minuto_0INT = minuto_0.toInt();             
  int hora_1INT = hora_1.toInt();
  int minuto_1INT = minuto_1.toInt();            
  int hora_2INT = hora_2.toInt(); 
  int minuto_2INT = minuto_2.toInt();                                                                                                             
  int hora_3INT = hora_3.toInt();   
  int minuto_3INT = minuto_3.toInt();           
  int hora_4INT = hora_4.toInt();   
  int minuto_4INT = minuto_4.toInt();           
  int hora_5INT = hora_5.toInt();    
  int minuto_5INT = minuto_5.toInt();                                        
  int hora_6INT = hora_6.toInt(); 
  int minuto_6INT = minuto_6.toInt();      
  int hora_7INT = hora_7.toInt();   
  int minuto_7INT = minuto_7.toInt();    
  int hora_8INT = hora_8.toInt();  
  int minuto_8INT = minuto_8.toInt();                                          
  int hora_9INT = hora_9.toInt();   
  int minuto_9INT = minuto_9.toInt();      
  int hora_10INT = hora_10.toInt();   
  int minuto_10INT = minuto_10.toInt();       
  int hora_11INT = hora_11.toInt();  
  int minuto_11INT = minuto_11.toInt();                           
  int hora_12INT = hora_12.toInt();    
  int minuto_12INT = minuto_12.toInt();       
  int hora_13INT = hora_13.toInt();  
  int minuto_13INT = minuto_13.toInt();     
  int hora_14INT = hora_14.toInt();  
  int minuto_14INT = minuto_14.toInt(); 
  int duracaoINT = duration.toInt();
  int versaoINT = config_version.toInt();
       
  if(EEPROM.read(0) != versaoINT){
  EEPROM.write(0, versaoINT);
  //------------------------------
  if(hora_0INT == 0){
    EEPROM.write(1, meiaNoite);
  }else{
    EEPROM.write(1, hora_0INT);
  }
  EEPROM.write(2, minuto_0INT);
  //------------------------------  
  if(hora_1INT == 0){
    EEPROM.write(3, meiaNoite);
  }else{
    EEPROM.write(3, hora_1INT);
  }
  EEPROM.write(4, minuto_1INT);
  //------------------------------
  if(hora_2INT == 0){
    EEPROM.write(5, meiaNoite);
  }else{
    EEPROM.write(5, hora_2INT);
  }
  EEPROM.write(6, minuto_2INT); 
  //------------------------------
  if(hora_3INT == 0){
    EEPROM.write(7, meiaNoite);
  }else{
    EEPROM.write(7, hora_3INT);
  }
  EEPROM.write(8, minuto_3INT); 
  //------------------------------
  if(hora_4INT == 0){
    EEPROM.write(9, meiaNoite);
  }else{
    EEPROM.write(9, hora_4INT);
  }
  EEPROM.write(10, minuto_4INT); 
  //------------------------------
  if(hora_5INT == 0){
    EEPROM.write(11, meiaNoite);
  }else{
    EEPROM.write(11, hora_5INT);
  }
  EEPROM.write(12, minuto_5INT);
  //------------------------------
  if(hora_6INT == 0){
    EEPROM.write(13, meiaNoite);
  }else{
    EEPROM.write(13, hora_6INT);
  }
  EEPROM.write(14, minuto_6INT); 
  //------------------------------
  if(hora_7INT == 0){
    EEPROM.write(15, meiaNoite);
  }else{
    EEPROM.write(15, hora_7INT);
  }
  EEPROM.write(16, minuto_7INT); 
  //------------------------------
  if(hora_8INT == 0){
    EEPROM.write(17, meiaNoite);
  }else{
    EEPROM.write(17, hora_8INT);
  }
  EEPROM.write(18, minuto_8INT); 
  //------------------------------
  if(hora_9INT == 0){
    EEPROM.write(19, meiaNoite);
  }else{
    EEPROM.write(19, hora_9INT);
  }
  EEPROM.write(20, minuto_9INT); 
  //------------------------------
  if(hora_10INT == 0){
    EEPROM.write(21, meiaNoite);
  }else{
    EEPROM.write(21, hora_10INT);
  }
  EEPROM.write(22, minuto_10INT);
  //------------------------------
  if(hora_11INT == 0){
    EEPROM.write(23, meiaNoite);
  }else{
    EEPROM.write(23, hora_11INT);
  }
  EEPROM.write(24, minuto_11INT);
  //------------------------------
  if(hora_12INT == 0){
    EEPROM.write(25, meiaNoite);
  }else{
    EEPROM.write(25, hora_12INT);
  }
  EEPROM.write(26, minuto_12INT);
  //------------------------------
  if(hora_13INT == 0){
    EEPROM.write(27, meiaNoite);
  }else{
    EEPROM.write(27, hora_13INT);
  }
  EEPROM.write(28, minuto_13INT);
  //------------------------------
  if(hora_14INT == 0){
    EEPROM.write(29, meiaNoite);
  }else{
    EEPROM.write(29, hora_14INT);
  }
  EEPROM.write(30, minuto_14INT);
  //------------------------------
  EEPROM.write(31, duracaoINT);
  //------------------------------
  EEPROM.commit();
  }

  int versaoEEPROM = EEPROM.read(0);
  int hora_0EEPROM = EEPROM.read(1);
  int minuto_0EEPROM = EEPROM.read(2);
  int hora_1EEPROM = EEPROM.read(3);
  int minuto_1EEPROM = EEPROM.read(4);
  int hora_2EEPROM = EEPROM.read(5);
  int minuto_2EEPROM = EEPROM.read(6);
  int hora_3EEPROM = EEPROM.read(7);
  int minuto_3EEPROM = EEPROM.read(8);
  int hora_4EEPROM = EEPROM.read(9);
  int minuto_4EEPROM = EEPROM.read(10);
  int hora_5EEPROM = EEPROM.read(11);
  int minuto_5EEPROM = EEPROM.read(12);
  int hora_6EEPROM = EEPROM.read(13);
  int minuto_6EEPROM = EEPROM.read(14);
  int hora_7EEPROM = EEPROM.read(15);
  int minuto_7EEPROM = EEPROM.read(16);
  int hora_8EEPROM = EEPROM.read(17);
  int minuto_8EEPROM = EEPROM.read(18);
  int hora_9EEPROM = EEPROM.read(19);
  int minuto_9EEPROM = EEPROM.read(20);
  int hora_10EEPROM = EEPROM.read(21);
  int minuto_10EEPROM = EEPROM.read(22);
  int hora_11EEPROM = EEPROM.read(23);
  int minuto_11EEPROM = EEPROM.read(24);
  int hora_12EEPROM = EEPROM.read(25);
  int minuto_12EEPROM = EEPROM.read(26);
  int hora_13EEPROM = EEPROM.read(27);
  int minuto_13EEPROM = EEPROM.read(28);
  int hora_14EEPROM = EEPROM.read(29);
  int minuto_14EEPROM = EEPROM.read(30);
  int duracaoEEPROM = EEPROM.read(31);

  Serial.println(versaoEEPROM);
  Serial.print(hora_0EEPROM);
  Serial.println(minuto_0EEPROM);
  Serial.print(hora_1EEPROM);
  Serial.println(minuto_1EEPROM);
  Serial.print(hora_2EEPROM);
  Serial.println(minuto_2EEPROM);
  Serial.print(hora_3EEPROM);
  Serial.println(minuto_3EEPROM);
  Serial.print(hora_4EEPROM);
  Serial.println(minuto_4EEPROM);
  Serial.print(hora_5EEPROM);
  Serial.println(minuto_5EEPROM);
  Serial.print(hora_6EEPROM);
  Serial.println(minuto_6EEPROM);
  Serial.print(hora_7EEPROM);
  Serial.println(minuto_7EEPROM);
  Serial.print(hora_8EEPROM);
  Serial.println(minuto_8EEPROM);
  Serial.print(hora_9EEPROM);
  Serial.println(minuto_9EEPROM);
  Serial.print(hora_10EEPROM);
  Serial.println(minuto_10EEPROM);
  Serial.print(hora_11EEPROM);
  Serial.println(minuto_11EEPROM);
  Serial.print(hora_12EEPROM);
  Serial.println(minuto_12EEPROM);
  Serial.print(hora_13EEPROM);
  Serial.println(minuto_13EEPROM);
  Serial.print(hora_14EEPROM);
  Serial.println(minuto_14EEPROM);
  Serial.println(duracaoEEPROM * 1000);
  
}
  void week(int dayW)
{
  
  switch(dayW)
  {
    case 1: Serial.print("Dom"); break;
    case 2: Serial.print("Seg"); break;
    case 3: Serial.print("Ter"); break;
    case 4: Serial.print("Qua"); break;
    case 5: Serial.print("Qui"); break;
    case 6: Serial.print("Sex"); break;
    case 7: Serial.print("Sab"); break;
   
  }
}

void loop()  
{

   if(millis() - tempoAnterior2 >= 600000){
    tempoAnterior2 = millis();
    wifi_connect();
    }

  
   if(millis() - tempoAnterior >= 600000){
    tempoAnterior = millis();
    load_json();
    }

    DS1302();
   
   if(myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(1) && myRTC.minutes == EEPROM.read(2) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(3) && myRTC.minutes == EEPROM.read(4) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(5) && myRTC.minutes == EEPROM.read(6) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(7) && myRTC.minutes == EEPROM.read(8) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(9) && myRTC.minutes == EEPROM.read(10) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(11) && myRTC.minutes == EEPROM.read(12) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(13) && myRTC.minutes == EEPROM.read(14) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(15) && myRTC.minutes == EEPROM.read(16) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(17) && myRTC.minutes == EEPROM.read(18) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(19) && myRTC.minutes == EEPROM.read(20) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(21) && myRTC.minutes == EEPROM.read(22) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(23) && myRTC.minutes == EEPROM.read(24) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(25) && myRTC.minutes == EEPROM.read(26) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(27) && myRTC.minutes == EEPROM.read(28) && myRTC.seconds == 0 ||
      myRTC.dayofweek >= 1 && myRTC.dayofweek <= 7 && myRTC.hours == EEPROM.read(29) && myRTC.minutes == EEPROM.read(30) && myRTC.seconds == 0)
   
   {
    sirene();
   }
  
}
