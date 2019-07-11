rm -f algobench
 gcc -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall -funroll-loops -maes -pipe -ffloat-store -fsingle-precision-constant -fcx-fortran-rules *.c sha3/*.c -o algobench
./algobench
