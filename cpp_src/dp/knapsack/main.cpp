#include <vector>
#include <algorithm>
struct Item
{
  int label;
  int value;
  int weight;
};

int getCell(int, int, std::vector<std::vector<int>> &);
std::vector<Item> items{
    {1, 1, 3},
    {2, 8, 1},
    {3, 8, 4},
    {4, 2, 1},
    {5, 2, 5},
    {6, 5, 9},
    {7, 3, 2},
    {8, 7, 6},
    {9, 5, 5}};
int main()
{
  int capacity = 12;

  std::vector<std::vector<int>> table;

  for (int i = 0; i <= capacity; i++)
  {
    std::vector<int> r;
    for (int j = 0; j < items.size(); j++)
    {
      r.push_back(-1);
    }
    table.push_back(r);
  }
  getCell(12, items.size() - 1, table);

  int remainingCapacity = capacity;

  printf("pick up: ");
  for (int i = items.size() - 1; i >= 0; i--)
  {
    Item item = items[i];
    int withoutVal = (i == 0 ? 0 : table[remainingCapacity][i - 1]);
    if (withoutVal != table[remainingCapacity][i])
    {
      printf("%d\t", item.label);
      remainingCapacity -= item.weight;
    }
  }
  printf("\n");
  return 0;
}

// i为行号，表示重量；j为列号，表示物品
int getCell(int i, int j, std::vector<std::vector<int>> &table)
{
  int withVal;
  int withoutVal;
  if (i < 0 || j < 0)
    return 0;
  Item item = items[j];
  if (table[i][j] == -1)
  {
    if (item.weight > i)
    {
      withVal = -1;
    }
    else
    {
      withVal = getCell(i - item.weight, j - 1, table) + item.value;
    }

    withoutVal = getCell(i, j - 1, table);
    table[i][j] = std::max(withVal, withoutVal);
  }

  return table[i][j];
}
