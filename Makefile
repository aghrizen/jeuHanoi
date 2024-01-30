CC = g++            # le compilateur à utiliser
CFLAGS = -g -Wall -pedantic -std=c++11 # les options du compilateur
LDFLAGS = -lSDL2       # les options pour l'éditeur de liens
LDLIBS = -lSDL2
SRC = main.cpp Tours.cpp jeuHanoi.cpp Disque.cpp # les fichiers sources
PROG = main          # nom de l'exécutable
OBJS =  $(SRC:.cpp=.o) # les .o qui en découlent
.SUFFIXES: .cpp .o     # lien entre les suffixes

all: run

# étapes de compilation et d'édition de liens
# $@ la cible  $^ toutes les dépendances	
$(PROG): $(OBJS)
	$(CC)  -o $@ $^ $(LDFLAGS)

Disque.o : Disque.hpp
Tours.o : Tours.hpp Disque.hpp

jeuHanoi.o : jeuHanoi.hpp Disque.hpp Tours.hpp 
main.o : jeuHanoi.hpp Tours.hpp Disque.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# exécute l'interface
run: $(PROG)
	./$(PROG)
# pour faire propre
.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
