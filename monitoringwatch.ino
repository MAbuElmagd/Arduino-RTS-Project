#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h> // Includes the PulseSensorPlayground Library.
const int PulseWire = 0; // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
int Threshold = 550; // Determine which Signal to "count as a beat" and which to ignore.
PulseSensorPlayground pulseSensor;
const int sensor=A1; // Assigning analog pin A5 to variable 'sensor'
float tempc;
float vout; 
byte b;
void setup() {
pinMode(sensor,INPUT);
Serial.begin(9600);
// Configure the PulseSensor object, by assigning our variables to it.
pulseSensor.analogInput(PulseWire);//auto-magically blink Arduino's LED with heartbeat.
pulseSensor.setThreshold(Threshold);
 //Double-check the "pulseSensor" object was created and "began" seeing a signal.
if (pulseSensor.begin()) {
}
}
void loop() {
 if(Serial.available()>0){
vout=analogRead(sensor); //Reading the value from sensor
vout=(vout/1024.0)*500;
tempc=vout;
b=(byte)Serial.read();
float myBPM = pulseSensor.getBeatsPerMinute(); 
if(b==48){
Serial.println((char)tempc);}
if(b==49){
if (pulseSensor.sawStartOfBeat()) {
Serial.println((char)myBPM);
}}
delay(60000);
}}
