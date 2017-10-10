#include "editeur.h"

/**
 * \file editeur.c
 * \brief contient toutes les fonctions gérant l'editeur de niveau
 * */ 
grille ChargerFichierEdit(int * a, int * b)
{
	FILE*  fichier = NULL;
	fichier = fopen("grille.txt","r");
	int i=0;
	int j;
	if (fichier == NULL){		
		perror("Error :");
		exit(-1);
	}		
	int n,m,x1,y1;
    fscanf(fichier,"%d %d %d %d",&n,&m,&x1,&y1); 
    grille g=creer_grille(n,m);
    *a=x1;
	*b=y1;
    int type_salle;
    while (i<n){				
		for (j=0;j<m;j++){
			fscanf(fichier,"%d ",&type_salle);
			g.salles[i][j]=type_salle;
		}
		i++;
	}
    fclose(fichier); 
	return g;
}

void SauvegardeGrille(grille g, SDL_Rect perso)
{
	int i,j;
	FILE*  fichier = NULL;
	fichier = fopen("test.txt","w+");
	if (fichier == NULL)		
	{
		perror("Error :");
		return;
	}
	else
	{
		fprintf(fichier,"%d %d\n",g.hauteur,g.largeur);
		fprintf(fichier,"%d %d\n",perso.x/32,perso.y/32);
		for (i=0;i<g.hauteur;i++)
		{
			for (j=0;j<g.largeur;j++)
			{
				fprintf(fichier,"%d ",g.salles[i][j]);
			}
			fputc(13,fichier); 
		}
	}
	fclose(fichier);
}

int ChargerSprite(int xc, int yc,SDL_Rect tab[])
{
	int i,j,k;
	for (i=0;i<11;i++)
	{
		for(j=0;j<SPRITE_SIZE;j++)
		{
			for(k=0;k<SPRITE_SIZE;k++)
			{
				if(tab[i].x+j==xc && tab[i].y+k==yc)
				{
					return i;
				}
			}
		}
	}
	return -1;
}

int PlacementPossible(SDL_Rect position, grille g)
{
	int cond1 = !(position.y/32 == 0 || position.y/32 == g.hauteur-1 || position.x/32 == 0 || position.x/32 == g.largeur-1);
	int cond2 = 1;
	int i,j;
	for (i=position.x/32-1;i<position.x/32+2;i++)
	{
		for (j=position.y/32-1;j<position.y/32+2;j++)
		{
			if (EstDansGrille(g,i,j) && !(j==position.y/32 && i==position.x/32) )
			{
				if(g.salles[j][i] == 6 || g.salles[j][i] == 9)
					cond2=0;
			}
		}
	}
	return (cond2 && cond1);
}

grille PlacerSprite(grille g, SDL_Rect position, int testsprite, SDL_Rect * RCPERSO)
{
	switch(testsprite+1){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 7:
		case 8:
		case 10:
			g.salles[position.y/32][position.x/32]=testsprite+1;
			break;
		case 6:
			if ( PlacementPossible(position,g) )
				{
					g.salles[position.y/32][position.x/32]=6;
				}
			break;
		case 9:
			if ( PlacementPossible(position,g) )
				{
					g.salles[position.y/32][position.x/32]=9;
				}
			break;
		case 11:
			if ( g.salles[position.y/32][position.x/32] == 0 )
			{
				RCPERSO->x=position.x/32*32;
				RCPERSO->y=position.y/32*32;
			}
			break;
		default:
			break;
	}
	
	return g;
}

void editeur(SDL_Surface *screen)
{
	
	SDL_Surface *menu = NULL,*tmp=NULL,*perso=NULL;
    SDL_Surface *decor[11]={NULL},*fond=NULL;
    SDL_Rect rcMenu,rcPersoGrille, position;    
    SDL_Rect tabRc[11];
	grille g;
	int * a= (int*)malloc(sizeof(int));
	int * b = (int*)malloc(sizeof(int));
	g=creer_grille(20,20);

    SDL_Event event;
  	int colorkey = SDL_MapRGB(screen->format, 255, 0, 255),continuer=1,i,testsprite=-1;

    SDL_WM_SetCaption("Editeur de niveau","Editeur de niveau");
    
    charger_sprites_decor(decor,colorkey);
	tmp = IMG_Load("./sprites/Editeur/caseedit.png");
	decor[0] = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);


	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

	tmp = IMG_Load("./ecran/menu_edit.png");
	menu = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	
	tmp = IMG_Load("./sprites/Editeur/caseedit.png");
	fond = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	
	tmp = IMG_Load("./sprites/Joueur/perso_face.png");
	perso = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	
	tabRc[0].x=650;
	tabRc[0].y=10;
	
	rcPersoGrille.x=0;
	rcPersoGrille.y=0;
	SDL_Rect * RCPERSO = &rcPersoGrille;
	
    rcMenu.x = 89; 
    rcMenu.y = 0;


	for(i=1;i<11;i++){
		tabRc[i].x = tabRc[i-1].x;
		tabRc[i].y= tabRc[i-1].y+10+SPRITE_SIZE;
	}
	
	  
	
    while(continuer)
    {
		while( SDL_PollEvent(&event) )
		{

			switch(event.type)
			{
				case SDL_QUIT:
					continuer = 0;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_m:
							SDL_BlitSurface(menu, NULL, screen, &rcMenu);
							SDL_Flip(screen);
							attendreTouche();
							break;
						case SDLK_q:
						case SDLK_ESCAPE:
							continuer = 0;
							break;
						case SDLK_s:
							SauvegardeGrille(g,rcPersoGrille);
							break;
						case SDLK_c:
							desaloue_grille(g);
							g=ChargerFichierEdit(a,b);
							rcPersoGrille.x=(*a)*SPRITE_SIZE;
							rcPersoGrille.y=(*b)*SPRITE_SIZE;
							break;
						case SDLK_n:
							desaloue_grille(g);
							g=creer_grille(20,20);
							rcPersoGrille.x=0;
							rcPersoGrille.y=0;
							break;
						default:
							break;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					switch(event.button.button)
					{
						case SDL_BUTTON_LEFT:
							if (event.button.x>=640)
							{
								testsprite=ChargerSprite(event.button.x,event.button.y,tabRc);
							}
							else
							{
								if ( event.button.x/32 != rcPersoGrille.x/32 || event.button.y/32 != rcPersoGrille.y/32 )
									{
										position.x=event.button.x;
										position.y=event.button.y;
										g=PlacerSprite(g,position,testsprite,RCPERSO);
									}
							}
							break;
						case SDL_BUTTON_RIGHT:
							if (event.button.x<=640)
							{
								position.x=event.button.x;
								position.y=event.button.y;
								g.salles[position.y/32][position.x/32]=0;
							}
							break;
					}// fin du switch sur la touche de souris
					break; //fin case CLICK MOUSE
			}
		}
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
		affiche_toolbox(screen,tabRc,decor,perso);
		disp_map(screen,g,decor);
		SDL_BlitSurface(perso, NULL, screen, &rcPersoGrille);
		SDL_Flip(screen);
	}
	free_all_editeur(decor, g, perso, menu, fond);
	free(a);
	free(b);
}
