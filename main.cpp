#include "Bignum.h"

using namespace std;

int main()
{
    Bignum nb(713, true), k(1, true), p(4992, true), d;

    d = nb - p;
    cout << endl << d;

    return 0;
}
