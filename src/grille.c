#include "grille.h"

/**  
*\file grille.c
*\brief Contient toutes les fonctions concernant le déplacement d'un joueur sur une grille et la gestion de la grille
* */ 


grille creer_grille(int n, int m){
	int i;
	grille g;
	g.salles=(int**)calloc(n,sizeof(int*));		//allocation tableau grille
	for(i=0;i<n;i++){
		g.salles[i]=(int*)calloc(m,sizeof(int));
	}
	g.largeur=m;
	g.hauteur=n;
	return g;
}

void desaloue_grille(grille g){
	int i;
	for (i=0;i<(g.hauteur);i++){    //on libère le tableau dynamique crée pour la grille 
		free(g.salles[i]);
	}
	free(g.salles);
	g.largeur=0;
	g.hauteur=0;
}

grille load_grille(joueur jro)
{
	FILE*  fichier = NULL;
	fichier = fopen("grille.txt","r");
	int i=0;
	int j;
	if (fichier == NULL){		// si le fichier n'a pas pu s'ouvrir -> erreur
		perror("Error :");
		exit(-1);
	}		
	int n,m,x1,y1;
    fscanf(fichier,"%d %d %d %d",&n,&m,&x1,&y1); // on récupère les 4 premiere infos de la grille
    grille g=creer_grille(n,m);
    jro->rcJoueur.x=x1;
    jro->rcJoueur.y=y1;
    int type_salle;
    while (i<n){				// on récupère le type de chaque salle
		for (j=0;j<m;j++){
			fscanf(fichier,"%d ",&type_salle);
			g.salles[i][j]=type_salle;
		}
		i++;
	}
    fclose(fichier); // on ferme le fichier
	return g;
}


void add_item(joueur j,int num,grille g)
{
	SDL_Rect pos;
	pos.x=j->rcJoueur.x;
	pos.y=j->rcJoueur.y;
	int m;
	for(m=0;(j->inventory[m])!=0;m++);
		j->inventory[m]=num;
		g.salles[pos.y][pos.x]=0;
		
	
}

int traversable(int salle)
{
	int est_traversable;
	switch(salle){
		case 0:
		case 2:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			est_traversable=1;
			break;
		case 1:
		case 3:
		default:
			est_traversable=0;
			break;
	}
	return est_traversable; //renvoie une valeur si la salle est traversable ou non
}
		
		
		
		
		
		

void rotation_six_joueur(int i,int j, joueur jro)
{
	SDL_Rect *pos= &(jro->rcJoueur);
if ( (pos->y)==(i-1) && (pos->x)==(j-1) ) {pos->y=i+1; pos->x=j-1;}  // on fait tourner le joueur si besoin est (pour les cases 6)
else
	if ( (pos->y)==(i-1) && (pos->x)==(j+1) ) {pos->y=i-1; pos->x=j-1;}  
	else
		if ( (pos->y)==(i+1) && (pos->x)==(j+1) ) {pos->y=i-1; pos->x=j+1;} 
		else
			if ( (pos->y)==(i+1) && (pos->x)==(j-1)) {pos->y=i+1; pos->x=j+1;}
			else
				if ( (pos->y)==(i-1) && (pos->x)==j) {pos->y=i; pos->x=j-1;}  
				else
					if ( (pos->y)==i && (pos->x)==(j+1)) {pos->y=i-1; pos->x=j;}
					else
						if ( (pos->y)==(i+1) && (pos->x)==j) {pos->y=i; pos->x=j+1;}  
						else
							if ( (pos->y)==i && (pos->x)==(j-1)) {pos->y=i+1; pos->x=j;}  

	
}

void rotation_six_grille(int i, int j,grille g)		
{
	int tmpa = g.salles[i-1][j-1];		//rotation d'une grille au centre d'une case 6
	int tmpb = g.salles[i-1][j];
	g.salles[i-1][j-1]=g.salles[i-1][j+1];
	g.salles[i-1][j+1]=g.salles[i+1][j+1];
	g.salles[i+1][j+1]=g.salles[i+1][j-1];
	g.salles[i+1][j-1]=tmpa;
	g.salles[i-1][j]=g.salles[i][j+1];
	g.salles[i][j+1]=g.salles[i+1][j];
	g.salles[i+1][j]=g.salles[i][j-1];
	g.salles[i][j-1]=tmpb;
}

void rotation_six(grille g,joueur jro)    //tourne toutes les salles 6 de la grille
{
	int i,j;
	for (i=0;i<(g.hauteur);i++){
		for (j=0;j<(g.largeur);j++){
			if (g.salles[i][j]==6){
				rotation_six_grille(i,j,g);
				rotation_six_joueur(i,j,jro);
			}
		}
	}	
}

void rotation_neuf_joueur(int i, int j, joueur jro)
{
SDL_Rect *pos = &(jro->rcJoueur);
if ( (pos->y)==(i-1) && (pos->x)==(j-1) ) {pos->y=i-1; pos->x=j+1;}  // on fait tourner le joueur si besoin est (pour les cases 9)
	else
	if ( (pos->y)==(i+1) && (pos->x)==(j-1) ) {pos->y=i-1; pos->x=j-1;} 
		else
		if ( (pos->y)==(i+1) && (pos->x)==(j+1) ) {pos->y=i+1; pos->x=j-1;}  
			else
			if ( (pos->y)==(i-1) && (pos->x)==(j+1)) {pos->y=i+1; pos->x=j+1;} 
				else
				if ( (pos->y)==(i-1) && (pos->x)==j) {pos->y=i; pos->x=j+1;}  
					else
					if ( (pos->y)==i && (pos->x)==(j-1)) {pos->y=i-1; pos->x=j;}  
						else
						if ( (pos->y)==(i+1) && (pos->x)==j) {pos->y=i; pos->x=j-1;}
							else
							if ( (pos->y)==i && (pos->x)==(j+1)) {pos->y=i+1; pos->x=j;} 
	
}

void rotation_neuf_grille(int i,int j, grille g)
{
	int tmpa = g.salles[i-1][j-1]; // rotation d'une grille autour d'une case 9
	int tmpb = g.salles[i-1][j];
	g.salles[i-1][j-1]=g.salles[i+1][j-1];
	g.salles[i+1][j-1]=g.salles[i+1][j+1];
	g.salles[i+1][j+1]=g.salles[i-1][j+1];
	g.salles[i-1][j+1]=tmpa;
	g.salles[i-1][j]=g.salles[i][j-1];
	g.salles[i][j-1]=g.salles[i+1][j];
	g.salles[i+1][j]=g.salles[i][j+1];
	g.salles[i][j+1]=tmpb;
}

void rotation_neuf(grille g,joueur jro)
{
	int i,j; //tourne toutes les salles autour d'une case 9
	for (i=0;i<(g.hauteur);i++){
		for (j=0;j<(g.largeur);j++){
			if (g.salles[i][j]==9){
				rotation_neuf_grille(i,j,g);
				rotation_neuf_joueur(i,j,jro);				
			}
		}
	}
}

void plaque_tournantes(joueur j, grille g)
{
	rotation_six(g,j); //tourner toutes les salles d'une grille suivant leur numéro
	rotation_neuf(g,j);
	
}

int EstDansGrille(grille g, int x, int y)
{
	return (x>=0 && x <g.largeur && y>=0 && y<g.hauteur );
}

