#include <stdio.h>
#include <stdint.h>

#define CRC_POLYNOMIAL 0x1021

uint16_t calculate_crc(uint8_t *data, size_t length) {
    uint16_t crc = 0x0000; // Initial value

    for (size_t i = 0; i < length; i++) {
        crc ^= (uint16_t)data[i] << 8; // XOR with next byte shifted by 8 bits
        
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ CRC_POLYNOMIAL;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main() {
  
    uint8_t data[]= {0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x11,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00};
    
    size_t data_length = sizeof(data) / sizeof(data[0]);

    uint16_t crc = calculate_crc(data, data_length);
    printf("CRC: 0x%04X\n", crc);

    return 0;
}
