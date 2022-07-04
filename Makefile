# Variables
O_FILES = build/backup.o build/help.o build/add.o

# Common executable build
backup: $(O_FILES)
	gcc -o backup $(O_FILES)

# Debug build
debug: $(O_FILES)
	gcc -g3 -o backup $(O_FILES)

# backup.o
build/backup.o: backup.c
	gcc -c backup.c -o build/backup.o

# help.o
build/help.o: help.c
	gcc -c help.c -o build/help.o

# add.o
build/add.o: add.c
	gcc -c add.c -o build/add.o