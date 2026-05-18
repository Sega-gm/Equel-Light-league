void goAngle(float angle, float seeAngle, int speeds) {//угол на который надо поехать по гироскопу, скорость
  float speedMotor1 = 0, speedMotor2 = 0;
  float err = 0, speedRotate = 0;
  err = -lead_to_degree_borders(corAng - seeAngle);
  speedRotate = PDcube(err);
  if (flagOff == true) {
    motor1.setSpeeds(0);
    motor2.setSpeeds(0);
    motor3.setSpeeds(0);
    motor4.setSpeeds(0);
  } else {
    motor1.setSpeeds(speeds * cos((-45 + angle) / 180 * 3.14) + speedRotate);
    motor2.setSpeeds(-speeds * cos((-135 + angle) / 180 * 3.14) + speedRotate);
    motor3.setSpeeds(speeds * cos((135 + angle) / 180 * 3.14) + speedRotate);
    motor4.setSpeeds(-speeds * cos((45 + angle) / 180 * 3.14) + speedRotate);
  }
}

void kick()
{
  digitalWrite(pinsolin, HIGH);
  kickDel = true;
  timer_kick2 = millis();
  //Serial.println("111");//4tc - 2

}

void kick_Del() {
  if (kickDel && (millis() - timer_kick2 >= 200)) {
    timer_kick2 = 0;
    digitalWrite(pinsolin, LOW);

    kickDel = false;
    Serial.println("222");//4tc - 2
  }
}
void dribler(int speeds) {
  dribblerESC.writeMicroseconds(speeds);

}
