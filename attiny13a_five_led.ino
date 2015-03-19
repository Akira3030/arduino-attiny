
int led0 = 0;
int led1 = 1;
int led2 = 2;
int led3 = 4;
int led4 = 3;

void setup() {                
  pinMode(led0, OUTPUT);  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  secuence(300);
}

void secuence(int time){
  // Go
  activar(led0);
  delay(time);
  activar(led1);
  delay(time);
  activar(led2);
  delay(time);
  activar(led3);
  delay(time);
  activar(led4);
  delay(time);
  
}

void activar(int pin){
  for (int i = 0; i < 5; i = i++) {
    if (pin == i) {
        digitalWrite(i, HIGH); 
    }else{
        digitalWrite(i, LOW); 
    }
  }
}