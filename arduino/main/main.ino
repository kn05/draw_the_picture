#include <AFMotor.h>

AF_DCMotor motor1(4);
AF_DCMotor motor2(3);
AF_DCMotor motor3(2);

void move(int x, int y){
    float r = 100;
    int dx = x - px;
    int dy = y - py;
    if(dx > 0){
        motor1.run(FORWARD);
        delay(r*dx);
    }
    if(dx < 0){
        motor1.run(BACKWARD);
        delay(-r*dx);
    }
    if(dy > 0){
        motor2.run(FORWARD);
        delay(r*dy);
    }
    if(dy < 0){
        motor2.run(BACKWARD);
        delay(-r*dy);
    }
    px = x;
    py = y;
}

int px= 0, py = 0;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
}

void loop(){
    char cmd;
    if(Serial.available()){
        char cmd = Serial.read();
    }
    if(cmd == 'm'){
        int i = 2
        int x, y;
        while(i){
            if(Serial.available()){
                i--;
                switch (i)
                {
                case 1:
                    x = Serial.read();
                    break;
                case 0: 
                    y = Serial.read();
                    break;
                default:
                    break;
                }
            }
        }
        move(x, y);
    } 
    if(cmd == 'u'){
        motor3.run(FORWARD);
        delay(300);
    }  
    if(cmd == 'd'){
        motor3.run(BACKWARD);
        delay(300);
    }
    else{
      println("Error!");
    }
    }
}
