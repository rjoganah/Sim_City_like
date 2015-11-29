#include "headers.h"

void maj_age(s_grille*g,t_banque* images)
{
    int i,j;

    for(i=0;i<L;i++)
    {
        for(j=0;j<H;j++)
        {


            if((g->elem[i][j].etatsol==3)&&(g->elem[i][j].alimtot))//si l'élement est une maisonet qu'elle est alimentée
            {
                g->elem[i][j].age= game_time-(g->elem[i][j].ageDebut); //mettre a jour l'age total du batiment

                if(g->elem[i][j].age>g->elem[i][j].habitant)// et si l'age de l'élement est plus grand que le nombre d'habitant..
                {
                    g->elem[i][j].construite=1; //ecrire la maison comme construite
                    printf("construite");
                }
                else{g->elem[i][j].construite=0;}// sinon non construite

            }
            if((g->elem[i][j].etatsol==4)||(g->elem[i][j].etatsol==5))// si l'element est une usine d'energie ou de desalement...
            {                g->elem[i][j].age= game_time-(g->elem[i][j].ageDebut); //mettre a jour l'age total du batiment

                if((g->elem[i][j].age)>100)
                {
                    detruire(g,i,j,images);
                    for(i=0; i<L; i++)
        {
            for(j=0; j<H; j++)
            {

            g->elem[i][j].alimel=0;
            g->elem[i][j].alimeau=0;
            }}
                    }
            }


        }
    }
}
