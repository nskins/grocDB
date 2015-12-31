CC=g++
CFLAGS=-std=c++11 -lsqlite3
SOURCES=src/driver.cpp src/groc_db.cpp src/output.cpp src/parse_file.cpp src/recipe.cpp

all: build_database grocDB

build_database: scripts/build_database.py
	python scripts/build_database.py

grocDB: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o grocDB

clean:
	rm grocDB groc.db
