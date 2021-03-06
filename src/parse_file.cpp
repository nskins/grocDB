#include <cstdlib>
#include <fstream>
#include <iostream>
#include "recipe.h"
#include <sstream>


void parse_file(std::string filename, Recipe *r) {
	std::ifstream filestream;
	filestream.open(filename.c_str());
	
	std::string input;
	std::getline(filestream, input);
	r->setName(input);
	std::getline(filestream, input);
	std::getline(filestream, input);
	r->setServes(atoi(input.c_str()));
	std::getline(filestream, input);

	std::vector<Ingredient> ingredients;

	while(std::getline(filestream, input) && input != "Directions") {
		if (input == "") {
			continue;
		}
		std::istringstream iss(input);
		Ingredient ing;
		iss >> ing.foodgroup >> ing.quantity >> ing.unit;
		while(iss >> input) {
			ing.name += input + " ";
		}
		ing.name = ing.name.substr(0, ing.name.size() - 1);

		ingredients.push_back(ing);
	}
	r->setIngredients(ingredients);
	std::string directions = input + "\n";
	while(std::getline(filestream, input)) {
		directions += input + "\n";
	}
	r->setDirections(directions);

	filestream.close();
	//"ok that might be it 11:37 pm Sunday 11/1/15"




	

  
  return;
}
