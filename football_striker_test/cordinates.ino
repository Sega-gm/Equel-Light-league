void coordinates() {
  
  int sideGame = 1;
  if (sideGame == 1) {
    forward_dist = blue_dist ;//blue_dist
    backward_dist = yel_dist;//yel_dist
    forward_angle = blue_angle;//blue_angle
    backward_angle = yel_angle;//yel_angle
  } else {
    forward_dist = yel_dist ;//blue_dist
    backward_dist = blue_dist;//yel_dist
    forward_angle = yel_angle;//blue_angle
    backward_angle = blue_angle;//yel_angle
  }
  //abs_ball_angle = lead_to_degree_borders(ball_cam_angle + corAng);
//  back_ball_angle = lead_to_degree_borders(abs_ball_angle + 180);
  abs_forward_angle = lead_to_degree_borders(forward_angle + corAng);
  abs_backward_angle = lead_to_degree_borders(backward_angle + corAng);
  
  x_forward = -forward_dist * sin(abs_forward_angle * DEG2RAD);
  x_backward = -backward_dist * sin(abs_backward_angle * DEG2RAD);
  y_forward =  230 - forward_dist * cos(abs_forward_angle * DEG2RAD);
  y_backward = -backward_dist * cos(abs_backward_angle * DEG2RAD);

  if ((forward_dist == 0 || backward_dist < 100) && backward_dist != 0) {
    Correct_coef = (backward_dist) / (2 * 220);
    x = (x_backward * (1 - Correct_coef));
    y = (y_backward * (1 - Correct_coef));
    //left_X_dop =
    flagOneGate = true;
    Serial.println("back");
  }
  else if ((backward_dist == 0 || forward_dist < 100) && forward_dist != 0) {
    Correct_coef = (forward_dist) / (2 * 220);
    x = (x_forward * (1 - Correct_coef));
    y = (y_forward * (1 - Correct_coef));

    flagOneGate = true;
    Serial.println("for");
  }
  else {
    Correct_coef = (backward_dist - forward_dist) / (2 * (forward_dist + backward_dist));
    x = (x_forward * Correct_coef) + (x_backward * (1 - Correct_coef));
    y = (y_forward * Correct_coef) + (y_backward * (1 - Correct_coef));
    flagOneGate = false;
    Serial.println(" 2gate ");
  }
  if (flagOneGate == false){
    right_out = right_out2G;
    left_out = left_out2G;
    //Serial.println(" 2gate ");
  }
  else{
    right_out = right_out1G;
    left_out = left_out1G;
    //Serial.println(" 1gate ");
    
  }
}
void KickPosition(){
  if (abs(x) >= 40 && y >= 170 && ball_retention <= 3){
    flagKickPosition = false;
    flagBadZone = true;
  }
  else if (forward_dist > 80 || abs(abs_forward_angle) > 70){ flagKickPosition = false; flagBadZone = false;}
  else {flagKickPosition = true; flagBadZone = false;}
    
  
}
void outs() {
  if ((right_out <= x) || (left_out >= x) || (backward_out >= backward_dist && backward_dist != 0) || (forward_out >= forward_dist && forward_dist != 0)) { //
    flagOut = true;

    if (left_out >= x) {
      out_angle = 90;
    }
    else if (right_out <= x) {
      out_angle = 270;
    }
    else if (backward_out >= backward_dist && backward_dist != 0) out_angle = 0;//Serial.println("back");
    else if (forward_out >= forward_dist && forward_dist != 0)  out_angle = 180;//Serial.println("for");
  }
  else flagOut = false;
}
