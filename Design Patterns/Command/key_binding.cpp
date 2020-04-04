Class Command {
public:
    virtual ~Command () {}
    virtual void execute() = 0;
};

Class JumpCommand : Command {
public:
    virtual void execute() { jump(); }
};

Class FireCommand : Command {
public:
    virtual void execute() { fire(); }
};

Class SwapWeaponCommand : Command {
public:
    virtual void execute() { swapWeapon(); }
};

Class LurchIneffectiveCommand : Command {
public:
    virtual void execute() { lurchIneffective(); }
};

Class InputHandler {
public:
    void handleInput();
    
    // Methods to bind commands...

private:
      Command* buttonX_;
      Command* buttonY_;
      Command* buttonA_;
      Command* buttonB_;
};

void InputHandler::handleInput()
{
  if (isPressed(BUTTON_X)) buttonX_->execute();
  else if (isPressed(BUTTON_Y)) buttonY_->execute();
  else if (isPressed(BUTTON_A)) buttonA_->execute();
  else if (isPressed(BUTTON_B)) buttonB_->execute();
};
