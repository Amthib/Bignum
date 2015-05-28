/** Bignum.h
 * by Blackwolffire
 * 02/13/2015 | 02/13/2015
 * Declaration of Bignum class
 */

#ifndef BIGNUM_H
#define BIGNUM_H

#include <iostream>

#define Max_Bignum 1000000

class Bignum
{

    public:
        Bignum(unsigned long long int base = 0, bool sign = false);
        //~Bignum();

        std::ostream& display(std::ostream &flux)const;

        void operator+=(const Bignum& added);
        void operator+=(const unsigned long long int& added);

    private:
        unsigned char A_Bignum[Max_Bignum];
        unsigned int A_Size;
};

Bignum operator+(const Bignum& a, const unsigned long long int& added);
Bignum operator+(const Bignum& a, const Bignum& b);
Bignum operator-(const Bignum& a, const Bignum& b);
Bignum operator*(const Bignum& a, const Bignum& b);
Bignum operator/(const Bignum& a, const Bignum& b);
std::ostream& operator<<( std::ostream &flux, Bignum const& nb );
std::ostream& display(Bignum number);

#endif
