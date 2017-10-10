#include "display.h"

/**
 * \file display.c
 * \brief contient les fonctions gérant l'affichage
 **/ 
void attendreTouche(void)
{
	SDL_Event event;
 
	do
		SDL_WaitEvent(&event);
	while (event.type != SDL_QUIT && event.type != SDL_KEYDOWN);
}

void afficheMonstres(SDL_Surface * screen, monstre tabmonstre[NBRMONSTREALEA], joueur jro)
{
	SDL_Rect position;
	int i;
	for (i=0;i<NBRMONSTREALEA;i++)
	{
		if ( (tabmonstre[i] != NULL) )
		{
			position.x=(tabmonstre[i])->rcMonstre.x*SPRITE_SIZE;
			position.y=(tabmonstre[i])->rcMonstre.y*SPRITE_SIZE;		
			if ( VoisinJoueur(jro,position) )
				SDL_BlitSurface((tabmonstre[i])->SpriteMonstre, NULL, screen, &position);
		}
	}
}


void AffichePartHUD(SDL_Surface * screen, SDL_Surface * sprite, int condition, SDL_Rect * position)
{
	int i;
	for (i=0; i<condition; i++)
	{
		SDL_BlitSurface(sprite,NULL,screen,position);
		position->x+=SPRITE_SIZE;
	}
}

void afficheHUD(SDL_Surface* screen, SDL_Surface* HUD[],joueur jro){
	SDL_Rect pos;
	int i;
	pos.x=648;
	pos.y=10;
	SDL_Rect * position=&pos;
	AffichePartHUD(screen,HUD[PV],(jro->pv)/3,position);

	AffichePartHUD(screen,HUD[SANSPV],((jro->pv_max)-(jro->pv))/3,position);
	
	pos.x = 648;
	pos.y+=10+SPRITE_SIZE;
	AffichePartHUD(screen,HUD[JaugeATK],jro->atk/3,position);

	pos.x=648;
	pos.y+=10+SPRITE_SIZE;
	AffichePartHUD(screen,HUD[JaugeDEF],jro->def/3,position);

	pos.y+=10+SPRITE_SIZE;
	pos.x=648;
	for(i=0;i<5;i++){
		switch(jro -> inventory[i]){
			case 5:
				
				SDL_BlitSurface(HUD[ItemATK],NULL, screen, &pos);
				pos.y +=SPRITE_SIZE;
				break;
			case 7:
				SDL_BlitSurface(HUD[ItemVIE], NULL, screen, &pos);
				pos.y += SPRITE_SIZE;
				break;
			case 8:
				SDL_BlitSurface(HUD[ItemDEF], NULL, screen, &pos);
				pos.y+=SPRITE_SIZE;
				break;
			default:
				break;
		}
	}	
}

void refresh(SDL_Surface* screen,SDL_Surface* fond,joueur jro,SDL_Surface* HUD[]){
	SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
	SDL_Rect pos;
	pos.x =0 ;
	pos.y =0 ;
	SDL_BlitSurface(fond,NULL,screen,&pos);	
	afficheHUD(screen,HUD,jro);
}

void disp_map(SDL_Surface* screen,grille g,SDL_Surface* decor[])
{
	int i,j;
	SDL_Rect position;
	for (i = 0;i<640/SPRITE_SIZE;i++)
	{
		for (j = 0;j<640/SPRITE_SIZE;j++)
		{
			position.x = i * SPRITE_SIZE;
			position.y = j * SPRITE_SIZE;
			SDL_BlitSurface(decor[g.salles[j][i]], NULL, screen, &position);
		}
	}
}

void affiche_toolbox(SDL_Surface * screen, SDL_Rect tab[], SDL_Surface * decor[],SDL_Surface * spritejoueur)
{
	int i;
	for (i=0;i<10;i++)
	{
		SDL_BlitSurface(decor[i+1], NULL, screen, &tab[i]);
	}
	SDL_BlitSurface(spritejoueur, NULL, screen, &tab[10]);
}


