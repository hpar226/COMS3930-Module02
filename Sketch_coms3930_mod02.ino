/**********************************************************************
  Filename    : Joystick ; modified by Henry Park, includes button and switch
  Description : Read data from joystick.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
enum playMode {OFF, MODE1, MODE2};

int xyzPins[] = {13, 12, 14};   //x,y,z pins
int buttonPin1 = 26;
int buttonPin2 = 27;
int switchPin = 15;
int bluePin = 18;
int redPin = 19;
int greenPin = 5;
enum playMode outputMode;

void setup() {
  Serial.begin(9600);
  pinMode(xyzPins[2], INPUT_PULLUP);  //z axis is a button.
  pinMode(buttonPin1, INPUT_PULLUP);  //blue button
  pinMode(buttonPin2, INPUT_PULLUP);  //red button
  pinMode(switchPin, INPUT_PULLUP);   //spdt switch
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);

  int buttonVal1 = digitalRead(buttonPin1);
  int buttonVal2 = digitalRead(buttonPin2);
  int switchVal = digitalRead(switchPin);

  if(switchVal == 0) {
    outputMode = OFF;
  }
  if(switchVal == 1) {
    outputMode = MODE1;
  }
  
  Serial.printf("%d\t%d\t%d\t%d\t%d\t%d", xVal, yVal, zVal, buttonVal1, buttonVal2, switchVal);

  //inactive mode
  if (switchPin == 0) {
    Serial.printf("");
  }

  else if (switchPin == 1) {
    Serial.printf("%d\t", xVal);
  }

  Serial.print('\n');
  delay(100);
}
