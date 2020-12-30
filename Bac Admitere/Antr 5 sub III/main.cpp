#include <iostream>
#include <fstream>
using namespace std;

ifstream f("bac.in");

int main()
{
    int n;
    f>>n;
    int s = n;
    int smax = n;
    while(f>>n)
    {
        if(s+n >= n)
        {
            s += n;
        }
        else
        {
            s=n;
        }
        if(s > smax)
            smax = s;
    }
    cout << smax << endl;
    return 0;
}
