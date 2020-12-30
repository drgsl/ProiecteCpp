#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    bool ok = false;
    ifstream fin ("bac.txt");
    int x, v[100] = {0};
    while(fin>>x)
    {
        int temp = x;
        while(temp>10)
        {
            v[temp%100]++;
            temp=temp/10;
        }
    }

    for(int i = 10; i<=99; i++)
        if(v[i] == 1) cout<<i<<" ", ok = true;

    if(ok == false)
        cout<<"nu exista";
    return 0;
}
