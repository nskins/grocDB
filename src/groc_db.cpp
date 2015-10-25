#include <iostream>
#include "groc_db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
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
  sql = "INSERT INTO dishes VALUES (" +
    r->getName() + ", " + std::to_string(r->getServes()) + ");";
rc = sqlite3_exec(db, std::c_str(sql), NULL, NULL, &zErrMsg);

  // Error handling.
  if (rc != SQLITE_OK) {
    std::cout << "SQL Error: " + zErrMsg + "\n";
    sqlite3_free(zErrMsg);
    exit(0);
  }
  
  int size = r->getIngredients()->size();

  // Add an entry for every ingredient in the recipe.
  for (int i = 0; i < size; ++i) {
    sql = "INSERT INTO madewith VALUES (" +
      r->getName() + ", " + r->(*getIngredients())[i].(*name) + ", " +
      to_string(r->(*getIngredients())[i].quantity) + ", " +
      r->(*getIngredients())[i].(*unit) + ", " +
      r->(*getIngredients())[i].(*foodgroup) + ");";
    rc = sqlite3_exec(db, std::c_str(sql), NULL, NULL, &zErrMsg);

    // Error handling.
    if (rc != SQLITE_OK) {
      std::cout << "SQL Error: " + zErrMsg + "\n";
      sqlite3_free(zErrMsg);
      exit(0);
    }
  }

  // Close database.
  sqlite3_close(db);
}
