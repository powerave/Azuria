# Nom de l'exécutable
NAME        = game

# Compilateur et drapeaux
CC          = g++
CXXFLAGS    = -std=c++17 -Wall -Wextra -g -Isrc
# Bibliothèques SFML
LDFLAGS     = -lsfml-graphics -lsfml-window -lsfml-system

# Récupération automatique des sources
# Prend main.cpp ET tous les .cpp dans src/ et ses sous-dossiers
SRC         = main.cpp \
              $(shell find src -name "*.cpp")

# Transformation des .cpp en .o
OBJ         = $(SRC:.cpp=.o)

# Règle principale
all: $(NAME)

# Édition des liens (Création de l'exécutable)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "Compilation terminée ! Lancez avec ./$(NAME)"

# Compilation des fichiers objets (.o)
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyage complet (objets + exécutable)
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
