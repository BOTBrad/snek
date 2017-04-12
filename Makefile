all:
	mkdir -p build
	cd build
	rebuild -I src/ snek.native
	mv snek.native snek

clean:
	mkdir -p build
	cd build
	rebuild -clean

