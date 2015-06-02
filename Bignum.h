/** Bignum.h
 * by Blackwolffire
 * 02/13/2015 | 02/13/2015
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

        std::ostream& display(std::ostream &flux)const;

        void operator=(const unsigned long long int& added);
        void operator=(const Bignum& b);
        void operator+=(const Bignum& added);
        void operator+=(unsigned long long int added);

    private:
        std::vector<unsigned char> A_Bignum;
};

Bignum operator+(Bignum a, const unsigned long long int& added);
Bignum operator+(Bignum a, const Bignum& b);
Bignum operator-(Bignum a, const unsigned long long int& added);
Bignum operator-(Bignum a, const Bignum& b);
Bignum operator*(Bignum a, const Bignum& b);
Bignum operator/(Bignum a, const Bignum& b);
std::ostream& operator<<( std::ostream &flux, Bignum const& nb );
void display(Bignum number);

#endif
