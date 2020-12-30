#include <stdio.h>
#include <string.h>
#include <winbgim.h>
#include <iostream>

#define MAX1 20
#define MAX2 40
#define FUNDAL 0

#define WIDTH 1000
#define HEIGHT 800

using namespace std;

float zoom=10.0;

struct descriere
{
    char comanda[MAX1];
    unsigned nComenzi;
    float x1[MAX1], y1[MAX1], x2[MAX1], y2[MAX1];
};

struct punctLegatura
{
    float x, y;
};

void roteste (float x, float y, float & xnou, float & ynou)
{
    xnou = y;
    ynou = -x;
}

struct piesa
{
    unsigned id;
    char nume[MAX1];
    int x,y;
    unsigned orientare;
    char continut[MAX2];
    unsigned nrLegaturi;
    punctLegatura pLeg[MAX1];
    descriere descr;
};

struct legatura {
    int nod1, nod2; // cele doua noduri ce se leaga
    int punct1, punct2; // punctele de legatura de la cele doua noduri
    int tipLegatura; // nu am folosit, dar va trebui folosit
};

void initializeaza(piesa& P)
{
    P.orientare=0;
    char numeFisier[MAX1],s[MAX1];
    strcpy(numeFisier,P.nume);
    strcat(numeFisier,".ps");
    FILE* f=fopen(numeFisier,"rt");
    fscanf(f,"%s",s);
    /*printf("%s\n",s);*/
    fscanf(f,"%d",&P.nrLegaturi);
    /*printf("%d\n",P.nrLegaturi); */
    for (unsigned i=1; i<=P.nrLegaturi; i++)
    {
        fscanf(f,"%f%f",&P.pLeg[i].x,&P.pLeg[i].y);
        /* printf("%f %f\n",P.pLeg[i].x,P.pLeg[i].y); */
    }
    fscanf(f,"%s",s);
    /* printf("%s\n",s); */
    fscanf(f,"%d\n",&P.descr.nComenzi);
    /* printf("%d comenzi\n",P.descr.nComenzi); */
    for (unsigned i=1; i<=P.descr.nComenzi; i++)
    {
        fscanf(f,"%c%f%f",&P.descr.comanda[i],&P.descr.x1[i],&P.descr.y1[i]);
        fscanf(f,"%f%f\n",&P.descr.x2[i],&P.descr.y2[i]);
        /* printf("%c %f %f %f %f\n",P.descr.comanda[i],P.descr.x1[i],P.descr.y1[i],P.descr.x2[i],P.descr.y2[i]); */
    }
    fclose(f);
}

void myLine(piesa P, unsigned i)
{
    float x_1,y_1,x_2,y_2;
    float x1,y1,x2,y2;
    x1=P.descr.x1[i];
    y1=P.descr.y1[i];
    x2=P.descr.x2[i];
    y2=P.descr.y2[i];
    switch (P.orientare)
    {
    case 0:
        x_1=x1;
        y_1=y1;
        x_2=x2;
        y_2=y2;
        break;
    case 1:
        roteste(x1,y1,x_1,y_1);
        roteste(x2,y2,x_2,y_2);
        break;
    case 2:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        x_1=x1;
        y_1=y1;
        roteste(x2,y2,x_2,y_2);
        roteste(x_2,y_2,x2,y2);
        x_2=x2;
        y_2=y2;
        break;
    case 3:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        roteste(x1,y1,x_1,y_1);
        roteste(x2,y2,x_2,y_2);
        roteste(x_2,y_2,x2,y2);
        roteste(x2,y2,x_2,y_2);
        break;
    }
    line(P.x+zoom*x_1,P.y+zoom*y_1,P.x+zoom*x_2,P.y+zoom*y_2);
}

void myRectangle(piesa P, unsigned i)
{
    float x_1,y_1,x_2,y_2;
    float x1,y1,x2,y2;
    x1=P.descr.x1[i];
    y1=P.descr.y1[i];
    x2=P.descr.x2[i];
    y2=P.descr.y2[i];
    switch (P.orientare)
    {
    case 0:
        x_1=x1;
        y_1=y1;
        x_2=x2;
        y_2=y2;
        break;
    case 1:
        roteste(x1,y1,x_1,y_1);
        roteste(x2,y2,x_2,y_2);
        break;
    case 2:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        x_1=x1;
        y_1=y1;
        roteste(x2,y2,x_2,y_2);
        roteste(x_2,y_2,x2,y2);
        x_2=x2;
        y_2=y2;
        break;
    case 3:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        roteste(x1,y1,x_1,y_1);
        roteste(x2,y2,x_2,y_2);
        roteste(x_2,y_2,x2,y2);
        roteste(x2,y2,x_2,y_2);
        break;
    }
    rectangle(P.x+zoom*x_1,P.y+zoom*y_1,P.x+zoom*x_2,P.y+zoom*y_2);
}

