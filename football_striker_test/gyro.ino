//MPU
/*void gyro() {
  static uint32_t tmr;
  if (millis() - tmr >= 11) {  // таймер на 11 мс (на всякий случай)
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
      // переменные для расчёта (ypr можно вынести в глобал)
      Quaternion q;
      VectorFloat gravity;
      float euler[3];
      // расчёты
      mpu.dmpGetQuaternion(&q, fifoBuffer);
      mpu.dmpGetEuler(euler, &q);
      float angle = euler[0] * 180.0 / M_PI;   // инвертируем направление
      //      angle = 360 - angle;
      //if (angle >= 360) angle -= 360;
      //      if (angle < 0) angle += 360;

      angleGyro = angle;
      tmr = millis();  // сброс таймера
      //      Serial.print("euler\t");
      //      Serial.print(angleGyro);//180-
      //      Serial.println(" ");
    }
  }
  }*/
//BNO
void gyro() {
  static uint32_t tmr;
  if (millis() - tmr >= 11) {
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    angleGyro = euler.x();
    tmr = millis();  // сброс таймера
  }
}
