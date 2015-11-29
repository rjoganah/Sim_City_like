#include "headers.h"
void carte(s_grille*g,BITMAP*page, BITMAP*carte,int posx,int posy)
{


//carte=create_bitmap((L/10)*2,(H/10)*2);
int i,j;
for(i=0; i<L; i++)
        {
            for(j=0; j<H; j++)
            {

                if(g->elem[i][j].etatsol==99)rectfill(carte, 2*i,2*j,2*(i+1),2*(j+1),makecol(0,0,255));

                 else  if(g->elem[i][j].etatsol==2)rectfill(carte, 2*i,2*j,2*(i+1),2*(j+1),makecol(255,0,0));

                  else  if(g->elem[i][j].etatsol==3)rectfill(carte, 2*i,2*j,2*(i+1),2*(j+1),makecol(0,0,0));
                  else  if(g->elem[i][j].etatsol==4)rectfill(carte, 2*i,2*j,2*(i+1),2*(j+1),makecol(0,128,255));
                   else  if(g->elem[i][j].etatsol==5)rectfill(carte, 2*i,2*j,2*(i+1),2*(j+1),makecol(255,255,128));

                else rectfill(carte, 2*i,2*j,2*(i+1),2*(j+1),makecol(0,255,128));

            }
        }
 rect(carte,(posx/C)*2,(posy/C)*2,((posx+SCREEN_W)/C)*2,((posy+SCREEN_H)/C)*2,makecol(255,255,255));

 //blit(carte, page, SCREEN_W-2*L,SCREEN_H-2*H, SCREEN_W-2*L, SCREEN_H-2*H, 2*L, 2*H);
 blit(carte, page, 0,0, SCREEN_W-2*L, SCREEN_H-2*H, 2*L, 2*H);

}

