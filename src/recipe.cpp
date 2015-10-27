#include "recipe.h"

Recipe::Recipe() {}

Recipe::Recipe(std::string n, std::string d,
	       std::vector<Ingredient> i, int s)
  : name(n), directions(d), ingredients(i), serves(s) {}
