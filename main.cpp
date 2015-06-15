#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(99);
    Bignum prout(3), p(198);

    cout << prout++;
    cout << ++prout;

    return 0;
}
