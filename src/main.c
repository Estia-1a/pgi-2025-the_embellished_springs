#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <estia-image.h>
#include <getopt.h>
 
#include "features.h"
#include "utils.h"
#include "argsparse.h"
 
int main(int argc, char **argv) {
 
 /*To use debug mode:
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */
 
  /*DO NOT EDIT THIS PART*/
Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
if ( strncmp( configuration.command, "color_invert", 12 ) == 0 ) { 
    color_invert(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_desaturatet", 16 ) == 0 ) { 
    color_desaturate(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "color_gray_luminance", 20 ) == 0 ) { 
    color_gray_luminance(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "mirror_vertical", 15 ) == 0 ) { 
    mirror_vertical(configuration.filenames[0]);
}