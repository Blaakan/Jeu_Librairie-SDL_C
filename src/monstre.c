#include "monstre.h"
#include "display.h"

/**
 * \file monstre.c
 * \brief contient les fonctions gérant les monstres
 * */

monstre Combat(monstre m,joueur jro,SDL_Surface * screen, SDL_Surface* HUD[])
{
	SDL_Rect pos;
	pos.x =720; 
	pos.y = 400;
	SDL_BlitSurface(HUD[COMBAT], NULL,screen,&pos);
	while(jro->pv>0 && m->pv >0)
	{
		if (jro->atk > m->def)
			m->pv = m->pv + m->def - jro->atk;
		if (m->atk > jro->def)
			jro->pv = jro->pv + jro->def - m->atk;
		afficheHUD(screen,HUD,jro);
		SDL_Flip(screen);
		SDL_Delay(400);
	}
	if (m->pv <= 0)
	{
		free(m);
		m=NULL;
	}
	return m;
}


void DeplacementMonstre(monstre tabmonstre[NBRMONSTREALEA], grille g)
{
	srand(time(NULL));
	int i,direction;
	for (i=0;i<NBRMONSTREALEA;i++)
	{
		if (tabmonstre[i] != NULL)
		{
			direction = rand()%4;
			switch(direction)
			{
				case 3:
					if( EstDansGrille(g,tabmonstre[i]->rcMonstre.x+1, tabmonstre[i]->rcMonstre.y) && traversable(g.salles[tabmonstre[i]->rcMonstre.y][tabmonstre[i]->rcMonstre.x+1]) )
						tabmonstre[i]->rcMonstre.x++;
					break;
				case 2:
					if( EstDansGrille(g,tabmonstre[i]->rcMonstre.x-1, tabmonstre[i]->rcMonstre.y) && traversable(g.salles[tabmonstre[i]->rcMonstre.y][tabmonstre[i]->rcMonstre.x-1]) )
						tabmonstre[i]->rcMonstre.x--;
					break;
				case 1:
					if( EstDansGrille(g,tabmonstre[i]->rcMonstre.x, tabmonstre[i]->rcMonstre.y+1) && traversable(g.salles[tabmonstre[i]->rcMonstre.y+1][tabmonstre[i]->rcMonstre.x]) )
						tabmonstre[i]->rcMonstre.y++;
					break;
				case 0:
					if( EstDansGrille(g,tabmonstre[i]->rcMonstre.x, tabmonstre[i]->rcMonstre.y-1) && traversable(g.salles[tabmonstre[i]->rcMonstre.y-1][tabmonstre[i]->rcMonstre.x]) )
						tabmonstre[i]->rcMonstre.y--;
					break;
			}
		}
	}
}

void MonstreInit(monstre m, int atk, int def, int pv, int x, int y)
{
	m->atk=atk;
	m->def=def;
	m->pv=pv;
	m->rcMonstre.x=x;
	m->rcMonstre.y=y;
}

void InitialisationMonstres(monstre tabmonstre[], int taille, SDL_Surface * sprmonstre,grille g,joueur jro)
{
	int i;
	SDL_Rect position;
	srand(time(NULL));
	int x,y;
	for (i=0;i<taille;i++)
	{
		x=rand()%g.largeur;
		y=rand()%g.hauteur;
		position.x=x*SPRITE_SIZE;
		position.y=y*SPRITE_SIZE;
		while( !(!VoisinJoueur(jro,position) && (traversable(g.salles[y][x]))) )
		{
			x=rand()%g.largeur;
			y=rand()%g.hauteur;
			position.x=x*SPRITE_SIZE;
			position.y=y*SPRITE_SIZE;
		}
		monstre m=(monstre)malloc(sizeof(str_monstre));
		m->SpriteMonstre=sprmonstre;
		MonstreInit(m,6,5,5,x,y);
		tabmonstre[i]=m;
	}
}

int TousMorts(monstre tabmonstre[NBRMONSTREALEA])
{
	int i;
	for (i=0;i<NBRMONSTREALEA;i++)
	{
		if (tabmonstre[i] != NULL)
			return 0;
	}
	return 1;
}

