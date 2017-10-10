#ifndef DEF_JEU
#define DEF_JEU
#include "load_elements.h"
#include "display.h"

/**
 * \file jeu.h
 * \brief contient les en-têtes des fonctions gerant le jeu 
 */
 
 
/** \fn pause(SDL_Surface * screen, SDL_Surface * Ecran[])
 * \brief attend que le joueur reappuie sur "p" pour relancer le jeu
 * \param screen Fenetre ou afficher la pause
 * \param Ecran Tableau des sprites en lien avec l'ecran
 * \return -
 * */
void pause(SDL_Surface * screen, SDL_Surface * Ecran[]);


/**
 * \fn restart(joueur j, grille g, grille fog);
 * \brief re initiliase le jeu
 * \param j Joueur
 * \param g Grille
 * \param fog Brouillard
 * \return grille : grille reinitialisee
 * */ 
 grille restart(joueur j, grille g, grille fog);


/**
 * \fn victoire(SDL_Surface *screen)
 * \brief se declenche quand le joueur gagne la partie
 * \param screen Fenêtre sur laquelle se deroule la partie
 * \return -
 * 
 * Affichage une image indiquant au joueur qu'il a gagne
 * Attend que le joueur appuie sur une touche
 * Retourne au menu principal
 * */
void victoire(SDL_Surface *screen);

/**
 * \fn mort(SDL_Surface *screen)
 * \brief se declenche quand le joueur perd la partie
 * \param screen Fenêtre sur laquelle se deroule la partie
 * \return -
 * 
 * Affichage une image indiquant au joueur qu'il a perdu
 * Attend que le joueur appuie sur une touche
 * Retourne au menu principal
 * */
void mort(SDL_Surface *screen);


/**
 * \fn conseq(joueur jro,int salle,grille g, SDL_Surface * screen, SDL_Surface * HUD[])
 * \brief Contient le comportement à adopter en fonction du type de case
 * \param joueur Joueur sur la grille
 * \param grille Grille sur la quelle se déplace le joueur
 * \param int type de la salle
 * \param screen Fenetre de jeu
 * \param HUD Inventaire du joueur
 * \return -
 * 
 * Cette fonction sert à rattacher chaque type de case à un évenement :
 * ici ; 1 = rien (mur)\n
 * 		 2 = 3 points de dégat\n
 * 		 3 = 5 points de dégat\n
 * 		 4 = 2 points de soin\n
 * 		 5 = obtention de l'épée "Anduril, Flamme de l'Ouest" -> attaque + 5\n
 * 		 7 = obtention de l'armure "Cotte de Mithril" -> PV max du joueur +10\n
 * 		 8 = obtention du bouclier "Youshallnotpass" -> défense du joueur +5\n
 * 		10 = le joueur remporte la partie\n
 * 
 * 	Cette fonction peut engendrer la modification de la grille (si le joueur ramasse un item)
 * ainsi que la modification de certains attribut (pv, pvmax, inventaire) du joueur de manière indirecte.
 * */ 
void conseq(joueur jro,int salle,grille g, SDL_Surface * screen, SDL_Surface * HUD[]);



/**
 * \fn deplacerJoueur(grille g,int direction,joueur jro,SDL_Rect *pos,SDL_Surface *darkMage[],SDL_Surface * screen, SDL_Surface * HUD[])
 * \brief Gère le deplacement du joueur sur la grille
 * \param g Grille sur laquelle le joueur se deplace
 * \param direction Direction du joueur
 * \param pos position du joueur
 * \param darkMage Sprites du joueur
 * \param screen Fenetre de jeu
 * \param HUD Sprites de l'inventaire
 * \return -
 * */
void deplacerJoueur(grille g,int direction,joueur jro,SDL_Rect *pos,SDL_Surface *darkMage[],SDL_Surface * screen, SDL_Surface * HUD[]);

/**
 * \fn DeplacerClick(joueur jro, SDL_Rect position, grille g,SDL_Surface *darkMage[],SDL_Surface * screen, SDL_Surface * HUD[])
 * \brief gère le deplacement à la souris
 * \param jro Joueur
 * \param position future position
 * \param g Grille du jeu
 * \param darkMage Sprites du joueur
 * \param screen Fenetre de jeu
 * \param HUD Sprites de l'inventaire
 * \return -
 * */ 
void DeplacerClick(joueur jro, SDL_Rect position, grille g,SDL_Surface *darkMage[],SDL_Surface * screen, SDL_Surface * HUD[]);


/**
 * \fn ClickVoisin(joueur jro,SDL_Rect position)
 * \brief renvoie un entier indiquant si le joueur a bien clique sur une case adjacente
 * \param jro Joueur
 * \param position Position du clic
 * \return int : indique si le joueur a clique sur une case valide
 * */
int ClickVoisin(joueur jro,SDL_Rect position);

/**
 * \fn RemplirFog(grille fog)
 * \brief Place des -2 dans la grille fog
 * \param fog Grille à remplir
 * \return grille : Fog rempli
 * */
grille RemplirFog(grille fog);

/**
 * \fn jouer(SDL_Surface* screen)
 * \brief Gère l'integralite du jeu
 * \param screen Fenêtre sur laquelle se deroule la partie
 * \return -
 * */
void jouer(SDL_Surface* screen);


#endif
