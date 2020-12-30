#include <iostream>
using namespace std;

int v[100005];
int DifMax = -1000000001, n;

int s[100005], d[100005];
int smax = -1000000001, dmin = 1000000001;
int main()
{
    cin>> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }

    for(int i = 0 ; i< n; i++)
    {
        if(v[i] > smax)
        {
            smax = v[i];
        }
        s[i] = smax;
    }

    for(int i = n-1; i>= 0; i--)
    {
        if(v[i] < dmin)
        {
            dmin = v[i];
        }
        d[i] = dmin;
    }

    for(int i = 0 ; i<n - 1  ; i++)
    {
        if(s[i] - d[i+1] > DifMax)
        {
            DifMax = s[i] - d[i+1];

        }
    }
/*
    for(int i = 0; i<n ; i++)
    {
        cout <<s[i];
    }
    cout << endl;
    for(int i = 0; i<n ; i++)
    {
        cout <<d[i];
    }
    */
    cout<< DifMax;
    return 0;
}
