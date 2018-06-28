#ifndef __BIGINTEGER_H__
#define __BIGINTEGER_H__

#include <string>

class BigInteger
{
public:
  BigInteger();
  BigInteger(const std::string &s);
  const std::string &value() const;

  friend BigInteger operator+(const BigInteger &x, const BigInteger &y);

private:
  std::string num;
};
#endif