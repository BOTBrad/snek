all:
	mkdir -p build
	cd build
	rebuild -r -cflags "-no-alias-deps -w -40+6+7+27+32..39+44+45" -I src/ snek.native
	mv snek.native snek

clean:
	mkdir -p build
	cd build
	rebuild -clean

