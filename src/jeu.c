#include "jeu.h"
 

/**
 * \file jeu.c
 * \brief contient les fonctions gerant le deroulement du jeu
 * */
 
void pause(SDL_Surface * screen, SDL_Surface * Ecran[])
{
	SDL_Event event;
	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
	SDL_BlitSurface(Ecran[PAUSE],NULL,screen,&pos);
	SDL_Flip(screen);
	int pause = 1;
 do{
	 SDL_WaitEvent(&event);
 	switch(event.type){
		case SDL_QUIT:
		pause = 0;
		break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_p:
				pause=0;
				break;
				default:
				break;
			}
		default:
		break;
	}
 }
while(pause);
	
}



grille restart(joueur j, grille g, grille fog){
	stat_init(j);
	desaloue_grille(g);
	desaloue_grille(fog);
	g=load_grille(j);	
	return g;
}


void victoire(SDL_Surface *screen){
		SDL_Surface* win_image,*temp;
		temp  = IMG_Load("./ecran/victoire.png");		//on charge l'image de victoire
		win_image  = SDL_DisplayFormat(temp);	
		SDL_FreeSurface(temp);
		SDL_Rect pos;
		pos.x=160; //on indique où afficher l'image
		pos.y=0;
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); //efface l'écran
		SDL_BlitSurface(win_image, NULL, screen, &pos); //affiche la win
	    SDL_Flip(screen); //actualise
	    attendreTouche();
	    SDL_FreeSurface(win_image); 
}   


void mort(SDL_Surface *screen){
	SDL_Surface * temp=NULL;
	SDL_Surface * defaite=NULL;
	temp   = IMG_Load("./ecran/defaite.png"); //on charge l'image de défaite
	defaite  = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	SDL_Rect pos;	
    	pos.x=160;
   	 pos.y=0;
   	 SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	SDL_BlitSurface(defaite, NULL, screen, &pos);
	SDL_Flip(screen);
	attendreTouche(); 
	SDL_FreeSurface(defaite); 
}  
 
void conseq(joueur jro,int salle,grille g, SDL_Surface * screen, SDL_Surface * HUD[])
{
	monstre m;
		switch(salle){
			case 2:		//traversble et blesse le joueur (-3)
				(jro->pv)-=3;
				break;				
			case 3:
				(jro -> pv)-=6; //non traversable et blesse le joueur (-6)
				break;				 
			case 4:
				(jro -> pv )+= 3; //traversable et soigne le joueur (+3)
				if ((jro->pv)>(jro->pv_max)) {jro->pv = jro->pv_max;}
				break;
			case 5:				
				(jro -> atk)+=5; //item atk+
				 add_item(jro,5,g);
				break;
			case 7:				
				jro->pv_max+=3; // rajoute une armure dans l'inventaire
				if(jro->pv_max > MAXPV) { jro -> pv_max=MAXPV;}
				 add_item(jro,7,g);
				break;
			case 8:
				 (jro -> def)+=6; //rajoute un bouclier dans l'inventaire
				 add_item(jro,8,g);
				break;
			case 11:
				m=malloc(sizeof(str_monstre));
				m->atk=1;
				m->def=1;
				m->pv=10;
				Combat(m,jro,screen,HUD);
				g.salles[jro->rcJoueur.y][jro->rcJoueur.x]=0;
				break;
			case 10:		//victoire
			case 0:
			case 1:
			case 6:
			case 9:
			default:
				break;	//aucun event
			}
}
 

