#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(198);
    Bignum prout(99), p(1000);

    cout << prout;

    prout = prout - i;

    cout << prout;

    return 0;
}
