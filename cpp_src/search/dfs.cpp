#include <iostream>
#define MAX_ROW 5
#define MAX_COL 5
struct point
{
  int row, col;
} stack[512];
int top = 0;
void push(struct point p)
{
  stack[top] = p;
  top++;
}
struct point pop(void)
{
  top--;
  return stack[top];
}
int is_empty(void)
{
  return top == 0;
}
int maze[MAX_ROW][MAX_COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}};

void print_maze(void)
{
  int i, j;
  for (i = 0; i < MAX_ROW; i++)
  {
    for (j = 0; j < MAX_COL; j++)
    {
      std::cout << maze[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "****************" << std::endl;
}

struct point predecessor[MAX_ROW][MAX_COL] = {
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}}};

void visit(int row, int col, struct point pre)
{
  struct point visit_point = {row, col};
  maze[row][col] = 2;
  predecessor[row][col] = pre;
  push(visit_point);
}

// 将起点标记为已走过并压栈;
// while (栈非空) {
// 从栈顶弹出一个点p; if (p这个点是终点)
// break;
// 否则沿右、下、左、上四个方向探索相邻的点，if (和p相邻的点有路可走，并
// 且还没走过) 将相邻的点标记为已走过并压栈，它的前趋就是p 点;
// }if (p点是终点) {
// 打印p 点的座标;
// while (p点有前趋) { p点=p点的前趋;
// } else } 打印p点的座标; 没有路线可以到达终点;
int main(void)
{
  struct point p = {0, 0};
  maze[p.row][p.col] = 2;
  push(p);

  while (!is_empty())
  {
    p = pop();
    if (p.row == MAX_ROW - 1 /* goal */ && p.col == MAX_COL - 1)
      break;
    if (p.col + 1 < MAX_COL /* right */
        && maze[p.row][p.col + 1] == 0)
      visit(p.row, p.col + 1, p);
    if (p.row + 1 < MAX_ROW /* down */ && maze[p.row + 1][p.col] == 0)
      visit(p.row + 1, p.col, p);
    if (p.col - 1 >= 0 /* left */ && maze[p.row][p.col - 1] == 0)
      visit(p.row, p.col - 1, p);
    if (p.row - 1 >= 0 /* up */ && maze[p.row - 1][p.col] == 0)
      visit(p.row - 1, p.col, p);
    print_maze();
  }

  if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
  {
    printf("(%d, %d)\n", p.row, p.col);
    while (predecessor[p.row][p.col].row != -1)
    {
      p = predecessor[p.row][p.col];
      printf("(%d, %d)\n", p.row, p.col);
    }
  }
  else
    printf("no path\n");

  return 0;
}
