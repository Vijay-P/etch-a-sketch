#define POTX A5 // x axis
#define POTY A4 // y axis
#define INP1 1  // button

unsigned long targetTime=0;
const unsigned long interval=100;
const int buttonPin = 0;
int buttonState = 0;
int xPos = 0;
int yPos = 0;

void setup(){
    pinMode(buttonPin, INPUT);
    Serial.begin(115200);
}

void loop(){
	if(millis()>=targetTime){
		targetTime= millis()+interval;
    xPos = analogRead(POTX);
    yPos = analogRead(POTY);
    Serial.println(String(String(xPos, DEC) + ',' + String(yPos, DEC)));
	}
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
        Serial.println("rst");
    }
}
