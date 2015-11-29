#include "headers.h"

void enfiler_el(s_grille* g,int x,int y,int i,int j)
{
    // créer le nouveau noeud à enfiler
    element* nouveau=(element*)malloc(sizeof(element));
    nouveau->next=NULL;
    nouveau->i=i;
    nouveau->j=j;

    if (g->file_elemel[x][y].taille==0)
      {//printf("hello");
            g->file_elemel[x][y].tete = g->file_elemel[x][y].queue = nouveau ;}
    else
    {
        g->file_elemel[x][y].queue->next = nouveau ;
        g->file_elemel[x][y].queue = nouveau ;
    }
    g->file_elemel[x][y].taille++ ;
   printf("enfile:%d::%d dans %d::%d   taille: %d\n",nouveau->i,nouveau->j,x,y,g->file_elemel[x][y].taille);
}

void enfiler_eau(s_grille* g,int x,int y,int i,int j)
{
    // créer le nouveau noeud à enfiler
    element* nouveau=(element*)malloc(sizeof(element));
    nouveau->next=NULL;
    nouveau->i=i;
    nouveau->j=j;

    if (g->file_elemeau[x][y].taille==0)
      {printf("hello");
            g->file_elemeau[x][y].tete = g->file_elemeau[x][y].queue = nouveau ;}
    else
    {
        g->file_elemeau[x][y].queue->next = nouveau ;
        g->file_elemeau[x][y].queue = nouveau ;
    }
    g->file_elemeau[x][y].taille++ ;
    //printf("enfile:%d::%d dans %d::%d   taille: %d\n",nouveau->i,nouveau->j,x,y,g->file_elemeau[x][y].taille);
}


element *defiler (liste_element* l)   // on suppose que la file n’est pas vide
{
    element* n  = l->tete ; // récupérer le noeud de tete de la liste
    if (l->tete==l->queue)
        l->tete = l->queue = NULL ;
    else
        l->tete = l->tete->next ;
    l->taille-- ;

    return n ;
}

int estVide (liste_element* l)
{
    return l->taille==0 ;
}
