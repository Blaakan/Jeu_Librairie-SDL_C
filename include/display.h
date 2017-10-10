#ifndef DEF_DISPLAY
#define DEF_DISPLAY
#include "monstre.h"


/**
 * \file display.h
 * \brief contient les fonctions gerant l'affichage du jeu
 * */


/**
 * \fn attendreTouche
 * \brief met le jeu en pause. Attend que le joueur appuie sur n'importe quelle touche
 * \return -
 * */
void attendreTouche(void);


/**
 * \fn afficheHUD(SDL_Surface* screen, SDL_Surface* HUD[],joueur jro)
 * \brief Affiche l'HUD du joueur
 * \param screen Fenêtre sur laquelle afficher l'HUD
 * \param HUD Sprites necessaire à l'HUD
 * \param jro Joueur sur la grille
 * \return -
 * L'affichage de l'HUD concerne 
 * -les points de vie
 * -l'attaque
 * -la defense 
 * -l'inventaire
 * */ 
void afficheHUD(SDL_Surface* screen, SDL_Surface* HUD[],joueur jro);


/**
 * \fn refresh(SDL_Surface* screen,SDL_Surface* fond,joueur jro,SDL_Surface* HUD[])
 * \brief Efface la fenêtre, puis affiche le fond et l'HUD du joueur en appelant afficheHUD
 * \param screen Fenêtre que l'on rafraichit
 * \param fond Fond à afficher
 * \param joueur Joueur sur la grille
 * \param HUD HUD à afficher
 * \return -
 * */
void refresh(SDL_Surface* screen,SDL_Surface* fond,joueur jro,SDL_Surface* HUD[]);



/**
 * \fn disp_map(SDL_Surface* screen,grille g,SDL_Surface* decor[])
 * \brief Affiche le jeu
 * \param screen Fenêtre sur laquelle afficher le jeu
 * \param g Grille contenant les informations à afficher
 * \param decor Sprites necessaire à l'affichage du jeu
 * \return -
 * */
void disp_map(SDL_Surface* screen,grille g,SDL_Surface* decor[]);


/**
 * \fn affiche_toolbox(SDL_Surface * screen, SDL_Rect tab[], SDL_Surface * decor[],SDL_Surface * spritejoueur)
 * \brief affiche la boite à outil de l'editeur
 * \param screen Fenêtre sur laquelle afficher le jeu
 * \param tab Tableau de coordonees
 * \param decor Sprites necessaires à l'affichage de la toolbox
 * \param spritejoueur Sprite du joueur
 * \return -
 * */
void affiche_toolbox(SDL_Surface * screen, SDL_Rect tab[], SDL_Surface * decor[],SDL_Surface * spritejoueur);


/**
 * \fn refresh_fog(SDL_Surface * screen,grille fog, grille g,SDL_Surface* decor[], joueur jro,SDL_Surface * ecran[], monstre tabmonstre[NBRMONSTREALEA],SDL_Surface *HUD[])
 * \brief Affiche en noir les cases non visitees, en grisees les cases visitees, et en clair les cases visibles
 * \param screen Fenêtre sur laquelle on joue
 * \param fog Une grille qui contient les valeurs des salles de la grille g qui ont ete visitees
 * \param g La grille dans laquelle on joue
 * \param decor Sprites necessaires à l'affichage des elements de decors
 * \param jro Joueur
 * \param ecran Sprites necessaires pour le fog et le fond
 * \param tabmonstre Tableau qui contient les monstres
 * \param HUD L'inventaire
 * \return - 
 * */
void refresh_fog(SDL_Surface * screen,grille fog, grille g,SDL_Surface* decor[], joueur jro,SDL_Surface * ecran[], monstre tabmonstre[NBRMONSTREALEA],SDL_Surface *HUD[]);


/**
 * \fn cases_adja(SDL_Surface * screen, grille fog, grille g,joueur jro, SDL_Surface* decor[], SDL_Surface * ecran[], monstre tabmonstre[NBRMONSTREALEA],SDL_Surface *HUD[]);
 * \brief Modifie les valeurs contenues dans la grille fog pour qu'elles prennent les celles des salles autour du joueur dans la grille g
 * \param screen Fenêtre dans laquelle on joue
 * \param fog Une grille qui contient les valeurs des salles de la grille g qui ont ete visitees
 * \param g La grille dans laquelle on joue
 * \param jro Joueur
 * \param decor Sprites necessaires à l'affichage des elements de decors
 * \param ecran Sprites necessaires pour le fog et le fond
 * \param tabmonstre Tableau qui contient les monstres
 * \param HUD L'inventaire
 * \return -
 * */
void cases_adja(SDL_Surface * screen, grille fog, grille g,joueur jro, SDL_Surface* decor[], SDL_Surface * ecran[], monstre tabmonstre[NBRMONSTREALEA],SDL_Surface *HUD[]);

/**
 * \fn afficheMonstres(SDL_Surface * screen, monstre tabmonstre[NBRMONSTREALEA], joueur jro);
 * \brief Affiche les monstres quand ils sont a portee de vision du joueur
 * \param screen Fenetre dans laquelle on joue
 * \param tabmonstre Tableau qui contient les monstres
 * \param jro Joueur
 * \return -
 * */
void afficheMonstres(SDL_Surface * screen, monstre tabmonstre[NBRMONSTREALEA], joueur jro);

/**
 * \fn AffichePartHUD(SDL_Surface * screen, SDL_Surface * sprite, int condition, SDL_Rect * position);
 * \brief Affiche les monstres quand ils sont a portee de vision du joueur
 * \param screen Fenetre dans laquelle on joue
 * \param sprite Sprite a afficher
 * \param condition Condition d'arret de la boucle
 * \param position Pointeur sur position
 * \return -
 * */
void AffichePartHUD(SDL_Surface * screen, SDL_Surface * sprite, int condition, SDL_Rect * position);

#endif
