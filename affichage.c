#include "headers.h"

void affichage_grille(BITMAP* terrain0, s_grille* g,t_banque*images, int posx, int posy)
{
    int i,j;//Coordonnées

    if (g->niveau==0)//Niveau de terrain

        //Affichage du niveau 0 (habitations)
    {

        //Parcours de toutes les cases de la grille et afficher par défaut de l'herbe


        for (i=0; i<L; i++)
        {
            for (j=0; j<H; j++)//
            {

                draw_sprite(terrain0,images->herbe,i*C+1,j*C+1);
            }
        }


        //Parcours de toutes les cases de la grille pour afficher l'image correspondant  à la nature de la case
        for (i=0; i<L; i++)
        {
            for (j=0; j<H; j++)//
            {

                draw_sprite(terrain0,g->elem[i][j].piece,i*C+1,j*C+1);
                /*
                //Affichage des éléments de 1 case (herbe, chemin, maison,eau)
                              if ((g->elem[i][j].etatsol==1)||(g->elem[i][j].etatsol==2)||(g->elem[i][j].etatsol==3) || (g->elem[i][j].etatsol==0))

                    draw_sprite(terrain0,g->elem[i][j].piece,i*C+1,j*C+1);
                    */
//printf("\ntest %d : %d",i,j);
                if ((g->outil==1)||(g->outil==2))
                {
                    if ((mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))
//if (((mouse_x+posx-3)/C > 7 )&&((mouse_x+posx+3)/C < 35 ) && ((mouse_y+posy-3)/C> 4 )&&((mouse_y+posy+3)/C< 55 ))
                        if (g->elem[i][j].etatsol==1)
                            if ((TX+TL<mouse_x) || (((0<mouse_y)&&(mouse_y<TY))||(((TY+TH<mouse_y)&&(mouse_y<600)) )))
                                rect(terrain0,i*C,j*C,(i+1)*C,(j+1)*C,makecol(0,0,0));
                }



                /* //Affichage des éléments de 4 cases (usine eau, centrale)
                if ((g->elem[i][j].etatsol==4)||(g->elem[i][j].etatsol==5))

                draw_sprite(terrain0,g->elem[i][j].piece,i*C+1,j*C+1);
                */
                if ((g->outil==4)||(g->outil==5))
                {

                    if ((mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))
//if (((mouse_x+posx-3)/C > 7 )&&((mouse_x+posx+3)/C < 34 ) && ((mouse_y+posy-3)/C> 4 )&&((mouse_y+posy+3)/C< 54 ))
                        if ((g->elem[i][j].etatsol==1)&&(g->elem[i+1][j].etatsol==1)&&(g->elem[i][j+1].etatsol==1)&&(g->elem[i+1][j+1].etatsol==1))
                            if ((mouse_x+posx<TAILLE_X-5*C)&& (mouse_y+posy<TAILLE_Y-5*C)
                                    && (TX+TL<mouse_x) || (((0<mouse_y)&&(mouse_y<TY))||(((TY+TH<mouse_y)&&(mouse_y<600)) )))
                                rect(terrain0,i*C,j*C,(i+2)*C,(j+2)*C,makecol(0,0,0));
                }

                if ((g->outil==3) )
                {if ((mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))
                {
  if ((g->elem[i][j].etatsol==1)&&(g->elem[i+1][j].etatsol==1)&&(g->elem[i][j+1].etatsol==1)&&(g->elem[i+1][j+1].etatsol==1)&&((g->elem[i+2][j].etatsol!=0)||(g->elem[i-1][j].etatsol!=0)||(g->elem[i][j+2].etatsol!=0)||(g->elem[i][j-1].etatsol!=0)))
                            {if ((mouse_x+posx<TAILLE_X-5*C)&& (mouse_y+posy<TAILLE_Y-5*C)
                                    && (TX+TL<mouse_x) || (((0<mouse_y)&&(mouse_y<TY))||(((TY+TH<mouse_y)&&(mouse_y<600)) )))
                                rect(terrain0,i*C,j*C,(i+2)*C,(j+2)*C,makecol(255,0,0));
                            }

                if ((g->elem[i][j].etatsol==1)&&(g->elem[i+1][j].etatsol==1)&&(g->elem[i][j+1].etatsol==1)&&(g->elem[i+1][j+1].etatsol==1)&&((g->elem[i+2][j].etatsol==0)||(g->elem[i-1][j].etatsol==0)||(g->elem[i][j+2].etatsol==0)||(g->elem[i][j-1].etatsol==0)))
                            {if ((mouse_x+posx<TAILLE_X-5*C)&& (mouse_y+posy<TAILLE_Y-5*C)
                                    && (TX+TL<mouse_x) || (((0<mouse_y)&&(mouse_y<TY))||(((TY+TH<mouse_y)&&(mouse_y<600)) )))
                                rect(terrain0,i*C,j*C,(i+2)*C,(j+2)*C,makecol(0,0,0));
                            }



}
                }

                //Affichage des éléments fixes de décor
                /* if ((g->elem[i][j].etatsol==10)||(g->elem[i][j].etatsol==11)||(g->elem[i][j].etatsol==12) || (g->elem[i][j].etatsol==13)
                           || (g->elem[i][j].etatsol==14)|| (g->elem[i][j].etatsol==15)|| (g->elem[i][j].etatsol==16)|| (g->elem[i][j].etatsol==17) || (g->elem[i][j].etatsol==18))
                       {

                     draw_sprite(terrain0,g->elem[i][j].piece,i*C+1,j*C+1);
                      }
                */


                /*



                                //Affichage des éléments de 1 case (eau, maison, chemin)
                                        if (g->elem[i][j].etatsol==4)
                                {
                                    //  draw_sprite(terrain0,images->herbe,i*C+1,j*C+1);
                                    draw_sprite(terrain0,g->elem[i][j].piece,i*C+1,j*C+1);
                                        if ((mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))rect(terrain0,i*C,j*C,(i+1)*C,(j+1)*C,makecol(0,0,0));

                                    }

                                if (g->elem[i][j].etatsol==5)
                            {
                                if ((mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))
                                    {

                                        rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(211,191,103));

                                    }
                                    else
                                    {
                                        if(g->elem[i][j].leadcase== 1)
                                        {


                                            draw_sprite(terrain0,images->herbebig,i*C+1,j*C+1);
                                            draw_sprite(terrain0,images->centrale,i*C+1,j*C+1);



                                        }
                                    }

                                }





                */



            }

        }
    }
    /*
        if (g->niveau==-2)
        {
            for (i=0; i<L; i++)
            {
                for (j=0; j<H; j++)
                {
                    if (g->elem[i][j].etatssol==1)
                    {
                        rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(87,179,227));
                    }

    if (g->elem[i][j].etatssol==99)
                    {
                        rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(70,70,70));
                    }

                    else
                    {
                        rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(255,255,255));
                    }

                        if (g->elem[i][j].etatssol==10)
                    {
                        rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                    }

                    if ( (mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))

                    {
                        rect(terrain0,i*C,j*C,C+i*C,C+j*C,makecol(67,247,226));
                    }
                    else
                    {
                        rect(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                    }



                }
            }
        }
    */


    if (g->niveau==-3)
    {
        for (i=0; i<L; i++)
        {
            for (j=0; j<H; j++)
            {
                if (g->elem[i][j].etatssol==1)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(241,255,59));
                }
                else
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+j*C,makecol(255,255,255));
                }

                if (g->elem[i][j].etatssol==10)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                }



                if ( (mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))

                {
                    rect(terrain0,i*C,j*C,C+i*C,C+j*C,makecol(67,247,226));
                }


                if (g->elem[i][j].etatssol==99)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(50,50,50));
                }



                if (g->elem[i][j].etatsssol==1)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(87,179,227));
                }


                if (g->elem[i][j].etatssol==10)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                }
                if ( (mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))

                {
                    rect(terrain0,i*C,j*C,C+i*C,C+j*C,makecol(67,247,226));
                }

                if (g->elem[i][j].etatsssol==99)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(50,50,50));
                }
