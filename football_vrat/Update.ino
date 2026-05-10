void updates() {
  digitalWrite(LED_BUILTIN, millis() % 200 > 100);
  corAng = lead_to_degree_borders(angleGyro - errAngleGyro);
  data_tcops();
  Camera();
  gyro();
  readSensors();

  coordinates();
  kick_Del();
  outs();
  //    if (enemy_side == 1){
  //      enemy_side_angle = yel_angle;
  //      enemy_side_dist = yel_dist;
  //    }
  //    else if (enemy_side == 2){
  //      enemy_side_angle = blue_angle;
  //      enemy_side_dist = blue_dist;
  //    }
  //goalkeaper
  if (flagOut == false) {

    //x position
    angle_gate = lead_to_degree_borders(abs_backward_angle + 180);
    angle_gate_ball = lead_to_degree_borders(abs_ball_angle - angle_gate);
    //    if (abs(abs_backward_angle) > 115) {
    //      if (x > 0) {
    //        Serial.print(" right ");
    //        spdX = 0;
    //        spdY = 0;
    //        spdY2 = angle_gate_ball * KPY2;
    //        spdX2 = float(XzeroRight - x) * KPX2;
    //        //spdX = constrain(spdX, spdMinX, spdMaxX);
    //        //spdY = constrain(spdY, spdMinY, spdMaxY);
    //        //vector
    //        //if(spdY > 0) spdY = spdY *
    //        spdGLK = sqrt(spdX2 * spdX2 + spdY2 * spdY2);
    //        spdGLK = constrain(spdGLK, 0, 10);
    //        if (spdGLK > 5.5) spdGLK = spdGLK + 100;
    //        alphaGLK = atan2(spdY2, spdX2) * 180.0 / PI;
    //        if (spdY2 > 0) alphaGLK = lead_to_degree_borders(90 + alphaGLK);
    //      }
    //      else {
    //        Serial.print(" left ");
    //        /*spdX = 0;
    //        spdY = 0;
    //        spdY2 = angle_gate_ball * KPY2;
    //        spdX2 = float(XzeroRight - x) * KPX2;
    //        //spdX = constrain(spdX, spdMinX, spdMaxX);
    //        //spdY = constrain(spdY, spdMinY, spdMaxY);
    //        //vector
    //        //if(spdY > 0) spdY = spdY *
    //        spdGLK = sqrt(spdX2 * spdX2 + spdY2 * spdY2);
    //        spdGLK = constrain(spdGLK, 0, 10);
    //        if (spdGLK > 5.5) spdGLK = spdGLK + 100;
    //        alphaGLK = atan2(spdY2, spdX2) * 180.0 / PI;
    //        if (spdY2 > 0) alphaGLK = lead_to_degree_borders(90 + alphaGLK);*/
    //      }
    //    }
    //    else {
    Serial.print(" front ");
    spdX2 = 0;
    spdY2 = 0;
    spdX = angle_gate_ball * KPX + KDX * (angle_gate_ball - angle_gate_ball_old);
    angle_gate_ball_old = angle_gate_ball;
    spdY = float(YzeroFront - y) * KPY;
    //spdX = constrain(spdX, spdMinX, spdMaxX);
    //spdY = constrain(spdY, spdMinY, spdMaxY);
    //vector
    spdGLK = 100+sqrt(spdX * spdX + spdY * spdY);
    //if (spdGLK > 3.5) spdGLK = spdGLK + 100;
    alphaGLK = lead_to_degree_borders(90 - atan2(spdY, spdX) * 180.0 / PI);
    //}
    //polar_dek(spdX, alphaX, spdY, alphaY);


    //    goAngle(lead_to_degree_borders(alphaGLK - corAng), lead_to_degree_borders(0 - corAng), spdGLK)
    if (abs(x) > 25){
      if(x > 0) goAngle(-90, 0, 102);
      else goAngle(90, 0, 102);
    }
    else goAngle(alphaGLK, 0, spdGLK);
    //    Serial.print(angle_gate);
    //    Serial.print("  ");
    Serial.print(abs_backward_angle);
    Serial.print("  ");
    Serial.print(angle_gate_ball);
    //Serial.print("  ");
    //    Serial.print(spdX);
    Serial.print("  ||  ");
    Serial.print(spdY2);
    Serial.print("  ");
    Serial.print(spdX2);
    Serial.print("  ||  ");
    Serial.print(spdGLK);
    Serial.print("  ");
    Serial.print(alphaGLK);
    Serial.print("  ||  ");
    Serial.print(x);
    Serial.print("  ");
    Serial.println(y);
  }
  else if (flagOut == true) {
    //goAngle(out_angle, corAng, 110);
    flagOut = false;
  }
}
