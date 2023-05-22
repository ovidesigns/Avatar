#include <CapacitiveSensor.h>
CapacitiveSensor Sensor = CapacitiveSensor(4, 6);
long val;

const int tens1 = 8;
const int tens2 = 2;
const int tens3 = 12;
const int tens4 = 13;

int sensorValue = 0;
int freq = 0;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // tens is initialized as an output
  pinMode(tens1, OUTPUT);
  pinMode(tens2, OUTPUT);
  pinMode(tens3, OUTPUT);
  pinMode(tens4, OUTPUT);
}

void loop() {

  val = Sensor.capacitiveSensor(30);
  Serial.println(val);


  if (val >= 500 && val <= 800) {
    digitalWrite(tens1, HIGH);
    digitalWrite(tens2, LOW);
    digitalWrite(tens3, LOW);
    digitalWrite(tens4, LOW);
  }

  else if (val > 1400) {
    digitalWrite(tens1, LOW);
    digitalWrite(tens2, HIGH);
    digitalWrite(tens3, LOW);
    digitalWrite(tens4, LOW);
  }

  else if (val >= 800 && val <= 1100) {
    digitalWrite(tens1, LOW);
    digitalWrite(tens2, LOW);
    digitalWrite(tens3, HIGH);
    digitalWrite(tens4, LOW);
  }

  else if (val >= 1100 && val <= 1400) {
    digitalWrite(tens1, LOW);
    digitalWrite(tens2, LOW);
    digitalWrite(tens3, LOW);
    digitalWrite(tens4, HIGH);
  }

  else {
    digitalWrite(tens1, LOW);
    digitalWrite(tens2, LOW);
    digitalWrite(tens3, LOW);
    digitalWrite(tens4, LOW);
  }  
  
  delay(50);
}
