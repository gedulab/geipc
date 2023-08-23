all: geipc geipcg geipco geipcm

geipc: geipc.c
	gcc -o $@ $^

geipcg: geipc.c
	gcc -g -o $@ $^

geipco: geipc.c
	gcc -O3 -g -o $@ $^
geipcm: geipc.c
	gcc -O3 -g -march=armv8.5-a+simd -mtune=cortex-a76.cortex-a55 -o $@ $^ 

clean:
	rm geipc geipcg geipco geipcm 
