#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "sha3.h"

uint64_t getTime(){
        struct timespec te;
        clock_gettime(CLOCK_REALTIME, &te);
        return 1000ULL*te.tv_sec + te.tv_nsec/1000000ULL;
}

int main(int argc, char** argv){
	uint32_t header32[32];
	uint8_t  widths[6]     = {32, 48, 64, 80, 96, 112};
	char*    hashNames[13] = {"Blue Midnight Wish [BMW]", "Groestl", "Skein", "JH", "Keccak",
			          "Luffa", "Shavite", "SIMD", "Echo", "Hamsi", "Fugue", "Shabal", "MD6"};
	uint8_t  printing      = argc>1?atoi(argv[1]):0;
	uint8_t  iterShifts    = argc>2?atoi(argv[2]):20;
	uint32_t seed          = argc>3?atoi(argv[3]):0x89ABCDEF;
	uint32_t iter          = 1UL<<(iterShifts-3);
	uint8_t* header        = (uint8_t*)header32;
	uint8_t* hash          = header;
	uint64_t curTime       = 0;
	uint8_t  width         = 0;
	uint32_t ctr           = 0;
	srand(seed);
	for(uint8_t i=0;i<32;i++) header32[i] = rand();
	if(printing){
		char buffer[65] = {0};
		for(uint8_t i=0; i<13; i++){
			printf("\nHash Algorithm: %s\n",hashNames[i]);
			for(uint8_t j=0; j<6; j++){
				for(uint8_t k=0;k<64;k++) buffer[k]=' ';
				width = widths[j];
				curTime = getTime();
				for(uint8_t k=0;k<64;k++){
					printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
					iter = 1UL<<(iterShifts-9);
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
				printf("\tProcessing %u bytes %lu times took %lums\n", width, 1UL<<(iterShifts), getTime()-curTime);
			}
		}
		
	}else{
		for(uint8_t i=0; i<13; i++){
			printf("\nHash Algorithm: %s\n",hashNames[i]);
			for(uint8_t j=0; j<6; j++){
				width = widths[j];
				curTime = getTime();
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
				printf("\tProcessing %u bytes %lu times took %lums\n", width, 1UL<<(iterShifts), getTime()-curTime);
			}
		}
	}
}

