#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "sha3.h"

// borrowed from yiimp
long long GET_TIME()
{
        long long milliseconds;
        struct timespec te;
        clock_gettime(CLOCK_REALTIME, &te);
        milliseconds = 1000LL*te.tv_sec + round(te.tv_nsec/1e6);
        return milliseconds;
}

int main(int argc, char** argv){
	uint32_t header32[32];
	uint8_t  widths[6]     = {32, 48, 64, 80, 96, 112};
	char*    hashNames[12] = {"Blue Midnight Wish [BMW]", "Groestl", "Skein", "JH", "Keccak",
			          "Luffa", "Shavite", "SIMD", "Echo", "Hamsi", "Fugue", "Shabal"};
	uint8_t  printing      = argc>1?atoi(argv[1]):0;
	uint8_t  iterShifts    = argc>2?atoi(argv[2]):20;
	uint32_t seed          = argc>3?atoi(argv[3]):0x89ABCDEF;
	uint32_t iter          = 1UL<<(iterShifts-3);
	uint8_t* header        = (uint8_t*)header32;
	uint8_t* hash          = header;
	long long curTime      = 0;
	uint8_t  width         = 0;
	uint32_t ctr           = iter;
	srand(seed);
	for(uint8_t i=0;i<32;i++) header32[i] = rand();
	if(printing){
		iter>>=6; ctr>>=6; 
		char buffer[65] = {0};
		for(uint8_t i=0; i<12; i++){
			printf("\nHash Algorithm: %s\n",hashNames[i]);
			for(uint8_t j=0; j<6; j++){
				for(uint8_t k=0;k<64;k++) buffer[k]=' ';
				width = widths[j];
				curTime = GET_TIME();
				for(uint8_t k=0;k<64;k++){
					printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
					iter = 1UL<<(iterShifts-3);
					ctr = iter;
					do{
						hashFunction[i](header,hash,width);
						hashFunction[i](header,hash,width);
						hashFunction[i](header,hash,width);
						hashFunction[i](header,hash,width);
						hashFunction[i](header,hash,width);
						hashFunction[i](header,hash,width);
						hashFunction[i](header,hash,width);
						hashFunction[i](header,hash,width);
					}while(--ctr);
					buffer[k] = '#';
				}
				printf("\r%*s\r",80,"");
				printf("\tProcessing %lu bytes %u times took %ums\n", width, 1UL<<(iterShifts), GET_TIME()-curTime);
			}
		}
		
	}else{
		for(uint8_t i=0; i<12; i++){
			printf("\nHash Algorithm: %s\n",hashNames[i]);
			for(uint8_t j=0; j<6; j++){
				width = widths[j];
				printf("\tInput Width: %u bytes\n", width);
				curTime = GET_TIME();
				ctr = iter;
				do{
					hashFunction[i](header,hash,width);
					hashFunction[i](header,hash,width);
					hashFunction[i](header,hash,width);
					hashFunction[i](header,hash,width);
					hashFunction[i](header,hash,width);
					hashFunction[i](header,hash,width);
					hashFunction[i](header,hash,width);
					hashFunction[i](header,hash,width);
				}while(--ctr);
				printf("\tCalculating %lu hashes took: %ums\n", 1UL<<(iterShifts), GET_TIME()-curTime);
			}
		}
	}
}

