game: main.c
	gcc -o build/game \
	main.c graphics.c logic.c input.c \
	./raylib/libraylib.a -lm -lX11 \
	-I./raylib/include/ -I./

