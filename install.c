#include "headers.h"
void charge_route(s_grille*g,int i,int j,t_banque*images)
{
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_07;
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_01;
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_01;
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_01;
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_02;
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_03;
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_04;
    if((g->elem[i][j].haut==0)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_11;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_02;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_06;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_05;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==0)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_09;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_02;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==0)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_10;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==0)) g->elem[i][j].piece=images->chemin_08;
    if((g->elem[i][j].haut==1)&&(g->elem[i][j].bas==1)&&(g->elem[i][j].gauche==1)&&(g->elem[i][j].droite==1)) g->elem[i][j].piece=images->chemin_07;


}
void install_route(s_grille*g,int i, int j)
{
    g->elem[i][j].etatsol=2;

    if(g->elem[i][j-1].etatsol==2){g->elem[i][j].haut=1; g->elem[i][j-1].bas=1;}
    if(g->elem[i][j+1].etatsol==2){g->elem[i][j].bas=1; g->elem[i][j+1].haut=1;}
    if(g->elem[i-1][j].etatsol==2){g->elem[i][j].gauche=1; g->elem[i-1][j].droite=1;}
    if(g->elem[i+1][j].etatsol==2){g->elem[i][j].droite=1; g->elem[i+1][j].gauche=1;}
    printf("haut%d bas%d gauche%d droite%d\n",g->elem[i][j].haut,g->elem[i][j].bas,g->elem[i][j].gauche,g->elem[i][j].droite);



}

void mettre_hab(s_grille*g,int i, int j)
{
    srand(time(NULL));
    g->elem[i][j].habitant=rand()%5+1;
    g->nb_hab=g->nb_hab+g->elem[i][j].habitant;
    g->cmp_usine=g->cmp_usine+g->elem[i][j].habitant;

    if(g->cmp_usine>=450)
    {
        g->cmp_eau++;
        g->cmp_el++;
        g->cmp_usine=0;

    }
}

void install_maison(s_grille* g,int i,int j,t_banque*images)
{
int k,l;
//     g->elem[i][j].ageDebut=game_time;
 //printf("nb: hab:: %d",g->elem[i][j].habitant);
//mettre_hab(g,i,j);
//g->elem[i][j].pif=rand()%12;

if  (g->elem[i][j].alimtot==0 )g->elem[i][j].piece=images->zonehab1;

if  ((g->elem[i][j].alimtot==1 )&& (g->elem[i][j].construite==0 )){g->elem[i][j].piece=images->chantier1;printf ("ok");}


if ((g->elem[i][j].alimtot==1 )&& (g->elem[i][j].construite==1 ))
{

     /*for(k=0; k<L; k++)
        {
            for(l=0; l<H; l++)
            {*/
                if (g->elem[i][j].etatsol==3)
                {



    g->elem[i][j].habitable=1;
   g->elem[i][j].pif=rand()%12;
    if(  g->elem[i][j].pif== 0) g->elem[i][j].piece=images->maison_12;
    if(  g->elem[i][j].pif== 1) g->elem[i][j].piece=images->maison_01;
    if(  g->elem[i][j].pif== 2) g->elem[i][j].piece=images->maison_02;
    if(  g->elem[i][j].pif== 3) g->elem[i][j].piece=images->maison_03;
    if(  g->elem[i][j].pif== 4) g->elem[i][j].piece=images->maison_04;
    if(  g->elem[i][j].pif== 5) g->elem[i][j].piece=images->maison_05;
    if(  g->elem[i][j].pif== 6) g->elem[i][j].piece=images->maison_06;
    if(  g->elem[i][j].pif== 7) g->elem[i][j].piece=images->maison_07;
    if(  g->elem[i][j].pif== 8) g->elem[i][j].piece=images->maison_08;
    if(  g->elem[i][j].pif== 9) g->elem[i][j].piece=images->maison_09;
    if(  g->elem[i][j].pif== 10) g->elem[i][j].piece=images->maison_10;
    if(  g->elem[i][j].pif== 11) g->elem[i][j].piece=images->maison_11;
                }
    //        }
      //  }

}

g->elem[i][j].etatsol=3;
       g->elem[i][j].etatssol=10;
          g->elem[i][j].etatsssol=10;

    ///test_alimr(g,i,j);


}

void install_usine(s_grille* g,int i,int j,t_banque*images)
{

    g->elem[i][j].piece=images->usine;
    g->elem[i+1][j].piece=images->magenta;
    g->elem[i][j+1].piece=images->magenta;
    g->elem[i+1][j+1].piece=images->magenta;


    g->elem[i+1][j].ageDebut=game_time;
    g->elem[i+1][j+1].ageDebut=game_time;
    g->elem[i][j+1].ageDebut=game_time;
    g->elem[i][j].ageDebut=game_time;

    g->elem[i][j].etatsol=4;//affichage niveau 0
    g->elem[i+1][j].etatsol=4;
    g->elem[i][j+1].etatsol=4;
    g->elem[i+1][j+1].etatsol=4;

      g->elem[i][j].etatsssol=1;//affichage niveau -2
    g->elem[i+1][j].etatsssol=1;
    g->elem[i][j+1].etatsssol=1;
    g->elem[i+1][j+1].etatsssol=1;

        g->elem[i][j].alimeau=1;//usine alimentée en eau
    g->elem[i+1][j].alimeau=1;
    g->elem[i][j+1].alimeau=1;
    g->elem[i+1][j+1].alimeau=1;

         test_alimeau(g,i,j);
    // test_alimeau(g,i+1,j);
    test_alimeau(g,i+1,j+1);
    // test_alimeau(g,i,j+1);

}

void install_centrale(s_grille* g,int i,int j,t_banque*images)
{


    g->elem[i+1][j].piece=images->magenta;
    g->elem[i][j+1].piece=images->magenta;
    g->elem[i+1][j+1].piece=images->magenta;

g->elem[i][j].ageDebut=game_time;
g->elem[i+1][j].ageDebut=game_time;
g->elem[i+1][j+1].ageDebut=game_time;
g->elem[i][j+1].ageDebut=game_time;

g->elem[i][j].marqueur=1;//affichage niveau 0
    g->elem[i][j].etatsol=5;
    g->elem[i+1][j].etatsol=5;
    g->elem[i][j+1].etatsol=5;
    g->elem[i+1][j+1].etatsol=5;

        g->elem[i][j].etatssol=1;//affichage niveau -1
    g->elem[i+1][j].etatssol=1;
    g->elem[i][j+1].etatssol=1;
    g->elem[i+1][j+1].etatssol=1;

       g->elem[i][j].alimel=1;//centrale alimenté en élec
    g->elem[i+1][j].alimel=1;
    g->elem[i][j+1].alimel=1;
    g->elem[i+1][j+1].alimel=1;

    test_alimel(g,i,j);
    test_alimel(g,i+1,j+1);
}
