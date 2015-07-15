/** Bignum.cpp
 * by Phacocherman
 * 02/13/2015 | 07/15/2015
 * Defines functions for Bignum class.
 */

#include "Bignum.h"

Bignum operator+(Bignum a, const Bignum& b)
{
    a += b;
    return a;
}

Bignum operator+(Bignum a, const unsigned long long int& b)
{
    a += b;
    return a;
}

Bignum operator-(Bignum a, const unsigned long long int& b)
{
    a -= b;
    return a;
}

Bignum operator-(Bignum a, const Bignum& b)
{
    a -= b;
    return a;
}

Bignum operator*(Bignum a, const unsigned long long int& b)
{
    a *= b;
    return a;
}

Bignum operator*(Bignum a, const Bignum& b)
{
    a *= b;
    return a;
}

Bignum operator/(Bignum a, const unsigned long long int& b)
{
    a /= b;
    return a;
}

Bignum operator/(Bignum a, const Bignum& b)
{
    a /= b;
    return a;
}

Bignum operator%(Bignum a, const unsigned long long int& b)
{
    a %= b;
    return a;
}

Bignum operator%(Bignum a, const Bignum& b)
{
    a %= b;
    return a;
}

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

Bignum::Bignum(unsigned long long int base, bool sign) : A_Bignum(0)
{
    A_IsSigned = false;
    *this += base;
    A_IsSigned = sign;
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

    if(A_IsSigned)
        flux << '-';

    if(A_Bignum.size() > 0)
        for(long long int i = A_Bignum.size() - 1; i >= 0; --i)
            flux <<  static_cast<uint16_t>(A_Bignum[i]);
    else
        flux << 0;
    flux << '\n';

    return flux;
}

void Bignum::operator=(const unsigned long long int& nb)
{
    A_Bignum.resize(0, 0);
    A_IsSigned = false;
    *this += nb;
}

void Bignum::operator=(const Bignum& nb)
{
    A_IsSigned = nb.A_IsSigned;
    A_Bignum.resize(nb.A_Bignum.size());
    for(unsigned int i = 0; i < nb.A_Bignum.size(); ++i)
        A_Bignum[i] = nb.A_Bignum[i];
}

