#ifndef DEF_LOAD_ELEMENTS
#define DEF_LOAD_ELEMENTS

#include "monstre.h"

/**
 * \file load_elements.h
 * \brief contient les en-têtes des fonctions gérant le chargement des différents sprites, ainsi que leur libération
 * */


/**
 * \fn chargement_sprites_perso(SDL_Surface *Mage[],int color)
 * \brief charge les sprites représentant le personnage dans un tableau 
 * \param Mage Tableau de sprites
 * \param color Couleur qui apparaitra transparente à l'affichage
 * \return -
 * */
void chargement_sprites_perso(SDL_Surface *Mage[],int color);


/**
 * \fn chargement_sprites_ecran(SDL_Surface *ecran[] )
 * \brief ecran Charge les Sprites prennant toutes la fenêtre (victoire, défaite, etc)
 * \param ecran Tableau dans lequel seront chargés les sprites
 * \return -
 * */
void chargement_sprites_ecran(SDL_Surface *ecran[] );

/**
 * \fn charger_sprites_HUD(SDL_Surface *interface[],int color)
 * \brief charge les sprites necessaire à l'HUD
 * \param interface tableau dans lequel seront chargés les sprites
 * \param color Couleur qui apparaitra transparent à l'affichage
 * \return -
 * */
void charger_sprites_HUD(SDL_Surface *interface[],int color);


/**
 * \fn charger_sprites_decor(SDL_Surface *load[],int color)
 * \brief charge les sprites du décor
 * \param load Tableau dans lequel seront chargés les sprites 
 * \param color Couleur qui apparaitra transparente à l'affichage
 * \return - */
void charger_sprites_decor(SDL_Surface *load[],int color);	


/**
 * \fn loadAll(SDL_Surface* DarkMage[],SDL_Surface* decor[],SDL_Surface* HUD[],SDL_Surface* Ecran[],int color)
 * \brief charge tous les sprites nécessaires
 * \param DarkMage Tableau dans lequel seront chargés les sprites du personnage
 * \param decor Tableau dans lequel seront chargés les sprites du décor
 * \param HUD Tableau dans lequel seront chargés les sprites de l'HUD
 * \param Ecran Tableau dans lequel seront chargé les sprites écran
 * \param color Couleur qui apparaitra transparente à l'affichage
 * \return -
 * */
void loadAll(SDL_Surface* DarkMage[],SDL_Surface* decor[],SDL_Surface* HUD[],SDL_Surface* Ecran[],int color);


/**
 * \fn free_monstrealea(monstre tabmonstre[NBRMONSTREALEA])
 * \brief free un tableau de monstres aléatoires
 * \param tabmonstre Tableau de monstres à free
 * \return -
 * */
void free_monstrealea(monstre tabmonstre[NBRMONSTREALEA]);

/**
 * \fn freeTableauSprite(SDL_Surface* tab[],int i)
 * \brief free un tableau de sprites
 * \param tab Tableau de sprite à free
 * \param i Taille du tableau (définie dans les constantes
 * \return -
 * */
void freeTableauSprite(SDL_Surface* tab[],int i);

/**
 * \fn free_all(SDL_Surface* decor[],SDL_Surface* darkMage[],SDL_Surface* HUD[],joueur jro,grille g,grille fog,SDL_Surface* Ecran[])
 * \brief free tous les espaces alloués pour le jeu
 * \param decor Tableau de sprites decor à free
 * \param darkMage Sprites du joueur à free
 * \param HUD sprite de l'HUD à free
 * \param jro Joueur à free
 * \param g grille à free
 * \param fog grille "brouillard" à free
 * \param Ecran Sprites Ecran à free
 * \return -
 * */
void free_all(SDL_Surface* decor[],SDL_Surface* darkMage[],SDL_Surface* HUD[],joueur jro,grille g,grille fog,SDL_Surface* Ecran[]);


/**
 * \fn free_all_editeur(SDL_Surface *decor[], grille g, SDL_Surface * perso, SDL_Surface * menu, SDL_Surface * fond)
 * \brief free tout l'espace alloué lors de l'ouverture du l'éditeur de niveau
 * \param decor Sprites decor à free
 * \param g grille à free
 * \param perso Sprite personnage à free
 * \param menu Menu Editeur à free
 * \param fond Fond à free
 * \param fondtoolbox Fond de la Toolbox à free
 * */
void free_all_editeur(SDL_Surface *decor[], grille g, SDL_Surface * perso, SDL_Surface * menu, SDL_Surface * fond);




#endif
