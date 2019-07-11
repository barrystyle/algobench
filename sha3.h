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

#define uint8_t unsigned char

inline static const void hash1(const uint8_t* input, uint8_t* output, uint8_t dataLen) {
	sph_bmw512_context ctx_bmw;
	sph_bmw512_init(&ctx_bmw);
	sph_bmw512(&ctx_bmw, input, dataLen);
	sph_bmw512_close(&ctx_bmw, output);
}
	
inline static const void hash2(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_groestl512_context ctx_groestl;
	sph_groestl512_init(&ctx_groestl);
	sph_groestl512(&ctx_groestl, input, dataLen);
	sph_groestl512_close(&ctx_groestl, output);
}
	
inline static const void hash3(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_skein512_context ctx_skein;
	sph_skein512_init(&ctx_skein);
	sph_skein512(&ctx_skein, input, dataLen);
	sph_skein512_close(&ctx_skein, output);
}
	
inline static const void hash4(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_jh512_context ctx_jh;
	sph_jh512_init(&ctx_jh);
	sph_jh512(&ctx_jh, input, dataLen);
	sph_jh512_close(&ctx_jh, output);
}		
		
inline static const void hash5(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_keccak512_context ctx_keccak;
	sph_keccak512_init(&ctx_keccak);
	sph_keccak512(&ctx_keccak, input, dataLen);
	sph_keccak512_close(&ctx_keccak, output);
}		
		
inline static const void hash6(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_luffa512_context ctx_luffa;
	sph_luffa512_init(&ctx_luffa);
	sph_luffa512(&ctx_luffa, input, dataLen);
	sph_luffa512_close(&ctx_luffa, output);
}	
		
inline static const void hash7(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_shavite512_context ctx_shavite;
	sph_shavite512_init(&ctx_shavite);
	sph_shavite512(&ctx_shavite, input, dataLen);
	sph_shavite512_close(&ctx_shavite, output);
}
		
inline static const void hash8(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_simd512_context ctx_simd;
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
	sph_hamsi512_context ctx_hamsi;
	sph_hamsi512_init(&ctx_hamsi);
	sph_hamsi512(&ctx_hamsi, input, dataLen);
	sph_hamsi512_close(&ctx_hamsi, output);
}	
		
inline static const void hash11(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_fugue512_context ctx_fugue;
	sph_fugue512_init(&ctx_fugue);
	sph_fugue512(&ctx_fugue, input, dataLen);
	sph_fugue512_close(&ctx_fugue, output);
} 		
		
inline static const void hash12(const uint8_t* input, uint8_t* output, uint8_t dataLen) {		
	sph_shabal512_context ctx_shabal;
	sph_shabal512_init(&ctx_shabal);
	sph_shabal512(&ctx_shabal, input, dataLen);
	sph_shabal512_close(&ctx_shabal, output);
} 

typedef  void (*hash_t)(const uint8_t*, uint8_t*, uint8_t);
hash_t hashFunction[12] = {&hash1, &hash2, &hash3,  &hash4,  &hash5, &hash6, &hash7,
			   &hash8, &hash9, &hash10, &hash11, &hash12};
