/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:29:32 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/13 14:35:42 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main() 
{
    void *mlx_ptr;
    void *win_ptr;
    int screenWidth = 640; // Définir la largeur de l'écran // standard d'affichage basique VGA
    int screenHeight = 480; // Définir la hauteur de l'écran
    
    double posX = 22;
    double posY = 12; // Position de départ x et y
    double dirX = -1;
    double dirY = 0; // Vecteur direction initial
    double planeX = 0;
    double planeY = 0.66; // Plan de la caméra pour le raycasting 2D

    // Initialiser la connexion au système graphique
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        printf("Erreur lors de l'initialisation de MinilibX.\n");
        return (1);
    }

    // Créer une fenêtre
    win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub3D");
    if (!win_ptr)
    {
        printf("Erreur lors de la création de la fenêtre.\n");
        return (1);
    }

    int done = 0; // Condition pour arrêter la boucle
    int x = 0; 
    while (!done)
    {
        while (x < screenWidth)
        {
            // calculer la position et la direction du rayon
            double cameraX = 2 * x / (double)screenWidth - 1; // Coordonnée x dans l'espace caméra
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;

            // Dans quelle case de la carte nous nous trouvons
            int mapX = (int)posX;
            int mapY = (int)posY;

            // Longueur du rayon entre la position actuelle et le cote x ou y suivant
            double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
            double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
            double sideDistX;
            double sideDistY;

            // Direction de la marche en x ou en y (soit +1 ou -1)
            int stepX;
            int stepY;
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
            }
            x++;
            // Vous pouvez ajouter ici le code pour dessiner les résultats du raycasting dans la fenêtre
        }

        // Vous devriez ajouter ici la gestion des événements pour déterminer quand "done" devrait être mis à 1
        // Exemple: mlx_hook(win_ptr, X_EVENT, X_MASK, &hook_function, &param);

        mlx_loop(mlx_ptr); // Gère les événements et les met à jour graphiques
    }

    // Libération des ressources et fermeture de MinilibX
    mlx_destroy_window(mlx_ptr, win_ptr);
    return 0;
}
