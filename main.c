#include <allegro.h>
#include <time.h>
#include "headers.h"

/// Le contenu entre les commentaires bleus correspond
///à des trucs qui sont actuellement en commentaires
///mais qui sont en fait peut être utile après
///, et donc éventuellement à décommenter

/*UTILISATION

Appuyer sur...
M : plan du terrain en mode consolemm
alt: accélère la vitesse de scrolling

*/


/// FONCTION TIMER///
/* on déclare la variable */

/* Et le timer pour ajuster la vitesse du jeu */
void game_timer(void)
{
    if(game_pause==0)
    game_time++;
}
END_OF_FUNCTION(game_timer);
/// FIN FONCTION TIMER

int main(int argc, char *argv[])
{

// DECLARATIONS DES VARIABLES DU MAIN ///////////////////////////////////////////////////////////

    int i,j;//Coordonnées des cases
    int posx, posy;//position du scrolling
    s_grille*g;// Grille de structures cases
    g=(s_grille*)malloc(sizeof(s_grille));

    g->elem=(element**)malloc(L*sizeof(element*));
    g->file_elemel=(liste_element**)malloc(L*sizeof(liste_element*));
    g->file_elemeau=(liste_element**)malloc(L*sizeof(liste_element*));

    for(i=0; i<L; i++)//Informations sur les cases
    {
         g->elem[i]=(element*)malloc(H*sizeof(element));
    g->file_elemel[i]=(liste_element*)malloc(H*sizeof(liste_element));
    g->file_elemeau[i]=(liste_element*)malloc(H*sizeof(liste_element));
    }
    BITMAP*page=NULL;//Bitmap de double buffer
    BITMAP *accueil;//Bitmap d'accueil
    BITMAP *terrain0;//eau
    BITMAP*minicarte;

    t_banque* images;//Structure banque d'images
    images=(t_banque*)malloc(sizeof(t_banque));

    int teolien;//compteur pour la gestions des animations de décor


    t_decors* decors;//Structure banque d'images
    decors=(t_decors*)malloc(sizeof(t_decors));




// INITIALISATION ALLEGRO + Aléatoire //////////////////////////////////////////////////////////

    allegro_init();
    install_keyboard();
    install_mouse();
    install_timer();

    srand(time(NULL));

// OUVERTURE MODE GRAPHIQUE ///////////////////////////////////////////////////////////////////

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

// AVANT BOUCLE JEU //////////////////////////////////////////////////////////////////////////
    game_pause=1;/// ON DEBUTE LE JEU SUR PAUSE
    posx=0;
    posy=0;
    minicarte=create_bitmap(L*2,H*2);
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    show_mouse(screen);
    int go;
    int intro;

for(i=0; i<L; i++)
    {
        for(j=0; j<H; j++)
        {
            g->elem[i][j].alimeau=0;
            g->elem[i][j].alimel=0;
            g->elem[i][j].alimr=0;
            g->elem[i][j].marque_maison=0;
            g->elem[i][j].habitant=0;
            g->elem[i][j].pif=0;
            g->elem[i][j].marqueur=0;
            g->elem[i][j].age=0;
            g->elem[i][j].marque_eau=0;
            g->elem[i][j].marque_el=0;
            g->elem[i][j].ageDebut=0;
            g->elem[i][j].construite=0;
            g->elem[i][j].habitable=0;
            g->elem[i][j].piece=NULL;





            g->elem[i][j].i=i;
            g->elem[i][j].j=j;
            g->file_elemeau[i][j].i=i;
            g->file_elemeau[i][j].j=j;
            g->elem[i][j].next=NULL;
            g->file_elemeau[i][j].tete=NULL;
            g->file_elemeau[i][j].queue=NULL;
            g->file_elemel[i][j].tete=NULL;
            g->file_elemeau[i][j].queue=NULL;

            g->cmp_el=1;
            g->cmp_eau=1;
            g->cmp_usine=0;
            g->nb_hab=0;

            g->elem[i][j].haut=0;
            g->elem[i][j].bas=0;
            g->elem[i][j].gauche=0;
            g->elem[i][j].droite=0;

        }
        }

//Affichage d'un écran d'accueil pendant le chargement de toutes les images
    accueil=load_bitmap("Images/POKECITY0.bmp",NULL);
    blit(accueil, page,0,0,0,0,SCREEN_W,SCREEN_H);
    blit(page,screen,g->dx,g->dy,0,0,SCREEN_W,SCREEN_H);
    terrain0=create_bitmap(TAILLE_X,TAILLE_Y);

    teolien=0;

    decors->ferryx=2000;
    decors->ferryy=30;


intro=1;
go=0;


///
    /*
        g->dx=0;
        g->dy=0;
    */
///



    chargement(images);
    initialiser_grille(g, images);

/// INITIALISATION DU TIMER //////////////////////////////
    install_timer();
    install_int(game_timer, 1000); /* 1 ms de temps de résolution */
    game_time = 2012;
    int game_timeDebut=0;
    int game_timeFin=0;

    LOCK_FUNCTION(game_timer);
    LOCK_VARIABLE(game_time);


    /// FIN INITIALISATION DU TIMER////////////////////////////////

    //rest(3000);//Laisser le temps de lire l'écran d'accueil

// BOUCLE JEU //////////////////////////////////////////////////////////////////////////////////





while (go==0)
{

if (intro==1)

{
accueil=images->normal;
     if ((mouse_x<330) && (mouse_y>115 )&& (mouse_y<400 ))accueil=images->jouer;


    if ((mouse_x>540) && (mouse_y>420) )  accueil=images->instrus;



}
if (intro==2)
{

    accueil=images->retour;
    if ((mouse_x<220) && (mouse_y>490) )  accueil=images->retourok;


}

if ((mouse_x<220) && (mouse_y>490) &&(mouse_b & 1)&& (intro==2))intro=1;

else{
      if ((mouse_x>540) && (mouse_y>420) &&(mouse_b & 1) && (intro==1))intro=2;
if ((mouse_x<330) && (mouse_y>115 )&& (mouse_y<400 )&&(mouse_b & 1)&& (intro==1))go=1;
}

////////////////////////
/*
    if ((mouse_x>540) && (mouse_y>420) && (intro==1))  accueil=images->instrus;
        if ((mouse_x>540) && (mouse_y>420) && (intro==1)&&(mouse_b & 1))
        {
            accueil=images->retour;
            intro=2;
        }

        if (intro==2)
        {
            if ((mouse_x<220) && (mouse_y>490) && (intro==2))  accueil=images->retourok;
          else  accueil=images->retour;
        }

        if ((mouse_x>220) && (mouse_y>490) && (intro==2)&&(mouse_b & 1))
        {
            accueil=images->normal;
            intro=1;
        }

 if ((mouse_x<330) && (mouse_y>250 )&& (mouse_y<400 )&& (intro==1))accueil=images->jouer;
 if ((mouse_x<330) && (mouse_y>250 )&& (mouse_y<400 )&& (intro==1)&&(mouse_b & 1))go=1;

*/

blit(accueil, page,0,0,0,0,SCREEN_W,SCREEN_H);
 blit(page,screen,g->dx,g->dy,0,0,SCREEN_W,SCREEN_H);
        rest(5);//Temporisation
    //textprintf_ex(screen,font,100,10, makecol(255,0,0),-1,"X : %d    Y : %d   ",mouse_x, mouse_y);
}
















    while (!key[KEY_ESC])
    {
        clear_bitmap(page);//effacer l'écran de double buffer

        teolien=teolien+1;//met à jour le compteur pour les animations du décor
        if (teolien==70) teolien=0;//boucle du compteur (remise à zéro)

        animations(g, images, teolien);//mettre à jour les éléments de décor variants

        decors->ferryx=decors->ferryx+V;
        if ((decors->ferryx)<(-100))decors->ferryx = 2000;




for(i=0; i<L; i++)
        {
            for(j=0; j<H; j++)
            {
                g->elem[i][j].depart_parcour=0;
                g->elem[i][j].alimeau=0;
                g->elem[i][j].alimel=0;

            }}
for(i=0; i<L; i++)
        {
            for(j=0; j<H; j++)
            {


                if((g->elem[i][j].etatsol==4 )&&(g->elem[i][j].depart_parcour==0))
                {
                    parcourirTouteau(g,i,j);
                    g->elem[i][j].depart_parcour=1;
                    g->elem[i+1][j].depart_parcour=1;
                    g->elem[i][j+1].depart_parcour=1;
                    g->elem[i+1][j+1].depart_parcour=1;
                }
                if((g->elem[i][j].etatsol==5)&&(g->elem[i][j].depart_parcour==0))
                {

                    parcourirToutel(g,i,j);
                    g->elem[i][j].depart_parcour=1;
                    g->elem[i+1][j].depart_parcour=1;
                    g->elem[i][j+1].depart_parcour=1;
                    g->elem[i+1][j+1].depart_parcour=1;

                }




            }
        }

        on_click(g, images, posx, posy);//actions lorsque l'utilisateur clique sur le terrain de jeu
        clic_menu(g, posx, posy, images); //actions lorsque l'utilisateur clique sur la barre d'outils

 test_alim_tot(g);
     maj_age(g,images);

     for(i=0; i<L; i++)
        {
            for(j=0; j<H; j++)
            {
              if(g->elem[i][j].etatsol==2)  charge_route(g,i,j,images);

                  if((g->elem[i][j].etatsol==3)&&(g->elem[i][j].habitable==0))
                     {
                         install_maison(g,i,j,images);
                     }

                     if ((g->elem[i][j].alimtot==0)&& (g->elem[i][j].habitable==1))

                     {
                         //printf("test");
                         g->elem[i][j].habitable=0;
                        // g->elem[i][j].etatsol=1;
                        // g->elem[i][j].piece=images->herbe;

                         //detruire(g,i,j,images);
                     }
            }

            }
//printf("etat::%d",g->elem[15][15]->alimtot);


   //  printf("an:%d\n",game_time);
   //  printf("age:%d\n",g->elem[1][1]->age);
// Contrôles clavier
        //Scrolling

        ///Scrolling robin
        /*
        if (key[KEY_ALT])//Vitesse plus rapide
        {
            if (key[KEY_UP]) g->dy=g->dy-15;
            if (key[KEY_LEFT]) g->dx=g->dx-15;
            if (key[KEY_RIGHT]) g->dx=g->dx+15;
            if (key[KEY_DOWN]) g->dy=g->dy+15;
        }
        else //Vitesse par défaut
        {
            if (key[KEY_UP]) g->dy=g->dy-4;
            if (key[KEY_LEFT]) g->dx=g->dx-4;
            if (key[KEY_RIGHT]) g->dx=g->dx+4;
            if (key[KEY_DOWN]) g->dy=g->dy+4;
        }
        */
///


            if ((key[KEY_UP])&&(posy>-1)) posy=posy-25;
            if ((key[KEY_LEFT]) && (posx>-1)) posx=posx-25;
            if ((key[KEY_RIGHT])&& (posx<TAILLE_X-1000)) posx=posx+25;
            if ((key[KEY_DOWN]) && (posy<TAILLE_Y-600)) posy=posy+25;



        if (posx<0) posx=0;
        if (posy<0) posy=0;
        if (posx>TAILLE_X-1000) posx=TAILLE_X-1000;
        if (posy>TAILLE_Y-600) posy=TAILLE_Y-600;

//printf("x: %d, y : %d", posx, posy);
//Autres commandes clavier
        if (key[KEY_SPACE])  carte_console(g);


//Affichage des éléments du jeu sur l'écran de double buffer

        affichage_grille(terrain0,g,images,posx, posy);

       if (g->niveau==0) affichage_animations_hors_grille (terrain0,images,decors);

//        affichage_menu(g,page);


       // draw_sprite(terrain0,images->terrain2,0,0);


        //draw (images->terrain2, terrain0,posx,posy,0,0 ,SCREEN_W,SCREEN_H);
        //Affichage d'une zone limité du terrain
        blit (terrain0, page,posx,posy,0,0 ,SCREEN_W,SCREEN_H);

        draw_sprite(page,images->toolbar,TX,TY);
textprintf_ex(page,font,25,385, makecol(0,0,0),-1,"annee : %d",game_time);
textprintf_ex(page,font,25,400, makecol(0,0,0),-1,"nb hab : %d",g->nb_hab);

if(game_pause==1)
{
    textprintf_ex(page,font,30,145, makecol(0,0,0),-1,"pause");
}
else     textprintf_ex(page,font,30,145, makecol(0,0,0),-1,"play");

if(g->niveau==0)
textprintf_ex(page,font,110,125, makecol(255,255,255),-1,"0");
else  textprintf_ex(page,font,110,125, makecol(0,0,0),-1,"0");
if(g->niveau==-1)
textprintf_ex(page,font,105,155, makecol(241,255,59),-1,"-1");
else  textprintf_ex(page,font,105,155, makecol(0,0,0),-1,"-1");
if(g->niveau==-2)
textprintf_ex(page,font,105,185, makecol(10,10,255),-1,"-2");
else  textprintf_ex(page,font,105,185, makecol(0,0,0),-1,"-2");
if(g->niveau==-3)
textprintf_ex(page,font,125,184, makecol(10,255,15),-1,"-3");
else  textprintf_ex(page,font,125,184, makecol(0,0,0),-1,"-3");

       // if (key[KEY_SPACE]) blit (images->terrain1, page,posx,posy,0,0 ,SCREEN_W,SCREEN_H);
///
//Afficher l'image de l'écran de double buffer sur l'écran réel

carte(g,page,minicarte,posx,posy);
        blit(page,screen,g->dx,g->dy,0,0,SCREEN_W,SCREEN_H);
         rest(5);//Temporisation
        textprintf_ex(screen,font,100,10, makecol(255,0,0),-1,"X : %d    Y : %d   posX : %d    posY : %d   ",mouse_x, mouse_y,mouse_x+posx,mouse_y+posy);
   textprintf_ex(screen,font,100,30, makecol(255,0,0),-1,"case i:%d  j:%d ",(mouse_x+posx)/C,(mouse_y+posy)/C);

  //   if (game_pause==0)printf("PLAY");
   // if (game_pause==1)printf("PAUSE");
//printf("an:%d",game_time);
    }//fin boucle de jeu




    return 0;
}
END_OF_MAIN();
