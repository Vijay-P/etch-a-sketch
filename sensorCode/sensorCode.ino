#define POTX A5 // x axis
#define POTY A4 // y axis
#define INP1 0  // button
#define FSR  A3 // fsr

unsigned long targetTime=0;
const unsigned long interval=100;
unsigned long lastDebounceTime = 0;
int buttonState = 0;
int xPos = 0;
int yPos = 0;
int fsrValue = 0;

void setup(){
    pinMode(INP1, INPUT);
    Serial.begin(115200);
}

void loop(){
    if(millis()>=targetTime){
    	targetTime= millis()+interval;
      xPos = analogRead(POTX);
      yPos = analogRead(POTY);
      Serial.println(String(String(xPos, DEC) + ',' + String(yPos, DEC)));
    }
    buttonState = digitalRead(INP1);
    if (buttonState == LOW) {
        Serial.println("rst");
    }

    fsrValue = analogRead(FSR);
    if(readFsr(fsrValue) == true){
      Serial.println("color");
    }

}

boolean readFsr(int fsrValue){
  if (fsrValue > 200) {
    if (millis()-lastDebounceTime > 200){
       lastDebounceTime = millis();
       return true;
    }
  }
  return false;
}
