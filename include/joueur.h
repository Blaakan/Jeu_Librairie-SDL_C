#ifndef DEF_JOUEUR
#define DEF_JOUEUR
/**
 * \file joueur.h
 * \brief Contient les prototypes des fonctions de joueur.c ainsi que les spécifications. 
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constantes.h"
#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>


/**
 * \struct str_joueur
 * \brief structure contenant les informations du joueur.
 * 
 * Str_joueur contient la position du joueur sur la grille
 * (x,y), son attaque, sa défense, son inventaire (chaine de caractères),
 * ses pvs, la direction dans laquelle il regarde, et ses pv maximum.
 * La statistique "pv maximum" d'un joueur dépend de son équipement, contrairement à la 
 * constante MAXPV qui est une limite maximale (quelque soit l'équipement). 
 */
typedef struct str_joueur{
	SDL_Rect rcJoueur; /*!<coordonnées du joueur*/	
	int atk;/*!<Attaque du joueur*/
	int def;/*!<Défense du joueur*/
	int inventory[10];/*!< Tableau 2D de caractères représentant l'inventaire du joueur */
	int pv;/*!< Point de vie actuels du joueur */
	SDL_Surface *regardAct;/*!< Direction vers laquelle regarde le joueur */
	int pv_max;/*!< Points de vie que peut avoir le joueur au maximum (dépend de l'équipement) */
}str_joueur,*joueur;





/**
 * \struct joueur
 * \brief pointeur sur structure str_joueur.
*/


/**
 * \fn stat_init(joueur)
 * \brief Initialise les statistiques de base du joueur.
 * \param joueur Pointeur vers le joueur dont on veut initialiser les statistiques.
 * \return -
 * 
 * Cette fonction va doter le joueur des statistiques de base suivantes :\n
 * defense : 2\n
 * attaque : 3\n
 * PV : 20\n
 * PV MAX : 20\n 
 *  un inventaire de 10 emplacements pouvant contenir des objets de 30 caractères maximum\n
 * -Modifications des stats du joueur
 * */ 
void stat_init(joueur);


/**
 * \fn VoisinJoueur(joueur jro, SDL_Rect position)
 * \brief Permet de savoir si une case est voisine au joueur
 * \param jro Joueur 
 * \param position Position de la case à tester
 * \return int 
 * 		renvoie 1 si la case est une case voisine
 * 		renvoie 0 si la case n'est pas une case voisine
 * */
int VoisinJoueur(joueur jro,SDL_Rect position);












#endif
