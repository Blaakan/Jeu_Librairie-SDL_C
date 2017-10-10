#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES
/**
 * \file constantes.h 
 * \brief Contient toutes les constantes necessaire au fonctionnement du jeu
 * */


/** Defini la taille d'un sprite en pixel
 * */
    #define SPRITE_SIZE  	32 
    
    
/** Defini la largeur du menu
 * */ 
   #define MENU_WIDTH   	640
   
 /** Defini la hauteur du menu
  * */
    #define MENU_HEIGHT  	640
    
/** Defini la largeur du jeu
 * */    
    #define SCREEN_WIDTH 	960
/**Defini la hauteur du jeu
 * */
    #define SCREEN_HEIGHT   640
    
/**Defini la largeur de l'editeur
 * */    
    #define EDITEUR_WIDTH   818 // 640 + 178 (taille du l'interface des sprites)


/**Defini la hauteur de l'editeur
 * */
    #define EDITEUR_HEIGHT  640 

/**Defini le maximum de pv que peut avoir le joueur
 * */
	#define MAXPV 	100

/**Defini le nombre de sprites du decor
 * */
	#define SPDECOR 12

/**Defini le nombre des sprites d'ecran
*/
	#define SPECRAN 6
	
/**Defini le nombre de sprites servant a representer le personnage
 * */	
	#define SPMAGE  4
	
	
/**Defini le nombre de sprites necessaire a l'HUD
 * */	
	#define SPHUD   8
		
/**Defini le nombre de monstres se deplacant aleatoirement
 * */
 	#define NBRMONSTREALEA 3
 	
/**Defini le nombre de monstres immobiles
 * */
 	#define NBRMONSTREIMMO 1

		
/**
 * Defini des constantes pour l'HUD
 * */	
typedef enum {ItemATK, ItemVIE, ItemDEF, JaugeDEF,JaugeATK,PV,SANSPV,COMBAT}HUD;

/** 
 * Defini des constantes pour les directions du joueur (regard)
 * */
typedef enum {HAUT, BAS, GAUCHE, DROITE}DIRECTIONS;

/**
 * Defini des constantes pour la gestion du fog et de la pause
 * */
typedef enum {FONDFOG1, 
	  FONDFOG2,
	  FOG1,
	  FOG2,
	  PAUSE
	  }FOG;
    

#endif
