#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

struct Ingredient {
  std::string name;
  std::string foodgroup;
  std::string unit;
  int quantity;

  friend bool operator<(const Ingredient &a, const Ingredient &b);
};

class Recipe {
 public:
  // EFFECTS: Default constructor.
  Recipe();
  
  // REQUIRES: s > 0
  // EFFECTS: Constructs a Recipe object with the given parameters.
  Recipe(std::string n, std::string d,
	 std::vector<Ingredient> i, int s);

  // Getter functions
  inline std::string getName() {
    return name;
  }
  inline std::string getDirections() {
    return directions;
  }
  inline std::vector<Ingredient> getIngredients() {
    return ingredients;
  }
  inline int getServes() {
    return serves;
  }

  // Setter functions
  inline void setName(std::string n) {
    name = n;
  }
  inline void setDirections(std::string d) {
    directions = d;
  }
  inline void setIngredients(std::vector<Ingredient> &i) {
    ingredients = i;
  }
  inline void setServes(int s) {
    serves = s;
  }
  
 private:
  std::string name;
  std::string directions;
  std::vector<Ingredient> ingredients;
  int serves;
};

#endif
