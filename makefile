DEP = game.c player.c unit.c listunit.c peta.c point.c listbuilding.c main.c pcolor/pcolor.c building.c util.c mesincmd.c playerq.c mesinkarsave.c mesinsave.c template.c load.c save.c mesinkataload.c mesinkarload.c stackt.c

main : $(DEP)
	gcc $(DEP) -o main -lm -g
