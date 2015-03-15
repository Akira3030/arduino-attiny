
int led2 = 2;
int led4 = 4;

void setup() {                
  pinMode(led2, OUTPUT);  
  pinMode(led4, OUTPUT); // 
}

void loop() {
  parpadeo(3,500);
  oneToOne(10, 300);
  oneToOne(40, 100);
}
void parpadeo(int rep, int time){
    for(int i=0;i < rep;i++){
      digitalWrite(led2, HIGH);  
      digitalWrite(led4, HIGH);  
      delay(time); 
      digitalWrite(led2, LOW);  
      digitalWrite(led4, LOW);  
      delay(time);
    }  
}

void oneToOne(int rep, int time){
      for(int i=0;i < rep;i++){
      digitalWrite(led2, HIGH);  
      digitalWrite(led4, LOW);  
      delay(time); 
      digitalWrite(led2, LOW);  
      digitalWrite(led4, HIGH);  
      delay(time);
    }  
}