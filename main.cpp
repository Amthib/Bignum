#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(50);

    cout <<prout;
    cin >> prout;
    cout << prout;

    return 0;
}