bool Bignum::operator==(unsigned long long int nb) const
{
    unsigned char i;

    if(A_IsSigned)
        return false;

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

bool Bignum::operator!=(unsigned long long int nb) const
{
    return !(*this == nb);
}

bool Bignum::operator!=(const Bignum& nb) const
{
    return !(*this == nb);
}

bool Bignum::operator<(const unsigned long long int& nb) const
{
    if(A_IsSigned)
        return true;

    if(A_Bignum.size() > 20 || (A_Bignum.size() == 20 && A_Bignum.back() > 1))
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
    bool result;

    if(A_IsSigned != nb.A_IsSigned)
        return A_IsSigned;

    result = !A_IsSigned;

    if(A_Bignum.size() < nb.A_Bignum.size())
        return result;
    else if(A_Bignum.size() > nb.A_Bignum.size())
        return !result;

    for(unsigned long long int i = 1; i <= A_Bignum.size(); ++i)
        if(A_Bignum[A_Bignum.size() - i] < nb.A_Bignum[A_Bignum.size() - i])
            return result;
        else if(A_Bignum[A_Bignum.size() - i] > nb.A_Bignum[A_Bignum.size() - i])
            return !result;
    return !result;
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

void Bignum::operator+=(unsigned long long int nb)
{
    unsigned int i;
    unsigned char retenue(0), value(0);

    if(A_IsSigned)
    {
        A_IsSigned = false;
        *this -= nb;
        A_IsSigned = !A_IsSigned;
    }
    else
    {
        for(i = 0; nb > 0 || retenue > 0; ++i)
        {
            if(i >= A_Bignum.size())
            {
                value = nb % 10 + retenue;
                A_Bignum.push_back(value % 10);
            }
            else
            {
                value = A_Bignum[i] + nb % 10 + retenue;
                A_Bignum[i] = value % 10;
            }
            retenue = value / 10;
            nb /= 10;
        }
    }
    while(A_Bignum.size() > 0 && A_Bignum.back() == 0)
        A_Bignum.pop_back();
    if(A_Bignum.size() <= 0)
        A_IsSigned = false;
}

void Bignum::operator+=(const Bignum& nb)
{
    unsigned long long int i = 0;
    unsigned char retenue = 0;
    unsigned char value;

    if(A_IsSigned != nb.A_IsSigned)
    {
        A_IsSigned = !A_IsSigned;
        *this -= nb;
        A_IsSigned = !A_IsSigned;
    }
    else
    {
        for(i = 0; i < nb.A_Bignum.size(); ++i)
        {
            if(i >= A_Bignum.size())
            {
                value = nb.A_Bignum[i] + retenue;
                A_Bignum.push_back(value % 10);
            }
            else
            {
                value = A_Bignum[i] + nb.A_Bignum[i] + retenue;
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
    while(A_Bignum.size() > 0 && A_Bignum.back() == 0)
        A_Bignum.pop_back();
    if(A_Bignum.size() <= 0)
        A_IsSigned = false;
}

void Bignum::operator-=(unsigned long long int nb)
{
    unsigned long long int masking(1);
    Bignum cp;

    if(A_IsSigned)
    {
        A_IsSigned = false;
        *this += nb;
        A_IsSigned = true;
    }
    else
    {
        if(*this < nb)
        {
            cp = nb;
            cp -= *this;
            *this = cp;
            A_IsSigned = true;
        }
        else
        {
            for(unsigned long long int i(0); i < A_Bignum.size(); ++i, masking *= 10)
            {
                if((nb / masking) % 10 > A_Bignum[i])
                {
                    A_Bignum[i] += 10;
                    nb += masking * 10;
                }
                A_Bignum[i] -= (nb / masking) % 10;
            }
        }
    }
    while(A_Bignum.size() > 0 && A_Bignum.back() == 0)
        A_Bignum.pop_back();
    if(A_Bignum.size() <= 0)
        A_IsSigned = false;
}

void Bignum::operator-=(const Bignum& nb)
{
    Bignum cp;

    if(A_IsSigned != nb.A_IsSigned)
    {
        A_IsSigned = !A_IsSigned;
        *this += nb;
        A_IsSigned = !A_IsSigned;
    }
    else
    {
        if(*this < nb)
        {
            cp = *this;
            *this = nb;
            A_IsSigned = !A_IsSigned;
        }
        else
            cp = nb;

        for(unsigned long long int i(0); i < cp.A_Bignum.size(); ++i)
        {
            if(A_Bignum[i] < cp.A_Bignum[i])
            {
                A_Bignum[i] += 10;
                if(i == cp.A_Bignum.size() - 1)
                    cp.A_Bignum.push_back(1);
                else
                    ++cp.A_Bignum[i + 1];
            }
            A_Bignum[i] -= cp.A_Bignum[i];
        }
    }
    while(A_Bignum.size() > 0 && A_Bignum.back() == 0)
        A_Bignum.pop_back();
    if(A_Bignum.size() <= 0)
        A_IsSigned = false;
}

void Bignum::operator*=(const unsigned long long int& nb)
{
    Bignum cp_nb(nb);
    *this *= cp_nb;
}

void Bignum::operator*=(const Bignum nb)
{
    unsigned char value, retenue;
    Bignum cp(*this), *tab;
    *this = 0;

    /*
    c'est de la merde ça pour multiplier
    for(Bignum i(0); i < nb; ++i)
        *this += cp;
    */

    tab = new Bignum[nb.A_Bignum.size()];

    for(unsigned long long int  i(0); i < nb.A_Bignum.size(); ++i){
        retenue = 0;
        for(unsigned long long int j(0); j < i; ++j)
            tab[i].A_Bignum.push_back(0);
        for(unsigned long long int j(0); j < cp.A_Bignum.size(); ++j){

            value = nb.A_Bignum[i] * cp.A_Bignum[j] + retenue;
            tab[i].A_Bignum.push_back(value % 10);
            retenue = value / 10;
            //std::cout << "value " << static_cast<unsigned short int>(value) << std::endl;
        }
        if(retenue)
            tab[i].A_Bignum.push_back(retenue);
    }

    for(unsigned long long int  i(0); i < nb.A_Bignum.size(); ++i)
        *this += tab[i];

    A_IsSigned = A_Bignum.size() && ((cp.A_IsSigned || nb.A_IsSigned) && !(cp.A_IsSigned && nb.A_IsSigned));
}

void Bignum::operator/=(const unsigned long long int& nb)
{
    Bignum cp(nb), i(0);
    bool cpIsSigned = A_IsSigned;

    A_IsSigned = false;

    for(; cp <= *this; ++i)
        cp += nb;

    *this = i;
    A_IsSigned = cpIsSigned;
    if(A_Bignum.size() <= 0)
        A_IsSigned = false;
}

void Bignum::operator/=(Bignum nb)
{
    Bignum cp(nb), i(0);
    bool cpIsSigned = A_IsSigned;
    bool cpNBIsSigned = nb.A_IsSigned;

    nb.A_IsSigned = false;
    cp.A_IsSigned = false;

    A_IsSigned = false;

    for(; cp <= *this; ++i)
        cp += nb;
    *this = i;

    A_IsSigned = (cpIsSigned ^ cpNBIsSigned) && A_Bignum.size() > 0;
}

void Bignum::operator%=(const unsigned long long int& nb)
{

}

void Bignum::operator%=(const Bignum& nb)
{

}

Bignum& Bignum::operator++()
{
    *this += 1;
    return *this;
}

Bignum Bignum::operator++(int)
{
    Bignum cp(*this);
    ++(*this);
    return cp;
}

Bignum& Bignum::operator--()
{
    *this -= 1;
    return *this;
}

Bignum Bignum::operator--(int)
{
    Bignum cp(*this);
    --(*this);
    return cp;
}











