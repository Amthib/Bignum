#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int bite(11);
    Bignum prout(16);

    cout << prout;
    prout += bite;
    cout << prout;

    return 0;
}
