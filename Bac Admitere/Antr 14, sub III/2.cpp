#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char S[101];
    cin.getline(S, 101);
    for(int i = 0; i<=strlen(S); i++)
        if(S[i] == '-')
            strcpy(S+i, S+i+1);
    cout<<S;
}
