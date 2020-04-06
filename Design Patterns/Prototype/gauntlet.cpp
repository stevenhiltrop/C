class Monster {
public:
  virtual ~Monster() {}
  virtual Monster* clone() = 0;
  
  // Other stuff...
};


class Ghost : public Monster () {
public:
  Ghost(int health, int speed):
  health_(health),
  speed_(speed)
  {}
  virtual Monster* clone() {
    return new Ghost(health_, speed_);
  }
private:
  int health_;
  int speed_;
};


class Demon : public Monster () {};
class Sorcerer : public Monster () {};


class Spawner {
public:
  Spawner(Monster* prototype) : prototype_(prototype) {}
  Monster* spawnMonster() {
    return prototype_->clone();
  }
private:
  Monster* prototype_;
};

int main() {
  Monster* ghostPrototype = new Ghost(15, 3);
  Spawner* ghostSpawner = new Spawner(ghostSpawner);
}
