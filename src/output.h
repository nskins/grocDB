#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include "recipe.h"
#include <vector>

// EFFECTS: Prints the available command-line options.
void print_commands();

// REQUIRES: master_list is sorted
// MODIFIES: output
// EFFECTS: Prints the grocery list
//          in a fashionable manner.
void print_grocery_list(std::vector<Ingredient>* master_list);

// EFFECTS: Prints the recipe names
//          in a fashionable manner.
void print_recipe_names(std::vector<std::string>* recipe_names);

#endif
