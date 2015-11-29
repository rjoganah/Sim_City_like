#include "headers.h"

void initialiser_grille(s_grille* g,t_banque*images )
{

    int i,j;
    for(i=0; i<L; i++)
    {
        for(j=0; j<H; j++)
        {


            g->elem[i][j].piece=images->magenta;//par défaut case transparente en image

            g->elem[i][j].etatsol=1;//de l'herbe partout en état
            g->elem[i][j].etatssol=0;
            g->elem[i][j].etatsssol=0;
            g->elem[i][j].marqueur=0;

        }

    }

    FILE*fp;
    char s[5];
// ouvrir le fichier en lecture
    fp = fopen("plan2.txt","r");

    // tester l'ouverture du fichier
    if (!fp)
    {
        printf("Je ne peux pas ouvrir le fichier plan2.txt\n");
    }
    else
    {
        for(j=0; j<H; j++)

        {
            for(i=0; i<L; i++)
            {
                fscanf(fp,"%s",s);
                if (atoi(s)==99)

                {
                    g->elem[i][j].etatsol=99;
                    g->elem[i][j].etatssol=99;
                    g->elem[i][j].etatsssol=99;


                }

                  if (atoi(s)==1)

                {
                    g->elem[i][j].etatsol=1;

                }

                if (atoi(s)==40)

                {
                    g->elem[i][j].etatsol=0;
                     g->elem[i][j].piece=images->roche43;
                }
                if (atoi(s)==43)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche44;
                }
                if (atoi(s)==41)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche41;
                }
                if (atoi(s)==42)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche42;
                }
 if (atoi(s)==46)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche45;
                }
                 if (atoi(s)==47)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche46;
                }
                 if (atoi(s)==44)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche47;
                }
                 if (atoi(s)==45)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche48;
                }

                  if (atoi(s)==48)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche52;
                }

                  if (atoi(s)==49)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche49;
                }

                  if (atoi(s)==50)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche50;
                }

                  if (atoi(s)==51)

                {
                    g->elem[i][j].etatsol=0;
                        g->elem[i][j].piece=images->roche51;
                }
  if (atoi(s)==18)

                {
                    g->elem[i][j].etatsol=1;
                        g->elem[i][j].piece=images->hautes_herbes;
                }

 if (atoi(s)==19)

                {
                    g->elem[i][j].etatsol=1;
                        g->elem[i][j].piece=images->fleurs;
                }



                if (atoi(s)==24)

                {
                    g->elem[i][j].etatsol=24;
                        g->elem[i][j].piece=images->pont11;
                }
            }
        }



        g->outil=0;

        /*
        //Mer
        //Mer bande gauche
        for (i=0; i<8; i++)
        {
            for (j=0; j<H; j++)//
            {
                g->elem[i][j].etatsol=0;//mer
            }
        }

        //mer bande droite
        for (i=L-5; i<L; i++)
        {
            for (j=0; j<H; j++)//
            {
                g->elem[i][j].etatsol=0;
            }
        }
        //mer bande haut
        for (i=0; i<L; i++)
        {
            for (j=0; j<5; j++)//
            {
                g->elem[i][j].etatsol=0;
            }
        }
        //mer bande bas
        for (i=0; i<L; i++)
        {
            for (j=H-5; j<H; j++)//
            {
                g->elem[i][j].etatsol=0;
            }
        }
        */
        //affichage de la matrice de jeu
        carte_console(g);


        //initialise le jeu sur le niveau zero
        g->niveau=0;
    }

}


