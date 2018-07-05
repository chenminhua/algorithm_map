#include "Maze.h"
#include <stack>

Maze::Maze(const std::vector<std::vector<int>> maze) : maze(maze)
{
  this->height = maze.size();
  this->width = maze[1].size();
}

int Maze::getHeight() const
{
  return this->height;
}

int Maze::getWeight() const
{
  return this->width;
}

void Maze::display() const
{
  for (int i = 0; i < this->height; i++)
  {
    for (int j = 0; j < this->width; j++)
    {
      printf("%d   ", this->maze[i][j]);
    }
    printf("\n");
  }
  printf("************\n");
}

void Maze::solveByBFS()
{
  std::queue<point> pointQueue;
  struct point direction[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  std::vector<std::vector<point>> predecessor;
  predecessor.clear();
  for (int i = 0; i < this->height; i++)
  {
    std::vector<struct point> r;
    for (int j = 0; j < this->width; j++)
    {
      r.push_back({-1, -1});
    }
    predecessor.push_back(r);
  }

  struct point currentPoint = {0, 0};
  pointQueue.push(currentPoint);
  this->maze[0][0] = 2;

  while (!pointQueue.empty())
  {
    currentPoint = pointQueue.front();
    pointQueue.pop();
    if (checkExit(currentPoint))
      break;
    point np, dir;
    for (int i = 0; i < 4; i++)
    {
      dir = direction[i];
      np = {currentPoint.row + dir.row,
            currentPoint.col + dir.col};
      if (checkVisitable(np))
      {
        maze[np.row][np.col] = 2;
        predecessor[np.row][np.col] = currentPoint;
        pointQueue.push(np);
        this->display();
      }
    }
  }
  if (checkExit(currentPoint))
  {
    printf("(%d, %d)\n", currentPoint.row, currentPoint.col);
    while (predecessor[currentPoint.row][currentPoint.col].row != -1)
    {
      currentPoint = predecessor[currentPoint.row][currentPoint.col];
      printf("(%d, %d)\n", currentPoint.row, currentPoint.col);
    }
  }
  else
    printf("no path\n");
}

void Maze::solveByDFS()
{
  std::stack<point> pointStack;
  struct point direction[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

  // 初始化predecessor
  std::vector<std::vector<point>> predecessor;
  predecessor.clear();
  for (int i = 0; i < this->height; i++)
  {
    std::vector<struct point> r;
    for (int j = 0; j < this->width; j++)
    {
      r.push_back({-1, -1});
    }
    predecessor.push_back(r);
  }
  struct point currentPoint = {0, 0};
  pointStack.push(currentPoint);
  this->maze[0][0] = 2;

  while (!pointStack.empty())
  {
    currentPoint = pointStack.top();
    pointStack.pop();
    if (checkExit(currentPoint))
      break;
    point np, dir;
    for (int i = 0; i < 4; i++)
    {
      dir = direction[i];
      np = {currentPoint.row + dir.row,
            currentPoint.col + dir.col};
      if (checkVisitable(np))
      {
        maze[np.row][np.col] = 2;
        predecessor[np.row][np.col] = currentPoint;
        pointStack.push(np);
        this->display();
      }
    }
  }

  if (checkExit(currentPoint))
  {
    printf("(%d, %d)\n", currentPoint.row, currentPoint.col);
    while (predecessor[currentPoint.row][currentPoint.col].row != -1)
    {
      currentPoint = predecessor[currentPoint.row][currentPoint.col];
      printf("(%d, %d)\n", currentPoint.row, currentPoint.col);
    }
  }
  else
    printf("no path\n");
}

bool Maze::checkExit(struct point p) const
{
  return p.col == this->width - 1 && p.row == this->height - 1;
}

bool Maze::checkVisitable(struct point p) const
{
  return (p.col < this->width && p.col >= 0 && p.row < this->height && p.row >= 0 && this->maze[p.row][p.col] == 0);
}