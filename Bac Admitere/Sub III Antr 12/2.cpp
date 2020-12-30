#include <iostream>

using namespace std;

int pDoi(int n)
{

    int p = 1;

    while(p<n/2)
    {
        p*=2;
    }

    return p;

}

int main()
{

    cout << pDoi(20);
    return 0;
}