void refresh_fog(SDL_Surface * screen,grille fog, grille g,SDL_Surface* decor[], joueur jro,SDL_Surface * ecran[], monstre tabmonstre[NBRMONSTREALEA],SDL_Surface *HUD[])
{
	SDL_Rect position;
	int i,j;
	for (i=0;i<fog.hauteur;i++)
	{
		for (j=0;j<fog.largeur;j++)
		{
			position.x=i*SPRITE_SIZE;
			position.y=j*SPRITE_SIZE;
			if( (fog.salles[j][i]) == -2 )
				SDL_BlitSurface(ecran[FOG1], NULL, screen, &position);
			else
			{
				if ( VoisinJoueur(jro,position) )
				{
					if (!(fog.salles[j][i]))
						SDL_BlitSurface(ecran[FONDFOG2], NULL, screen, &position); 
					else
						SDL_BlitSurface(decor[g.salles[j][i]], NULL, screen, &position);
				}
				else 
				{
					if (!(fog.salles[j][i]))
						SDL_BlitSurface(ecran[FONDFOG2], NULL, screen, &position); 
					else
						SDL_BlitSurface(decor[fog.salles[j][i]], NULL, screen, &position);
					SDL_BlitSurface(ecran[FOG2], NULL, screen, &position);
				}
			}
		}
	}
	position.x = jro->rcJoueur.x * SPRITE_SIZE;
	position.y = jro->rcJoueur.y * SPRITE_SIZE;
	SDL_BlitSurface(jro->regardAct, NULL, screen, &position);
	afficheMonstres(screen,tabmonstre,jro); 
	for (i=0;i<NBRMONSTREALEA;i++)
	{
		if ( tabmonstre[i] != NULL && jro->rcJoueur.x==tabmonstre[i]->rcMonstre.x && jro->rcJoueur.y==tabmonstre[i]->rcMonstre.y )
			tabmonstre[i]=Combat(tabmonstre[i],jro,screen,HUD);
	}
}


void cases_adja(SDL_Surface * screen, grille fog, grille g,joueur jro, SDL_Surface* decor[], SDL_Surface * ecran[], monstre tabmonstre[NBRMONSTREALEA],SDL_Surface *HUD[])
{
	int i,j;
	for (i=0;i<fog.hauteur;i++)
	{
		for (j=0;j<fog.largeur;j++)
		{
			if ( EstDansGrille(fog,jro->rcJoueur.x,jro->rcJoueur.y+1) )
				fog.salles[jro->rcJoueur.y+1][jro->rcJoueur.x]=g.salles[jro->rcJoueur.y+1][jro->rcJoueur.x];
			if ( EstDansGrille(fog,jro->rcJoueur.x+1,jro->rcJoueur.y+1) )
				fog.salles[jro->rcJoueur.y+1][jro->rcJoueur.x+1]=g.salles[jro->rcJoueur.y+1][jro->rcJoueur.x+1];
			if ( EstDansGrille(fog,jro->rcJoueur.x+1,jro->rcJoueur.y) )
				fog.salles[jro->rcJoueur.y][jro->rcJoueur.x+1]=g.salles[jro->rcJoueur.y][jro->rcJoueur.x+1];
			if ( EstDansGrille(fog,jro->rcJoueur.x+1,jro->rcJoueur.y-1) )
				fog.salles[jro->rcJoueur.y-1][jro->rcJoueur.x+1]=g.salles[jro->rcJoueur.y-1][jro->rcJoueur.x+1];
			if ( EstDansGrille(fog,jro->rcJoueur.x,jro->rcJoueur.y-1) )
				fog.salles[jro->rcJoueur.y-1][jro->rcJoueur.x]=g.salles[jro->rcJoueur.y-1][jro->rcJoueur.x];
			if ( EstDansGrille(fog,jro->rcJoueur.x-1,jro->rcJoueur.y-1) )
				fog.salles[jro->rcJoueur.y-1][jro->rcJoueur.x-1]=g.salles[jro->rcJoueur.y-1][jro->rcJoueur.x-1];
			if ( EstDansGrille(fog,jro->rcJoueur.x-1,jro->rcJoueur.y) )
				fog.salles[jro->rcJoueur.y][jro->rcJoueur.x-1]=g.salles[jro->rcJoueur.y][jro->rcJoueur.x-1];
			if ( EstDansGrille(fog,jro->rcJoueur.x-1,jro->rcJoueur.y+1) )
				fog.salles[jro->rcJoueur.y+1][jro->rcJoueur.x-1]=g.salles[jro->rcJoueur.y+1][jro->rcJoueur.x-1];
				
				fog.salles[jro->rcJoueur.y][jro->rcJoueur.x]=g.salles[jro->rcJoueur.y][jro->rcJoueur.x];
		}
	}
	refresh_fog(screen,fog,g,decor,jro,ecran,tabmonstre,HUD);
}
