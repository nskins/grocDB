#include "../groc_db.h"
#include <iostream>
#include "../recipe.h"
#include <string>
#include <vector>

int main(int argc, char **argv) {

  Recipe r;
  std::string name = "LotOLettuce";
  
  retrieve_from_db(name, &r);

  int size = r.getIngredients().size();

  for (int i = 0; i < size; ++i) {
    std::cout << r.getIngredients().at(i).name << "|"
	      << r.getIngredients().at(i).quantity << "|"
	      << r.getIngredients().at(i).unit << "|"
	      << r.getIngredients().at(i).foodgroup << "\n";
  }

  return 0;
}

