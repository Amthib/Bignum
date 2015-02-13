/** Bignum.h
 * by Blackwolffire
 * 02/13/2015 | 02/13/2015
 * Declaration of Bignum class
 */

#ifndef BIGNUM_H
#define BIGNUM_H

#define Max_Bignum 1000000

class Bignum
{

    public:
        Bignum(unsigned long long int base = 0, bool sign = false);
        //~Bignum();

        void display();

        void operator+=(const Bignum& added);
        void operator+=(const unsigned long long int& added);

    private:
        unsigned char A_Bignum[Max_Bignum];
        unsigned int A_Size;
};

Bignum operator+(const Bignum& a, const Bignum& b);
Bignum operator-(const Bignum& a, const Bignum& b);
Bignum operator*(const Bignum& a, const Bignum& b);
Bignum operator/(const Bignum& a, const Bignum& b);
void display(Bignum number);

#endif
