#include <ctime>
#include <iostream>
#include "recipe.h"
#include <string>
#include <vector>

void print_commands() {
  std::cout << "\nAvailable command-line options:\n\n"
	    << "[-h/--help]\n"
	    << "\tShow command-line options.\n"
	    << "[-r/--read] <filename> ... <filename>\n"
	    << "\tReads the recipes contained in each <filename>.\n"
	    << "[-w/--write] <recipe name> ... <recipe name>\n"
	    << "\tWrites a grocery list containing the ingredients\n"
	    << "\tin each <recipe name>.\n\n";
  
  return;
}

void print_grocery_list(std::vector<Ingredient>* master_list) {
  
  if (master_list->empty()) {
    return;
  }
  
  // Get the current time
  time_t t = time(0);
  struct tm * now = localtime(&t);
  
  std::cout << "***Groceries for " << now->tm_year + 1900
	 << "-" << now->tm_mon + 1 << "-"
	 << now->tm_mday << "***\n\n";

  std::string current_foodgroup = master_list->at(0).foodgroup;

  std::cout << "----------------------\n";
  std::cout << current_foodgroup << "\n";
  std::cout << "----------------------\n";

  int size = master_list->size();
  for (int i = 0; i < size; ++i) {

    if (master_list->at(i).foodgroup != current_foodgroup) {
      current_foodgroup = master_list->at(i).foodgroup;

      std::cout << "\n----------------------\n";
      std::cout << "" << current_foodgroup << "\n";
      std::cout << "----------------------\n";
    }
    
    std::cout << master_list->at(i).name << ", "
	   << master_list->at(i).quantity << " "
	   << master_list->at(i).unit << "\n";
  }
  
  return;
}

void print_recipe_names(std::vector<std::string>* recipe_names) {
  for (int i = 0; i < recipe_names->size(); ++i) {
    std::cout << recipe_names->at(i) << "\n";
  }
  return;
}
