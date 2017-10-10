#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>
#include "jeu.h"
#include "editeur.h"

/**
 * \file main.c
 * \brief gere le lancement du jeu ou de l'editeur
 * */
 
 
 
/*! 
 * \mainpage Presentation
 * \section intro_sec Introduction
 * 
 * Ce Programme affiche une grille a l'ecran une sur laquelle se deplace un joueur
 * Le jeu se termine si le joueur meurt ou si il se deplace sur la case verte en ayant auparavant tuer tous les monstres presents sur la grille
 * \section cmd_sec Commandes
 * \subsection Lancement 
 * Fleche du haut : Lancer le jeu
 * Fleche du bas : lancer l'editeur
 * Esc ou Q : Quitter
 * \subsection Jeu
 * Le deplacement du personnage se fait a l'aide des touches flechees
 * R : redemarre la partie
 * Q ou ESC : Retour au menu principal
 * \subsection Editeur
 * L'editeur fonctionne de la maniere suivant : un clic sur un sprite de la toolboox charge ce dernier\n
 * Un clic gauche sur la grille place le sprite a la case sur la quelle le joueur a clique\n
 * Un clic droit sur la grille supprime le sprite place la ou le joueur a clique\n
 * C : charge la grille contenue dans grille.txt\n
 * N : Affiche une nouvelle grille vide\n
 * S : sauvegarde la grille dans test.txt\n
 * M : Affiche le menu de l'editeur\n
 * Q : Quitte l'editeur\n
 * Contraintes : On ne peut pas placer des salles tournantes les unes a cote des autres\n
 * 	On ne peut pas placer plusieurs joueur sur la grille\n
 * On ne peut pas placer de salles tournantes sur les bords de la grille\n
 * */

int main()
{
    SDL_Surface *screen = NULL, *menu = NULL,*tmp;
    SDL_Rect rcMenu;
    SDL_Event event;
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);
    screen= SDL_SetVideoMode(MENU_WIDTH, MENU_HEIGHT,0,0);
    SDL_WM_SetCaption("MENU","MENU");
	tmp=IMG_Load("./ecran/menu.png");
    menu = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    rcMenu.x = 0;
    rcMenu.y = 0;

    SDL_BlitSurface(menu, NULL, screen, &rcMenu);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
					case SDLK_q:
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = 0;
                        break;
                    case SDLK_UP:
						screen= SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT,0,0);
						SDL_WM_SetCaption("DAT LABYRINTHE","DAT LABYRINTHE");
						jouer(screen);
                     	screen= SDL_SetVideoMode(MENU_WIDTH, MENU_HEIGHT,0,0);
                     	SDL_WM_SetCaption("MENU","MENU");
                        break;
		    
                    case SDLK_DOWN:
						screen = SDL_SetVideoMode(EDITEUR_WIDTH,EDITEUR_HEIGHT,0,0);
                        editeur(screen);
                        screen= SDL_SetVideoMode(MENU_WIDTH, MENU_HEIGHT,0,0);
                        SDL_WM_SetCaption("MENU","MENU");
                        break;
                     default:
                     break;
                }
                break;
        }
        // Effacement de l'ecran
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        SDL_BlitSurface(menu, NULL, screen, &rcMenu);
        SDL_Flip(screen);
    }
    SDL_FreeSurface(menu);
    SDL_Quit();
    return EXIT_SUCCESS;
}
