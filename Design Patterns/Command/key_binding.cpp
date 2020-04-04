Class Command {
public:
  virtual ~Command () {}
  virtual void execute(GameActor& actor) = 0;
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

int main( int argc, const char* argv[] ) {
  Command* command = InputHandler.handleInput()
  if (command) {
    command->execute(actor);
  }
  // Nothing pressed, so do nothing.
  return NULL;
};
