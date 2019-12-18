rm -f algobench.o &&
# gcc -Wno-unused-const-variable -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall -funroll-loops -maes -pipe -ffloat-store -fsingle-precision-constant -fcx-fortran-rules algobench.c md6/*.c sha3/*.c -o algobench.o &&
gcc -Wno-unused-const-variable -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall -funroll-loops -maes -pipe -ffloat-store -fsingle-precision-constant -fcx-fortran-rules algobench.c dcrypt/*.c -o algobench.o -lcrypto -lm &&
./algobench.o
