#include <estia-image.h>
#include <stdio.h>
#include "features.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>


void first_pixel(char *source_path)
{
    // Variables pour stocker les données de l'image
    unsigned char *data;
    int width, height, channel_count;
    
    // Lire l'image (cette fonction existe déjà dans votre projet)
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    // Vérifier si l'image a été correctement chargée
    if (result != 0 || data == NULL)
    {
        printf("Erreur: Impossible de charger l'image %s\n", source_path);
        return;
    }
    
    // Le premier pixel = les 3 premiers nombres dans le tableau
    // data[0] = Rouge, data[1] = Vert, data[2] = Bleu
    unsigned char rouge = data[0];
    unsigned char vert = data[1];
    unsigned char bleu = data[2];
    
    // Afficher le résultat
    printf("first_pixel: %d, %d, %d\n", rouge, vert, bleu);
    
    // Libérer la mémoire (très important !)
    free(data);
}