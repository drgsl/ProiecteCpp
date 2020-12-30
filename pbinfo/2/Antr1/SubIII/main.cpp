#include <iostream>
#include <cstring>

using namespace std;

char s[101], voc[] = "aeiou", *p, sep[] = " ";


int main()
{
    cin.getline(s, 101);
    p = strtok(s, sep);
    while(p)
    {
        int nv = 0;
        int nc = 0;

        for(int i = 0; i<strlen(p); i++)
            if(strchr(voc, p[i]))
                nv ++;
            else
                nc ++;

        if(nv<nc) cout<<p<<endl;

        p = strtok(NULL, sep);
    }
    return 0;
}
