# WebAssembly-Eval
Evaluate the performance of WebAssembly

## WebAssembly Tutorials

WS defines a binary format (.wasm) and a human-readable text format (.wat). It is a compilation target of other languages.

Example runtimes of the language: (Integrated in Web Browser), wasmer, wasm3, wasmtime, wasmedge, ...

[Tutorial](https://awesome.red-badger.com/chriswhealy/Introduction%20to%20WebAssembly%20Text/03/), [Reference](https://developer.mozilla.org/en-US/docs/WebAssembly/JavaScript_interface) for running WebAssembly using JavaScript Runtime (Node.js / Browser) as a host environment. (Using the "WebAssembly" JavaScript namespace object)

A basic [tutorial](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm) to compile C/C++ to WebAssembly (Using Emscripten).

A basic [tutorial](https://developer.mozilla.org/en-US/docs/WebAssembly/Rust_to_wasm) to compile Rust to WebAssembly (Thanks to the wasm-pack crate)

For these examples to work, opening the html file using the browser is not enough - it is necessary to set up a local http server (for example Apache) and access the file through the server.