void myEllipse(piesa P, unsigned i)
{
    float x_1,y_1,x_2,y_2;
    float x1,y1,x2,y2;
    x1=P.descr.x1[i];
    y1=P.descr.y1[i];
    x2=P.descr.x2[i];
    y2=P.descr.y2[i];
    switch (P.orientare)
    {
    case 0:
        x_1=x1;
        y_1=y1;
        x_2=x2;
        y_2=y2;
        break;
    case 1:
        roteste(x1,y1,x_1,y_1);
        x_2=y2;
        y_2=x2;
        break;
    case 2:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        x_1=x1;
        y_1=y1;
        x_2=x2;
        y_2=y2;
        break;
    case 3:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        roteste(x1,y1,x_1,y_1);
        x_2=y2;
        y_2=x2;
        break;
    }
    ellipse(P.x+x_1*zoom,P.y+y_1*zoom,0,360,x_2*zoom,y_2*zoom);
}

void myArc(piesa P, unsigned i)
{
    float x1,y1,x2;
    float x_1,y_1;
    x1=P.descr.x1[i];
    y1=P.descr.y1[i];
    x2=P.descr.x2[i]; /* y2=P.descr.y2[i]; */
    switch (P.orientare)
    {
    case 0:
        arc(P.x+x1*zoom,P.y+y1*zoom,-90,90,x2*zoom);
        break;
    case 1:
        roteste(x1,y1,x_1,y_1);
        arc(P.x+x_1*zoom,P.y+y_1*zoom,0,180,x2*zoom);
        break;
    case 2:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        arc(P.x+x1*zoom,P.y+y1*zoom,90,270,x2*zoom);
        break;
    case 3:
        roteste(x1,y1,x_1,y_1);
        roteste(x_1,y_1,x1,y1);
        roteste(x1,y1,x_1,y_1);
        arc(P.x+x_1*zoom,P.y+y_1*zoom,-180,0,x2*zoom);
        break;
    }
}

void deseneaza(piesa P, int culoare)
{
    setcolor(culoare);
    for (unsigned i=1; i<=P.descr.nComenzi; i++)
        switch(P.descr.comanda[i])
        {
        case 'L':
            myLine(P,i);
            break;
        case 'R':
            myRectangle(P,i);
            break;
        case 'O':
            myEllipse(P,i);
            break;
        case 'A':
            myArc(P,i);
            break;
        }
}

void amplaseaza(piesa& P, unsigned x, unsigned y, unsigned orient)
{
    P.x=x;
    P.y=y;
    P.orientare=orient;
    deseneaza(P, WHITE);
}

void roteste(piesa& P)
{
    deseneaza(P,FUNDAL);
    P.orientare=(P.orientare+1) % 4;
    deseneaza(P, WHITE);
}



void updateZoom(int increment)
{
    zoom +=increment;
    cleardevice();
    // Redraw canvas
    //deseneazaMeniul(Meniu,nrPieseMeniu);
}

unsigned alegePiesa(piesa vectorPiese[MAX2], unsigned nrPiese)
{
    bool click=false;
    unsigned i, nrPiesaAleasa=0;
    int xMouse,yMouse;
    do
    {
        //New Frame Event Update
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse=mousex();
            yMouse=mousey();
            for (i=1; i<=nrPiese; i++)
            {
                //Mouse Click Event
                //if(xMouse >= WIDTH - 50 && yMouse >= HEIGHT - 50) updateZoom(4);

                if (abs(vectorPiese[i].x - xMouse)<=10
                        && abs(vectorPiese[i].y - yMouse)<=10)
                {
                    nrPiesaAleasa=i;
                    click=true;
                }
            }
        }
    }
    while (!click);
    return nrPiesaAleasa;
}

void deseneazaMeniul(piesa Meniu[MAX2],unsigned int nrPieseMeniu)
{
    setcolor(WHITE);
    rectangle(0,0,getmaxx(),getmaxy());
    strcpy(Meniu[1].nume,"DIODA");
    strcpy(Meniu[2].nume,"ZENNER");
    strcpy(Meniu[3].nume,"TRANZNPN");
    strcpy(Meniu[4].nume,"TRANZPNP");
    strcpy(Meniu[5].nume,"CONDENS");
    strcpy(Meniu[6].nume,"REZIST");
    strcpy(Meniu[7].nume,"BATERIE");
    strcpy(Meniu[8].nume,"POLARIZ");
    strcpy(Meniu[9].nume,"SINU");
    strcpy(Meniu[10].nume,"SERVOMOT");
    strcpy(Meniu[11].nume,"AMPLOP");
    strcpy(Meniu[12].nume,"STOP");
    rectangle(0,0,getmaxx(),50);
    int lat=getmaxx()/nrPieseMeniu;
    for (unsigned i=1; i<=nrPieseMeniu; i++)
    {
        initializeaza(Meniu[i]);
        amplaseaza(Meniu[i],lat*i-lat/2,25,0);
    }
}

unsigned alegeOPiesaDinMeniu(piesa Meniu[MAX2],unsigned nrPieseMeniu)
{
    unsigned nrPiesaAleasa=0;
    nrPiesaAleasa=alegePiesa(Meniu,nrPieseMeniu);
    // printf("%d, ",nrPiesaAleasa);
    return nrPiesaAleasa;
}

