#ifndef DEF_MONSTRE
#define DEF_MONSTRE
#include <time.h>
#include "grille.h"

/**
 * \file monstre.h
 * \brief Contient les prototypes des fonctions de monstre.c ainsi que les specifications. 
 * */


/**
 * \struct str_monstre
 * \brief structure contenant les informations d'un monstre.
 * 
 * Str_monstre contient la position du monstre sur la grille
 * (x,y), son attaque, sa defense, ses pvs, et son sprite
 **/
typedef struct str_monstre{
	SDL_Rect rcMonstre;/*!<coordonnees du monstre*/
	int atk;/*!<Attaque du joueur*/
	int def;/*!<Defense du joueur*/
	int pv;/*!< Point de vie actuels du joueur */
	SDL_Surface * SpriteMonstre;/*!< Sprite du monstre */
}str_monstre,*monstre;

/**
 * \struct monstre
 * \brief pointeur sur structure str_monstre.
**/


/**
 * \fn Combat(monstre m,joueur jro,SDL_Surface * screen, SDL_Surface* HUD[])
 * \brief Lance le combat entre un joueur et un monstre
 * \param m Monstre
 * \param jro Joueur
 * \param screen Fenetre dans laquelle on joue
 * \param HUD Inventaire du joueur pour y afficher un logo de combat
 * \return monstre
 * 		Renvoie le monstre avec ses pv eventuellement modifies
 * */
monstre Combat(monstre m,joueur jro,SDL_Surface * screen, SDL_Surface* HUD[]);

/**
 * \fn DeplacementMonstre(monstre tabmonstre[NBRMONSTREALEA], grille g)
 * \brief Deplace les monstres aleatoirement dans la grille
 * \param tabmonstre Tableau des monstres
 * \param g Grille sur laquelle se trouve les cases tournantes
 * \return -
 * */
void DeplacementMonstre(monstre tabmonstre[NBRMONSTREALEA], grille g); 

/**
 * \fn MonstreInit(monstre m, int atk, int def, int pv, int x, int y)
 * \brief Initialise les statistiques d'un monstre
 * \param m Monstre à initialiser
 * \param atk Attaque du monstre
 * \param def Defense du monstre
 * \param pv Vie du monstre
 * \param x Coordonnee x du monstre
 * \param y Coordonnee y du monstre
 * \return -
 * */
void MonstreInit(monstre m, int atk, int def, int pv, int x, int y);

/**
 * \fn InitialisationMonstres(monstre tabmonstre[], int taille, SDL_Surface * sprmonstre,grille g)
 * \brief Initialise le tableau des monstres
 * \param tabmonstre Tableau des monstres à deplacement aleatoire
 * \param taille Taille du tableau
 * \param sprmonstre Sprite des monstres aleatoire
 * \param g Grille sur laquelle on joue
 * \param jro Joueur
 * \return -
 * */
void InitialisationMonstres(monstre tabmonstre[], int taille, SDL_Surface * sprmonstre,grille g,joueur jro);

/**
 * \fn TousMorts(monstre tabmonstre[NBRMONSTREALEA])
 * \brief Renvoie un booléen indiquant si tous les monstres du tableau sont morts
 * \param tabmonstre Tableau des monstres à vérifier
 * \return int
 * 		renvoie 1 si tous les monstres sont morts
 * 		renvoie 0 sinon
 * */
int TousMorts(monstre tabmonstre[NBRMONSTREALEA]);

#endif 
