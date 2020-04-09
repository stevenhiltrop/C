class FileSystem {
public:
  static FileSystem& instance() {
    // Lazy initialize.
    static FileSystem *instance = new FileSystem();
    return *instance;
  }
private:
  FileSystem() {}
}
