native: smallpt.cpp
	g++ -std=c++11 -O3 -fopenmp smallpt.cpp -o smallpt

native-noopenmp: smallpt.cpp
	g++ -std=c++11 -O3 smallpt.cpp -o smallpt-noopenmp

wasm_app: wasm.cpp
	emcc -lembind -o wasm_app.html wasm.cpp -O3 --shell-file shell_minimal.html -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" -s ALLOW_MEMORY_GROWTH=1 -s TOTAL_STACK=4mb -s INITIAL_MEMORY=16mb

clean:
	rm smallpt smallpt.exe image.ppm