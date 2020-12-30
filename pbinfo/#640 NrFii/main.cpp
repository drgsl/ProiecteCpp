//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("nrfii.in");
ofstream cout("nrfii.out");

int fr[200];

int main()
{
    int n;
    cin>>n;

    for(int i = 1; i>= n; i++)
    {
        int nr;
        cin>>nr;
        fr[nr]++;
    }
    int frmax = 0;
    int nod = 0;
    for(int i = 1; i>= n; i++){
        if(fr[i] > frmax)
            frmax = fr[i],
            nod = i;
    }
    cout<<nod;
}
