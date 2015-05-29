/** Bignum.cpp
 * by Phacocherman
 * 02/13/2015 | 02/13/2015
 * Defines functions for Bignum class.
 */

#include "Bignum.h"

Bignum operator+(Bignum a, const Bignum& b)
{
    std::cout << "bite";
    return a;//a += b;
}

Bignum operator+(Bignum a, const unsigned long long int& added)
{
    return a +=added;
}
/*
Bignum operator-(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    a -= b;
    return copie;
}

Bignum operator*(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    a *= b;
    return copie;
}

Bignum operator/(const Bignum& a, const Bignum& b)
{
    Bignum copie(a);
    a /= b;
    return copie;
}
*/
std::ostream& operator<<( std::ostream &flux, Bignum const& nb )
{
    return nb.display(flux);
}

std::ostream& display(Bignum number)
{
    return number.display(std::cout);
}


/// BigNum functions

Bignum::Bignum(unsigned long long int base, bool sign) : A_Size(0), A_Bignum({0})
{
    *this += base;
}

Bignum::Bignum(const Bignum& nb) : A_Size(nb.A_Size)
{
    for(unsigned int i = 0; i < A_Size; ++i)
        A_Bignum[i] = nb.A_Bignum[i];
}

void Bignum::operator=(const unsigned long long int& added)
{
    unsigned int i(0);
    unsigned long long int copie(added);

    for(i = 0; i < Max_Bignum && copie > 0; ++i)
    {
        A_Bignum[i] = copie % 10;
        copie /= 10;
    }
    A_Size = i;
}

void Bignum::operator=(const Bignum& nb)
{
    A_Size = nb.A_Size;
    for(unsigned int i = 0; i < A_Size; ++i)
        A_Bignum[i] = nb.A_Bignum[i];
}

std::ostream& Bignum::display(std::ostream &flux) const
{
    flux << A_Size << '\n';

    for(int i = A_Size - 1; i >= 0; --i)
        flux <<  static_cast<uint16_t>(A_Bignum[i]);
    flux << '\n';

    return flux;
}

Bignum Bignum::operator+=(const Bignum& added)
{
    unsigned int i = 0;
    unsigned char retenue = 0;
    unsigned char value;

    for(i = 0; i < Max_Bignum && (A_Size > i || i < added.A_Size || retenue > 0); ++i)
    {
        value = A_Bignum[i] + added.A_Bignum[i] + retenue;
        A_Bignum[i] = value % 10;
        retenue = value / 10;
    }

    if (A_Size < i + retenue)
        A_Size = i + retenue;

    return *this;
}

Bignum Bignum::operator+=(const unsigned long long int& added)
{
    unsigned int i;
    unsigned long long int copie(added);
    unsigned char retenue(0), value(0);

    for(i = 0; i < Max_Bignum && (copie > 0 || retenue > 0); ++i)
    {
        value = A_Bignum[i] + copie % 10 + retenue;
        A_Bignum[i] = value % 10;
        retenue = value / 10;
        copie /= 10;
    }
    if(A_Size < i + retenue)
        A_Size = i + retenue;

    return *this;
}









