# Programme à créer
PROG= projet

# Sources
SRC = \
    main/main.c \
    combat/combat.c \
    demarrage/demar.c \
    pokemon/choixpokes.c \
    pokemon/structure.c \
    pokemon/fonction.c \
    pokemon/affichage.c

# Règle par défaut : compile et exécute
all: $(PROG)
	./$(PROG)

# Compilation du programme
$(PROG): $(SRC) pokemon/structure.h pokemon/fonction.h pokemon/affichage.h pokemon/choixpokes.h demarrage/demar.h combat/combat.h
	gcc -Wall -o $(PROG) $(SRC)

# Nettoyage
clean:
	rm -f $(PROG)