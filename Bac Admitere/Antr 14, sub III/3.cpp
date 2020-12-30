#include <iostream>
#include <fstream>
using namespace std;

ifstream f("bac.in");
int best[3];

int main()
{
    for(int i =0; i<3; i++)
        best[i] = 1000000001; // 10^9 +1
        int n;
    while(f>>n)
    {
        //cout<<n<<endl;
        if(n%10 == 0 && (n/10)%10 == 2)
        {
            if(n<best[0])
            {
                best[2] = best[1];
                best[1] = best[0];
                best[0] = n;
            }
            else if(n < best[1])
            {
                best[2] = best[1];
                best[1] = n;
            }
            else if(n<best[2])
            {
                best[2] = n;
            }
            //cout<<best[0]<<" "<<best[1]<<" "<<best[2]<<endl;
        }
    }
    cout<<best[0]<<" "<<best[1]<<" "<<best[2];
}
