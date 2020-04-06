class Subject {
  Subject(): head_(NULL) {}
  
private:
  Observer* head_;
};


class Observer {
  friend class Subject;
  
public:
  Observer() : next_(NULL) {}
  
private:
  Observer* next_;
};

void Subject::addObserver(Observer* observer) {
  observer->next_ = head_;
  head_ = observer;
}

void Subject::removeObserver(Observer* observer) {
  if (head_ == observer) {
    head_ = observer->next_;
    observer->next_ = NULL;
    return;
  }
  
  Observer* current = head_;
  while (current != NULL) {
    if (current->next_ = observer) {
      current->next_ = observer->next_;
      observer->next_ = NULL;
      return;
    }
    
    current = current->next_;
  }
}

void Subject::notify(const Entity& entitiy, Event event) {
  Observer* observer = head_;
  while (observer != NULL) {
    observer->onNotify(entitiy, event);
    observer = observer->next_;
  }
}
