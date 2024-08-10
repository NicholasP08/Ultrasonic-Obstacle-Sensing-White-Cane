//Nicholas_Pillay_Code_for_White_Cane_Distance_Detector

//Defines Pins
const int trigPin = 9;            //Define 9 as Trig Pin on Ultrasonic Sensor
const int echoPin = 10;           //Define 10 as Echo Pin on Ultrasonic Sensor
const int buzzer = 11;            //Define 11 as Buzzer Pin
const int ledPin = 13;            //Define 13 as LED Pin

//Defines Variables
long duration;                    //Define duration as a Variable
int distance;                     //Define distance as a Variable

void setup() {
  pinMode(trigPin, OUTPUT);       //Sets the Trig Pin as an Output
  pinMode(echoPin, INPUT);        //Sets the Echo Pin as an Input
  pinMode(buzzer, OUTPUT);        //Sets the Buzzer as an Output
  pinMode(ledPin, OUTPUT);        //Sets the LED as an Output
  Serial.begin(9600);             //Starts the Serial Communication

  digitalWrite(ledPin, HIGH);
  tone(buzzer,400);
  delay(2000);
  digitalWrite(ledPin, LOW);
  noTone(buzzer);

}

void loop() {
  digitalWrite(trigPin, LOW);     //Sets the Trig Pin to Low for the beginning of the pulse
  delayMicroseconds(2);           //Keeps the Trig Pin Low for 0.000002 Seconds

  digitalWrite(trigPin, HIGH);    //Sets the Trig Pin to High for the middle of the pulse
  delayMicroseconds(10);          //Keeps the Trig Pin High for 0.00001 Seconds

  digitalWrite(trigPin, LOW);     //Sets the Trig Pin back to Low for the end of the pulse which launches the Ultrasonic Pulses

  duration=pulseIn(echoPin, HIGH);//Reads the Echo Pin and places the sound wave travel time in microseconds to duration variable

  distance=duration*0.034/2;      //Calculates the distance from the speed of sound in centimeters and places the result to distance variable

  if (distance>=45){
    digitalWrite(ledPin,LOW);
    noTone(buzzer);
}

  if (distance<45&&distance>=30){
    digitalWrite(ledPin,HIGH);
    tone(buzzer,100);
}

  if (distance<30&&distance>=15){
    digitalWrite(ledPin,HIGH);
    tone(buzzer,250);
}

  if (distance<15){
    digitalWrite(ledPin,HIGH);
    tone(buzzer,400);
}

  Serial.print("Distance: ");     //Prints on Serial Monitor Distance:
  Serial.println(distance);       //Prints on Serial Monitor the value under distance variable and then goes to the next line
  delay(500);
}