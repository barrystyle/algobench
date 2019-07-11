rm -f algobench.o &&
gcc -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall -funroll-loops -maes -pipe -ffloat-store -fsingle-precision-constant -fcx-fortran-rules algobench.c sha3/*.c -o algobench.o &&
./algobench.o
