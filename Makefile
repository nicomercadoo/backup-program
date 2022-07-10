# Variables
O_FILES = build/backup.o build/help.o build/add.o build/auxfunc.o
STD = -std=gnu11
# Common executable build
backup: $(O_FILES)
	gcc $(STD) -o backup $(O_FILES)

# Debug build
debug: $(O_FILES)
	gcc $(STD) -g3 -o backup $(O_FILES)

# backup.o
build/backup.o: backup.c
	gcc $(STD) -g3 -c backup.c -o build/backup.o

# help.o
build/help.o: help.c
	gcc $(STD) -g3 -c help.c -o build/help.o

# add.o
build/add.o: add.c
	gcc $(STD) -g3 -c add.c -o build/add.o

build/auxfunc.o: auxfunc.c
	gcc $(STD) -g3 -c auxfunc.c -o build/auxfunc.o
