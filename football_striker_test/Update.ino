void updates() {
  digitalWrite(LED_BUILTIN, millis() % 200 > 100);
  corAng = lead_to_degree_borders(angleGyro - errAngleGyro);
  data_tcops();
  Camera();
  gyro();
  readSensors();
  coordinates();
  kick_Del();
  //KickPosition();
  outs();

  //Serial.println(abs(lead_to_degree_borders(ball_cam_angle)));
//  if (ball_cam_dist <= 10 && ball_retention <= 3) {
//    dribler(1620);
//    flagOne = true;
//  }
//  else if (ball_cam_dist <= 20) dribler(1615);
//  if (ball_retention <= 3) {
//    goAngle(0,0,0);
//  }
//  else 
  //goAngle(exponential_detour(lead_to_degree_borders(ball_cam_angle), ball_cam_dist, 0.45, 0.15, 0.35, 0.7),forward_angle,105);
  Serial.print(lead_to_degree_borders(ball_cam_angle));
  Serial.print("  ||  ");
  Serial.print(ball_cam_dist);
  Serial.print("  ||  ");
//  Serial.print(exponential_detour(lead_to_degree_borders(ball_cam_angle), ball_cam_dist, 0.45, 0.15, 0.35, 0.7));
//  Serial.print("  ||  ");
//  Serial.print(ball_cam_dist);
//  Serial.println(" ");

}
