#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(260004);

    cout << prout;
    prout /= 2;
    cout << prout;

    /*for(;;++i)
    {
        cout << prout;
        if(prout > 1000000000)
            prout /= 2;
        else
            prout *= 2;
    }*/

    return 0;
}
