This benchmark compares the runtime of native C++ vs WebAssembly for arbitrary C++ functions. 

1. Native Machine Code: `make native` compiles the code to an executable in native machine code (the usual compilation process).

2. WebAssembly: `make wasm_app` invokes the tool "emscripten". Emscripten compiles the C++ code to WebAssembly (creates a WebAssembly file in this folder), and creates a HTML file and a JavaScript file which enables both user interaction in the browser and execution of the WebAssembly code. To run, open wasm_app.html in a browser.

3. JavaScript Only: To run, open js_app.html in a browser. For a version that uses BigInt to represent integers in the original C++ program, open js_app_bigint.html.

Testcase 1: Calculating the sum of all prime numbers that is not greater than N. Task is CPU-Bound.

| N | Native(ms) | WebAssembly (ms) | JavaScript (ms) | JavaScript-BigInt (ms)
| ------- | ------- | ------- | ------- | ------- |
| 10000 | 1 | 0 | 4 | 26 |
| 30000 | 4 | 4 | 6 | 74 |
| 100000 | 9 | 12 | 7 | 311 |
| 300000 | 34 | 34 | 29 | 1387 |
| 1000000 | 179 | 165 | 131 | 7293 |
| 3000000 | 777 | 779 | 570 | - |
| 10000000 | 4186 | 4215 | 3312 | - |

For this example application and range of inputs, JavaScript and WebAssembly's version of the C++ program are both fast enough (around native speed) in the browser.

Testcase 2: Calculating Fibonacci numbers fib(x). This task is also CPU bound but involves lots of function calls (recursion).

| x | Navive(ms) | WebAssembly(ms) | 
| ------- | -------| ------- |
| 30 | 2 | 4 |
| 35 | 19 | 28 |
| 40 | 100 | 258 |
| 45 | 821 | 2789 |

In this testcase, WebAssembly is evidently slower than Native code. We infer that function calls are more expensive in WebAssembly.

Testcase 3: Matrix multiplication. Two integer matrices of size N x N are filled with numbers generated from Linear Congruential Generator and then multiplied. This task takes a lot of arithmetic operations and memory access.

| N | Navive(ms) | WebAssembly(ms) | 
| ------- | -------| ------- |
| 100 | 2 | 2 |
| 200 | 13 | 9 |
| 300 | 19 | 24 |
| 400 | 52 | 60 |
| 500 | 82 | 98 |
| 700 | 203 | 274 |
| 1000 | 681 | 837 |
| 1500 | 2711 | 3240 |
| 2000 | 6196 | 8357 |
| 2500 | 14647 | 19993 |
| 3000 | 23813 | 31348 |

On this task, WebAssembly is slower than native. Without the `-s ALLOW_MEMORY_GROWTH=1` emcc compiler option, WebAssembly throws an OOM (out of memory) exception for N >= 1500, since it defaults to using a fixed sized (16MB) memory.