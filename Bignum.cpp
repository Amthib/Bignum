/** Bignum.cpp
 * by Phacocherman
 * 02/13/2015 | 02/13/2015
 * Defines functions for Bignum class.
 */

#include "Bignum.h"

Bignum operator+(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    copie += b;
    return a;
}

Bignum operator+(const Bignum& a, const unsigned long long int& added)
{
    Bignum copie(a);
    copie += added;
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

std::ostream& operator<<( std::ostream &flux, Bignum const& nb )
{
    return nb.display(flux);
}

std::ostream& display(Bignum number)
{
    return number.display(std::cout);
}

Bignum::Bignum(unsigned long long int base, bool sign) : A_Size(0), A_Bignum({0})
{
    *this += base;
}

std::ostream& Bignum::display(std::ostream &flux) const
{
    flux << A_Size << '\n';

    for(int i = A_Size - 1; i >= 0; --i)
        flux <<  static_cast<unsigned short>(A_Bignum[i]);
    flux << '\n';

    return flux;
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
    unsigned int i;
    unsigned long long int copie(added);
    unsigned char retenue(0), value(0);

    for(i = 0; i < Max_Bignum && copie > 0; ++i)
    {
        value = A_Bignum[i] + copie % 10;
        A_Bignum[i] = (value % 10) + retenue;
        retenue = value / 10;
        copie /= 10;
    }
    if(A_Size < i + retenue)
        A_Size = i + retenue;
}









