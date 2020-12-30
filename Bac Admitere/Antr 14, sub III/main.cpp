#include <iostream>

using namespace std;

void perechi(int n)
{
    int ok = 0;
    for(int d=1; d*d<=n; d++){
        if(n%d !=0)
            continue;
        if(d%2 == (n/d)%2)
            continue;
        else
        cout<<"["<<d<<" "<<n/d<<"]";
        ok=1;
    }
    if(ok==0)
        cout<<"nu exista";
}

int main()
{
    perechi(36);
    return 0;
}





void perechi2(int n)
{
    int ok = 0;
    for(int d=1; d*d<=n; d++)
    {
        if(n%d == 0 && d%2 != (n/d)%2)
        {
            cout<<"["<<d<<" "<<n/d<<"]";
            ok=1;
        }
    }
    if(ok==0)
        cout<<"nu exista";
}
