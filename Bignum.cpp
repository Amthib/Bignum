/** Bignum.cpp
 * by Phacocherman
 * 02/13/2015 | 02/13/2015
 * Defines functions for Bignum class.
 */

#include "Bignum.h"


Bignum::Bignum(unsigned long long int base = 0, bool sign = false) : A_Size(0), A_Bignum({0}), A_Signed(sign)
{

}

Bignum operator+()
{

}

bool Bignum::operator+=(const Bignum& added)
{
    unsigned int i = 0;
    unsigned char retenue = 0;
    unsigned char value;

    while (i < A_Signed)
    {
        value = A_Bignum[i] + added[i];
        A_Bignum[i] = (value % 10) + retenue;
        retenue = value / 10;
    }

    if (i < Max_Bignum - 1)
        A_Bignum[i+1] = retenue;
    else if (retenue > 0)
        return false; /// le Bignum a depasse Max Bignum

    return true;
}
