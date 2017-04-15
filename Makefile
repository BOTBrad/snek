all:
	mkdir -p build && \
	rebuild -r -cflags "-no-alias-deps -w -40+6+7+27+32..39+44+45" -I src/ main.native && \
	mv -f main.native build/snek

clean:
	rm -rf build/* && \
	rebuild -clean

run: all
	./build/snek
