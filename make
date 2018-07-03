rm -f algobench
gcc -O3 algobench.c sha3/*.c -o algobench
./algobench
