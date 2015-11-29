#include "headers.h"

void chargement (t_banque* images)
{
images->centrale=load_bitmap("Images/Centrale.bmp",NULL);
images->centrale1=load_bitmap("Images/Centrale1.bmp",NULL);
images->centrale2=load_bitmap("Images/Centrale2.bmp",NULL);
images->centrale3=load_bitmap("Images/Centrale3.bmp",NULL);
images->centrale4=load_bitmap("Images/Centrale4.bmp",NULL);
images->centrale5=load_bitmap("Images/Centrale5.bmp",NULL);
images->centrale6=load_bitmap("Images/Centrale6.bmp",NULL);
images->centrale7=load_bitmap("Images/Centrale7.bmp",NULL);
images->chemin=load_bitmap("Images/Chemin.bmp",NULL);
images->chemin_01=load_bitmap("Images/Chemin_01.bmp",NULL);
images->chemin_02=load_bitmap("Images/Chemin_02.bmp",NULL);
images->chemin_03=load_bitmap("Images/Chemin_03.bmp",NULL);
images->chemin_04=load_bitmap("Images/Chemin_04.bmp",NULL);
images->chemin_05=load_bitmap("Images/Chemin_05.bmp",NULL);
images->chemin_06=load_bitmap("Images/Chemin_06.bmp",NULL);
images->chemin_07=load_bitmap("Images/Chemin_07.bmp",NULL);
images->chemin_08=load_bitmap("Images/Chemin_08.bmp",NULL);
images->chemin_09=load_bitmap("Images/Chemin_09.bmp",NULL);
images->chemin_10=load_bitmap("Images/Chemin_10.bmp",NULL);
images->chemin_11=load_bitmap("Images/Chemin_11.bmp",NULL);
images->eau=load_bitmap("Images/Eau.bmp",NULL);
images->eau1=load_bitmap("Images/Eau1.bmp",NULL);
images->eau2=load_bitmap("Images/Eau2.bmp",NULL);
images->eau3=load_bitmap("Images/Eau3.bmp",NULL);
images->herbe=load_bitmap("Images/Herbe.bmp",NULL);
images->herbebig=load_bitmap("Images/Herbebig.bmp",NULL);
images->hautes_herbes=load_bitmap("Images/Hautesherbes.bmp",NULL);
images->maison_01=load_bitmap("Images/Maison_01.bmp",NULL);
images->maison_02=load_bitmap("Images/Maison_02.bmp",NULL);
images->maison_03=load_bitmap("Images/Maison_03.bmp",NULL);
images->maison_04=load_bitmap("Images/Maison_04.bmp",NULL);
images->maison_05=load_bitmap("Images/Maison_05.bmp",NULL);
images->maison_06=load_bitmap("Images/Maison_06.bmp",NULL);
images->maison_07=load_bitmap("Images/Maison_07.bmp",NULL);
images->maison_08=load_bitmap("Images/Maison_08.bmp",NULL);
images->maison_09=load_bitmap("Images/Maison_09.bmp",NULL);
images->maison_10=load_bitmap("Images/Maison_10.bmp",NULL);
images->maison_11=load_bitmap("Images/Maison_11.bmp",NULL);
images->maison_12=load_bitmap("Images/Maison_12.bmp",NULL);
images->pont_1=load_bitmap("Images/Pont_01.bmp",NULL);
images->pont_2=load_bitmap("Images/Pont_02.bmp",NULL);
images->usine=load_bitmap("Images/Usine_eau.bmp",NULL);
images->magenta=load_bitmap("Images/magenta.bmp",NULL);
//images->terrain1=load_bitmap("Images/terrain1.bmp",NULL);
images->terrain2=load_bitmap("Images/terrain2.bmp",NULL);
images->ferry=load_bitmap("Images/ferry.bmp",NULL);
images->toolbar=load_bitmap("Images/toolbar.bmp",NULL);
images->toolbar2=load_bitmap("Images/toolbar2.bmp",NULL);
images->roche41=load_bitmap("Images/roche41.bmp",NULL);
images->roche42=load_bitmap("Images/roche42.bmp",NULL);
images->roche43=load_bitmap("Images/roche43.bmp",NULL);
images->roche44=load_bitmap("Images/roche44.bmp",NULL);
images->roche45=load_bitmap("Images/roche45.bmp",NULL);
images->roche46=load_bitmap("Images/roche46.bmp",NULL);
images->roche47=load_bitmap("Images/roche47.bmp",NULL);
images->roche48=load_bitmap("Images/roche48.bmp",NULL);
images->roche49=load_bitmap("Images/roche49.bmp",NULL);
images->roche50=load_bitmap("Images/roche50.bmp",NULL);
images->roche51=load_bitmap("Images/roche51.bmp",NULL);
images->roche52=load_bitmap("Images/roche52.bmp",NULL);
images->zonehab1=load_bitmap("Images/zonehab1.bmp",NULL);
images->zonehab4=load_bitmap("Images/zonehab4.bmp",NULL);
images->chantier1=load_bitmap("Images/chantier1.bmp",NULL);
images->chantier4=load_bitmap("Images/chantier4.bmp",NULL);
images->fleurs=load_bitmap("Images/fleurs.bmp",NULL);
images->pont11=load_bitmap("Images/pont11.bmp",NULL);
images->pont12=load_bitmap("Images/pont12.bmp",NULL);
images->pont13=load_bitmap("Images/pont13.bmp",NULL);

	images->jouer=load_bitmap("Images/POKECITY3.bmp",NULL);
images->instrus=load_bitmap("Images/POKECITY2.bmp",NULL);
images->normal=load_bitmap("Images/POKECITY1.bmp",NULL);
images->retour=load_bitmap("Images/POKECITY6ok.bmp",NULL);
images->retourok=load_bitmap("Images/POKECITY5ok.bmp",NULL);

//printf("Chargement terminé");
/*images [3]= load_bitmap("Herbe.txt",NULL);
images [4]= load_bitmap("Herbe.txt",NULL);
images [5]= load_bitmap("Herbe.txt",NULL);
images [6]= load_bitmap("Herbe.txt",NULL);
images [7]= load_bitmap("Herbe.txt",NULL);
images [8]= load_bitmap("Herbe.txt",NULL);
images [9]= load_bitmap("Herbe.txt",NULL);
images [10]= load_bitmap("Herbe.txt",NULL);
images [11]= load_bitmap("Herbe.txt",NULL);
images [12]= load_bitmap("Herbe.txt",NULL);
images [13]= load_bitmap("Herbe.txt",NULL);
images [14]= load_bitmap("Herbe.txt",NULL);
images [15]= load_bitmap("Herbe.txt",NULL);
images [16]= load_bitmap("Herbe.txt",NULL);
images [17]= load_bitmap("Herbe.txt",NULL);
images [18]= load_bitmap("Herbe.txt",NULL);
images [19]= load_bitmap("Herbe.txt",NULL);
images [20]= load_bitmap("Herbe.txt",NULL);
images [21]= load_bitmap("Herbe.txt",NULL);
images [22]= load_bitmap("Herbe.txt",NULL);
images [23]= load_bitmap("Herbe.txt",NULL);
images [24]= load_bitmap("Herbe.txt",NULL);
images [25]= load_bitmap("Herbe.txt",NULL);
images [26]= load_bitmap("Herbe.txt",NULL);
images [27]= load_bitmap("Herbe.txt",NULL);
images [28]= load_bitmap("Herbe.txt",NULL);
images [29]= load_bitmap("Herbe.txt",NULL);
images [30]= load_bitmap("Herbe.txt",NULL);
*/



}
