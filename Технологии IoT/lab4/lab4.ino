bool leftBut = false;
bool rightBut = false;
bool lastBT = false;
bool currentBT = false;
bool ledOn = LOW;

int LED[4] = {13, 15, 12 ,14};

int LEDIndex = 0;
int LEDPin = LED[LEDIndex];
int LEDBright = 0;

void setup() {
  Serial.begin(115200);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
}

void loop() {
  leftBut = !((bool)debvence(lastBT, 1));
  rightBut = !((bool)debvence(lastBT, 2));

  if(leftBut && rightBut){
    if(LEDIndex == 3){
      LEDIndex = 0;
    } else{
      LEDIndex++;
    }
    LEDPin = LED[LEDIndex];
    digitalWrite(LEDPin, HIGH);
    delay(1000);
    digitalWrite(LEDPin, LOW);
    return;
  }

  if(rightBut && !leftBut){
    for(LEDBright = 0; LEDBright < 255; LEDBright++){
      analogWrite(LEDPin, LEDBright);
      delay(3);
    }
  }

  if(!rightBut && leftBut){
    for(LEDBright = 255; LEDBright > 0; LEDBright--){
      analogWrite(LEDPin, LEDBright);
      delay(3);
    }
  }
}

bool debvence (bool last, int PIN) {
  bool current = digitalRead(PIN);
  if (current == false)
  {
    delay(5);
    current = digitalRead(PIN);
  }
  return current;
}