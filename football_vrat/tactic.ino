void tactic() {//ворота ->мяч
  //goalkeaper
  if (flagOut == false) {
    //x position
    angle_gate = lead_to_degree_borders(abs_backward_angle + 180);
    angle_gate_ball = lead_to_degree_borders(abs_ball_angle - angle_gate);
    spdX = angle_gate_ball * KPX + KDX * (angle_gate_ball - angle_gate_ball_old);
    angle_gate_ball_old = angle_gate_ball;
    spdY = float(YzeroFront - y) * KPY;
    //spdX = constrain(spdX, spdMinX, spdMaxX);
    //spdY = constrain(spdY, spdMinY, spdMaxY);
    //vector
    spdGLK = 105+sqrt(spdX * spdX + spdY * spdY);
    //if (spdGLK > 3.5) spdGLK = spdGLK + 100;
    alphaGLK = lead_to_degree_borders(90 - atan2(spdY, spdX) * 180.0 / PI);
    //}
    //polar_dek(spdX, alphaX, spdY, alphaY);


    //    goAngle(lead_to_degree_borders(alphaGLK - corAng), lead_to_degree_borders(0 - corAng), spdGLK)
    if (abs(x) > 26){
      if(x > 0) goAngle(-90, 0, 104);
      else goAngle(90, 0, 104);
    }
    else goAngle(alphaGLK, 0, spdGLK);
    
  }
  else if (flagOut == true) {
    //goAngle(out_angle, corAng, 110);
    flagOut = false;
  }
}
