class Game {
public:
  static Game& instance() { return instance_; }
  
  // Functions to set log_, et. al. ...
  
  Log& getLog() { return *log_; }
  FileSystem& getFileSystem() { return *fileSystem_; }
  AudioPlayer& getAudioPlayer() { return *audioPlayer_; }
  
private:
  static Game instance_;
  
  Log * log_;
  FileSystem * fileSystem_;
  AudioPlayer *audioPlayer_;
};


class GameObject {
protected:
  Log& getLog() { return log_; }
private:
  static Log& log_;
};


class Enemy : public GameObject {
  void doSomething() {
    getLog().write("I can log!");
  }
};
