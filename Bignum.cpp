/** Bignum.cpp
 * by Phacocherman
 * 02/13/2015 | 02/13/2015
 * Defines functions for Bignum class.
 */

#include <iostream>
#include "Bignum.h"

Bignum operator+(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    copie += b;
    return a;
}

/*Bignum operator-(const Bignum& a, const Bignum& b)
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
}*/

void display(Bignum number)
{
    number.display();
}

Bignum::Bignum(unsigned long long int base, bool sign) : A_Size(0), A_Bignum({0})
{
    *this += base;
}

void Bignum::display()
{
    for(int i = A_Size - 1; i >= 0; --i)
    {
        std::cout <<  static_cast<unsigned short>(A_Bignum[i]);
    }
}

void Bignum::operator+=(const Bignum& added)
{
    unsigned int i = 0;
    unsigned char retenue = 0;
    unsigned char value;

    do
    {
        value = A_Bignum[i] + added.A_Bignum[i];
        A_Bignum[i] = (value % 10) + retenue;
        retenue = value / 10;
        ++i;
    }while (i < Max_Bignum && (i < A_Size || i < added.A_Size));

    if (i < Max_Bignum - 1)
        A_Bignum[i+1] = retenue;
    A_Size = i + retenue;
}

void Bignum::operator+=(const unsigned long long int& added)
{
    unsigned int i(0);
    unsigned long long int copie(added);
    unsigned char retenue(0), value(0);

    while(i < Max_Bignum && copie > 0)
    {
        value = A_Bignum[i] + copie % 10;
        retenue = value % 10;
        A_Bignum[i] = (value % 10) + retenue;
        copie /= 10;
        ++i;
    }
    A_Size = i + retenue;
}









