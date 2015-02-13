/** Bignum.cpp
 * by Phacocherman
 * 02/13/2015 | 02/13/2015
 * Defines functions for Bignum class.
 */

#include "Bignum.h"

Bignum operator+(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    a += b;
    return a;
}

Bignum operator-(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    a -= b;
    return a;
}

Bignum operator*(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    a *= b;
    return a;
}

Bignum operator/(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    a /= b;
    return a;
}

Bignum::Bignum(unsigned long long int base = 0, bool sign = false) : A_Size(0), A_Bignum({0}), A_Signed(sign)
{

}

Bignum operator+()
{

}

void Bignum::operator+=(const Bignum& added)
{
    unsigned int i = 0;
    unsigned char retenue;

}
