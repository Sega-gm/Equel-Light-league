void goAngle(float angle, float seeAngle, int speeds) {//угол на который надо поехать по гироскопу, скорость
  float speedMotor1 = 0, speedMotor2 = 0;
  float err = 0, speedRotate = 0;
  err = -lead_to_degree_borders(corAng - seeAngle);
  speedRotate = PDcube(err);
//  angle *= 0.017453;
//  speedMotor1 = speeds * cosf(0.785 + angle);
//  speedMotor2 = speeds * cosf(2.36 + angle);
//  Serial.print(speedMotor1);
//  Serial.print("speedMotor1");
//  Serial.print(speedMotor2);
//  Serial.print("speedMotor2");
//  Serial.print(speedRotate);
//  Serial.println("speedRotate");
  motor1.setSpeeds(speeds * cos((-45 + angle)/180*3.14) + speedRotate);
  motor2.setSpeeds(-speeds * cos((-135 + angle)/180*3.14) + speedRotate);
  motor3.setSpeeds(speeds * cos((135 + angle)/180*3.14) + speedRotate);
  motor4.setSpeeds(-speeds * cos((45 + angle)/180*3.14) + speedRotate);
}

void kick()
{
  digitalWrite(pinsolin, HIGH);
  kickDel = true;
  timer_kick2 = millis();
  //Serial.println("111");//4tc - 2
  
}
void KickPosition(){
  if (abs(x) >= 40 && y >= 170 && ball_retention <= 3){
    flagKickPosition = false;
    flagBadZone = true;
  }
  else if (forward_dist > 65 || abs(abs_forward_angle) > 70){ flagKickPosition = false; flagBadZone = false;}
  else {flagKickPosition = true; flagBadZone = false;}
    
  
}
void kick_Del(){
  if (kickDel && (millis() - timer_kick2 >= 200)){
    timer_kick2 = 0;
    digitalWrite(pinsolin, LOW);
    
    kickDel = false;
    Serial.println("222");//4tc - 2
  }
}
void dribler(int speeds) {
  dribblerESC.writeMicroseconds(speeds);
  
}
