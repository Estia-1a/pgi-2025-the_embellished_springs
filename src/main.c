#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"


int main(int argc, char **argv) {
  struct Arguments configuration;
  parse_arguments(argc, argv, &configuration);

  if ( strncmp(configuration.command, "first_pixel", 11) == 0 ) {
    first_pixel(configuration.file_path);
  }

  return 0;
}
