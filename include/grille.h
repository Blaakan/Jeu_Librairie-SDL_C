#ifndef DEF_GRILLE
#define DEF_GRILLE
#include "joueur.h"

/**
 * \file grille.h 
 * \brief Contient tous les prototypes des fonctions de grille.c ainsi que les spécifications.
 * */



/**
 * \struct grille
 * \brief Tableau à deux dimension, ainsi que deux entiers représentant la hauteur et la largeur du tableau
 * 
 * Cette structure représente le labyrinthe dans lequel se déplacera le personnage.
 * C'est un tableau 2D d'entiers, chacun représentant le type d'une salle.
 * */
typedef struct grille {
	int**  salles; /*!< Tableau 2D d'entiers : une case représente une salle de la grille */
	int largeur;/*!< Largeur de la grille*/
	int hauteur;/*!< Hauteur de la grille*/
} grille;

/**
 * \fn creer_grille(int,int)
 * \brief Création d'une grille
 * \param int m Largeur de la grille
 * \param int n Hauteur de la grille
 * \return Grille
 * 
 * Cette fonction va créer une grille de largeur et hauteur données
 * et retourner la structure créee
 * 
 * 	-Création d'un tableau 2D par allocation dynamique
 * */
grille creer_grille(int,int);


/**
 * \fn desaloue_grille(grille)
 * \brief Desalloue la mémoire occupée par la grille
 * 
 * \param grille Grille à désallouer
 * \return -
 * 
 * Cette fonction va désallouer le tableau 2D dans la grille
 * entrée en paramètre
 *  
 *  -Perte des informations contenues dans la grille
 * */
void desaloue_grille(grille);


/**
 * \fn load_grille(joueur)
 * \brief Charge une grille depuis un fichier "grille.txt" 
 * \param joueur Joueur qui se déplacera sur la grille
 * \return Grille
 * 
 * Cette fonction va charger la grille contenue dans le répertoire
 * du programme (ici grille.txt). Elle va également affecter les coordonées
 * du joueur
 * 
 * -Création d'une grille -> allocation dynamique d'un tableau 2D\n
 * -Modification des attributs x,y du joueur entré en paramètre 
 * */
grille load_grille(joueur);



/**
 * \fn traversable(int)
 * \brief Renvoie un entier indiquant si une case est traversable ou non
 * \param int type de salle
 * \return entier
 * 
 * renvoie 0 pour les cases non traversables (ici 1,3)
 * renvoie 1 pour les cases traversables (ici 2,4,5,6,7,8,9)
 * */
int traversable(int);



/**
 * \fn rotation_six_joueur(int,int,joueur)
 * \brief Gère la rotation du joueur pour les cases tournantes 6
 * \param int i Compteur de rotation_six
 * \param int j Compteur de rotation_six
 * \param joueur Joueur se déplacant sur la grille
 * \return -
 * 
 * Cette fonction va déplacer le joueur lorsqu'il se trouve dans une salle tournante de type 6
 * 
 * Modification des attributs x,y du joueur 
 * */
void rotation_six_joueur(int,int,joueur);



/**
 * \fn rotation_six_grille(int,int,grille)
 * \brief Gère la rotation des cases qui sont autour d'une case tournante de type 6
 * \param int i Compteur de rotation_six
 * \param int j Compeur de rotation_six
 * \param grille Grille loadée au démarrage du programme 
 * \return -
 * 
 * Cette fonction va faire tourner les cases qui sont autour d'une case de type 6
 * dans le sens inverse des aiguilles d'une montre\n
 * Modification de la grille : échange de cases
*/
void rotation_six_grille(int , int ,grille );		

/**
 * \fn rotation_six(grille, joueur)
 * \brief Fait bouger les cases situées autour des cases 6 ainsi que le joueur si il se trouve dessus dans le sens inverse des aiguilles d'une montre
 * \param grille Grille sur laquelle se trouve les cases tournantes
 * \param joueur Joueur se déplacant sur la grille
 * \return -
 * 
 * -Modification de la grille, et possiblement des coordonnées du joueur
 * */
void rotation_six(grille,joueur);



/**
 * \fn rotation_neuf_joueur(int,int,joueur)
 * \brief gère la rotation du joueur pour les cases tournantes 9
 * \param int i compteur de rotation_neuf
 * \param int j compteur de rotation_neuf
 * \param joueur joueur se déplacant sur la grille
 * \return -
 * 
 * Cette fonction va déplacer le joueur lorsqu'il se trouve dans une salle tournante de type 9
 * 
 * Modification des coordonées du joueur
 * */
void rotation_neuf_joueur(int,int,joueur);


/**
 * \fn rotation_neuf_grille(int,int,grille)
 * \brief Gère la rotation des cases qui sont autour d'une case tournante de type 9
 * \param int i Compteur de rotation_neuf
 * \param int j Compeur de rotation_neuf
 * \param grille Grille loadée au démarrage 
 * \return -
 * 
 * Cette fonction va faire tourner les cases qui sont autour d'une case de type 9
 * dans le sens des aiguilles d'une montre`
 * 
 * Modification de la grille
*/
void rotation_neuf_grille(int,int,grille);


/**
 * \fn rotation_neuf(grille, joueur)
 * \brief Fait bouger les cases autour des cases 9 ainsi que le joueur si il se trouve dessus dans le sens  des aiguilles d'une montre
 * \param grille grille sur laquelle se trouve les cases tournantes
 * \param joueur joueur se déplacant sur la grille
 * \return - 
 *
 * Modification de la grille , et possiblement des coordonnées du joueur
 * */
void rotation_neuf(grille,joueur);


/**
 * \fn plaque_tournantes(joueur,grille)
 * \brief Fait tourner toutes les cases tournantes de la grille (6 et 9)
 * \param joueur Joueur évoluant sur la grille
 * \param grille Grille sur laquelle se trouve les salles à faire tourner
 * 
 * -Une salle tournante ne doit JAMAIS être collée à la bordure d'une grille ou à une autre salle tournante\n
 * -Appel de rotation neuf et rotation six : possible modification des coordonées du joueur, modification de la grille
 * 
 * */ 
void plaque_tournantes(joueur, grille);

/**
 * \fn add_item(joueur,int,grille)
 * \brief Ajoute un item à l'inventaire
 * \param joueur Joueur se déplacant sur la grille
 * \param grille Grille sur laquelle évolue le joueur
 * \param int numéro de l'item
 * 
 * Cette fonction va rajouter un item dans l'inventaire du joueur,
 * et va également remplacer le type de la case où se trouvait l'item par
 * 0, pour que le joueur ne puisse pas le ramasser à nouveau au même endroit
 * 
 * Modification de l'inventaire du joueur
  */
void add_item(joueur,int,grille);


/**
 * \fn EstDansGrille(grille g, int x, int y)
 * \brief Indique si la grille au coordonnées x y est dans la grille
 * \param g Grille 
 * \param x abscisse de la case
 * \param y ordonnées de la case
 * \return -
 * */
int EstDansGrille(grille g, int x, int y);


#endif
