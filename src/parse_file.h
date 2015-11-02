#ifndef PARSE_FILE_H
#define PARSE_FILE_H

#include <iostream>
#include "recipe.h"
#include <string>

// REQUIRES: *r is a default constructed Recipe.
// MODIFIES: *r
// EFFECTS: Loads
void parse_file(std::string filename, Recipe *r);

#endif
