#include <iostream>
#include "BigInteger.h"
int main()
{
  BigInteger a("123");
  BigInteger b("456");
  BigInteger c = a + b;
  std::cout << c.value() << std::endl;
}
