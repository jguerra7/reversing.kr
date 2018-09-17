#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void XorBytes(uint8_t a[], const uint8_t b[]) {
    ((uint64_t*)a)[0] ^= ((const uint64_t*)b)[0];
    ((uint32_t*)a)[2] ^= ((const uint32_t*)b)[2];
    ((uint8_t*)a)[12] ^= ((const uint8_t*)b)[12];
}

int main(int argc, char* argv[]) {

    uint8_t origin[13] = {
        0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30
    };

    uint8_t particular_solution[13] = {
        0x74, 0x0c, 0x3f, 0x09, 0x39, 0x03, 0x36, 0x77, 0x29, 0x00, 0x00, 0x00, 0x00
    };

    uint8_t general_solutions[27][13] = {
        { 0x01, 0x00, 0x00, 0x00, 0x34, 0x79, 0x10, 0x7d, 0x1d, 0x37, 0x36, 0x04, 0x63 },
		{ 0x02, 0x00, 0x00, 0x00, 0x46, 0x65, 0x04, 0x3c, 0x05, 0x47, 0x05, 0x28, 0x0b },
		{ 0x04, 0x00, 0x00, 0x00, 0x46, 0x79, 0x3f, 0x1b, 0x02, 0x4d, 0x2c, 0x1d, 0x32 },
		{ 0x08, 0x00, 0x00, 0x00, 0x46, 0x41, 0x49, 0x55, 0x0c, 0x59, 0x7e, 0x77, 0x40 },
		{ 0x10, 0x00, 0x00, 0x00, 0x09, 0x76, 0x72, 0x6a, 0x33, 0x06, 0x2a, 0x00, 0x16 },
		{ 0x20, 0x00, 0x00, 0x00, 0x79, 0x08, 0x41, 0x1b, 0x14, 0x53, 0x63, 0x05, 0x0a },
		{ 0x40, 0x00, 0x00, 0x40, 0x7e, 0x42, 0x5d, 0x16, 0x23, 0x0f, 0x2c, 0x6f, 0x49 },
		{ 0x00, 0x01, 0x00, 0x00, 0x31, 0x1b, 0x21, 0x30, 0x19, 0x5e, 0x1d, 0x3e, 0x02 },
		{ 0x00, 0x02, 0x00, 0x40, 0x29, 0x57, 0x79, 0x2f, 0x56, 0x12, 0x7a, 0x31, 0x3f },
		{ 0x00, 0x04, 0x00, 0x40, 0x1f, 0x7c, 0x0c, 0x5b, 0x66, 0x6f, 0x19, 0x52, 0x5a },
		{ 0x00, 0x08, 0x00, 0x00, 0x77, 0x0c, 0x0a, 0x5f, 0x41, 0x4c, 0x6f, 0x7a, 0x19 },
		{ 0x00, 0x10, 0x00, 0x00, 0x59, 0x18, 0x58, 0x62, 0x77, 0x3c, 0x5d, 0x5a, 0x73 },
		{ 0x00, 0x20, 0x00, 0x40, 0x0b, 0x22, 0x46, 0x5e, 0x32, 0x04, 0x27, 0x72, 0x77 },
		{ 0x00, 0x40, 0x00, 0x00, 0x44, 0x06, 0x22, 0x6b, 0x26, 0x5d, 0x68, 0x45, 0x3d },
		{ 0x00, 0x00, 0x01, 0x40, 0x5a, 0x12, 0x2c, 0x2a, 0x7e, 0x30, 0x32, 0x44, 0x15 },
		{ 0x00, 0x00, 0x02, 0x40, 0x54, 0x06, 0x24, 0x40, 0x6b, 0x4a, 0x21, 0x17, 0x58 },
		{ 0x00, 0x00, 0x04, 0x00, 0x47, 0x1b, 0x4d, 0x63, 0x28, 0x5f, 0x2c, 0x5b, 0x04 },
		{ 0x00, 0x00, 0x08, 0x40, 0x08, 0x50, 0x13, 0x4c, 0x35, 0x16, 0x1c, 0x55, 0x0c },
		{ 0x00, 0x00, 0x10, 0x40, 0x4a, 0x63, 0x74, 0x1e, 0x48, 0x5d, 0x17, 0x02, 0x16 },
		{ 0x00, 0x00, 0x20, 0x40, 0x72, 0x16, 0x63, 0x7d, 0x69, 0x57, 0x19, 0x06, 0x2c },
		{ 0x00, 0x00, 0x40, 0x00, 0x4e, 0x48, 0x42, 0x10, 0x61, 0x13, 0x02, 0x5c, 0x07 },
		{ 0x00, 0x00, 0x00, 0x41, 0x61, 0x22, 0x59, 0x03, 0x3a, 0x5f, 0x4e, 0x3e, 0x79 },
		{ 0x00, 0x00, 0x00, 0x42, 0x1d, 0x73, 0x00, 0x40, 0x7d, 0x7b, 0x65, 0x3a, 0x6a },
		{ 0x00, 0x00, 0x00, 0x04, 0x78, 0x60, 0x36, 0x30, 0x7e, 0x67, 0x69, 0x52, 0x49 },
		{ 0x00, 0x00, 0x00, 0x08, 0x69, 0x57, 0x04, 0x7a, 0x36, 0x43, 0x38, 0x2a, 0x1e },
		{ 0x00, 0x00, 0x00, 0x10, 0x19, 0x5b, 0x4d, 0x64, 0x03, 0x47, 0x06, 0x67, 0x71 },
		{ 0x00, 0x00, 0x00, 0x60, 0x57, 0x21, 0x34, 0x03, 0x7a, 0x32, 0x40, 0x5f, 0x6b }
    };
	
    for (uint32_t i = 0; i < (uint32_t)1 << 27; ++i) {
        uint8_t X[13];
        memcpy(X, particular_solution, 13);

        for (uint32_t j = 0; j < 27; ++j)
            if (i & ((uint32_t)1 << j)) 
                XorBytes(X, general_solutions[j]);
            
        XorBytes(X, origin);

        int sum = 0;
        for (int j = 0; j < 13; ++j)
            sum += X[j];
        
        if (sum == 0x4d0) {
            int alpha_num = 1;
            for (int j = 0; j < 13; ++j) {
                if (X[j] < '0' || (X[j] > '9' && X[j] < 'A') || (X[j] > 'Z' && X[j] < 'a') || X[j] > 'z') {
                    alpha_num = 0;
                    break;
                }
            }

            if (alpha_num) {
                char flag_str[14];
                memcpy(flag_str, X, 13);
                flag_str[13] = 0;
                printf("%s\n", flag_str);
            }
        }
    }
    
    return 0;
}

