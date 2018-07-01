#include <stdlib.h>
#include <iostream>
int *generateArr(int size)
{
  int i;
  int *arr = new int[size];
  for (i = 0; i < size; i++)
  {
    arr[i] = rand();
  }
  return arr;
};

int find_smallest(int *arr, int length)
{
  int i, smallest;
  smallest = arr[0];
  for (i = 1; i < length - 1; i++)
  {
    if (arr[i] < smallest)
    {
      smallest = arr[i];
    }
  }
  return smallest;
}

int main()
{
  int *arr = generateArr(1000);
  int n = find_smallest(arr, 1000);
  std::cout << n << std::endl;
  return 0;
}