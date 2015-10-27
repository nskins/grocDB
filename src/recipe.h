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
  // EFFECTS: Default constructor.
  Recipe();
  
  // REQUIRES: s > 0
  // EFFECTS: Constructs a Recipe object with the given parameters.
  Recipe(std::string n, int s, std::vector<Ingredient> i);

  // Getter functions
  inline std::string getName() {
    return name;
  }
  inline int getServes() {
    return serves;
  }
  inline std::vector<Ingredient> getIngredients() {
    return ingredients;
  }

  // Setter functions
  inline void setName(std::string n) {
    name = n;
  }
  inline void setServes(int s) {
    serves = s;
  }
  inline void setIngredients(std::vector<Ingredient> &i) {
    ingredients = i;
  }
  
 private:
  std::string name;
  int serves;
  std::vector<Ingredient> ingredients;
};

#endif
