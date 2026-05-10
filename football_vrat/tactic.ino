void tactic() {//ворота ->мяч
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
    
  }
  else if (flagOut == true) {
    //goAngle(out_angle, corAng, 110);
    flagOut = false;
  }
}
