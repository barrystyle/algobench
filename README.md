Compile and execute the program using `bash compile.sh` on Unix-based systems or `cl *.c sha3\*.c /Ox /Ot /arch:AVX2 /GA /GL /GS /Qpar /link /LARGEADDRESSAWARE && algobench.exe` to benchmark all twelve algorithms contained in this suite with maximum optimisation and no portability.

The following benchmarking results from a [Xeon E3-1225v2](https://ark.intel.com/content/www/de/de/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html) in Ubuntu 18.04.3 give an idea about what the output of the program is going to be. Those results also work as reference values.

```
Hash Algorithm: Blue Midnight Wish [BMW]
        Processing 32 bytes 67108864 times took 21s                              
        Processing 48 bytes 67108864 times took 20s                              
        Processing 64 bytes 67108864 times took 20s                              
        Processing 80 bytes 67108864 times took 21s                              
        Processing 96 bytes 67108864 times took 20s                              

Hash Algorithm: Groestl
        Processing 32 bytes 67108864 times took 155s                             
        Processing 48 bytes 67108864 times took 155s                             
        Processing 64 bytes 67108864 times took 154s                             
        Processing 80 bytes 67108864 times took 156s                             
        Processing 96 bytes 67108864 times took 153s                             

Hash Algorithm: Skein
        Processing 32 bytes 67108864 times took 17s                              
        Processing 48 bytes 67108864 times took 17s                              
        Processing 64 bytes 67108864 times took 18s                              
        Processing 80 bytes 67108864 times took 25s                              
        Processing 96 bytes 67108864 times took 26s                              

Hash Algorithm: JH
        Processing 32 bytes 67108864 times took 150s                             
        Processing 48 bytes 67108864 times took 152s                             
        Processing 64 bytes 67108864 times took 154s                             
        Processing 80 bytes 67108864 times took 224s                             
        Processing 96 bytes 67108864 times took 222s                             

Hash Algorithm: Keccak
        Processing 32 bytes 67108864 times took 41s                              
        Processing 48 bytes 67108864 times took 39s                              
        Processing 64 bytes 67108864 times took 40s                              
        Processing 80 bytes 67108864 times took 76s                              
        Processing 96 bytes 67108864 times took 73s                              

Hash Algorithm: Luffa
        Processing 32 bytes 67108864 times took 95s                              
        Processing 48 bytes 67108864 times took 96s                              
        Processing 64 bytes 67108864 times took 118s                             
        Processing 80 bytes 67108864 times took 118s                             
        Processing 96 bytes 67108864 times took 143s                             

Hash Algorithm: Shavite
        Processing 32 bytes 67108864 times took 69s                              
        Processing 48 bytes 67108864 times took 71s                              
        Processing 64 bytes 67108864 times took 69s                              
        Processing 80 bytes 67108864 times took 70s                              
        Processing 96 bytes 67108864 times took 69s                              

Hash Algorithm: SIMD
        Processing 32 bytes 67108864 times took 180s                             
        Processing 48 bytes 67108864 times took 181s                             
        Processing 64 bytes 67108864 times took 181s                             
        Processing 80 bytes 67108864 times took 181s                             
        Processing 96 bytes 67108864 times took 179s                             

Hash Algorithm: Echo
        Processing 32 bytes 67108864 times took 148s                             
        Processing 48 bytes 67108864 times took 148s                             
        Processing 64 bytes 67108864 times took 149s                             
        Processing 80 bytes 67108864 times took 148s                             
        Processing 96 bytes 67108864 times took 147s                             

Hash Algorithm: Hamsi
        Processing 32 bytes 67108864 times took 184s                             
        Processing 48 bytes 67108864 times took 231s                             
        Processing 64 bytes 67108864 times took 274s                             
        Processing 80 bytes 67108864 times took 319s                             
        Processing 96 bytes 67108864 times took 360s                             

Hash Algorithm: Fugue
        Processing 32 bytes 67108864 times took 165s                             
        Processing 48 bytes 67108864 times took 179s                             
        Processing 64 bytes 67108864 times took 195s                             
        Processing 80 bytes 67108864 times took 211s                             
        Processing 96 bytes 67108864 times took 225s                             

Hash Algorithm: Shabal
        Processing 32 bytes 67108864 times took 30s                              
        Processing 48 bytes 67108864 times took 28s                              
        Processing 64 bytes 67108864 times took 38s                              
        Processing 80 bytes 67108864 times took 38s                              
        Processing 96 bytes 67108864 times took 38s   
```
