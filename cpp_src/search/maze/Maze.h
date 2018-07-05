#include <vector>
struct point
{
  int row, col;
};

class Maze
{
private:
  std::vector<std::vector<int>> maze;
  std::vector<std::vector<point>> predecessor;
  int width;
  int height;

public:
  Maze(std::vector<std::vector<int>> maze);
  int getHeight() const;
  int getWeight() const;
  void display() const;
  void solve();
  bool checkExit(struct point) const;
  bool checkVisitable(struct point) const;
};
