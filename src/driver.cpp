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

//
enum class MODE {
  delete_mode,
    query_mode,
    read_mode,
    write_mode   
};

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  
  struct option longOpts[] = {
    { "delete", no_argument, NULL, 'd' },
    { "help", no_argument, NULL, 'h' },
    { "query", no_argument, NULL, 'q' },
    { "read", no_argument, NULL, 'r' },
    { "write", no_argument, NULL, 'w' }
  };

  opterr = false;
  int opt = 0; int index = 0;

  MODE mode;
  
  while ((opt = getopt_long(argc, argv, "dhqrw", longOpts,
			    &index)) != -1) {
    switch (opt) {
    case 'd':
      mode = MODE::delete_mode;
      break;
    case 'h':
      print_commands();
      break;
    case 'q':
      mode = MODE::query_mode;
      break;
    case 'r':
      mode = MODE::read_mode;
      break;
    case 'w':
      mode = MODE::write_mode;
      break;
    default:
      std::cout << "One of those flags is invalid. Use -h or --help\n";
    }
  }

  if (mode == MODE::delete_mode) {
    for (int i = FIRST_REC_ARG; i < argc; ++i) {
      remove_from_db(argv[i]);
    }
  }
  if (mode == MODE::query_mode) {
    std::vector<std::string> recipe_names;
    
    query_db(&recipe_names);

    print_recipe_names(&recipe_names);
    
  }
  if (mode == MODE::read_mode) {
    for (int i = FIRST_REC_ARG; i < argc; ++i) {
      Recipe r;
      
      parse_file(argv[i], &r);
      
      add_to_db(&r);
    }
  }
  if (mode == MODE::write_mode) {
    std::vector<Ingredient> master_list;
    
    for (int i = FIRST_REC_ARG; i < argc; ++i) {
      Recipe r;

      retrieve_from_db(argv[i], &r);

      int size = r.getIngredients().size();
      for (int j = 0; j < size; ++j) {
	master_list.push_back(r.getIngredients().at(j));
      }
    }
    
    std::sort(master_list.begin(), master_list.end());

    print_grocery_list(&master_list);
    
  }
  
  return 0;
}
