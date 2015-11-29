#include "headers.h"

void animations (s_grille* g,t_banque*images,int teolien)

{
    int i,j;
    for(i=0; i<L; i++)
    {
        for(j=0; j<H; j++)
        {
            if ((g->elem[i][j].marqueur==1) && (teolien>-1) && (teolien<10)) g->elem[i][j].piece=images->centrale1;
            if ((g->elem[i][j].marqueur==1) && (teolien>9) && (teolien<20))g->elem[i][j].piece=images->centrale2;
            if ((g->elem[i][j].marqueur==1) && (teolien>19) && (teolien<30))g->elem[i][j].piece=images->centrale3;
            if ((g->elem[i][j].marqueur==1) && (teolien>29) && (teolien<40))g->elem[i][j].piece=images->centrale4;
            if ((g->elem[i][j].marqueur==1) && (teolien>39) && (teolien<50))g->elem[i][j].piece=images->centrale5;
            if ((g->elem[i][j].marqueur==1) && (teolien>49) && (teolien<60))g->elem[i][j].piece=images->centrale6;
            if ((g->elem[i][j].marqueur==1) && (teolien>59) && (teolien<70))g->elem[i][j].piece=images->centrale7;
        }
    }

    //Mer

    for (i=0; i<L; i++)
    {
        for (j=0; j<H; j++)//
        {
if (g->elem[i][j].etatsol==99)
{

            if ((teolien>-1) && (teolien<30)) g->elem[i][j].piece=images->eau1;
            if ((teolien>29) && (teolien<40))g->elem[i][j].piece=images->eau2;
            if ((teolien>39) && (teolien<50))g->elem[i][j].piece=images->eau3;
            if ((teolien>49) && (teolien<70))g->elem[i][j].piece=images->eau2;
}

if (g->elem[i][j].etatsol==24)
{

            if ((teolien>-1) && (teolien<30)) g->elem[i][j].piece=images->pont11;
            if ((teolien>29) && (teolien<40))g->elem[i][j].piece=images->pont12;
            if ((teolien>39) && (teolien<50))g->elem[i][j].piece=images->pont13;
            if ((teolien>49) && (teolien<70))g->elem[i][j].piece=images->pont12;
}
        }
    }

    /*
    //mer bande droite
    for (i=L-5; i<L; i++)
    {
        for (j=0; j<H; j++)//
        {


            if ((teolien>-1) && (teolien<30)) g->elem[i][j].piece=images->eau1;
            if ((teolien>29) && (teolien<40))g->elem[i][j].piece=images->eau2;
            if ((teolien>39) && (teolien<50))g->elem[i][j].piece=images->eau3;
            if ((teolien>49) && (teolien<70))g->elem[i][j].piece=images->eau2;

        }
    }
    //mer bande haut
    for (i=0; i<L; i++)
    {
        for (j=0; j<5; j++)//
        {


            if ((teolien>-1) && (teolien<30)) g->elem[i][j].piece=images->eau1;
            if ((teolien>29) && (teolien<40))g->elem[i][j].piece=images->eau2;
            if ((teolien>39) && (teolien<50))g->elem[i][j].piece=images->eau3;
            if ((teolien>49) && (teolien<70))g->elem[i][j].piece=images->eau2;

        }
    }
    //mer bande bas
    for (i=0; i<L; i++)
    {
        for (j=H-5; j<H; j++)//
        {


            if ((teolien>-1) && (teolien<30)) g->elem[i][j].piece=images->eau1;
            if ((teolien>29) && (teolien<40))g->elem[i][j].piece=images->eau2;
            if ((teolien>39) && (teolien<50))g->elem[i][j].piece=images->eau3;
            if ((teolien>49) && (teolien<70))g->elem[i][j].piece=images->eau2;

        }
    }

    */
}
