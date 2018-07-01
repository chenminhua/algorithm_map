#include <iostream>

int partition_kth(int *arr, int st, int ed)
{
  int j = st;
  int i = j - 1;
  int pivot = arr[ed];
  int temp;
  while (j <= ed - 1)
  {
    if (pivot > arr[j])
    {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    j++;
  }

  i++;
  temp = arr[ed];
  arr[ed] = arr[i];
  arr[i] = temp;
  return i;
}

//Kth Order Statistic算法
int kth_order_statistic(int *arr, int st, int ed, int order)
{
  int attemp_order = partition_kth(arr, st, ed);
  int temp1 = attemp_order - st + 1;
  if (temp1 == order)
    return arr[attemp_order];
  else if (temp1 < order)
    kth_order_statistic(arr, attemp_order + 1, ed, order - temp1);
  //NOTE1:不是 kth_order_statistic(arr, attemp_order+1, ed, order);
  //NOTE2:Kth Order是一个和长度一致的变量，不是一个刻度变量。
  else
    kth_order_statistic(arr, st, attemp_order - 1, order);
}

int main()
{
  int unsorted_arr[10] = {10, 7, 9, 6, 8, 4, 11, 15, 1, 5};
  std::cout << kth_order_statistic(unsorted_arr, 0, 9, 1) << std::endl;
  std::cout << kth_order_statistic(unsorted_arr, 0, 9, 7) << std::endl;
  std::cout << kth_order_statistic(unsorted_arr, 0, 9, 9) << std::endl;
  return 0;
}