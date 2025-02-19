
// Value of Pir pins
int pirPinUp = 2;
int pirPinDown = 3;

// Variables for determening if the sensors are triggered
bool pirStatOpp = false;
bool pirStatNed = false;  
  
//Values for the logic about light
int LEDPinsUp[] = {12,13}; //Change in here for light pins for steps
int LEDPinsDown[] = {13,12}; // Needs to be the excact opposite of LedPinsUp
int numberOfElements = sizeof(LEDPinsUp) / sizeof(LEDPinsUp[0]);

void setup() {
  //Output LED
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  //Input PIR
  pinMode(pirPinUp,INPUT);
  pinMode(pirPinDown,INPUT);

  //Serial
  Serial.begin(9600);

  //Confirmation of element amount
  Serial.println(numberOfElements);
}

void loop() {
  //Reads sensors and sets variables
  pirStatOpp=digitalRead(pirPinUp);
  pirStatNed=digitalRead(pirPinDown);

  //Check of values before this iteration
  Serial.print("Value bool up before process: ");
  Serial.print(pirStatOpp);
  Serial.print(", and bool down: ");
  Serial.println(pirStatNed);

  //Statement to check if the sensor is triggered to turn on lights
  if (pirStatOpp == HIGH){ 
    lightloop(1,LEDPinsUp);
    //Delay between turn on and turn off
    delay(10000);
    lightloop(0,LEDPinsUp);
    Serial.println("For loop done");
    delay(1000);
  }
  else if (pirStatNed == HIGH){ 
    lightloop(1,LEDPinsDown);
    //Delay between turn on and turn off
    delay(10000);
    lightloop(0,LEDPinsDown);
    Serial.println("For loop done");
    delay(1000);
  }
  //Not turn
  else{
    delay(1000);
  }
 
Serial.println("Loop done");
}

void lightloop(int turn, int array[]) {
  //Decides if the call is is for turn on or turn off
  int val;
  if (turn == 0){
    val = LOW;
  }
  else {
    val = HIGH;
  }
  //Loop for turning on/off light
  for(int i = 0; i < numberOfElements ; i++){
      digitalWrite(array[i] ,val);
      delay(1000);
    }
}

