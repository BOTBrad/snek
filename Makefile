all:
	mkdir -p build
	cd build
	rebuild -r -I src/ snek.native
	mv snek.native snek

clean:
	mkdir -p build
	cd build
	rebuild -clean

