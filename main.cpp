#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(2), p(2);

    for(;;++i)
    {
        if(i % 1 == 0)
            cout << prout;
        prout *= 512;
        p *= prout;
    }

    return 0;
}
