/*enum TacticState {
  ST_GO_TO_BALL,      // едем к мячу
  ST_ALIGN_TO_BALL,   // доворачиваемся к мячу
  ST_DRIBBLE,  // ведем мяч на ворота
  ST_KICK,            // удар
  ST_RETURN_OUT  // возврат после аута
  };

  TacticState tacticState = ST_GO_TO_BALL;

  void tactic() {

  if (flagOut) {
    tacticState = ST_RETURN_OUT;
  }

  switch (tacticState) {

    case ST_RETURN_OUT://ауты
      goAngle(out_angle, corAng, 110);
      flagOut = false;
      tacticState = ST_GO_TO_BALL;
      break;

    case ST_GO_TO_BALL://езда к мячу
      dribler(0);

      if (abs(lead_to_degree_borders(ball_cam_angle)) <= 15) {//запуск дриблера
        tacticState = ST_DRIBBLE;
      } else {
        if (ball_cam_dist > 35) {
          goAngle(ball_cam_angle, forward_angle, 110);
        } else {
          if (lead_to_degree_borders(ball_cam_angle) < 0) {
            goAngle(lead_to_degree_borders(ball_cam_angle + 90), forward_angle, 107);
          } else {
            goAngle(lead_to_degree_borders(ball_cam_angle - 90), forward_angle, 107);
          }
        }
      }
      break;

    case ST_DRIBBLE:
      if (ball_cam_dist <= 20) {
        if (ball_retention <= 3) {
          dribler(1620);
          flagOne = true;
        } else {
          dribler(1615);
        }
      } else {
        dribler(0);
      }

      goAngle(ball_cam_angle, forward_angle, 105);
      flagKick = true;
      if (flagKick && forward_dist <= 65 && ball_retention <= 3 && (millis() - timer_kick) >= 5000) tacticState = ST_KICK;
      if (abs(lead_to_degree_borders(ball_cam_angle)) > 15) {
        tacticState = ST_ALIGN_TO_BALL;
      }
      break;

    case ST_ALIGN_TO_BALL:
      dribler(0);

      if (abs(lead_to_degree_borders(ball_cam_angle)) <= 15) {
        tacticState = ST_DRIBBLE;
      } else {
        if (lead_to_degree_borders(ball_cam_angle) < 0) {
          goAngle(lead_to_degree_borders(ball_cam_angle + 90), forward_angle, 107);
        } else {
          goAngle(lead_to_degree_borders(ball_cam_angle - 90), forward_angle, 107);
        }
      }
      break;

    case ST_KICK:
      kick();
      flagKick = false;
      flagOne = false;
      timer_kick = millis();
      tacticState = ST_GO_TO_BALL;
      break;
  }
  }*/

//void tactic() {
//  if (flagOut == false) {
//      if (ball_cam_dist <= 10 && ball_retention <= 3) {
//        dribler(1620);
//        flagOne = true;
//      }
//      else if (ball_cam_dist <= 20) dribler(1615);
//    if (abs(lead_to_degree_borders(ball_cam_angle)) <= 15) {
//      goAngle(ball_cam_angle, forward_angle, 105);
//      flagKick = true;
//      Serial.println(" for1 ");
//    }
//    else {
//      dribler(0);
//      if (ball_cam_dist > 35) {
//        //Serial.println(" Dist ");
//        goAngle(ball_cam_angle, forward_angle, 110);
//      }
//      else {
//
//        if (lead_to_degree_borders(ball_cam_angle) < 0) //Serial.println(" Left ");
//          goAngle(lead_to_degree_borders(ball_cam_angle + 90), forward_angle, 107);
//        else  //Serial.println(" Right ");
//          goAngle(lead_to_degree_borders(ball_cam_angle - 90), forward_angle, 107);
//      }
//    }
//    if (flagKick == true && forward_dist <= 65 && ball_retention <= 3 && (millis() - timer_kick) >= 5000) {//
//      kick();
//      flagKick = false;
//      timer_kick = millis();
//      flagOne = false;
//    }
//  }
//  else if (flagOut == true) {
//    goAngle(out_angle, corAng, 110);
//    flagOut = false;
//  }
//}

void tactic() {
  if (flagOut == false) {
    if (flagBadZone == true) {
      if (x < 0) goAngle(145, corAng, 110);
      else goAngle(-145, corAng, 110);
    }
    else if (ball_retention <= 3) goAngle(0, forward_angle, 110);
    else if (abs(lead_to_degree_borders(ball_cam_angle)) <= 10) {
      goAngle(ball_cam_angle, forward_angle, 110);
      //Serial.println(" for1 ");
    }
    else {

      if (ball_cam_dist > 35) {
        //Serial.println(" Dist ");

        goAngle(ball_cam_angle, forward_angle, 110);
      }
      else {
        //if(ball_cam_dist < 12) goAngle(ball_cam_angle, ball_cam_angle, 105);
        if (lead_to_degree_borders(ball_cam_angle) < 0) //Serial.println(" Left ");
          goAngle(lead_to_degree_borders(ball_cam_angle + exponential_detour(lead_to_degree_borders(ball_cam_angle), ball_cam_dist, 0.61, 0.35, 0.45, 0.8)), forward_angle, 107);
        else  //Serial.println(" Right ");
          goAngle(lead_to_degree_borders(ball_cam_angle - exponential_detour(lead_to_degree_borders(ball_cam_angle), ball_cam_dist, 0.63, 0.35, 0.45, 0.8)), forward_angle, 107);
      }
    }
    if (flagKick == true && flagKickPosition == true && ball_retention <= 3 && (millis() - timer_kick) >= 5000) {//
      kick();
      flagKick = false;
      timer_kick = millis();
      flagOne = false;
    }
    if (ball_cam_dist <= 12 && ball_retention <= 3) {
      dribler(1620);
      driblerON = true;
      flagKick = true;
    }
    else if (ball_cam_dist <= 22) dribler(1615);
    else dribler(0);
  }
  else if (flagOut == true) {
    goAngle(out_angle, corAng, 110);
    flagOut = false;
  }
}
