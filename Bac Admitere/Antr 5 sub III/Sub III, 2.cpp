#include <iostream>
#include <cstring>
using namespace std;
char *p;
char S[101];
int main()
{
    cin.getline(S, 101);

    p = strtok(S, " ");
    int c = 0;
    while(p)
    {
        bool ok = true;
        if(p[0] >= '0' && p[0] <='9')
        {
            for(int i = 0; i<=strlen(p); i++)
            {
                if(p[i] == ',')
                    ok = false;
            }
            if(ok)
                c++;
        }

        p = strtok(NULL, " ");
    }
    cout<<c;
}
