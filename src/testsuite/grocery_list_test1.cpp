#include <algorithm>
#include "../groc_db.h"
#include <iostream>
#include "../output.h"
#include "../recipe.h"
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

  Ingredient i1 { "Lettuce", "Produce", "Heads", 5 };
  Ingredient i2 { "Orange", "Produce", "", 2 };
  Ingredient i3 { "Pepper", "Spice", "Dashes", 3 };
  Ingredient i4 { "Apple", "Produce", "", 12 };
  Ingredient i5 { "Salt", "Spice", "Buckets", 17 };
  Ingredient i6 { "Milk", "Dairy", "Gallons", 2 };

  std::vector<Ingredient> master_list;
  master_list.push_back(i1);
  master_list.push_back(i2);
  master_list.push_back(i3);
  master_list.push_back(i4);
  master_list.push_back(i5);
  master_list.push_back(i6);

  std::sort(master_list.begin(), master_list.end());
  print_grocery_list(&master_list);
  
  return 0;
}
