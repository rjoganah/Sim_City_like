#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

// CONSTANTES #define //////////////////////////////////////////////////////////////////////////

#define L 40 //nb de lignes
#define H 60 //nb de colonnes
#define TAILLE_X 2000
#define TAILLE_Y 3000

#define V -2

#define C 50 //nb de pixel de la longueur d'un côté d'une case

#define TX 0 //coordonnées d'affichage de la toolbar
#define TY 100
#define TL 150//dimension d'affichage de la toolbar
#define TH 400


//DEFINITIONS DES STRUCTURES ////////////////////////////////////////////////////////////////////

volatile int game_time;
volatile int game_pause;

typedef struct element
{
    int i,j;
    int etatsol, etatssol, etatsssol; // quel type d'élement c'est? (maison, herbe, route...)
    int alimeau, alimel, alimr,alimtot;  //booléen alimenté en eau en elec et en route
    int habitant; //si c'est une maison=> nb habitants
    int pif; //si c'est une maison, laquelle ^^
    int marqueur; //marqueur à 1 si la case est la case principale (supérieure gauche) d'une centrale
    struct element*  next; // pointeur sur le voisin suivant
    int age;// age de la ville au moment de la construction
    int ageDebut;//Temps initial du timer
     int marque_eau,marque_el;//marquage pour le parcour de graphe
     int construite; //indique si une maison a fini d'etre construite.
     int habitable;
     int marque_maison;
     int haut,bas,gauche,droite;
    BITMAP*piece;//image dans la case
    int depart_parcour;
} element;

typedef struct decors
{
    int ferryx, ferryy;
}t_decors;

typedef  struct liste_element
{
    int i,j;
    element* tete; // pointeur sur le premier voisin
    element* queue;// pointeur sur le dernier voisin
        int taille;
} liste_element;

typedef struct grille
{
    ///liste_element* file_elem[L][H];
liste_element** file_elemel;
liste_element** file_elemeau;

    element** elem;
    int niveau;
    int outil;
    int dx;
    int dy;
    int an;
    int nb_hab;
    int cmp_usine;
    int cmp_eau;
    int cmp_el;
} s_grille;

typedef struct banque
{
    BITMAP *centrale;
    BITMAP *centrale1;
    BITMAP *centrale2;
    BITMAP *centrale3;
    BITMAP *centrale4;
    BITMAP *centrale5;
    BITMAP *centrale6;
    BITMAP *centrale7;
    BITMAP *chemin;
    BITMAP *chemin_01;
    BITMAP* chemin_02;
    BITMAP* chemin_03;
    BITMAP* chemin_04;
    BITMAP* chemin_05;
    BITMAP* chemin_06;
    BITMAP* chemin_07;
    BITMAP* chemin_08;
    BITMAP* chemin_09;
    BITMAP* chemin_10;
    BITMAP* chemin_11;
    BITMAP* eau;
    BITMAP* eau1;
    BITMAP* eau2;
    BITMAP* eau3;
    BITMAP* hautes_herbes;
    BITMAP* herbe;
    BITMAP* herbebig;
    BITMAP* maison_01;
    BITMAP* maison_02;
    BITMAP* maison_03;
    BITMAP* maison_04;
    BITMAP* maison_05;
    BITMAP* maison_06;
    BITMAP* maison_07;
    BITMAP* maison_08;
    BITMAP* maison_09;
    BITMAP* maison_10;
    BITMAP* maison_11;
    BITMAP* maison_12;
    BITMAP* pont_1;
    BITMAP* pont_2;
    BITMAP* usine;
    BITMAP* magenta;
    BITMAP* terrain0;//océan
  //  BITMAP* terrain1;//carte colision
    BITMAP* terrain2;//décors

     BITMAP* ferry;
     BITMAP* toolbar;
     BITMAP* toolbar2;//carte de collision
     BITMAP* roche41;
     BITMAP* roche42;
     BITMAP* roche43;
     BITMAP* roche44;
      BITMAP* roche45;
       BITMAP* roche46;
        BITMAP* roche47;
         BITMAP* roche48;

    BITMAP* roche49;
    BITMAP* roche50;
    BITMAP* roche51;
    BITMAP* roche52;
          BITMAP* zonehab1;
           BITMAP* zonehab4;
            BITMAP* chantier1;
             BITMAP* chantier4;
                 BITMAP* fleurs;
    BITMAP* pont11;
    BITMAP* pont12;
BITMAP* pont13;
	    BITMAP* jouer;
    BITMAP* retour;
BITMAP* retourok;
    BITMAP* normal;
    BITMAP* instrus;


} t_banque;


///BITMAP* ground(s_grille* g);


// PROTOTYPES DES SOUS-PROGRAMMES ///////////////////////////////////////////////////////////////
void chargement (t_banque*images);
void initialiser_grille(s_grille*g,t_banque*images );
void on_click(s_grille* g,t_banque*images,int posx,int posy);
void carte_console(s_grille*g);
void clic_menu(s_grille*g,int posx, int posy, t_banque*images) ;
void affichage_grille(BITMAP* terrain0, s_grille* g,t_banque*images, int posx, int posy);
//void affichage_grille(BITMAP* page, s_grille* g,t_banque*images, int posx, int posy);
void test_alim(s_grille* g, int i ,int j);
void install_maison(s_grille* g,int i,int j,t_banque*images);
void install_usine(s_grille* g,int i,int j,t_banque*images);
void install_centrale(s_grille* g,int i,int j,t_banque*images);
void animations (s_grille* g,t_banque*images,int teolien);
void affichage_animations_hors_grille (BITMAP* terrain0,t_banque*images,t_decors*decors);

void enfiler_eau(s_grille* g,int x,int y,int i,int j);
void enfiler_el(s_grille* g,int x,int y,int i,int j);
element* defiler (liste_element* l) ;
int estVide (liste_element* l);


void inondereau(s_grille* g, element *ps);
 void parcourirTouteau(s_grille* g, int x,int y);
 void parcourirToutel(s_grille* g, int x, int y);

 void test_alimr(s_grille* g,int i,int j);
 void test_alim_tot(s_grille*g);
void test_alimel(s_grille*g,int i,int j);
void test_alimeau(s_grille*g,int i,int j);

//void carte(s_grille*g, t_banque*images,BITMAP*page, BITMAP*carte,int posx,int posy);
void carte(s_grille*g,BITMAP*page, BITMAP*carte,int posx,int posy);
#endif // HEADERS_H_INCLUDED
