#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

uint32_t read_network_order(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("fail : name  %s\n", filename);
        exit(1);
    }

    uint32_t num;
    if (fread(&num, sizeof(num), 1, file) != 1) {
        printf("fail name :  %s\n", filename);
        exit(1);
    }

    fclose(file);

    return ntohl(num);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("argv is not ex) /add-nbo thousand.bin five-hundred.bin ", argv[0]);
        return 1;
    }

    uint32_t num1 = read_network_order(argv[1]);
    uint32_t num2 = read_network_order(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}
