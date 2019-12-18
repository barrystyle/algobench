#include "dcrypt/dcrypt.h"
#include "dcrypt/dcrypt_sha256.h"

#define uint8_t unsigned char

// void dcrypt(const unsigned char *data, size_t data_sz, unsigned char *hash_digest, uint32_t *hashRet);
// void dcrypt(const uint8_t *data, size_t data_sz, uint8_t *hash_digest, uint32_t *hashRet)
inline static const void hash1(const uint8_t* input, uint32_t* output, uint8_t dataLen) {
    dcrypt(input, dataLen, 0, output);
}

typedef  void (*hash_t)(const uint8_t*, uint32_t*, uint8_t);
hash_t hashFunction[1] = {&hash1};
