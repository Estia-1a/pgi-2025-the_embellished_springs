#include <estia-image.h>
#include <stdio.h>
 
#include "features.h"
#include "utils.h"
 
 
void helloWorld() {
    printf("Hello World !");
}
void color_invert(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);

    int y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            unsigned char red = data[y * width * 3 + x * 3];
            unsigned char green = data[y * width * 3 + x * 3 + 1];
            unsigned char blue = data[y * width * 3 + x * 3 + 2];
        
            data[y * width * 3 + x * 3] = 255 - red;    // Invert red component
            data[y * width * 3 + x * 3 + 1] = 255 - green;  // Invert green component
            data[y * width * 3 + x * 3 + 2] = 255 - blue;   // Invert blue component
    }
}

    write_image_data("image_out.bmp", data, width, height);
    free(data);
} 

void mirror_horizontal(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    
    int y, x, c;
    unsigned char temp;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width / 2; x++) {
            for (c = 0; c < nbChannels; c++) {
                temp = data[y * width * nbChannels + x * nbChannels + c];
                data[y * width * nbChannels + x * nbChannels + c] = data[y * width * nbChannels + (width - x - 1) * nbChannels + c];
                data[y * width * nbChannels + (width - x - 1) * nbChannels + c] = temp;
            }
        }
    }
    
    write_image_data("image_out.bmp", data, width, height);
    free(data);
}

void color_blue(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    
    int y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            data[y * width * 3 + x * 3] = 0;  
            data[y * width * 3 + x * 3 + 1] = 0;  
        }
    }
    
    write_image_data("image_out.bmp", data, width, height);
}
