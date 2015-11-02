#include "../groc_db.h"
#include "../recipe.h"
#include <vector>

int main(int argc, char **argv) {

  std::vector<Ingredient> ingredients;
  
  Ingredient i1 { "Lettuce", "Produce", "Heads", 5 };
  Ingredient i2 { "Salt", "Spice", "Dashes", 7 };
 
  ingredients.push_back(i1);
  ingredients.push_back(i2);
  
  Recipe r("LotOLettuce", 3, &ingredients);
  add_to_db(&r);

  return 0;
}