void on_click(s_grille* g,t_banque*images, int posx, int posy)
{


//if (((mouse_x+posx-3)/C > 7 )&&((mouse_x+posx+3)/C < 35 ) && ((mouse_y+posy-3)/C> 4 )&&((mouse_y+posy+3)/C< 55 ))
      if ((TX+TL<mouse_x) || (((0<mouse_y)&&(mouse_y<TY))||(((TY+TH<mouse_y)&&(mouse_y<600)) )))



    {


        int i,j;
        if(g->niveau==0)
        {
            for(i=0; i<L; i++)
            {
                for(j=0; j<H; j++)
                {
                    if((mouse_b & 1)&&(mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))
                    {
                        if ((g->outil==1) && (g->elem[i][j].etatsol==1))

                        {
                            printf("Outil 1");
                            g->elem[i][j].etatsol=2;
                            install_route(g,i,j,images);
                            //g->elem[i][j].piece=images->chemin;

                        }
                        //   if ((g->outil==2) && (g->elem[i][j].etatsol==1) && (g->elem[i+1][j].etatsol==1) && (g->elem[i][j+1].etatsol==1) && (g->elem[i+1][j+1].etatsol==1))
                        if ((g->outil==2) && (g->elem[i][j].etatsol==1) )
                        {
                            printf("Outil 2");
                            install_maison(g,i,j,images);
                            /*   g->elem[i][j].etatsol=3;
                               g->elem[i+1][j].etatsol=3;
                               g->elem[i][j+1].etatsol=3;
                               g->elem[i+1][j+1].etatsol=3;
                                                            */

                        }

                        if ((g->outil==3) && (g->elem[i][j].etatsol==1) && (g->elem[i+1][j].etatsol==1) && (g->elem[i][j+1].etatsol==1) && (g->elem[i+1][j+1].etatsol==1) &&(g->cmp_eau!=0))
                        {
                            printf("Outil 3");
                            if((g->elem[i+2][j].etatsol==0)||(g->elem[i-1][j].etatsol==0)||(g->elem[i][j+2].etatsol==0)||(g->elem[i][j-1].etatsol==0))
                            {

                            install_usine(g,i,j,images);
                            g->cmp_eau--;
                            printf("test");
                            }
                            else printf("pas d'eau a cote");

                        }
                        if ((g->outil==4) && (g->elem[i][j].etatsol==1) && (g->elem[i+1][j].etatsol==1) && (g->elem[i][j+1].etatsol==1) && (g->elem[i+1][j+1].etatsol==1)&&(g->cmp_el!=0))
                        {
                            printf("Outil 4");

                            install_centrale(g,i,j,images);
                            g->cmp_el--;

                        }

                          if ((g->outil==5) && (g->elem[i][j].etatsol==1) && (g->elem[i+1][j].etatsol==1) && (g->elem[i][j+1].etatsol==1) && (g->elem[i+1][j+1].etatsol==1))
                        {
                            printf("Outil 5");

                            install_maison(g,i,j,images);
                            install_maison(g,i+1,j,images);
                            install_maison(g,i,j+1,images);
                            install_maison(g,i+1,j+1,images);


                        }

                    }
                }
            }
        }

        if(g->niveau==-1)
        {
            for(i=0; i<L; i++)
            {
                for(j=0; j<H; j++)
                {
                    if((mouse_b & 1)&&(mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))
                    {
                        if( g->elem[i][j].etatssol==0)
                        {
                        g->elem[i][j].etatssol=1;
                        test_alimel(g,i,j);
                        }
                    }
                }
            }

        }




        if(g->niveau==-2)
        {
            for(i=0; i<L; i++)
            {
                for(j=0; j<H; j++)
                {
                    if((mouse_b & 1)&&(mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))
                    {
                         if(g->elem[i][j].etatsssol==0)
                    {
                        g->elem[i][j].etatsssol=1;
                        test_alimeau(g,i,j);
                    }
                    }
                }
            }

        }

    }
}

void carte_console(s_grille*g)
{
    printf("\netat sol\n");
    int i,j;
    for(j=0; j<H; j++)

    {
        for(i=0; i<L; i++)
        {
             if (g->elem[i][j].etatsol<10) printf("0");
            printf("%d",g->elem[i][j].etatsol);
   }
        printf("\n");
    }

    printf("\n\n\nalimeau\n");

    for(j=0; j<H; j++)

    {
        for(i=0; i<L; i++)
        {
           //  if (g->elem[i][j].alimeau<10) printf("0");
            printf("%d",g->elem[i][j].alimel);
        }
        printf("\n");
    }
}

void clic_menu(s_grille*g,int posx, int posy, t_banque*images)  //fonction de clic sur un menu
{
    /////////////////////////////////////////////////////choix de l'outil//////////////////////////////////////////////////////////////////////////////////////////

    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY))==makecol(255,0,0)&& (mouse_b & 1))
        // if((mouse_x+posx>g->dx+25) && (mouse_x+posx<g->dx+50) && (mouse_y+posy>250) &&(mouse_y+posy<275) && (mouse_b & 1))
    {
        g->outil=1;
        game_pause=1;
    }

    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(255,128,255))&& (mouse_b & 1))
    {
        g->outil=2;
                game_pause=1;

    }

    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(0,128,255))&& (mouse_b & 1))
    {
        g->outil=3;
                game_pause=1;

    }
    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(128,255,255))&& (mouse_b & 1))
    {
        g->outil=4;
                game_pause=1;

    }

     if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY))==makecol(255,128,192)&& (mouse_b & 1))
        // if((mouse_x+posx>g->dx+25) && (mouse_x+posx<g->dx+50) && (mouse_y+posy>250) &&(mouse_y+posy<275) && (mouse_b & 1))
    {
        g->outil=5;
        game_pause=1;
    }
///////////////////////////////////////////////////////////////choix du niveau/////////////////////////////////////////////////////////////////////////////
    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(128,255,128))&& (mouse_b & 1))
    {
        g->niveau=-1;
    }

    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(255,255,128))&& (mouse_b & 1))
    {
        g->niveau=0;
    }
    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(0,255,128))&& (mouse_b & 1))
    {
        g->niveau=-2;
    }
    if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(255,255,0))&& (mouse_b & 1))
    {
        g->niveau=-3;
    }




        if((getpixel(images->toolbar2, mouse_x-TX, mouse_y-TY)==makecol(255,128,128))&& (mouse_b & 1))
    {
        if (game_pause==0){

            game_pause=1;

            //printf("pause");

            }
          else {game_pause=0; printf("play");}
    }







}



