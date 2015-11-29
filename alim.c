#include "headers.h"

void test_alimr(s_grille* g,int i,int j)
{int ii,jj;
   int temp=0;
   if(g->elem[i][j].etatsol==3)
                        for(ii=-2; ii<3; ii++)
                        {
                            for(jj=-temp; jj<temp+1; jj++)
                            {
                                if((g->elem[i+jj][j+ii].etatsol==2)&&(i+jj<L)&&(j+ii<H)&&(i+jj>0)&&(j+ii>0))
                                {
                                    g->elem[i][j].alimr=1;
                                    //printf("alim_maison");
                                }
                            }
                            if(ii<0) temp++;
                            else temp--;



                        }



}


void test_alimel(s_grille*g,int i,int j)
{
    if((g->elem[i+1][j].etatssol==1)||(g->elem[i+1][j].etatsol==5))
    {printf("coucou i+1\n");

        enfiler_el(g,i,j,i+1,j);
        enfiler_el(g,i+1,j,i,j);
        if(g->elem[i+1][j].alimel==1)
        g->elem[i][j].alimel=1;
        else  g->elem[i][j].alimel=0;

    }

    if((g->elem[i-1][j].etatssol==1)||(g->elem[i-1][j].etatsol==5))
    {printf("coucou i-1\n");
        enfiler_el(g,i,j,i-1,j);
        enfiler_el(g,i-1,j,i,j);
        if(g->elem[i-1][j].alimel==1)

            g->elem[i][j].alimel=1;
        else             g->elem[i][j].alimel=0;

    }

    if((g->elem[i][j+1].etatssol==1)||(g->elem[i][j+1].etatsol==5))
    {printf("coucou j+1\n");
        enfiler_el(g,i,j,i,j+1);
        enfiler_el(g,i,j+1,i,j);
        if(g->elem[i][j+1].alimel==1)

            g->elem[i][j].alimel=1;
            else   g->elem[i][j].alimel=0;


    }

    if((g,g->elem[i][j-1].etatssol==1)||(g->elem[i][j-1].etatsol==5))
    {printf("coucou j-1\n");
        enfiler_el(g,i,j,i,j-1);
        enfiler_el(g,i,j-1,i,j);
        if(g->elem[i][j-1].alimel==1)

            g->elem[i][j].alimel=1;
            else g->elem[i][j].alimel=0;

    }//printf("coincointaille:%d\n",g->file_elemel[i][j].taille);
}



void test_alimeau(s_grille*g,int i,int j)
{
    if((g->elem[i+1][j].etatsssol==1) ||(g->elem[i+1][j].etatsol==4))
    {
        //printf("coucou i+1\n");
        enfiler_eau(g,i,j,i+1,j);
        enfiler_eau(g,i+1,j,i,j);
        if(g->elem[i+1][j].alimeau==1)
            g->elem[i][j].alimeau=1;
        else g->elem[i][j].alimeau=0;

    }

    if ((g->elem[i-1][j].etatsssol==1) || (g->elem[i-1][j].etatsol==4))
    {
    //    printf("coucou i-1\n");
        enfiler_eau(g,i,j,i-1,j);
        enfiler_eau(g,i-1,j,i,j);
        if(g->elem[i-1][j].alimeau==1)

            g->elem[i][j].alimeau=1;
          else    g->elem[i][j].alimeau=0;

    }

    if((g->elem[i][j+1].etatsssol==1)||(g->elem[i][j+1].etatsol==4))
    {
     //   printf("coucou j+1\n");
        enfiler_eau(g,i,j,i,j+1);
        enfiler_eau(g,i,j+1,i,j);
        if(g->elem[i][j+1].alimeau==1)

            g->elem[i][j].alimeau=1;
         else    g->elem[i][j].alimeau=0;

    }

    if((g,g->elem[i][j-1].etatsssol==1)||(g->elem[i][j-1].etatsol==4))
    {
      //  printf("coucou j-1\n");
        enfiler_eau(g,i,j,i,j-1);
        enfiler_eau(g,i,j-1,i,j);
        if(g->elem[i][j-1].alimeau==1)

            g->elem[i][j].alimeau=1;
            else  g->elem[i][j].alimeau=0;

    }

}



void test_alim_tot(s_grille*g)///fonction qui verifie si un batiment est totalement alimentée
{
    int i,j;
    for(i=0; i<L-2; i++)
    {
        for(j=0; j<H-2; j++)
        {
test_alimr(g,i,j);
                      // printf("test alim %d %d", i, j);

           //test_alimel(g,i,j);
            //test_alimeau(g,i,j);

            if((g->elem[i][j].etatsol==3))// si l'element est une maison et qu'elle est alimentée: en route; en elec; et en eau
            {


                if((g->elem[i][j].alimeau==1)&&(g->elem[i][j].alimel==1)&&(g->elem[i][j].alimr)==1)
                {

                    g->elem[i][j].alimtot=1; // la maison est totalement alimentée
                    printf("alimtot");
                    if (g->elem[i][j].marque_maison==0)
                    {
                        mettre_hab(g,i,j);

                       g->elem[i][j].marque_maison=1;
                    g->elem[i][j].ageDebut=game_time;

                    }
                }
                else

                {
                  //  if (g->elem[i][j].habitant!=0)
                  //  {
                        g->elem[i][j].alimtot=0;
                        g->elem[i][j].marque_maison=0;
                        g->nb_hab=g->nb_hab-g->elem[i][j].habitant;
                        g->cmp_usine=g->cmp_usine-g->elem[i][j].habitant;
                        g->elem[i][j].habitant=0;

                        g->elem[i][j].construite=0;
                      //  g->elem[i][j].habitant=0;
                   // }
                }
            }
        }
    }

}