else   {
                    rect(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                }



   if ((g->elem[i][j].etatssol==1)&&(g->elem[i][j].etatsssol==1))
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(20,255,20));

                }
if (g->elem[i][j].etatsol!=99)
 rect(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));


            }
        }
    }



    if (g->niveau==-1)
    {
        for (i=0; i<L; i++)
        {
            for (j=0; j<H; j++)
            {
                if (g->elem[i][j].etatssol==1)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(241,255,59));
                }
                else
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+j*C,makecol(255,255,255));
                }

                if (g->elem[i][j].etatssol==10)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                }



                if ( (mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))

                {
                    rect(terrain0,i*C,j*C,C+i*C,C+j*C,makecol(67,247,226));
                }


                if (g->elem[i][j].etatssol==99)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(50,50,50));
                }

                else
                {
                    rect(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                }
  if (g->elem[i][j].etatsssol==99)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(50,50,50));
                }

            }
        }
    }

    if (g->niveau==-2)
    {
        for (i=0; i<L; i++)
        {
            for (j=0; j<H; j++)
            {
                if (g->elem[i][j].etatsssol==1)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(87,179,227));
                }
                else
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(255,255,255));
                }


                if (g->elem[i][j].etatssol==10)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                }
                if ( (mouse_x+posx>C*i)&&(mouse_x+posx<C+1+i*C)&&(mouse_y+posy>j*C)&&(mouse_y+posy<C+1+j*C))

                {
                    rect(terrain0,i*C,j*C,C+i*C,C+j*C,makecol(67,247,226));
                }

                if (g->elem[i][j].etatsssol==99)
                {
                    rectfill(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(50,50,50));
                }


                else
                {
                    rect(terrain0,i*C,j*C,C+1+i*C,C+1+j*C,makecol(0,0,0));
                }



            }
        }
    }

}
/*
void affichage_menu(s_grille* g, BITMAP* terrain0)
{
    //  printf ("\ncoucou::%d\n",g->niveau);

    if (g->niveau==0)
    {
        rectfill(terrain0,g->dx+0,200,g->dx+75,400,makecol(255,255,255));
        rectfill(terrain0,g->dx+25,250,g->dx+50,275,makecol(255,59,59));
        textprintf_ex(terrain0,font,g->dx+25,250,makecol(255,255,255),-1,"r");
        rectfill(terrain0,g->dx+25,200,g->dx+50,225,makecol(255,59,59));
        textprintf_ex(terrain0,font,g->dx+25,200,makecol(255,255,255),-1,"eau");
        rectfill(terrain0,g->dx+25,300,g->dx+50,325,makecol(255,59,59));
        textprintf_ex(terrain0,font,g->dx+25,300,makecol(255,255,255),-1,"m");
        rectfill(terrain0,g->dx+25,350,g->dx+50,375,makecol(255,59,59));
        textprintf_ex(terrain0,font,g->dx+25,350,makecol(255,255,255),-1,"el");
    }

    if (g->niveau==-1)
    {
        rectfill(terrain0,g->dx+0,200,g->dx+75,400,makecol(255,255,255));
        rectfill(terrain0,g->dx+25,250,g->dx+50,275,makecol(255,59,59));
        textprintf_ex(terrain0,font,g->dx+25,250,makecol(255,255,255),-1,"el");

    }

    if (g->niveau==-2)
    {
        rectfill(terrain0,g->dx+0,200,g->dx+75,400,makecol(255,255,255));
        rectfill(terrain0,g->dx+25,250,g->dx+50,275,makecol(255,59,59));
        textprintf_ex(terrain0,font,g->dx+25,250,makecol(255,255,255),-1,"eau");

    }


    if (g->niveau==-2) rectfill(terrain0,g->dx+450,0,g->dx+475,25,makecol(255,59,59));
    else rectfill(terrain0,g->dx+450,0,g->dx+475,25,makecol(0,0,0));
    if (g->niveau==-1) rectfill(terrain0,g->dx+500,0,g->dx+525,25,makecol(255,59,59));
    else  rectfill(terrain0,g->dx+500,0,g->dx+525,25,makecol(0,0,0));
    if (g->niveau==0) rectfill(terrain0,g->dx+550,0,g->dx+575,25,makecol(255,59,59));
    else  rectfill(terrain0,g->dx+550,0,g->dx+575,25,makecol(0,0,0));

    textprintf_ex(terrain0,font,g->dx+500,0,makecol(255,255,255),-1,"-1");
    textprintf_ex(terrain0,font,g->dx+550,0,makecol(241,255,59),-1,"0");
    textprintf_ex(terrain0,font,g->dx+450,0,makecol(255,255,255),-1,"-2");
}
*/
void affichage_animations_hors_grille (BITMAP* terrain0,t_banque*images,t_decors*decors)
{
    draw_sprite(terrain0,images->ferry,decors->ferryx,decors->ferryy);
}
