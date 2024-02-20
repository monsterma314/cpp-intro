#include <iostream>

#define NUM_MC_SAMPLES  1000

using namespace std;

union fltRand {
    int randInt;
    float randFloat;
};

void test_rand(void) {
    uint32_t seed_value = 0xABCDEF;

    int tmp;
    union fltRand test1, test2, test3;
    float test4, test5, test6;

    srand(seed_value); // repeatable pseudo-random numbers

    test1.randInt = rand();
    cout << "Test 1: 0x" << hex << uppercase << test1.randInt;
    cout << ", or " << test1.randFloat << endl;

    test2.randInt = rand();
    cout << "Test 2: 0x" << hex << uppercase << test2.randInt;
    cout << ", or " << test2.randFloat << endl;

    test3.randInt = rand();
    cout << "Test 3: 0x" << hex << uppercase << test3.randInt;
    cout << ", or " << test3.randFloat << endl;

    tmp = rand();
    test4 = *(float *) &tmp;
    cout << "Test 4: 0x" << hex << uppercase << *(int *) &test4;
    cout << ", or " << test4 << endl;

    tmp = rand();
    test5 = *(float *) &tmp;
    cout << "Test 5: 0x" << hex << uppercase << *(int *) &test5;
    cout << ", or " << test5 << endl;

    tmp = rand();
    test6 = *(float *) &tmp;
    cout << "Test 6: 0x" << hex << uppercase << *(int *) &test6;
    cout << ", or " << test6 << endl;
}

void mc_cpu_estimation(void) {
    // srand(0xDEADBEEF);

    // uint32_t total_hits;
    
	// int x_rand;
	// int y_rand;
	// uint64_t x_32_32f;			// x coordinate in 32.32 fixed point format
	// uint64_t y_32_32f;			// y coordinate in 32.32 fixed point format
	// int mc_result;				// random variable result (0 or 1)
	// uint64_t x_squared_1_63f;	// x squared coordinate in 1.63 fixed point format
	// uint64_t y_squared_1_63f;	// y squared coordinate in 1.63 fixed point format


    // while(int i = 0; i < NUM_MC_SAMPLES; i++) {
    //     x_rand = rand();
    //     y_rand = rand();
    //     x_32_32f = x_rand * x_rand
    // }
    
}

void print_bin_uint64(uint64_t num) {
    for(int i = 63; i > -1; i--) {
        if((num >> i) & 0x1) {
            std::cout << "1";
        }
        else {
            std::cout << "0";
        }
    }
    std::cout << std::endl;
}

void print_bin_int(int num) {
    for(int i = 31; i > -1; i--) {
        if((num >> i) & 0x1) {
            std::cout << "1";
        }
        else {
            std::cout << "0";
        }
    }
    std::cout << std::endl;
}

int main(void) {
    srand(0x1);
    int x;
    uint64_t x_uint;

    while(1) {
        x = rand() << 1;
        if(x < 0) { break; }
    }

    x_uint = *(uint64_t *) &x & 0xFFFFFFFF;

    printf("x = %d\n", x);
    print_bin_int(x);
    printf("x_uint = %lu\n", x_uint);
    print_bin_uint64(x_uint);

    return EXIT_SUCCESS;
}