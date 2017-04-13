all:
	mkdir -p build && \
	rebuild -r -cflags "-no-alias-deps -w -40+6+7+27+32..39+44+45" -I src/ snek.native && \
	mv -f snek.native build/snek

clean:
	rm -rf build/* && \
	rebuild -clean

run: all
	./build/snek
