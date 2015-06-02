/** Bignum.cpp
 * by Phacocherman
 * 02/13/2015 | 06/02/2015
 * Defines functions for Bignum class.
 */

#include "Bignum.h"

Bignum operator+(Bignum a, const Bignum& b)
{
    a += b;
    return a;
}

Bignum operator+(Bignum a, const unsigned long long int& added)
{
    a += added;
    return a;
}

Bignum operator-(Bignum a, const unsigned long long int& added)
{
    a += added;
    return a;
}

Bignum operator-(Bignum a, const Bignum& b)
{
    a += b;
    return a;
}

/*
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

void display(Bignum number)
{
    number.display(std::cout);
}

unsigned long long int pow_int(const unsigned long long int& base, const unsigned int& exponent)
{
    unsigned long long int result = 1;

    for(unsigned int i = 0; i < exponent; ++i)
        result *= base;

    return result;
}

/// BigNum functions

Bignum::Bignum(unsigned long long int base, bool sign) : A_Bignum(0), A_IsSigned(sign)
{
    *this += base;
}

Bignum::Bignum(const Bignum& nb) : A_IsSigned(nb.A_IsSigned)
{
    A_Bignum.resize(nb.A_Bignum.size());
    for(unsigned int i = 0; i < nb.A_Bignum.size(); ++i)
        A_Bignum[i] = nb.A_Bignum[i];
}

std::ostream& Bignum::display(std::ostream &flux) const
{
    flux << A_Bignum.size() << '\n';

    for(int i = A_Bignum.size() - 1; i >= 0; --i)
        flux <<  static_cast<uint16_t>(A_Bignum[i]);
    flux << '\n';

    return flux;
}

void Bignum::operator=(const unsigned long long int& nb)
{
    A_Bignum.resize(0, 0);
    *this += nb;
}

void Bignum::operator=(const Bignum& nb)
{
    A_Bignum.resize(nb.A_Bignum.size());
    for(unsigned int i = 0; i < nb.A_Bignum.size(); ++i)
        A_Bignum[i] = nb.A_Bignum[i];
}

bool Bignum::operator==(unsigned long long int nb) const
{
    unsigned int i;

    for(i = 0; nb > 0; ++i, nb /= 10)
        if(i >= A_Bignum.size() || A_Bignum[i] != nb % 10)
            return false;

    if(i != A_Bignum.size())
        return false;
    else
        return true;
}

bool Bignum::operator==(const Bignum& nb) const
{
    if(nb.A_Bignum.size() != A_Bignum.size() || nb.A_IsSigned != A_IsSigned)
        return false;
    for(unsigned long long int i = 0; i < A_Bignum.size(); ++i)
        if(A_Bignum[i] != nb.A_Bignum[i])
            return false;
    return true;
}

bool Bignum::operator<(const unsigned long long int& nb) const
{
    if(A_Bignum.size() > 20 || A_Bignum.size() == 20 && A_Bignum.back() > 1)
        return false;

    if(nb / pow_int(10, A_Bignum.size() - 1) > 9)
        return true;
    else if(nb / pow_int(10, A_Bignum.size() - 1) == 0)
        return false;

    for(unsigned long long int i = 1; i <= A_Bignum.size(); ++i)
        if(A_Bignum[A_Bignum.size() - i] < (nb / pow_int(10, A_Bignum.size() - i)) % 10)
            return true;
        else if(A_Bignum[A_Bignum.size() - i] > (nb / pow_int(10, A_Bignum.size() - i)) % 10)
            return false;

    return false;
}

bool Bignum::operator<(const Bignum& nb) const
{
    if(A_Bignum.size() < nb.A_Bignum.size())
        return true;
    else if(A_Bignum.size() > nb.A_Bignum.size())
        return false;

    for(unsigned long long int i = 1; i <= A_Bignum.size(); ++i)
        if(A_Bignum[A_Bignum.size() - i] < nb.A_Bignum[A_Bignum.size() - i])
            return true;
        else if(A_Bignum[A_Bignum.size() - i] > nb.A_Bignum[A_Bignum.size() - i])
            return false;
    return false;
}

bool Bignum::operator>(const unsigned long long int& nb) const
{
    return !(*this < nb || *this == nb);
}

bool Bignum::operator>(const Bignum& nb) const
{
    return !(*this < nb || *this == nb);
}

bool Bignum::operator<=(const unsigned long long int& nb) const
{
    return *this < nb || *this == nb;
}

bool Bignum::operator<=(const Bignum& nb) const
{
    return *this < nb || *this == nb;
}

bool Bignum::operator>=(const unsigned long long int& nb) const
{
    return !(*this < nb);
}

bool Bignum::operator>=(const Bignum& nb) const
{
    return !(*this < nb);
}

void Bignum::operator+=(unsigned long long int added)
{
    unsigned int i;
    unsigned char retenue(0), value(0);

    for(i = 0; added > 0 || retenue > 0; ++i)
    {
        if(i >= A_Bignum.size())
        {
            value = added % 10 + retenue;
            A_Bignum.push_back(value % 10);
        }
        else
        {
            value = A_Bignum[i] + added % 10 + retenue;
            A_Bignum[i] = value % 10;
        }
        retenue = value / 10;
        added /= 10;
    }
}

void Bignum::operator+=(const Bignum& added)
{
    unsigned int i = 0;
    unsigned char retenue = 0;
    unsigned char value;

    for(i = 0; i < added.A_Bignum.size(); ++i)
    {
        if(i >= A_Bignum.size())
        {
            value = added.A_Bignum[i] + retenue;
            A_Bignum.push_back(value % 10);
        }
        else
        {
            value = A_Bignum[i] + added.A_Bignum[i] + retenue;
            A_Bignum[i] = value % 10;
        }
        retenue = value / 10;
    }
    for(; retenue > 0; ++i)
    {
        if(i >= A_Bignum.size())
        {
            value = retenue;
            A_Bignum.push_back(value % 10);
        }
        else
        {
            value = A_Bignum[i] + retenue;
            A_Bignum[i] = value % 10;
        }
        retenue = value / 10;
    }
}

void Bignum::operator-=(unsigned long long int added)
{
    unsigned int i;
    unsigned char retenue(0), value(0);

    for(i = 0; added > 0 || retenue > 0; ++i)
    {
        if(i >= A_Bignum.size())
        {
            value = added % 10 + retenue;
            A_Bignum.push_back(value % 10);
        }
        else
        {
            value = A_Bignum[i] + added % 10 + retenue;
            A_Bignum[i] = value % 10;
        }
        retenue = value / 10;
        added /= 10;
    }
}

void Bignum::operator-=(const Bignum& added)
{
    unsigned int i = 0;
    unsigned char retenue = 0;
    unsigned char value;

    for(i = 0; i < added.A_Bignum.size(); ++i)
    {
        if(i >= A_Bignum.size())
        {
            value = added.A_Bignum[i] + retenue;
            A_Bignum.push_back(value % 10);
        }
        else
        {
            value = A_Bignum[i] + added.A_Bignum[i] + retenue;
            A_Bignum[i] = value % 10;
        }
        retenue = value / 10;
    }
    for(; retenue > 0; ++i)
    {
        if(i >= A_Bignum.size())
        {
            value = retenue;
            A_Bignum.push_back(value % 10);
        }
        else
        {
            value = A_Bignum[i] + retenue;
            A_Bignum[i] = value % 10;
        }
        retenue = value / 10;
    }
}









