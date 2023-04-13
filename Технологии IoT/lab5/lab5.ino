#define Button 1
#define DHD 14
#define DDD 2
#define LED1 13
#define LED2 15
#define LED3 12

bool But = false;

void setup() {
  Serial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(DHD, INPUT);
  pinMode(DDD, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  delay(100);
}

void loop() {
  int DD = digitalRead(DDD);
  int DH = digitalRead(DHD);
  But = !((bool)digitalRead(Button));
  
  if(But){
    digitalWrite(LED3, HIGH);
    Serial.println("But");
    delay(6000);
  }

  if(DD){
    digitalWrite(LED1, HIGH);
    Serial.println("DD");
    delay(3000);
  }

  else if(DH){
    digitalWrite(LED2, HIGH);
    Serial.println("DH");
    delay(3000);
  }

  else{
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    Serial.println("0");
  }
}
