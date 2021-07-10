# emscripten-bug-14617
Just showcasing in a succinct example emscripten-core/emscripten#14617 

Run `make`, run the resulting build on a simple server, and look in the js console.

After a few seconds, you should get two messages like the following, though specific numbers may vary.
First a warning:
```
crashtest.js:1459 Cannot enlarge memory arrays to size 16781312 bytes (OOM). Either (1) compile with  -s INITIAL_MEMORY=X  with X higher than the current value 16777216, (2) compile with  -s ALLOW_MEMORY_GROWTH=1  which allows increasing the size at runtime, or (3) if you want malloc to return NULL (0) instead of this abort, compile with  -s ABORTING_MALLOC=0
 abort	@	crashtest.js:1459
 abortOnCannotGrowMemory	@	crashtest.js:3304
 _emscripten_resize_heap	@	crashtest.js:3309
 (anonymous)	@	crashtest.wasm:0x4fe0
 malloc	@	crashtest.wasm:0x3a65
 (anonymous)	@	crashtest.wasm:0x2286
 (anonymous)	@	crashtest.wasm:0xe98
 (anonymous)	@	crashtest.wasm:0xa84
 get	@	crashtest.js:2890
 onRuntimeInitialized	@	(index):10
 doRun	@	crashtest.js:3793
 run	@	crashtest.js:3810
 runCaller	@	crashtest.js:3752
 removeRunDependency	@	crashtest.js:1444
 receiveInstance	@	crashtest.js:1623
 receiveInstantiationResult	@	crashtest.js:1640
 Promise.then (async)		
 (anonymous)	@	crashtest.js:1667
 Promise.then (async)		
 instantiateAsync	@	crashtest.js:1665
 createWasm	@	crashtest.js:1693
 (anonymous)	@	crashtest.js:3365
```

Then an error:
```
crashtest.js:1470 Uncaught (in promise) RuntimeError: abort(Cannot enlarge memory arrays to size 16781312 bytes (OOM). Either (1) compile with  -s INITIAL_MEMORY=X  with X higher than the current value 16777216, (2) compile with  -s ALLOW_MEMORY_GROWTH=1  which allows increasing the size at runtime, or (3) if you want malloc to return NULL (0) instead of this abort, compile with  -s ABORTING_MALLOC=0 ) at Error
    at jsStackTrace (crashtest.js:1748)
    at stackTrace (crashtest.js:1765)
    at abort (crashtest.js:1464)
    at abortOnCannotGrowMemory (crashtest.js:3304)
    at _emscripten_resize_heap (crashtest.js:3309)
    at crashtest.wasm:0x4fe0
    at malloc (crashtest.wasm:0x3a65)
    at crashtest.wasm:0x2286
    at crashtest.wasm:0xe98
    at crashtest.wasm:0xa84
    at abort (crashtest.js:1470)
    at abortOnCannotGrowMemory (crashtest.js:3304)
    at _emscripten_resize_heap (crashtest.js:3309)
    at crashtest.wasm:0x4fe0
    at malloc (crashtest.wasm:0x3a65)
    at crashtest.wasm:0x2286
    at crashtest.wasm:0xe98
    at crashtest.wasm:0xa84
    at Parent.get [as child] (crashtest.js:2890)
    at Object.onRuntimeInitialized ((index):10)    
 abort	@	crashtest.js:1470
 abortOnCannotGrowMemory	@	crashtest.js:3304
 _emscripten_resize_heap	@	crashtest.js:3309
 (anonymous)	@	crashtest.wasm:0x4fe0
 malloc	@	crashtest.wasm:0x3a65
 (anonymous)	@	crashtest.wasm:0x2286
 (anonymous)	@	crashtest.wasm:0xe98
 (anonymous)	@	crashtest.wasm:0xa84
 get	@	crashtest.js:2890
 onRuntimeInitialized	@	(index):10
 doRun	@	crashtest.js:3793
 run	@	crashtest.js:3810
 runCaller	@	crashtest.js:3752
 removeRunDependency	@	crashtest.js:1444
 receiveInstance	@	crashtest.js:1623
 receiveInstantiationResult	@	crashtest.js:1640
```
