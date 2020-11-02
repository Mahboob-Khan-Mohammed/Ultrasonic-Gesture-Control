// define pins numbers
const int VCC = 7;
const int trigPin = 6;
const int echoPin = 5;
const int GND = 4;
// define variables
long duration;
float distance;
int avg = 0;
int n = 100;

void setup()
{
  pinMode(VCC, OUTPUT); // Sets the VCC as an Output
  digitalWrite(VCC, HIGH); //Pull VCC high
  
  pinMode(GND, OUTPUT); // Sets the GND as an Output
  digitalWrite(GND, LOW); //Pull GND low
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200); // Starts the serial communication
}

void loop() 
{
  for(int i = 0; i < n; i++)
  {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH, 1000);
    avg += duration;
    }
    if(avg/n > 10)
    {
      Serial.print("1");
    }
    else
    {
      Serial.print("0");
    }
    avg = 0;
}


