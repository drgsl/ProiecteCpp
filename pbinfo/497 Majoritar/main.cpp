#include <iostream>
#include <cmath>

using namespace std;

int n;
int v[100000];
int mini;

int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        cin>>v[i];
        if(v[i] < mini)
            mini = v[i];
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(v[i] > v[j])
                swap(v[i],v[j]);
        }
    }
    int frMax= 0;
    int x = 0;

    int prev = v[1];
    int fr = 0;

    for(int i = 2; i<=n; i++)
    {
        if(v[i]!=prev)
        {
            if(fr >= frMax)
            {
                frMax = fr;
                x = i;
            }
            fr = 0;
        }
        else
        {
            fr++;
        }
        prev = i;
    }


    for(int i = 1; i<=n; i++)
    {
        cout<<v[i]<<" ";
    }

    cout<< " " << x << " "<< frMax;

}
