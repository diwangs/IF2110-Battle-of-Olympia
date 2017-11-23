DEP = game.c player.c unit.c listunit.c peta.c point.c listvillage.c main.c pcolor/pcolor.c village.c util.c mesincmd.c playerq.c mesinkarsave.c mesinsave.c

main : $(DEP)
	gcc $(DEP) -o main -lm 
