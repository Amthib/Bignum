#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(1);//, p(1);

    for(;; ++i)
    {
        if(i % 10000 == 0)
            cout << prout;
        prout += prout;
    }

    return 0;
}
