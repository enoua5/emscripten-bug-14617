CC = em++
OPTIONS = -s WASM=1 --bind --no-entry
OUT = crashtest.js

$(OUT): crashtest.cpp
	$(CC) $(OPTIONS) -o $(OUT) crashtest.cpp
	
clean:
	rm $(OUT)
	rm *.wasm
