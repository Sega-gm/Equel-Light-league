void polar_dek(float longsX, float alphaX, float longsY, float alphaY) {
  float x_decX = longsX * cosf(alphaX * DEG2RAD);
  float y_decX = longsX * sinf(alphaX * DEG2RAD);

  float x_decY = longsY * cosf(alphaY * DEG2RAD);
  float y_decY = longsY * sinf(alphaY * DEG2RAD);

  float sum_x = x_decX + x_decY;
  float sum_y = y_decX + y_decY;
//  Serial.print(x_decY);
//  Serial.print("  ");
//  Serial.print(y_decY);
  Serial.print("  ||  ");
  Serial.print(sum_x);
  Serial.print("  ");
  Serial.print(sum_y);
  Serial.print("  ||  ");
  spdGLK = sqrt(sum_x * sum_x + sum_y * sum_y);
  spdGLK = 100 + (int)constrain(spdGLK, 0, 15);
  if(ball_cam_angle > 180) {
    alphaGLK = lead_to_degree_borders(atan2(sum_y, sum_x) * 180.0 / PI);
    alphaGLK = -alphaGLK;

  }
  else alphaGLK = lead_to_degree_borders(atan2(sum_y, sum_x) * 180.0 / PI);
}
void coordinates() {
  //  const float minDist = 0;
  //  const float maxDist = 210;

  forward_dist = blue_dist;//blue_dist
  backward_dist = yel_dist;//yel_dist
  forward_angle = blue_angle;//blue_angle
  backward_angle = yel_angle;//yel_angle

  abs_ball_angle = lead_to_degree_borders(ball_cam_angle + corAng);
  abs_forward_angle = lead_to_degree_borders(forward_angle + corAng);
  abs_backward_angle = lead_to_degree_borders(backward_angle + corAng);

  x_forward = -forward_dist * sinf(abs_forward_angle * DEG2RAD);
  x_backward = -backward_dist * sinf(abs_backward_angle * DEG2RAD);

  y_forward =  230 - forward_dist * cosf(abs_forward_angle * DEG2RAD);
  y_backward = -backward_dist * cosf(abs_backward_angle * DEG2RAD);

  //bool visForward = forward_dist > constrain(forward_dist, minDist, maxDist);
  //bool visBackward = backward_dist > constrain(backward_dist, minDist, maxDist);

  //if (forward_dist == 0) {
  Correct_coef = (backward_dist) / (2 * 230);
  x = (x_backward * (1 - Correct_coef));
  y = (y_backward * (1 - Correct_coef));

  //    flagOneGate = true;
  //    //    Serial.println("back");
  //  }
  //  else if (backward_dist == 0) {
  //    Correct_coef = (forward_dist) / (2 * 230);
  //    x = (x_forward * (1 - Correct_coef));
  //    y = (y_forward * (1 - Correct_coef));
  //
  //    flagOneGate = true;
  //    //    Serial.println("for");
  //  }
  //  else {
  //    Correct_coef = (backward_dist - forward_dist) / (2 * (forward_dist + backward_dist));
  //    x = (x_forward * Correct_coef) + (x_backward * (1 - Correct_coef));
  //    y = (y_forward * Correct_coef) + (y_backward * (1 - Correct_coef));
  //    flagOneGate = false;
  //    //    Serial.println(" 2gate ");
  //  }
  //  if (flagOneGate == false) OneGate_Out_KofX = 0;
  //  else if (flagOneGate == true) OneGate_Out_KofX = 10; //10
}
void outs() {
  if ((right_out - OneGate_Out_KofX) <= x || (left_out + OneGate_Out_KofX)) { //  || backward_out >= y || forward_out <= y) >= x
    //flagOut = true;

    if ((left_out + OneGate_Out_KofX) >= x) {
      out_angle = 90;
    }
    else if ((right_out - OneGate_Out_KofX) <= x) {
      out_angle = 270;
    }
    //    else if (backward_out >= y) out_angle = 0;
    //    else if (forward_out <= y)  out_angle = 180;
  }
  else flagOut = false;
}
