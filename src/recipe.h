#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

struct Ingredient {
  std::string name;
  std::string foodgroup;
  std::string unit;
  int quantity;
};

class Recipe {
 public:
  // REQUIRES: s > 0
  // EFFECTS: Constructs a Recipe object.
  Recipe(std::string n, int s, std::vector<Ingredient>* i);

  // Getter functions
  inline std::string getName() {
    return name;
  }
  inline int getServes() {
    return serves;
  }
  inline std::vector<Ingredient>* getIngredients() {
    return ingredients;
  }
  
 private:
  std::string name;
  int serves;
  std::vector<Ingredient> *ingredients;
};

#endif