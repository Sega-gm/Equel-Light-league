void striker() {
  if (flagOut == false) {
    if (ball_retention <= 3) goAngle(0, forward_angle, 110);
    else if (abs(lead_to_degree_borders(ball_cam_angle)) <= 10) {
      goAngle(ball_cam_angle, forward_angle, 110);
      //Serial.println(" for1 ");
    }
    else {

      if (ball_cam_dist > 35) {

        goAngle(ball_cam_angle, forward_angle, 107);
      }
      else {
        if (lead_to_degree_borders(ball_cam_angle) < 0) {//Serial.println(" Left ");
          goAngle(lead_to_degree_borders(ball_cam_angle + exponential_detour(lead_to_degree_borders(ball_cam_angle), ball_cam_dist, 0.65, 0.35, 0.45, 0.8)), forward_angle, 107);//0.61, 0.35, 0.45, 0.8
        }
        else { //Serial.println(" Right ");
          goAngle(lead_to_degree_borders(ball_cam_angle - exponential_detour(lead_to_degree_borders(ball_cam_angle), ball_cam_dist, 0.57, 0.35, 0.45, 0.8)), forward_angle, 107);
        }
      }
    }
    if (flagKick == true && abs(abs_forward_angle) < 70 && ball_retention <= 3 && (millis() - timer_kick) >= 5000) {//
      kick();
      flagKick = false;
      timer_kick = millis();
      flagOne = false;
    }
    if (ball_cam_dist <= 14 && ball_retention <= 3) {
      dribler(1620);
      flagKick = true;
    }
    else if (ball_cam_dist <= 25) dribler(1615);
    else dribler(0);
  }
  else if (flagOut == true) {
    goAngle(out_angle, corAng, 110);
    flagOut = false;
  }
}
void tmrSTRK() {
  if ((millis() - timer_goForward2 >= 30000)) flagZeroGate = false;
}

void tactic() {//ворота ->мяч
  //goalkeaper

  //if (flagOut == false) {
  //x position
  angle_gate = lead_to_degree_borders(abs_backward_angle + 180);
  angle_gate_ball = lead_to_degree_borders(abs_ball_angle - angle_gate);
  float delta = lead_to_degree_borders(angle_gate_ball - angle_gate_ball_old);
  if (abs(delta) >= 7) {
    GoFor = false;
    wasMoving = true;
  }
  else {
    GoFor = true;
    if (wasMoving) {
      timer_goForward = millis();
      wasMoving = false;
    }
  }
  if (GoFor && (millis() - timer_goForward >= 7500)) flagZeroGate = true;
  spdX = angle_gate_ball * KPX + KDX * (angle_gate_ball - angle_gate_ball_old);
  angle_gate_ball_old = angle_gate_ball;
  if (x >= 27 && x <= 33)
    spdY = float(YzeroFront2 - y) * KPY2;
  else if (x >= -20 && x <= -25)
    spdY = float(YzeroFront2 - y) * KPY2;
  else spdY = float(YzeroFront - y) * KPY;
  //spdX = constrain(spdX, spdMinX, spdMaxX);
  //spdY = constrain(spdY, spdMinY, spdMaxY);
  //vector
  spdGLK = 103 + sqrt(spdX * spdX + spdY * spdY);
  //if (spdGLK > 3.5) spdGLK = spdGLK + 100;
  alphaGLK = lead_to_degree_borders(90 - atan2(spdY, spdX) * 180.0 / PI);
  //}
  //polar_dek(spdX, alphaX, spdY, alphaY);


  //    goAngle(lead_to_degree_borders(alphaGLK - corAng), lead_to_degree_borders(0 - corAng), spdGLK)
  if (flagZeroGate == false) {
    //timer_goForward2 = 0;
    if (x >= 33 && x >= -25) {
      if (x > 0) goAngle(-90, 0, 107);
      else goAngle(90, 0, 107);
    }
    else goAngle(alphaGLK - corAng, abs_ball_angle, spdGLK);
  }
  else {
    timer_goForward2 = millis();
    tmrSTRK();
    striker();
  }
  //}
  //else if (flagOut == true) {
  //goAngle(out_angle, corAng, 110);
  //flagOut = false;
  //}
}
