#include "recipe.h"

Recipe::Recipe(std::string n, int s, std::vector<Ingredient>* i)
  : name(n), serves(s), ingredients(i) {}