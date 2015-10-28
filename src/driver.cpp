#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <iostream>

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
      // Print commands help.
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
      // Algorithm:
      
      // 1. Open the file given by argv[i]

      
      
      // 2. Parse the data and obtain Recipe data.
      //    (Hardest step - contain in its own function)


      
      // 3. Construct the appropriate Recipe object.


      
      // 4. Pass the address of the Recipe object in add_to_db.


      
      // 5. Close the file


      
    }
  }
  if (write_mode) {
    for (int i = FIRST_REC_ARG; i < argc; ++i) {
      // Algorithm:
      
      // 1. Default construct a Recipe object.



      // 2. Pass argv[i] and the new Recipe object to retrieve_from_db.



      // 3. Add the Recipe to a vector of Recipes.


      
    }
    // 4. Loop through the vector of Recipes and generate a master list
    //    of ingredients (unsorted).



    // 5. Sort the master list using a functor.



    // 6. Output the master list in a fashionable manner.


    
  }

  return 0;
}
