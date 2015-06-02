/** Bignum.h
 * by Blackwolffire
 * 02/13/2015 | 06/02/2015
 * Declaration of Bignum class
 */

#ifndef BIGNUM_H
#define BIGNUM_H

#include <iostream>
#include <vector>

//#define Max_Bignum 1000000

class Bignum
{

    public:
        Bignum(unsigned long long int base = 0, bool sign = false);
        Bignum(const Bignum& nb);
        //~Bignum();

        void operator=(const unsigned long long int& nb);
        void operator=(const Bignum& nb);
        bool operator==(unsigned long long int nb) const;
        bool operator==(const Bignum& nb) const;
        bool operator<(const unsigned long long int& nb) const;
        bool operator<(const Bignum& nb) const;
        bool operator>(const unsigned long long int& nb) const;
        bool operator>(const Bignum& nb) const;
        bool operator<=(const unsigned long long int& nb) const;
        bool operator<=(const Bignum& nb) const;
        bool operator>=(const unsigned long long int& nb) const;
        bool operator>=(const Bignum& nb) const;
        void operator+=(const Bignum& added);
        void operator+=(unsigned long long int added);
        void operator-=(const Bignum& substracted);
        void operator-=(unsigned long long int substracted);

        std::ostream& display(std::ostream &flux)const;

    private:
        std::vector<unsigned char> A_Bignum;
        bool A_IsSigned;
};

Bignum operator+(Bignum a, const unsigned long long int& added);
Bignum operator+(Bignum a, const Bignum& b);
Bignum operator-(Bignum a, const unsigned long long int& added);
Bignum operator-(Bignum a, const Bignum& b);
Bignum operator*(Bignum a, const Bignum& b);
Bignum operator/(Bignum a, const Bignum& b);

std::ostream& operator<<( std::ostream &flux, Bignum const& nb );
void display(Bignum number);
unsigned long long int pow_int(const unsigned long long int& base, const unsigned int& exponent);

#endif
