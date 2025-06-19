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


void color_desaturate(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));
    if (new_data == NULL) {
        printf("Allocation à la mémoire échoué.\n");
        return;
    }
    int i = 0;
    while (i < width * height) {
        pixelRGB *pixel = (pixelRGB *)(data + i * channel_count);
        unsigned char min_value = pixel->R;
        if (pixel->G < min_value) {
            min_value = pixel->G;
        }
        if (pixel->B < min_value) {
            min_value = pixel->B;
        }
        unsigned char max_value = pixel->R;
        if (pixel->G > max_value) {
            max_value = pixel->G;
        }
        if (pixel->B > max_value) {
            max_value = pixel->B;
        }
        unsigned char new_value = (min_value + max_value) / 2;
        new_data[i * channel_count] = new_value;
        new_data[i * channel_count + 1] = new_value;
        new_data[i * channel_count + 2] = new_value;
        i++;
    }
    write_image_data("image_out.bmp", new_data, width, height);
    
}

void color_gray_luminance(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    
    int y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            unsigned char red = data[y * width * 3 + x * 3];
            unsigned char green = data[y * width * 3 + x * 3 + 1];
            unsigned char blue = data[y * width * 3 + x * 3 + 2];
            unsigned char gray = (unsigned char)(0.21 * red + 0.72 * green + 0.07 * blue);
            
            data[y * width * 3 + x * 3] = gray;
            data[y * width * 3 + x * 3 + 1] = gray;
            data[y * width * 3 + x * 3 + 2] = gray;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void mirror_vertical(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    
    int y, x, c;
    unsigned char temp;
    for (y = 0; y < height / 2; y++) {
        for (x = 0; x < width; x++) {
            for (c = 0; c < nbChannels; c++) {
                temp = data[y * width * nbChannels + x * nbChannels + c];
                data[y * width * nbChannels + x * nbChannels + c] = data[(height - y - 1) * width * nbChannels + x * nbChannels + c];
                data[(height - y - 1) * width * nbChannels + x * nbChannels + c] = temp;
            }
        }
    }
    
    write_image_data("image_out.bmp", data, width, height);
    free(data);
} 

void color_gray(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    
    int y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            unsigned char red = data[y * width * 3 + x * 3];
            unsigned char green = data[y * width * 3 + x * 3 + 1];
            unsigned char blue = data[y * width * 3 + x * 3 + 2];
            unsigned char gray = (red + green + blue) / 3;
            
            data[y * width * 3 + x * 3] = gray;  
            data[y * width * 3 + x * 3 + 1] = gray; 
            data[y * width * 3 + x * 3 + 2] = gray;  
        }
    }
    
    write_image_data("image_out.bmp", data, width, height);
}

