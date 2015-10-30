#include "recipe.h"

bool operator<(const Ingredient &a, const Ingredient &b) {
  if (a.foodgroup == b.foodgroup) {
    return (a.name < b.name);
  }
  return (a.foodgroup < b.foodgroup);
}

Recipe::Recipe() {}

Recipe::Recipe(std::string n, std::string d,
	       std::vector<Ingredient> i, int s)
  : name(n), directions(d), ingredients(i), serves(s) {}