void deplacerJoueur(grille g,int direction,joueur jro,SDL_Rect *pos,SDL_Surface *darkMage[],SDL_Surface * screen, SDL_Surface * HUD[]){
	switch(direction){
		case HAUT:
			if ( jro->regardAct != darkMage[HAUT] )
				{jro->regardAct = darkMage[HAUT];break;}
			if ( jro->rcJoueur.y-1 < 0 ) break;
			if ( traversable(g.salles[pos->y-1][pos->x]) ){
				jro->rcJoueur.y--;
				conseq(jro,(g.salles[pos->y][pos->x]),g,screen,HUD);
				break;
			}		
			conseq(jro,(g.salles[pos->y-1][pos->x]),g,screen,HUD);
			break;
		case BAS:
			if (jro->regardAct != darkMage[BAS])
				{jro->regardAct = darkMage[BAS];break;}
			if(pos->y+1>=(SCREEN_HEIGHT/32)) break;
			if (traversable(g.salles[pos->y+1][pos->x])){
				jro->rcJoueur.y++;
				conseq(jro,(g.salles[pos->y][pos->x]),g,screen,HUD);
				break;
			}
			conseq(jro,(g.salles[pos->y+1][pos->x]),g,screen,HUD);
			break;
		case GAUCHE:
			if (jro->regardAct != darkMage[GAUCHE])
				{jro->regardAct = darkMage[GAUCHE];break;}
			if (pos->x - 1 < 0)
				break;
			if(traversable((g.salles[pos->y][pos->x-1]))){
				jro->rcJoueur.x--;
				conseq(jro,(g.salles[pos->y][pos->x]),g,screen,HUD);
				break;
			}
			conseq(jro,(g.salles[pos->y][pos->x-1]),g,screen,HUD);
			break;
		case DROITE:
			if (jro->regardAct != darkMage[DROITE])
				{jro->regardAct = darkMage[DROITE];break;}
			if (!EstDansGrille(g,pos->x + 1 ,pos->y))
				break;
			if (traversable(g.salles[pos->y][pos->x+1])){
				jro->rcJoueur.x++;
				conseq(jro,(g.salles[pos->y][pos->x]),g,screen,HUD);
				break;
			 }
			conseq(jro,(g.salles[pos->y][pos->x+1]),g,screen,HUD);
				break;
	} //fin du switch
}

void DeplacerClick(joueur jro, SDL_Rect position, grille g,SDL_Surface *darkMage[],SDL_Surface * screen, SDL_Surface * HUD[])
{
	int x = jro->rcJoueur.x - position.x;
	int y = jro->rcJoueur.y - position.y;
	if (x==0)
	{
		if (y<0) deplacerJoueur(g,BAS,jro,&(jro->rcJoueur),darkMage,screen,HUD);
		else
		{
			if (y>0) deplacerJoueur(g,HAUT,jro,&(jro->rcJoueur),darkMage,screen,HUD);
		}
	}

	if(y==0)
	{
		if (x<0) deplacerJoueur(g,DROITE,jro,&(jro->rcJoueur),darkMage,screen,HUD);
		
		else
		{
			if (x>0) deplacerJoueur(g,GAUCHE,jro,&(jro->rcJoueur),darkMage,screen,HUD);
			
		}
	}
}

int ClickVoisin(joueur jro,SDL_Rect position)
{
	return position.x >= (jro->rcJoueur.x-1) && position.x <= (jro->rcJoueur.x+1) && position.y >= (jro->rcJoueur.y-1) && position.y <= (jro->rcJoueur.y+1) ;
}

grille RemplirFog(grille fog)
{
	int i,j;
	for (i=0;i<fog.hauteur;i++)
	{
		for (j=0;j<fog.largeur;j++)
		{
			fog.salles[j][i]=-2;
		}
	}
	return fog;
}





