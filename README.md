Compile and execute the program using `make` on Unix-based systems or `cl *.c sha3\*.c /Ox /Ot /arch:AVX2 /GA /GL /GS /Qpar /link /LARGEADDRESSAWARE && algobench.exe` to benchmark all twelve algorithms contained in this suite with maximum optimisation and no portability.

The following benchmarking results from a [Xeon E3-1225v2](https://ark.intel.com/content/www/de/de/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html) in Ubuntu 18.04.3 give an idea about what the output of the program is going to be. Those results also work as reference values.

```
Hash Algorithm: Blue Midnight Wish [BMW]
        Processing 32 bytes 1048576 times took 21s                              
        Processing 48 bytes 1048576 times took 20s                              
        Processing 64 bytes 1048576 times took 20s                              
        Processing 80 bytes 1048576 times took 21s                              
        Processing 96 bytes 1048576 times took 20s                              

Hash Algorithm: Groestl
        Processing 32 bytes 1048576 times took 155s                             
        Processing 48 bytes 1048576 times took 155s                             
        Processing 64 bytes 1048576 times took 154s                             
        Processing 80 bytes 1048576 times took 156s                             
        Processing 96 bytes 1048576 times took 153s                             

Hash Algorithm: Skein
        Processing 32 bytes 1048576 times took 17s                              
        Processing 48 bytes 1048576 times took 17s                              
        Processing 64 bytes 1048576 times took 18s                              
        Processing 80 bytes 1048576 times took 25s                              
        Processing 96 bytes 1048576 times took 26s   
```
