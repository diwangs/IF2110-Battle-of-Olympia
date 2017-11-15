DEP = game.c player.c unit.c listunit.c peta.c point.c listvillage.c main.c pcolor/pcolor.c

all : $(DEP)
	gcc $(DEP) -o main -lm 
