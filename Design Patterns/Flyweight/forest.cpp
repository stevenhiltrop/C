Class Tree {
private:
  TreeModel* model_;
  Vector position_;
  double height, weight;
  Color barkTint_, leafTint_;
}

Class TreeModel{
private:
  Mesh mesh_;
  Texture bark_, leaves_;
}