void punePiesa(piesa& P)
{
    bool click=false;
    int xMouse,yMouse;
    do
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse=mousex();
            yMouse=mousey();
            // printf("%d, %d\n",xMouse,yMouse);
            amplaseaza(P,xMouse,yMouse,0);
            click=true;
        }
    while (!click);
}

piesa Meniu[MAX1];
unsigned nrPieseMeniu=12;

piesa Piesa[MAX2];
unsigned nrPiese=0;

legatura Legatura[MAX2];
unsigned nrLegaturi=0;

void deseneazaPuncteDeLegatura(piesa P)
{
    circle(P.x + P.pLeg[1].x * zoom,P.y + P.pLeg[1].y * zoom,10);
    circle(P.x + P.pLeg[2].x * zoom,P.y + P.pLeg[2].y * zoom,10);
}

void drawLine(int x1, int y1, int x2, int y2, int cul)
{
    setcolor(cul);
    line(x1,y1,(x1+x2)/2,y1);
    line((x1+x2)/2,y1,(x1+x2)/2,y2);
    line((x1+x2)/2,y2,x2,y2);
}

void deseneazaLegatura(int &idNod1, int &p1, int &idNod2, int &p2)
{
    bool click=false;
    int i, xMouse,yMouse;
    // aleg un punct de legatura (p1) de la nodul 1 (idNod1)
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            Beep(2000,100);
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse=mousex();
            yMouse=mousey();
            for (i=1; i<=nrPiese; i++)
                if (abs(Piesa[i].pLeg[1].x * zoom + Piesa[i].x - xMouse)<=5
                        && abs(Piesa[i].pLeg[1].y * zoom + Piesa[i].y - yMouse)<=5)
                {
                    idNod1=i;
                    p1=1;
                    click=true;
                }
                else if (abs(Piesa[i].pLeg[2].x * zoom + Piesa[i].x - xMouse)<=5
                         && abs(Piesa[i].pLeg[2].y * zoom + Piesa[i].y - yMouse)<=5)
                {
                    idNod1=i;
                    p1=2;
                    click=true;
                }
        }
    }
    while (!click);
    // aleg un punct de legatura (p2) de la nodul 2 (idNod2)
    // pana aleg, desenez mereu o linie
    click=false;
    int x1,y1,x2,y2;
    x1=Piesa[idNod1].pLeg[p1].x*zoom + Piesa[idNod1].x;
    y1=Piesa[idNod1].pLeg[p1].y*zoom + Piesa[idNod1].y;
    xMouse=mousex();
    yMouse=mousey();
    do
    {
        drawLine(x1,y1,xMouse,yMouse, 15-FUNDAL);
        delay(50);
        drawLine(x1,y1,xMouse,yMouse,FUNDAL);
        xMouse=mousex();
        yMouse=mousey();
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            Beep(1200,100);
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse=mousex();
            yMouse=mousey();
            for (i=1; i<=nrPiese; i++)
                if (abs(Piesa[i].pLeg[1].x * zoom + Piesa[i].x - xMouse)<=5
                        && abs(Piesa[i].pLeg[1].y * zoom + Piesa[i].y - yMouse)<=5)
                {
                    idNod2=i;
                    p2=1;
                    click=true;
                }
                else if (abs(Piesa[i].pLeg[2].x * zoom + Piesa[i].x - xMouse)<=5
                        && abs(Piesa[i].pLeg[2].y * zoom + Piesa[i].y - yMouse)<=5)
                {
                    idNod2=i;
                    p2=2;
                    click=true;
                }
        }
    }
    while (!click);
    drawLine(x1,y1,xMouse,yMouse, 15-FUNDAL);
}

int main()
{
    initwindow(WIDTH,HEIGHT,"Electron");

    unsigned nrPiesaAleasa;
    deseneazaMeniul(Meniu,nrPieseMeniu);
    nrLegaturi=0;

    int ind = 0;
    do
    {

        if(ind)
        {
            nrLegaturi ++;
            int idNod1, idNod2, p1, p2;
        deseneazaLegatura(idNod1,p1,idNod2,p2);
        Legatura[nrLegaturi].nod1=idNod1;
        Legatura[nrLegaturi].nod2=idNod2;
        Legatura[nrLegaturi].punct1=p1;
        Legatura[nrLegaturi].punct2=p2;
        cout<<"Am trasat legatura de la punctul "<<p1<<" al nodului "<<idNod1;
        cout<<" la punctul "<<p2<<" al nodului "<<idNod2<<".\n";
        ind = 0;
        }
        else
        {
            ind = 1;
            nrPiesaAleasa=alegeOPiesaDinMeniu(Meniu,nrPieseMeniu);
            //printf("Am ales piesa %u\n",nrPiesaAleasa);
            if (nrPiesaAleasa!=nrPieseMeniu)
            {
                nrPiese++;
                Piesa[nrPiese]=Meniu[nrPiesaAleasa];
                punePiesa(Piesa[nrPiese]);
                deseneazaPuncteDeLegatura(Piesa[nrPiese]);
                //zoom++;
            }
        }
    }
    while (nrPiesaAleasa!=nrPieseMeniu);
    // getch();
    closegraph();
    return 0;
}
