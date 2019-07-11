#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "sha3/sph_bmw.h"
#include "sha3/sph_groestl.h"
#include "sha3/sph_skein.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_keccak.h"
#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"
#include "sha3/sph_hamsi.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_shabal.h"


inline static const void hash1(const uint8_t* input, uint8_t* output, uint8_t dataLen) {
	sph_bmw512_context			 ctx_bmw;
	sph_bmw512_init(&ctx_bmw);
	sph_bmw512(&ctx_bmw, input, dataLen);
	sph_bmw512_close(&ctx_bmw, output);
}
	
inline static const void hash2(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_groestl512_context	 ctx_groestl;
	sph_groestl512_init(&ctx_groestl);
	sph_groestl512(&ctx_groestl, input, dataLen);
	sph_groestl512_close(&ctx_groestl, output);
}
	
inline static const void hash3(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_skein512_context		 ctx_skein;
	sph_skein512_init(&ctx_skein);
	sph_skein512(&ctx_skein, input, dataLen);
	sph_skein512_close(&ctx_skein, output);
}
	
inline static const void hash4(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_jh512_context				ctx_jh;
	sph_jh512_init(&ctx_jh);
	sph_jh512(&ctx_jh, input, dataLen);
	sph_jh512_close(&ctx_jh, output);
}		
		
inline static const void hash5(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_keccak512_context		ctx_keccak;
	sph_keccak512_init(&ctx_keccak);
	sph_keccak512(&ctx_keccak, input, dataLen);
	sph_keccak512_close(&ctx_keccak, output);
}		
		
inline static const void hash6(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_luffa512_context		 ctx_luffa;
	sph_luffa512_init(&ctx_luffa);
	sph_luffa512(&ctx_luffa, input, dataLen);
	sph_luffa512_close(&ctx_luffa, output);
}	
		
inline static const void hash7(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_shavite512_context	 ctx_shavite;
	sph_shavite512_init(&ctx_shavite);
	sph_shavite512(&ctx_shavite, input, dataLen);
	sph_shavite512_close(&ctx_shavite, output);
}
		
inline static const void hash8(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_simd512_context			ctx_simd;
	sph_simd512_init(&ctx_simd);
	sph_simd512(&ctx_simd, input, dataLen);
	sph_simd512_close(&ctx_simd, output);
}
		
inline static const void hash9(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_echo512_context			ctx_echo;
	sph_echo512_init(&ctx_echo);
	sph_echo512(&ctx_echo, input, dataLen);
	sph_echo512_close(&ctx_echo, output);
}		
		
inline static const void hash10(const uint8_t* input, uint8_t* output, uint8_t dataLen) {				
	sph_hamsi512_context		 ctx_hamsi;
	sph_hamsi512_init(&ctx_hamsi);
	sph_hamsi512(&ctx_hamsi, input, dataLen);
	sph_hamsi512_close(&ctx_hamsi, output);
}	
		
inline static const void hash11(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_fugue512_context		 ctx_fugue;
	sph_fugue512_init(&ctx_fugue);
	sph_fugue512(&ctx_fugue, input, dataLen);
	sph_fugue512_close(&ctx_fugue, output);
} 		
		
inline static const void hash12(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_shabal512_context		ctx_shabal;
	sph_shabal512_init(&ctx_shabal);
	sph_shabal512(&ctx_shabal, input, dataLen);
	sph_shabal512_close(&ctx_shabal, output);
} 

typedef  void (*hash_t)(const uint8_t*, uint8_t*, uint8_t);
hash_t hashFunction[12] = {&hash1, &hash2, &hash3,  &hash4,  &hash5, &hash6, &hash7,
					 &hash8, &hash9, &hash10, &hash11, &hash12};

#define GET_TIME (uint32_t)time(NULL)

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
	uint32_t curTime       = 0;
	uint8_t  width         = 0;
	uint32_t ctr           = iter;
	srand(seed);
	for(uint8_t i=0;i<32;i++) header32[i] = rand();
	if(printing){
		iter>>=6; ctr>>=6; 
		char buffer[65] = {0};
		for(uint8_t i=0; i<12; i++){
			printf("\nHash Algorithm: %s\n",hashNames[i]);
			for(uint8_t j=0; j<5; j++){
				for(uint8_t k=0;k<64;k++) buffer[k]=' ';
				width = widths[j];
				curTime = GET_TIME;
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
				printf("\tProcessing %u bytes %u times took %us\n", width, 1UL<<(iterShifts), GET_TIME-curTime);
			}
		}
		
	}else{
		for(uint8_t i=0; i<12; i++){
			printf("\nHash Algorithm: %s\n",hashNames[i]);
			for(uint8_t j=0; j<5; j++){
				width = widths[j];
				printf("\tInput Width: %u bytes\n", width);
				curTime = GET_TIME;
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
				printf("\tCalculating %u hashes took: %us\n", 1UL<<(iterShifts), GET_TIME-curTime);
			}
		}
	}
}

