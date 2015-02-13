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
        Bignum(unsigned long long int);
        //~Bignum();

        void operator+=(const Bignum& added);

    private:
        unsigned char A_Bignum[Max_Bignum];
        unsigned int A_Size;
        bool A_Signed;
};

#endif
