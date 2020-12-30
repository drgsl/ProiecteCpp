#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("s_p_c.in");
ofstream g("s_p_c.out");

char S[101][41];
char P[101][41];
char C[101][41];
int is, ip, ic;

char cuvinte[303][41],aux[41];
int ind;

int main()
{
    while(f)
    {
        f>>cuvinte[ind];
        ind ++;
    }

    for(int i = 0; i<ind-1 ; i++)
    {
        switch(cuvinte[i][strlen(cuvinte[i]) - 1])
        {
        case 'S':
            strcpy(cuvinte[i]+strlen(cuvinte[i]) - 2, cuvinte[i] + strlen(cuvinte[i]));
            strcpy(S[is], cuvinte[i]);

            is++;
            break;
        case 'P':
            strcpy(cuvinte[i]+strlen(cuvinte[i]) - 2, cuvinte[i] + strlen(cuvinte[i]));
            strcpy(P[ip], cuvinte[i]);
            ip++;
            break;
        case 'C':
            strcpy(cuvinte[i]+strlen(cuvinte[i]) - 2, cuvinte[i] + strlen(cuvinte[i]));
            strcpy(C[ic], cuvinte[i]);
            ic++;
            break;
        }
    }

    for(int i = 0 ; i < is - 1; i++)
    {
        for(int j = i+1 ; j<=is - 1; j++)
            if(strcmp(S[j], S[i]) < 0)
            {
                strcpy(aux, S[j]);
                strcpy(S[j], S[i]);   //S[i+1] = S[i];
                strcpy(S[i], aux);    //S[i] = aux;
            }
    }

    for(int i = 0 ; i < ip - 1; i++)
    {
        for(int j = i+1 ; j<=ip - 1; j++)
            if(strcmp(P[j], P[i]) < 0)
            {
                strcpy(aux, P[j]);
                strcpy(P[j], P[i]);   //P[i+1] = P[i];
                strcpy(P[i], aux);    //P[i] = aux;
            }
    }

    for(int i = 0 ; i < ic - 1; i++)
    {
        for(int j = i+1 ; j<=ic - 1; j++)
            if(strcmp(C[j], C[i]) < 0)
            {
                strcpy(aux, C[j]);
                strcpy(C[j], C[i]);   //C[i+1] = C[i];
                strcpy(C[i], aux);    //C[i] = aux;
            }
    }

    for(int i = 0; i< is; i++)
    {
        for(int j = 0; j < ip; j++)
        {
            for(int z = 0; z < ic; z++)
            {
                g<<S[i] <<  " " << P[j] << " " << C[z] << endl;
            }

        }
    }

    return 0;
}
