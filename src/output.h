#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>

// EFFECTS: Prints the available command-line options.
void print_commands();

// MODIFIES: output
// EFFECTS: Prints the grocery list
//          in a fashionable manner.
void print_grocery_list(ostream &output);

#endif
