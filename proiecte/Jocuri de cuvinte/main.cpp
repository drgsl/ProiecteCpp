#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
using namespace std;

ifstream A("Alfabet1.in");
ofstream L("WordsSortedLength1.in");

ofstream S("Stats1.out");
ofstream CC("CreatedWords1.out");

ofstream Suf("Sufix1.out");

struct cuvant
{
    char text[40];
    int ascii;
    //int lun;
};

cuvant longWords[10];

int MaxLun = 0;
cuvant longest;

int nrCuv;

cuvant cuvinte[200000];
cuvant sufixe[200000];

int LenInd[40];

void loadWords()
{
    cout<<"Started Loading Words..."<<endl;
    long long i = 0;
    while(A)
    {
        A>>(cuvinte[i].text);
        if((strcmp(cuvinte[i].text," ") != 0)) // || strlen(cuvinte[i].text) <=1))
        {
            i++;
        }
    }
    nrCuv = i;
    cout<<nrCuv << " Words loaded"<<endl<<endl;
}

void Print()
{
    cout<<"Started printing words into console..."<<endl;
    for(int i = 0; i<= nrCuv; i++)
        cout<<cuvinte[i].text <<endl;
    cout<<nrCuv << " Words printed"<<endl<<endl;
}

void PrintFile()
{
    cout<<"Started saving words into file..."<<endl;
    for(int i = 0; i<= nrCuv; i++)
        L<<cuvinte[i].text <<endl;
    cout<<nrCuv << " Words saved into file"<<endl<<endl;
}

void SlowSort()
{
    cout<<"Started slow sorting words..."<<endl;

    for(int i = 0; i<= nrCuv; i++)
    {
        cout<<" i: ";
        cout.fill( '0' );
        cout.width( 5 );
        cout<<i << "/" << nrCuv;
        cout<<"\r";

        for(int j = i; j<= nrCuv; j++)
        {
            /*
                        cout<<" i: ";
                        cout.fill( '0' );
                        cout.width( 5 );
                        cout<<i << "/" << nrCuv;

                        cout<<" j: ";
                        cout.fill( '0' );
                        cout.width( 5 );
                        cout<<j<<"/"<<nrCuv;

                        cout<<"\r                \r";
            */

            if(strlen(cuvinte[j].text) < strlen(cuvinte[i].text) )
            {
                //swap
                cuvant aux;
                strcpy(aux.text,cuvinte[j].text);
                strcpy(cuvinte[j].text,cuvinte[i].text);
                strcpy(cuvinte[i].text,aux.text);
            }
        }
    }
    cout<<nrCuv << " Words slow sorted by length"<<endl<<endl;
}

void FastCombine()
{
    cout<<"Started faster word combining"<<endl;

    for(int i = 0; i<= nrCuv; i++)
    {
        //cout<<" i: ";
        cout.fill( '0' );
        cout.width( 5 );
        cout<<i << "/" << nrCuv;
        cout<<"\r";

        for(int j = 0; j<= nrCuv; j++)
        {
            if(strcmp(cuvinte[i].text, " ") == 0 || strcmp(cuvinte[j].text, " ") == 0 || i == j)
                continue;

            int wstart =  LenInd[strlen(cuvinte[i].text) + strlen(cuvinte[j].text)];
            int wstop = LenInd[strlen(cuvinte[i].text) + strlen(cuvinte[j].text) + 1];

            for(int w = wstart; w<=wstop; w++)
            {
                cuvant aux;
                strcpy(aux.text, cuvinte[i].text);
                strcat(aux.text, cuvinte[j].text);
                if(strcmp(aux.text, cuvinte[w].text) == 0)
                {
                    CC<<cuvinte[w].text<< "  =  " << cuvinte[i].text << " + " << cuvinte[j].text <<endl;
                    break;
                }
            }
        }
    }

    cout<<"Faster word combining ended"<<endl;
}

