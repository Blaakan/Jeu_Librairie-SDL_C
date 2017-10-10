#include "load_elements.h"

/**
 *\file load_elements.c
 *\brief contient les fonctions gérant le chargement des éléments
 * */ 


void chargement_sprites_perso(SDL_Surface *Mage[],int color){
	int i;
	SDL_Surface *temp = NULL;
	temp = IMG_Load("./sprites/Joueur/perso_face.png");
	Mage[BAS] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	temp   = IMG_Load("./sprites/Joueur/perso_dos.png");
	Mage[HAUT] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	temp   = IMG_Load("./sprites/Joueur/perso_gauche.png");
	Mage[GAUCHE] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	temp   = IMG_Load("./sprites/Joueur/perso_droite.png");
	Mage[DROITE] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);		
	for(i=0;i<SPMAGE;i++){
		SDL_SetColorKey(Mage[i],SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
	}
}


void charger_sprites_HUD(SDL_Surface *interface[],int color){
	int i;
	SDL_Surface *temp = NULL;
	temp = IMG_Load("./sprites/HUD/inventatk.png");
	interface[ItemATK] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	temp   = IMG_Load("./sprites/HUD/inventvie.png");
	interface[ItemVIE] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	temp   = IMG_Load("./sprites/HUD/inventdef.png");
	interface[ItemDEF] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	temp   = IMG_Load("./sprites/HUD/jaugeatk.png");
	interface[JaugeATK] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);		
	temp   = IMG_Load("./sprites/HUD/jaugedef.png");
	interface[JaugeDEF] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);		
	
	temp   = IMG_Load("./sprites/HUD/vie.png");
	interface[PV] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	
	
	temp   = IMG_Load("./sprites/HUD/sansvie.png");
	interface[SANSPV] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
		
	temp   = IMG_Load("./sprites/HUD/combat.png");
	interface[COMBAT] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	
		
	for(i=0;i<SPHUD;i++){
		SDL_SetColorKey(interface[i],SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
	}
}


void charger_sprites_decor(SDL_Surface *load[],int color){	
	SDL_Surface *temp =NULL;	
	int i;
		
	//Chargement du sprite mur
	temp   = IMG_Load("./sprites/Decors/wall.jpg");
	load[1] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	

	//chargement sprite case 2
	temp   = IMG_Load("./sprites/Decors/flame.png");
	load[2] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	//chargement sprite case 3
	temp   = IMG_Load("./sprites/Decors/mur_elect.png");
	load[3] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	//chargement sprite case soin
	temp   = IMG_Load("./sprites/Decors/soin.png");
	load[4] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	//chargement sprite case atk+
	temp   = IMG_Load("./sprites/Items/attaque_plus.png");
	load[5] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	//chargement sprite cases tournantes
	temp   = IMG_Load("./sprites/Decors/salletournante6.png");
	load[6]= SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	temp   = IMG_Load("./sprites/Decors/salletournante9.png");
	load[9]= SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	//chargement sprite case def+
	temp   = IMG_Load("./sprites/Items/defense_plus.png");
	load[8] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	//chargement sprite case pv+
	temp   = IMG_Load("./sprites/Items/pv_plus.png");
	load[7] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	//chargement case win
	temp   = IMG_Load("./sprites/Decors/win.png");
	load[10] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	//chargement monstre immo
	temp   = IMG_Load("./sprites/Decors/monstreimmo.png");
	load[11] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	for(i=1;i<SPDECOR;i++){
		SDL_SetColorKey(load[i], SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
	}
	
}

void chargement_sprites_ecran(SDL_Surface *ecran[]){
	
	SDL_Surface *temp = NULL;
	
	temp  = IMG_Load("./ecran/fond.png");
	ecran[FONDFOG1] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	
	
    temp   = IMG_Load("./ecran/fond.bmp"); //FOND POUR LE FOG
	ecran[FONDFOG2] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	
	
	temp   = IMG_Load("./ecran/fog.png");
	ecran[FOG1] =SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	
	
	temp   = IMG_Load("./ecran/fog2.png");
	ecran[FOG2] =SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
		
	temp  = IMG_Load("./ecran/pause.png");
	ecran[PAUSE] = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	

		
	SDL_SetAlpha(ecran[FOG2], SDL_SRCALPHA, 128); //TRANSPARENT POUR LE FOG
}

void loadAll(SDL_Surface* darkMage[],SDL_Surface* decor[],SDL_Surface* HUD[],SDL_Surface* Ecran[],int color){

	chargement_sprites_perso(darkMage,color);
	charger_sprites_decor(decor,color);
	charger_sprites_HUD(HUD,color);
	chargement_sprites_ecran(Ecran);
}

void freeTableauSprite(SDL_Surface* tab[],int i){
	int j=0;
	for(j=0;j<i;j++){
		if (tab[j] != NULL)	SDL_FreeSurface(tab[j]);
	}
}

void free_all(SDL_Surface* decor[],SDL_Surface* darkMage[],SDL_Surface* HUD[],joueur jro,grille g,grille fog,SDL_Surface* Ecran[]){
	freeTableauSprite(decor,SPDECOR);
	freeTableauSprite(darkMage,SPMAGE);
	freeTableauSprite(HUD,SPHUD);
	freeTableauSprite(Ecran,SPECRAN);	
    free(jro);
    desaloue_grille(g);
    desaloue_grille(fog);
    SDL_EnableKeyRepeat(0, 0);
}

void free_monstrealea(monstre tabmonstre[NBRMONSTREALEA])
{
	int i;
	for(i=0;i<NBRMONSTREALEA;i++)
	{
		if(tabmonstre[i] != NULL) 
		free(tabmonstre[i]);
	}
	
}

void free_all_editeur(SDL_Surface *decor[], grille g, SDL_Surface * perso, SDL_Surface * menu, SDL_Surface * fond){
	freeTableauSprite(decor,SPDECOR);
	SDL_FreeSurface(perso);
	SDL_FreeSurface(menu);
	SDL_FreeSurface(fond);
    desaloue_grille(g);
    SDL_EnableKeyRepeat(0, 0);
}

