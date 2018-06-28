#include "BigInteger.h"

BigInteger::BigInteger() {}

BigInteger::BigInteger(const std::string &s) : num(s) {}

const std::string &BigInteger::value() const
{
  return num;
}

BigInteger operator+(const BigInteger &x, const BigInteger &y)
{
  // 反转字符串
  std::string a(x.value().rbegin(), x.value().rend());
  std::string b(y.value().rbegin(), y.value().rend());
  std::string res = "";
  int i = 0, add_digit = 0;
  while (i < a.size() || i < b.size())
  {
    int sum = 0;
    if (i >= a.size())
      sum = b[i] - '0' + add_digit;
    else if (i >= b.size())
      sum = a[i] - '0' + add_digit;
    else
      sum = a[i] - '0' + b[i] - '0' + add_digit;
    res += std::string(1, sum % 10 + '0');
    // add_digit表示进位
    add_digit = sum / 10;
    ++i;
  }
  if (add_digit)
    res += std::string(1, '0' + add_digit);
  return BigInteger(std::string(res.rbegin(), res.rend()));
}
