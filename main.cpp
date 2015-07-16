#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(50);

    display(prout);
    cin >> prout;
    display(prout);

    return 0;
}
