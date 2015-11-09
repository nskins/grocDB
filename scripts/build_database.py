import os
import sqlite3

# Open groc.db in the appropriate location.
conn = sqlite3.connect(os.getcwd() + '//groc.db')

# Establish a cursor.
c = conn.cursor()

# Execute SQL statements.
c.execute(
'''CREATE TABLE recipes (
name TEXT PRIMARY KEY,
directions TEXT,
serves INT);''')

c.execute(
'''CREATE TABLE madewith (
recipe TEXT REFERENCES recipes(name),
ingredient TEXT,
ingredientFg TEXT,
ingredientUnit TEXT,
ingredientQty NUMERIC(7,2),
PRIMARY KEY(recipe, ingredient));''')

# Commit changes.
conn.commit()

# Close groc.db
conn.close()



