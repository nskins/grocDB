#include <iostream>
#include "groc_db.h"
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void add_to_db(Recipe *r) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  
  std::string sql;

  // Open database.
  rc = sqlite3_open("groc.db", &db);
  if (rc) {
    std::cout << "Error opening database.\n";
    exit(0);
  }

  // Set and execute an SQL statement.
  sql = std::string("INSERT INTO recipes VALUES ('") +
    r->getName() + "', '" + r->getDirections() +
    "', "  + std::to_string(r->getServes()) + ");";
  rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &zErrMsg);

  // Error handling.
  if (rc != SQLITE_OK) {
    std::cout << "SQL Error!\n";
    std::cout << zErrMsg << "\n";
    sqlite3_free(zErrMsg);
    exit(0);
  }
  
  int size = r->getIngredients().size();

  // Add an entry for every ingredient in the recipe.
  for (int i = 0; i < size; ++i) {
    sql = std::string("INSERT INTO madewith VALUES ('") +
      r->getName() + "', '" + (r->getIngredients().at(i).name) + "', '" +
      r->getIngredients().at(i).foodgroup + "', '" +
      r->getIngredients().at(i).unit + "', " +
      std::to_string(r->getIngredients().at(i).quantity) + ");";
    rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &zErrMsg);

    // Error handling.
    if (rc != SQLITE_OK) {
      std::cout << "SQL Error!\n";
      std::cout << zErrMsg << "\n";
      sqlite3_free(zErrMsg);
      exit(0);
    }
  }

  // Close database.
  sqlite3_close(db);

  return;
}

void remove_from_db(std::string name) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  
  std::string sql;

  // Open database.
  rc = sqlite3_open("groc.db", &db);
  if (rc) {
    std::cout << "Error opening database.\n";
    exit(0);
  }

  // Set and execute an SQL statement.
  sql = std::string("DELETE FROM madewith WHERE recipe='") +
    name + "';";
  rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &zErrMsg);

  // Error handling.
  if (rc != SQLITE_OK) {
    std::cout << "SQL Error!\n";
    std::cout << zErrMsg << "\n";
    sqlite3_free(zErrMsg);
    exit(0);
  }

  // Set and execute an SQL statement.
  sql = std::string("DELETE FROM recipes WHERE name='") +
    name + "';";
  rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &zErrMsg);

  // Error handling.
  if (rc != SQLITE_OK) {
    std::cout << "SQL Error!\n";
    std::cout << zErrMsg << "\n";
    sqlite3_free(zErrMsg);
    exit(0);
  }

  // Close database.
  sqlite3_close(db);
  
}

static int retrieve_callback_1(void *data, int argc,
			     char **argv, char **azColName) {

  // Static cast the void pointer.
  Recipe* r = static_cast<Recipe*>(data);
  
  r->setName(argv[0]);
  r->setDirections(argv[1]);
  r->setServes(atoi(argv[2]));

  return 0;
}

static int retrieve_callback_2(void *data, int argc,
			       char **argv, char **azColName) {
  // argc is the number of attributes retreived from the row.
  // azColName is the name of the i^th column (0 <= i < argc).
  // argv is the attribute for the i^th column.

  // Static cast the void pointer.
  std::vector<Ingredient> *ingredients =
    static_cast<std::vector<Ingredient>*>(data);
  
  // argv[1] is the ingredient's name
  // argv[2] is the ingredient's foodgroup
  // argv[3] is the unit of measurement
  // argv[4] is the quantity
  Ingredient j { argv[1], argv[2], argv[3], atof(argv[4]) };
  ingredients->push_back(j);

  return 0;
}

void retrieve_from_db(std::string name, Recipe *r) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  
  std::string sql;

  // Open database.
  rc = sqlite3_open("groc.db", &db);
  if (rc) {
    std::cout << "Error opening database.\n";
    exit(0);
  }

  // Set and execute an SQL statement.
  sql = std::string("SELECT * FROM recipes") +
        " WHERE name = '" + name + "';";
  rc = sqlite3_exec(db, sql.c_str(), retrieve_callback_1,
		    r, &zErrMsg);

  // Error handling.
  if (rc != SQLITE_OK) {
    std::cout << "SQL Error!\n";
    std::cout << zErrMsg << "\n";
    sqlite3_free(zErrMsg);
    exit(0);
  }

  // We must initialize the ingredients vector outside
  // of the callback function.
  std::vector<Ingredient> ingredients;

  // Set and execute an SQL statement.
  sql = std::string("SELECT * FROM madewith WHERE recipe = '")
    + name + "';";
  // This statement is called once for each row that is SELECTed.
  rc = sqlite3_exec(db, sql.c_str(), retrieve_callback_2,
		    &ingredients, &zErrMsg);

  r->setIngredients(ingredients);

  // Error handling.
  if (rc != SQLITE_OK) {
    std::cout << "SQL Error!\n";
    std::cout << zErrMsg << "\n";
    sqlite3_free(zErrMsg);
    exit(0);
  }

  // Close database.
  sqlite3_close(db);
  
  return;
}
