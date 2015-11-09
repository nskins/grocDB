#ifndef GROC_DB_H
#define GROC_DB_H

#include "recipe.h"
#include <string>
#include <vector>

// EFFECTS: Adds Recipe r to groc.db
void add_to_db(Recipe *r);

// EFFECTS: Fills the vector to which v
//          points with the names of all
//          of the recipes in groc.db
void query_db(std::vector<std::string>* v);

// EFFECTS: Removes the specified recipe from groc.db
void remove_from_db(std::string name);

// REQUIRES: Recipe r points to a recipe initialized by a
//           default constructor which has not been further modified.
// MODIFIES: The object to which r points.
// EFFECTS: Retrieves data for the recipe given by the first parameter.
//          Stores the information in the object to which r points.
void retrieve_from_db(std::string name, Recipe *r);

#endif
