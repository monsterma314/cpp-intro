#include <iostream>
#include <cstdint>
#include <stdlib.h>

#define ROWS    3
#define COLS    5
#define HEIGHT  2

void print_arr3d(uint32_t arr3d[][ROWS][COLS]);

int main(void) {
    uint32_t *arr3_1d = (uint32_t *) malloc(ROWS * COLS * HEIGHT * sizeof(*arr3_1d));
    for(int i = 0; i < ROWS * COLS * HEIGHT; i++) {
        arr3_1d[i] = i;
    }

    print_arr3d(arr3_1d);

    free(arr3_1d);
    return EXIT_SUCCESS;
}

void print_arr3d(uint32_t arr3d[][ROWS][COLS]) {
    for(int i = 0; i < HEIGHT; i++) {
        printf("arr3d[%d]:\n", i);
        for(int j = 0; j < ROWS; j++) { // print the 2d array
            for(int k = 0; k < COLS; k++) {
                printf("%4u ", arr3d[i][j][k]);
            }
            std::cout << std::endl;
        }
    }
}