#include <vector>
#include <queue>
struct point
{
  int row, col;
};

class Maze
{
private:
  std::vector<std::vector<int>> maze;
  int width;
  int height;

public:
  Maze(std::vector<std::vector<int>> maze);
  int getHeight() const;
  int getWeight() const;
  void display() const;
  void solveByDFS();
  void solveByBFS();
  bool checkExit(struct point) const;
  bool checkVisitable(struct point) const;
};
