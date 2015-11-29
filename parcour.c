#include "headers.h"


void parcourirTouteau(s_grille* g, int x,int y)
{
    liste_element *file = (liste_element*)malloc(sizeof(liste_element));// liste finale des noeuds de la file d'attente
    element *s = (element*)malloc(sizeof(element));
    element *ps = (element*)malloc(sizeof(element));
    element*p = (element*)malloc(sizeof(element)); // noeuds du chemin
    int i,j;
    int ii,jj;
    int compteur=500;/// LIMITE pour le dessalement

    ps=&g->elem[x][y];

    //on met toutes les marques à zero
    for(i=0; i<L; i++)
    {
        for(j=0; j<H; j++)
        {
            if(g->elem[i][j].etatsssol==1)
                g->elem[i][j].marque_eau=0;
        }
    }

    //  on alloue la liste, on enfile le premier noeud dans la liste
    file->queue=file->tete=NULL;
    file->taille=0;
//    enfiler(g,file, ps);
////////////////////////////////////////////////////////////////////////////////////////////
    element* nouveau=(element*)malloc(sizeof(element));
    nouveau->next=NULL;
    nouveau->i=ps->i;
    nouveau->j=ps->j;

    if (file->taille==0)
        file->tete = file->queue = nouveau ;
    else
    {
        file->queue->next = nouveau ;
        file->queue = nouveau ;
    }
    file->taille++ ;
    /////////////////////////////////////////////////////////////////////////////////////////////
    // si le noeud de départ ps n'a pas de voisin, retourner la liste qui ne contient que ce noeud
    /* if (g->[ps->i][ps->j]==NULL)
       return ;
    */
    // marquer le noeud de départ ps
    g->elem[ps->i][ps->j].marque_eau = 1;
    g->elem[ps->i][ps->j].alimeau= 1;//on dit que la canalisation est alimentée en eau

    // tant que la file d'attente n'est pas vide et que le noeud out n'est pas atteint
    while (!estVide(file) && compteur>0)
    {
//printf("passage\n");
        s = defiler(file); // défiler le premier noeud de la liste
        // printf("defiler: %d::%d\n",s->i,s->j);
        //  si le noeud défilé arrive au noeud de sortie out (s'il existe), on sort
//printf("taille:%d\n",g->file_elemeau[s->i][s->j].taille);
        // le noeud défilé n'est pas out, enfiler ses voisins non marqués
        if (&g->elem[s->i][s->j] != NULL && (g->file_elemeau[s->i][s->j].taille!=0))
        {
            //printf("passage\n");

            for(p = g->file_elemeau[s->i][s->j].tete ; p != NULL  ; p = p->next)
            {
                if (g->elem[p->i][p->j].marque_eau==0)
                {
                    // printf("coucou%d::%d",p->i,p->j);
////////////////////////////////////////////////////////////////////////////////////////////////////////
                    element* nouveau=(element*)malloc(sizeof(element));
                    nouveau->next=NULL;
                    nouveau->i=p->i;
                    nouveau->j=p->j;

                    if (file->taille==0)
                        file->tete = file->queue = nouveau ;
                    else
                    {
                        file->queue->next = nouveau ;
                        file->queue = nouveau ;
                    }
                    file->taille++ ; // empiler le noeud voisin dans la liste
/////////////////////////////////////////////////////////////////////////////////////////////////
                    ///VERIFICATION DES MAISONS AUX ALENTOURS DE LA CASE D'EAU
                    if(compteur>0)
                     {
                        int temp=0;
                        for(ii=-5; ii<6; ii++)
                        {
                            for(jj=-temp; jj<temp+1; jj++)
                            {
                                if((g->elem[p->i+jj][p->j+ii].etatsol==3)&&(p->i+jj<L)&&(p->j+ii<H)&&(p->i+jj>0)&&(p->j+ii>0)&&(g->elem[p->i+jj][p->j+ii].alimeau==0))
                                {
                                    g->elem[p->i+jj][p->j+ii].alimeau=1;
                                    compteur=compteur-g->elem[p->i+jj][p->j+ii].habitant; /// On décrémente le compteur
                                    printf("alim_maison eau");
                                }
                            }
                            if(ii<0) temp++;
                            else temp--;



                        }
                    }

                      /*  for(ii=0; ii<5; ii++)
                        {

                            if((g->elem[p->i+ii][p->j].etatsol==3)&&(p->i+ii<40)&&(g->elem[p->i+ii][p->j].alimeau==0))//3 conditions : La case est une maison, blindage i
                            {
                                printf("alim_maison");
                                //Et la maison n'est pas encore alimentée
                                g->elem[p->i+ii][p->j].alimeau=1;/// La maison est connectée à la canalisation
                                compteur=compteur-g->elem[p->i+ii][p->j].habitant; /// On décrémente le compteur


                            }
                            if((g->elem[p->i-ii][p->j].etatsol==3)&&(i-ii>0)&&(g->elem[p->i-ii][p->j].alimeau==0))
                            {
                                printf("alim_maison");
                                g->elem[p->i-ii][p->j].alimeau=1;
                                compteur=compteur-g->elem[p->i-ii][p->j].habitant; /// On décrémente le compteur


                            }
                            if((g->elem[p->i][p->j-ii].etatsol==3)&&(p->j-ii>0)&&(g->elem[p->i][p->j-ii].alimeau==0))
                            {
                                printf("alim_maison");
                                g->elem[p->i][p->j-ii].alimeau=1;
                                compteur=compteur-g->elem[p->i][p->j-ii].habitant; /// On décrémente le compteur


                            }
                            if((g->elem[p->i][p->j+ii].etatsol==3)&&(p->j+ii<40)&&(g->elem[p->i][p->j+ii].alimeau==0))
                            {
                                printf("alim_maison");
                                g->elem[p->i][p->j+ii].alimeau=1;
                                compteur=compteur-g->elem[p->i][p->j+ii].habitant; /// On décrémente le compteur


                            }


                        }*/


                        /// FIN de vérification des maisons autour de la case

                    g->elem[p->i][p->j].marque_eau = 1; // marquer le noeud du noeud voisin

                    g->elem[p->i][p->j].alimeau= 1;//on dit que la canalisation est alimentée en eau

                }
                // printf("coucou\n");
// soprintf("voisinsuiv:%d::%d\n",p->next->i,p->next->j);

            }
        }



    }


}

