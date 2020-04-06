class Observer {
public:
  virtual ~Observer() {}
  virtual void onNotify(const Entity& entitiy, Event event) = 0;
};


class Achievements : public Observer {
public:
  virtual void onNotify(const Entity& entitiy, Event event) {
    switch (event) {
      case EVENT_ENTITY_FELL:
        if (entitiy.isHero() && heroIsOnBridge_) {
          unlock(ACHIEVEMENT_FELL_OFF_BRIDGE);
        }
        break;
        // Handle other events, and update heroIsOnBridge_...
      default:
        break;
    }
  }
  
private:
  void unlock(Achievement achievement) {
    // Unlock if it hasn't yet..
  }
  bool heroIsOnBridge_;
};


class Physics : public Subject {
public:
  void updateEntity(Entity& entitiy);
}

class Subject {
public:
  void addObserver(Observer* observer) {
    // Add to array..
  }
  
  void removeObserver(Observer* observer) {
    // Remove from array..
  }
  
  // Other stuff..
protected:
  void notify(const Entity& entitiy, Event event) {
    for (int i = 0; i < numObservers_; i++) {
      observers_[i]->onNotify(entitiy, event);
    }
  }
  
private:
  Observer* observers_[MAX_OBSERVERS];
  int numObservers_;
};
