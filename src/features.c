#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void dimension(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    
    // Utiliser read_image_data pour obtenir les dimensions
    data = read_image_data(source_path, &width, &height, &channel_count);
    
    if (data == NULL) {
        return; // Erreur de chargement
    }
    
    // Afficher le format requis
    printf("dimension: %d, %d\n", width, height);
    
    // Libérer la mémoire
    free(data);
}