void parcourirToutel(s_grille* g, int x, int y)
{
    liste_element *file = (liste_element*)malloc(sizeof(liste_element));// liste finale des noeuds de la file d'attente
    element *s = (element*)malloc(sizeof(element));
    element *ps = (element*)malloc(sizeof(element));
    element*p = (element*)malloc(sizeof(element)); // noeuds du chemin
    int i,j;
    int ii,jj;
    int compteur=500;
    ps=&g->elem[x][y];

    //on met toutes les marques à zero
    for(i=0; i<L; i++)
    {
        for(j=0; j<H; j++)
        {
            if(g->elem[i][j].etatssol==1)
                g->elem[i][j].marque_el=0;
        }
    }

    //  on alloue la liste, on enfile le premier noeud dans la liste
    file->queue=file->tete=NULL;
    file->taille=0;
    /////////////////////////////////////////////////////////////////////////////////////////////
    element* nouveau=(element*)malloc(sizeof(element));
    nouveau->next=NULL;
    nouveau->i=ps->i;
    nouveau->j=ps->j;

    if (file->taille==0)
        file->tete = file->queue = nouveau ;
    else
    {
        file->queue->next = nouveau ;
        file->queue = nouveau ;
    }
    file->taille++ ;
////////////////////////////////////////////////////////////////////////////////////////////////////
    // si le noeud de départ ps n'a pas de voisin, retourner la liste qui ne contient que ce noeud
    /* if (g->[ps->i][ps->j]==NULL)
       return ;*/


    // marquer le noeud de départ ps
    g->elem[ps->i][ps->j].marque_el = 1;
    g->elem[ps->i][ps->j].alimel= 1;//on dit que la canalisation est alimentée en eau

    // tant que la file d'attente n'est pas vide et que le noeud out n'est pas atteint
    while (!estVide(file) && compteur>0)
    {
        //printf("passage\n");
        s = defiler(file); // défiler le premier noeud de la liste
        //  si le noeud défilé arrive au noeud de sortie out (s'il existe), on sort



        // le noeud défilé n'est pas out, enfiler ses voisins non marqués
        if (&g->elem[s->i][s->j] != NULL && (g->file_elemel[s->i][s->j].taille!=0))

            for(p = g->file_elemel[s->i][s->j].tete ; p!= NULL  ; p = p->next)
            {

                if (g->elem[p->i][p->j].marque_el==0)
                {
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    element* nouveau=(element*)malloc(sizeof(element));
                    nouveau->next=NULL;
                    nouveau->i=p->i;
                    nouveau->j=p->j;

                    if (file->taille==0)
                        file->tete = file->queue = nouveau ;
                    else
                    {
                        file->queue->next = nouveau ;
                        file->queue = nouveau ;
                    }
                    file->taille++ ;  // empiler le noeud voisin dans la liste
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//printf("enf%d::%d\n",p->i,p->j);
                    ///VERIFICATION DES MAISONS AUX ALENTOURS DE LA CASE D' ELEC

                    if(compteur>0)
                    {
                        int temp=0;
                        for(ii=-3; ii<4; ii++)
                        {
                            for(jj=-temp; jj<temp+1; jj++)
                            {
                                if((g->elem[p->i+jj][p->j+ii].etatsol==3)&&(p->i+jj<L)&&(p->j+ii<H)&&(p->i+jj>0)&&(p->j+ii>0)&&(g->elem[p->i+jj][p->j+ii].alimel==0))
                                {
                                    g->elem[p->i+jj][p->j+ii].alimel=1;
                                    compteur=compteur-g->elem[p->i+jj][p->j+ii].habitant; /// On décrémente le compteur
                                    printf("alim_maison el");
                                }
                            }
                            if(ii<0) temp++;
                            else temp--;



                        }
                    }


                    /*  for(ii=0; ii<3; ii++)
                      {//printf("passage\n");

                          if((g->elem[p->i+ii][p->j].etatsol==3)&&(p->i+ii<L)&&(g->elem[p->i+ii][p->j].alimel==0))//3 conditions : La case est une maison, blindage i
                          {printf("passage%d",compteur);
                              //Et la maison n'est pas encore alimentée
                              g->elem[p->i+ii][p->j].alimel=1;/// La maison est connectée à la canalisation
                              compteur=compteur-g->elem[p->i+ii][p->j].habitant; /// On décrémente le compteur


                          }
                          if((g->elem[p->i-ii][p->j].etatsol==3)&&(i-ii>0)&&(g->elem[p->i-ii][p->j].alimel==0))
                          {printf("passage%d",compteur);
                              g->elem[p->i-ii][p->j].alimel=1;
                              compteur=compteur-g->elem[p->i-ii][p->j].habitant; /// On décrémente le compteur


                          }
                          if((g->elem[p->i][p->j-ii].etatsol==3)&&(p->j-ii>0)&&(g->elem[p->i][p->j-ii].alimel==0))
                          {printf("passage%d",compteur);
                              g->elem[p->i][p->j-ii].alimel=1;
                              compteur=compteur-g->elem[p->i][p->j-ii].habitant; /// On décrémente le compteur


                          }
                          if((g->elem[p->i][p->j+ii].etatsol==3)&&(p->j+ii<H)&&(g->elem[p->i][p->j+ii].alimel==0))
                          {printf("passage%d",compteur);
                              g->elem[p->i][p->j+ii].alimel=1;
                              compteur=compteur-g->elem[p->i][p->j+ii].habitant; /// On décrémente le compteur


                          }


                      }*/
                    /// FIN de vérification des maisons autour de la case

                    g->elem[p->i][p->j].marque_el = 1; // marquer le noeud du noeud voisin
                    //p->marque = 1; // marquer le noeud du noeud voisin

                    g->elem[p->i][p->j].alimel= 1;//on dit que la canalisation est alimentée en eau

                }
                //   printf("coucou\n");


            }



    }

}

