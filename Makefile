build: main.c clay_renderer_raylib.c
	gcc -I./raylib-5.5_linux_amd64/include/ \
	-o main main.c											    \
	-L./raylib-5.5_linux_amd64/lib/         \
	-l:libraylib.a -lm

run: build
	./main
