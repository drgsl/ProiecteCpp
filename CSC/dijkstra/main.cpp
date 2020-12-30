#include <iostream>

using namespace std;

#define INFINIT 1000000000

//nodul sursa este s

int f[100], s[100], i, n, d[100], a[100][100];

int main()
{
    for(i =1 ; i <= n ; i ++ )
    {
        f[i] = 0;
        d[i] = a[s][i];
    }

    f[s] = 1, d[s] = 0;
    d[0] = INFINIT; // pentru determinarea nodului cu costul minim
    for(int k = 1 ; k < n ; ++k)
    {
        int pmax = 0;
        for(i = 1 ; i <= n ; ++i)
            if(f[i] == 0 && d[i] < d[pmax])
                pmax = i;

        if(pmax > -1)
        {
            f[pmax] = 1;
            for(i = 1; i <= n ; ++i)
                if(f[i] == 0 && d[i] > d[pmax] + a[pmax][i])
                    d[i] = d[pmax] + a[pmax][i];
        }
    }
}
