#ifndef DEF_EDITEUR
#define DEF_EDITEUR

/**
 * \file editeur.h
 * \brief contient les en têtes des fonctions gerant l'editeur
 * 
 * */

#include "display.h"
#include "load_elements.h"


/**
 * \fn editeur(SDL_Surface*)
 * \brief gère l'integralite de l'editeur 
 * \param screen Fenêtre sur laquelle sera affichee l'editeur
 * \return -
 * 
 * Cette fonction charge tous les sprites necessaires à l'editeur, et contient la boucle principale permettant de placer les sprites sur une grille
 * */
void editeur(SDL_Surface* screen);


/**
 * \fn ChargerFichierEdit(int* a,int* b)
 * \brief Charge la grille contenue dans le fichier "grille.txt"
 * \param a Contiendra l'abscisse du joueur
 * \param b Contiendra l'ordonnee du joueur
 * \return g : Grille chargee 
 * */
grille ChargerFichierEdit(int * a, int * b);

/**
 * \fn SauvegardeGrille(grille g, SDL_Rect perso)
 * \brief Sauvegarde la grille cree par le joueur
 * \param g Grille à sauvegarder
 * \param perso Coordonees du joueur
 * \return -
 * */
void SauvegardeGrille(grille g, SDL_Rect perso);
	
	
/**
 * \fn ChargerSprite(int xc,int yc,SDL_Rect tab[])
 * \brief renvoie un entier correspondant au sprite à charger
 * \param xc Abscisse du clic 
 * \param yx Ordonnees du clic
 * \return int : sprite à charger
 * 
 * Le joueur souhaitant creer sa grille doit cliquer sur le sprite qu'il souhaite place dans la liste à droite de l'ecran
 * Le sprite est ensuite charge, et le joueur n'a qu'à cliquer sur la case sur laquelle il souhaite placer le sprite
 * Pour supprimer un sprite charge, il suffit d'effectuer un clic droit sur ce dernier
 * */
int ChargerSprite(int xc, int yc,SDL_Rect tab[]);

/**
 * \fn PlacementPossible(SDL_Rect position, grille g)
 * \brief renvoie un entier indiquant si on peut poser une salle tournante
 * \param position Coordonnées du clic 
 * \return int : booléen
 * */
int PlacementPossible(SDL_Rect position, grille g);

/**
 * \fn PlacerSprite(grille g, SDL_Rect position, int testsprite, SDL_Rect * RCPERSO)
 * \brief Place un sprite dans la grille et l'affiche a l'ecran
 * \param g Grille dans laquelle placer le sprite
 * \param position Position ou placer le sprite
 * \param testsprite Numero du sprite a charger
 * \param RCPERSO Coordonnees du personnage
 * \return grille Retourne la grille modifiee
 * */
grille PlacerSprite(grille g, SDL_Rect position, int testsprite, SDL_Rect * RCPERSO);

#endif
