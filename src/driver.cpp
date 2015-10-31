#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <getopt.h>
#include "groc_db.h"
#include <iostream>
#include <ostream>
#include "output.h"
#include "parse_file.h"
#include "recipe.h"
#include <sstream>

// Specifies the first argument in argv that contains
// a file/recipe for read and write.
const int FIRST_REC_ARG = 2;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  
  bool read_mode = false;
  bool write_mode = false;
  
  struct option longOpts[] = {
    { "help", no_argument, NULL, 'h' },
    { "read", no_argument, NULL, 'r' },
    { "write", no_argument, NULL, 'w' }
  };

  opterr = false;
  int opt = 0; int index = 0;
  
  while ((opt = getopt_long(argc, argv, "hrw", longOpts,
			    &index)) != -1) {
    switch (opt) {
    case 'h':
      print_commands();
      break;
    case 'r':
      if (write_mode) {
	std::cout << "Error: Read and write cannot both be specified.\n";
	exit(1);
      }
      read_mode = true;
      break;
    case 'w':
      if (read_mode) {
	std::cout << "Error: Read and write cannot both be specified.\n";
	exit(1);
      }
      write_mode = true;
      break;
    default:
      std::cout << "One of those flags is invalid. Use -h or --help\n";
    }

  }

  if (read_mode) {
    for (int i = FIRST_REC_ARG; i < argc; ++i) {
      // Open the file given by argv[i]
      std::ifstream file;
      file.open(argv[i]);

      // Default construct a Recipe object.
      Recipe r;
      
      // Parse the data and obtain Recipe data.
      // (Hardest step - contain in its own function)
      
      
      // Pass the address of the Recipe object in add_to_db.
      add_to_db(&r);
      
      // Close the file
      file.close();
    }
  }
  if (write_mode) {
    std::vector<Ingredient> master_list;
    
    for (int i = FIRST_REC_ARG; i < argc; ++i) {
      // Default construct a Recipe object.
      Recipe r;

      // Pass argv[i] and the new Recipe object to retrieve_from_db.
      retrieve_from_db(argv[i], &r);

      // Load the master list of ingredients.
      int size = r.getIngredients().size();
      for (int j = 0; j < size; ++j) {
	master_list.push_back(r.getIngredients().at(j));
      }
    }
    
    // Sort the master list using a functor.
    std::sort(master_list.begin(), master_list.end());

    // Output the master list in a fashionable manner.
    // Change from std::cout to file output using
    // command-line option.
    print_grocery_list(&master_list);
    
  }
  
  return 0;
}
