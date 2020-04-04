Class Command {
public:
  virtual ~Command () {}
  virtual void execute(GameActor& actor) = 0;
  virtual void undo() = 0;
};

Class JumpCommand : Command {
public:
  virtual void execute(GameActor& actor) {
    actor.jump();
  }
};

Class FireCommand : Command {
public:
  virtual void execute(GameActor& actor) {
    actor.fire();
  }
};

Class SwapWeaponCommand : Command {
public:
  virtual void execute(GameActor& actor) {
    actor.swapWeapon();
  }
};

Class LurchIneffectiveCommand : Command {
public:
  virtual void execute(GameActor& actor) {
    actor.lurchIneffective();
  }
};

Command* handleInput()
{
  Unit* unit = getSelectedUnit();
  
  if (isPressed(BUTTON_UP)) {
    // Move the unit up one.
    int destY = unit->y() - 1;
    return new MoveUnitCommand(unit, unit->x(), destY);
  }
  
  if (isPressed(BUTTON_DOWN)) {
    // Move the unit down one.
    int destY = unit->y() + 1;
    return new MoveUnitCommand(unit, unit->x(), destY);
  }
  
  // Other moves...
  
  return NULL;
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

class MoveUnitCommand : public Command
{
public:
  MoveUnitCommand(Unit* unit, int x, int y):
  unit_(unit),
  xBefore_(0),
  yBefore_(0),
  x_(x),
  y_(y)
  {}
  
  virtual void execute()
  {
    // Remember the unit's position before the move
    // so we can restore it.
    xBefore_ = unit_->x();
    yBefore_ = unit_->y();
    unit_->moveTo(x_, y_);
  }
  
private:
  Unit* unit_;
  int xBefore_, yBefore_;
  int x_, y_;
};

int main( int argc, const char* argv[] ) {
  Command* command = InputHandler.handleInput()
  if (command) {
    command->execute(actor);
  }
  // Nothing pressed, so do nothing.
  return NULL;
};
