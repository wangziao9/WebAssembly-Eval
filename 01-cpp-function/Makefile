native: workload.h workload.cpp native.cpp
	g++ -O3 native.cpp workload.cpp -o native

wasm_app: workload.h workload.cpp wasm.cpp
	emcc -o wasm_app.html wasm.cpp workload.cpp -O3 --shell-file shell_minimal.html -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" -s ALLOW_MEMORY_GROWTH=1

clean:
	rm native wasm_app.wasm wasm_app.js wasm_app.html
