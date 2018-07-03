#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

void hash1(const char* input, char* output, int dataLen) {
        int hash[32];
        sph_bmw512_context       ctx_bmw;
        sph_bmw512_init(&ctx_bmw);
        sph_bmw512(&ctx_bmw, input, dataLen);
        sph_bmw512_close(&ctx_bmw, hash);
        memcpy(output,hash,64);
}
	
void hash2(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_groestl512_context   ctx_groestl;
        sph_groestl512_init(&ctx_groestl);
        sph_groestl512(&ctx_groestl, input, dataLen);
        sph_groestl512_close(&ctx_groestl, hash);
        memcpy(output,hash,64);
}
	
void hash3(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_skein512_context     ctx_skein;
        sph_skein512_init(&ctx_skein);
        sph_skein512(&ctx_skein, input, dataLen);
        sph_skein512_close(&ctx_skein, hash);
        memcpy(output,hash,64);
}
	
void hash4(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_jh512_context        ctx_jh;
        sph_jh512_init(&ctx_jh);
        sph_jh512(&ctx_jh, input, dataLen);
        sph_jh512_close(&ctx_jh, hash);
        memcpy(output,hash,64);
}		
		
void hash5(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_keccak512_context    ctx_keccak;
        sph_keccak512_init(&ctx_keccak);
        sph_keccak512(&ctx_keccak, input, dataLen);
        sph_keccak512_close(&ctx_keccak, hash);
        memcpy(output,hash,64);
}		
		
void hash6(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_luffa512_context     ctx_luffa;
        sph_luffa512_init(&ctx_luffa);
        sph_luffa512(&ctx_luffa, input, dataLen);
        sph_luffa512_close(&ctx_luffa, hash);
        memcpy(output,hash,64);
}	
		
void hash7(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_shavite512_context   ctx_shavite;
        sph_shavite512_init(&ctx_shavite);
        sph_shavite512(&ctx_shavite, input, dataLen);
        sph_shavite512_close(&ctx_shavite, hash);
        memcpy(output,hash,64);
}
		
void hash8(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_simd512_context      ctx_simd;
        sph_simd512_init(&ctx_simd);
        sph_simd512(&ctx_simd, input, dataLen);
        sph_simd512_close(&ctx_simd, hash);
        memcpy(output,hash,64);
}
		
void hash9(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_echo512_context      ctx_echo;
        sph_echo512_init(&ctx_echo);
        sph_echo512(&ctx_echo, input, dataLen);
        sph_echo512_close(&ctx_echo, hash);
        memcpy(output,hash,64);
}		
		
void hash10(const char* input, char* output, int dataLen) {
        int hash[32];        
	sph_hamsi512_context     ctx_hamsi;
        sph_hamsi512_init(&ctx_hamsi);
        sph_hamsi512(&ctx_hamsi, input, dataLen);
        sph_hamsi512_close(&ctx_hamsi, hash);
        memcpy(output,hash,64);
}	
		
void hash11(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_fugue512_context     ctx_fugue;
        sph_fugue512_init(&ctx_fugue);
        sph_fugue512(&ctx_fugue, input, dataLen);
        sph_fugue512_close(&ctx_fugue, hash);
        memcpy(output,hash,64);
} 		
		
void hash12(const char* input, char* output, int dataLen) {
        int hash[32];		
        sph_shabal512_context    ctx_shabal;
        sph_shabal512_init(&ctx_shabal);
        sph_shabal512(&ctx_shabal, input, dataLen);
        sph_shabal512_close(&ctx_shabal, hash);
        memcpy(output,hash,64);
} 
	
long st1, st2, s1;

long qiktime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return t.tv_sec * 1000 + t.tv_usec / 1000;
}

int main()
{

  unsigned char header[128], hash[64];
  int width;
  long st1, st2;

  for (int widthvariant = 0; widthvariant < 4; widthvariant++) {

   // set variations
   if (widthvariant == 0) width = 32;
   if (widthvariant == 1) width = 48;
   if (widthvariant == 2) width = 80;
   if (widthvariant == 3) width = 96;
   if (widthvariant == 4) width = 112;

   // per algorithm
   for (int hashalgo = 1; hashalgo < 13; hashalgo++) {

    // clear 'header'
    for (int w = 0; w < width; w++)
      header[w] = 0;

     // set timer to zero
     st1 = qiktime();

     // iterate first three bytes like nonce
     for (int x = 0; x < 16; x++) {
      header[0] = x;
      for (int y = 0; y < 256; y++) {
       header[1] = y;
       for (int z = 0; z < 256; z++) {
        header[2] = z;

        // this favours no algorithm as all execute the same amount of conditional checks
        if (hashalgo == 1) hash1(header,hash,width);
        if (hashalgo == 2) hash2(header,hash,width);
        if (hashalgo == 3) hash3(header,hash,width);
        if (hashalgo == 4) hash4(header,hash,width);
        if (hashalgo == 5) hash5(header,hash,width);
        if (hashalgo == 6) hash6(header,hash,width);
        if (hashalgo == 7) hash7(header,hash,width);
        if (hashalgo == 8) hash8(header,hash,width);
        if (hashalgo == 9) hash9(header,hash,width);
        if (hashalgo == 10) hash10(header,hash,width);
        if (hashalgo == 11) hash11(header,hash,width);
        if (hashalgo == 12) hash12(header,hash,width);

       }
      }
     }

     // set timer finish
     st2 = qiktime();

     // print results
     printf("1mh worth of hashes on algorithm %d with headerwidth %lu took %lu ms\n", hashalgo, width, (st2-st1));

   }

  }

  return(0);

}
