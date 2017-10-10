#include "joueur.h"
/**  
*\file joueur.c
*\brief Contient les fonctions concernant le joueur
* */
 


void stat_init(joueur jro)
{
	
	int i;
	for(i=0;i<5;i++){
		jro->inventory[i]=0;
	}
	jro->def=3;
	jro->atk=3;
	jro->pv=15;
	jro->pv_max=15;
	
}

int VoisinJoueur(joueur jro,SDL_Rect position)
{
	return position.x/32 >= (jro->rcJoueur.x-1) && position.x/32 <= (jro->rcJoueur.x+1) && position.y/32 >= (jro->rcJoueur.y-1) && position.y/32 <= (jro->rcJoueur.y+1) ;
}