void FindLongestWord()
{

    //cout<<"Started searching longest word"<<endl;
    for(int i = 0; i<= nrCuv; i++)
    {
        if(strlen(cuvinte[i].text) > MaxLun)
        {
            MaxLun = strlen(cuvinte[i].text);
            strcpy(longest.text, cuvinte[i].text);
        }
    }
    S << "Longest word is "<< longest.text << " with " << MaxLun << " letters"<<endl<<endl;
    cout << "Wrote longest word"<<endl<<endl;
}

void TopLongestWords()
{

    int arrsize = (sizeof(longWords)/sizeof(*longWords));
    int index = nrCuv;
    S<<"Longest " << arrsize << " words "<< endl;
    for(int i = arrsize; i>=0; i--)
    {
        longWords[i] = cuvinte[index--];
        S << i << ": " << longWords[i].text << " ( " << strlen(longWords[i].text) << " letters ) "<<endl;
    }
    cout << "Finished Printing top longest words"<<endl<<endl;
}

void UpdateLenInd()
{
    cout<<"Started updating length indices..."<<endl;

    for(int i = 0; i<=MaxLun; i++)
    {
        LenInd[i] = -1;
    }

    int ind = 0;
    for(int i = 0; i<= nrCuv; i++)
    {
        if(strlen(cuvinte[i].text) > ind)
        {
            ind = strlen(cuvinte[i].text);
            LenInd[ind] = i;
        }
    }

    for(int i = 2; i<=MaxLun; i++)
    {
        int nxt = i+1;
        while(LenInd[nxt] == -1)
        {
            nxt = nxt +1;
            if(nxt > MaxLun)
                nxt = nrCuv;
        }
        if(LenInd[i] != -1)
        {
            if(i<10)
                S << "Words of length 0"<< i <<" start at " << LenInd[i] << "  ( "<< LenInd[nxt] - LenInd[i]<<" letters ) "<< endl;
            else
                S << "Words of length "<< i <<" start at " << LenInd[i] << " ( "<< LenInd[nxt] - LenInd[i] <<" letters ) "<< endl;
        }
        else
        {
            S << "There are no " << i << " letters words" <<endl;
        }
    }
    cout<<"Finished updating length indices"<<endl<<endl;


}


void bubbleSort()
{
    cout<<"Started bubble sorting words..."<<endl;
    int i, j;
    bool swapped;
    for (i = 0; i < nrCuv-1; i++)
    {
        swapped = false;
        for (j = 0; j < nrCuv-i-1; j++)
        {
            /*
                        cout<<" i: ";
                        cout.fill( '0' );
                        cout.width( 5 );
                        cout<<i << "/" << nrCuv;

                        cout<<" j: ";
                        cout.fill( '0' );
                        cout.width( 5 );
                        cout<<j<<"/"<<nrCuv;

                        cout<<"\r                \r";
            */
            if (strlen(cuvinte[j].text) > strlen(cuvinte[j+1].text))
            {
                cuvant aux;
                strcpy(aux.text,cuvinte[j].text);
                strcpy(cuvinte[j].text,cuvinte[j+1].text);
                strcpy(cuvinte[j+1].text,aux.text);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
    cout<<nrCuv << " Words bubble sorted by length"<<endl<<endl;
}

void calculateAsciiCodes()
{

    for (int i = 0; i < nrCuv; i++)
        for(int j = 0; j<=strlen(cuvinte[i].text); j++)
            cuvinte[i].ascii += cuvinte[i].text[j];
}

void PrintAscii()
{
    for (int i = 0; i < nrCuv; i++)
        cout<<cuvinte[i].ascii<<endl;
}

void AsciiSearch()
{

    cout<<"Started ASCII Search";
    for (int i = 0; i < nrCuv; i++)
        for (int j = 0; j < nrCuv; j++)
            if(cuvinte[i].ascii == cuvinte[j].ascii);
    //cout<<cuvinte[i].text << " " << cuvinte[j].text << " "<< cuvinte[i].ascii<<endl;
    cout<<"ASCII Search ended";
}

int main()
{
    loadWords();
    //calculateAsciiCodes();
    //AsciiSearch();
    //PrintAscii();
    //Print();
    SlowSort();
    //bubbleSort();
    PrintFile();
    FindLongestWord();
    UpdateLenInd();
    TopLongestWords();
    FastCombine();
    return 0;
}
