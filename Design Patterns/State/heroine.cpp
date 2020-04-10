enum State {
  STATE_STANDING;
  STATE_JUMPING;
  STATE_DUCKING;
  STATE_DIVING;
}

void Heroine::handleInput(Input input) {
  switch (state_) {
    case STATE_STANDING:
      if (input == PRESS_B) {
        state_ = STATE_JUMPING;
        setGraphics(IMAGE_JUMP);
      }
      else if (input == PRESS_DOWN) {
        state_ = STATE_DUCKING;
        chargeTime_ = 0;
        setGraphics(IMAGE_DUCK);
      }
      break;
      
    case STATE_JUMPING:
      if (input == PRESS_DOWN) {
        state_ = STATE_DIVING;
        setGraphics(IMAGE_DIVE);
      }
      break;
      
    case STATE_DUCKING:
      if (input == RELEASE_DOWN) {
        state_ = STATE_STANDING;
        setGraphics(IMAGE_STAND);
      }
      break;
  }
}

void Heroine::update() {
  if (state_ == STATE_DUCKING) {
    chargeTime_++;
    if (chargeTime_ > MAX_CHARGE) {
      superBomb();
    }
  }
}

//  if (input == PRESS_B) {
//    if (!isJumping_ && !isDucking_) {
//      isJumping_ = true;
//      yVelocity_ = JUMP_VELOCITY;
//      setGraphics(IMAGE_JUMP);
//    }
//  }
//  else if (input == PRESS_DOWN) {
//    if (!isJumping_) {
//      isDucking_ = true;
//      setGraphics(IMAGE_DUCK);
//    }
//    else {
//      isJumping_ = false;
//      setGraphics(IMAGE_DIVE);
//    }
//  }
//  else if (input == RELEASE_DOWN) {
//    if (isDucking_) {
//      isDucking_ = false;
//      setGraphics(IMAGE_STAND);
//    }
//  }
