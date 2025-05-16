// devurandom_windows.c
#include <windows.h>
#include <wincrypt.h>
#include <stdint.h>

void randombytes(uint8_t *buf, size_t len) {
    HCRYPTPROV hProvider = 0;
    CryptAcquireContext(&hProvider, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
    CryptGenRandom(hProvider, (DWORD)len, buf);
    CryptReleaseContext(hProvider, 0);
}
