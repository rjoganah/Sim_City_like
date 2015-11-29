#include "headers.h"



void detruire (s_grille*g, int i, int j,t_banque* images)
{
    /*
    if(g->niveau==0)
    {
        g->elem[i][j].etatsol=1;
        g->elem[i][j].piece=images->magenta;
        g->elem[i][j].marqueur=0;

    }
    if(g->niveau==-1) g->elem[i][j].etatssol=0;
    if(g->niveau==-2) g->elem[i][j].etatsssol=0;

    */
 g->elem[i][j].habitable=0;
     g->elem[i][j].alimeau=0;
           g->elem[i][j].alimel=0;
      g->elem[i][j].alimr=0;
      g->elem[i][j].alimtot=0;
      g->elem[i][j].construite=0;
     g->elem[i][j].etatsol=1;
        g->elem[i][j].piece=images->magenta;
        g->elem[i][j].marqueur=0;
        g->elem[i][j].etatssol=0;
     g->elem[i][j].etatsssol=0;
}
