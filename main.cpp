#include "Bignum.h"

using namespace std;

int main()
{
    Bignum prout(59), pipi(41);

    cout << prout;
    prout.operator=(operator+(prout, pipi));
    cout << prout;

    return 0;
}
