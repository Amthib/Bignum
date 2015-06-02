#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(256), p(255);

    if(prout <= p)
        cout << "vrai\n";
    else
        cout << "faux!\n";

    return 0;
}