void jouer(SDL_Surface* screen)
{
	srand(time(NULL)); 
    int continuer = 1,time=0,timepre=0;
   	int colorkey = SDL_MapRGB(screen->format, 255, 0, 255);	//definition de la couleur transparent pour chaque sprites
	SDL_Event event;

	//initialisation des sprites
	SDL_Surface *HUD[SPHUD] = {NULL};		//sprite HUD
    SDL_Surface *darkMage[SPMAGE] = {NULL}; // directions du perso
    SDL_Surface *decor[SPDECOR]={NULL};	//décors
    SDL_Surface *Ecran[SPECRAN]={NULL};
    SDL_Surface *sprmonstre=NULL;
    SDL_Surface *temp=NULL;
	SDL_Rect position;
	
	
    // Chargement de tous les sprites
    loadAll(darkMage,decor,HUD,Ecran,colorkey);
    temp = IMG_Load("./sprites/Decors/monstrealea.png");
	sprmonstre = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	SDL_SetColorKey(sprmonstre,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

	//initialisation des paramètres
   	joueur jro =(joueur) malloc(sizeof(str_joueur));	
   	stat_init(jro);
   	jro->regardAct=darkMage[BAS];   	
	grille g = load_grille(jro);
	grille fog = creer_grille(g.hauteur,g.largeur);
	fog = RemplirFog(fog); 
	
	monstre tabmonstre[NBRMONSTREALEA];
	//monstre tabmonstreagg[NBRMONSTREAGG];

	InitialisationMonstres(tabmonstre,NBRMONSTREALEA,sprmonstre,g,jro);
	
    SDL_EnableKeyRepeat(100, 100);	

	 while (continuer){	
		while( SDL_PollEvent(&event) )
		{
			switch(event.type){
				case SDL_QUIT:
					continuer = 0;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym){
						case SDLK_q:
						case SDLK_ESCAPE:
							continuer = 0;
							break;
		
						case SDLK_UP:
							deplacerJoueur(g,HAUT,jro,&(jro->rcJoueur),darkMage,screen,HUD);
							DeplacementMonstre(tabmonstre,g);
							break;
							
						case SDLK_DOWN:
							deplacerJoueur(g,BAS,jro,&(jro->rcJoueur),darkMage,screen,HUD);
							DeplacementMonstre(tabmonstre,g);
							break;
								
						case SDLK_RIGHT:
							deplacerJoueur(g,DROITE,jro,&(jro->rcJoueur),darkMage,screen,HUD);
							DeplacementMonstre(tabmonstre,g);
							break;
						
						case SDLK_LEFT:
							deplacerJoueur(g,GAUCHE,jro,&(jro->rcJoueur),darkMage,screen,HUD);
							DeplacementMonstre(tabmonstre,g);
							break;
						
						case SDLK_p:
							pause(screen,Ecran);
							break;
						
						case SDLK_r:
							g=restart(jro,g,fog);
						   	jro->regardAct=darkMage[BAS];   	
							free_monstrealea(tabmonstre);
							InitialisationMonstres(tabmonstre,NBRMONSTREALEA,sprmonstre,g,jro);
							fog=creer_grille(g.largeur,g.hauteur);
							RemplirFog(fog);
							break;
						default:
							break;
					}
				break;
				case SDL_MOUSEBUTTONUP:
					switch(event.button.button)
					{
						case SDL_BUTTON_LEFT:
							position.x=event.button.x/32;
							position.y=event.button.y/32;
							if(ClickVoisin(jro,position))
							{
								DeplacerClick(jro,position,g,darkMage,screen,HUD);
								DeplacementMonstre(tabmonstre,g);
							}
							break;
						default :
							break;
					}
					break;
			 default:
				break;
			}
		}
		time=SDL_GetTicks();
		if(time-timepre > 1000 ){
			plaque_tournantes(jro,g);
			timepre=time;
		}
	
	refresh(screen,Ecran[FONDFOG1],jro,HUD);
    fog.salles[jro->rcJoueur.y][jro->rcJoueur.x]=0;
	cases_adja(screen,fog,g,jro,decor,Ecran,tabmonstre,HUD);
	position.x=9*SPRITE_SIZE;
	position.y=9*SPRITE_SIZE;
	SDL_Flip(screen);

		if ( g.salles[jro->rcJoueur.y][jro->rcJoueur.x]==10 && TousMorts(tabmonstre) ){
			victoire(screen); 
			continuer = 0;
		}
		if (jro -> pv <= 0 ){
			mort(screen);
			continuer =0;
		}
	}//end while (continuer)	
	free_all(decor,darkMage,HUD,jro,g,fog,Ecran);
	free_monstrealea(tabmonstre);
	SDL_FreeSurface(sprmonstre);
	return; 
}

