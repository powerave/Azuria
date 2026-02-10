# Makefile mis à jour pour le projet Azuria
# Ajout de vérifications pour les dépendances et clarification des sections

# Nom de l'exécutable
NAME        = game

# Compilateur et drapeaux
CC          = g++
SFML_DIR    = SFML-2.6.1
CXXFLAGS    = -std=c++17 -Wall -Wextra -g -v -D_GLIBCXX_USE_CXX11_ABI=1 -Isrc -I$(SFML_DIR)/include -IIncludes
# Bibliothèques SFML
LDFLAGS     = -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,$(SFML_DIR)/lib

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

# Vérification des dépendances SFML
check-sfml:
	@if [ ! -d "$(SFML_DIR)" ]; then \
		echo "Erreur : Le dossier SFML n'existe pas. Veuillez vérifier le chemin."; \
		exit 1; \
	fi

.PHONY: all clean fclean re check-sfml
