#include <iostream>
#include <stack>
#define MAX_ROW 5
#define MAX_COL 5

struct point
{
  int row, col;
};

int maze[MAX_ROW][MAX_COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}};

std::stack<struct point> st;

bool is_exit(struct point p)
{
  return p.row == MAX_ROW - 1 && p.col == MAX_COL - 1;
}

struct point predecessor[MAX_ROW][MAX_COL] = {
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}}};

void visit(int row, int col, struct point pre)
{
  if (col >= MAX_COL || col < 0 || maze[row][col] != 0)
    return;
  if (row >= MAX_ROW || row < 0 || maze[row][col] != 0)
    return;
  struct point visit_point = {row, col};
  maze[row][col] = 2;
  predecessor[row][col] = pre;
  st.push(visit_point);
}

int main(void)
{
  struct point p = {0, 0};
  maze[0][0] = 2;
  st.push(p);

  while (!st.empty())
  {
    p = st.top();
    st.pop();
    if (is_exit(p))
      break;
    visit(p.row, p.col + 1, p);
    visit(p.row + 1, p.col, p);
    visit(p.row, p.col - 1, p);
    visit(p.row - 1, p.col, p);
  }

  if (is_exit(p))
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
