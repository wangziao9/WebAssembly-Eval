This benchmark compares the runtime of native C++ vs WebAssembly for arbitrary C++ functions. We "calculating the sum of all prime numbers that is not greater than N", which is implemented by two for loops, as an example workload that takes substantial time to execute.

1. Native Machine Code: `make native` compiles the code to an executable in native machine code (the usual compilation process).

2. WebAssembly: `make wasm_app` invokes the tool "emscripten". Emscripten compiles the C++ code to WebAssembly (creates a WebAssembly file in this folder), and creates a HTML file and a JavaScript file which enables both user interaction in the browser and execution of the WebAssembly code. To run, open wasm_app.html in a browser.

3. JavaScript Only: To run, open js_app.html in a browser. For a version that uses BigInt to represent integers in the original C++ program, open js_app_bigint.html.


| x | Native(ms) | WebAssembly (ms) | JavaScript (ms) | JavaScript-BigInt (ms)
| ------- | ------- | ------- | ------- | ------- |
| 10000 | 1 | 0 | 4 | 26 |
| 30000 | 4 | 4 | 6 | 74 |
| 100000 | 10 | 12 | 7 | 311 |
| 300000 | 38 | 34 | 29 | 1387 |
| 1000000 | 172 | 165 | 131 | 7293 |
| 3000000 | 776 | 779 | 570 | - |
| 10000000 | 4220 | 4215 | 3312 | - |

For this example application and range of inputs, JavaScript and WebAssembly's version of the C++ program are both fast enough (around native speed) in the browser.