#include <estia-image.h>
#include <stdio.h>
#include "features.h"
#include "utils.h"

void first_pixel(char *source_path)
{
    // Variables to store image data
    unsigned char *data;
    int width, height, channel_count;
    
    // Read the image data using the provided function
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    // Check if image was successfully loaded
    if (result != 0 || data == NULL)
    {
        printf("Error: Could not load image %s\n", source_path);
        return;
    }
    
    // The first pixel is at position (0,0) which corresponds to the first 3 bytes
    // in the data array (assuming RGB format)
    // data[0] = Red component
    // data[1] = Green component  
    // data[2] = Blue component
    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];
    
    // Print the RGB values in the required format
    printf("first_pixel: %d, %d, %d\n", r, g, b);
    
    // Free the allocated memory for image data
    free(data);
}