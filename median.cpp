#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define MAX_FILTER_W    11
#define MAX_FILTER_H    11

int partition(uint8_t *arr, int start, int end);
uint8_t easy_median(uint8_t *arr, int num_elements);
uint8_t hard_median(uint8_t *arr, int num_elements);
void print_arr(uint8_t *arr, int num_elements);

int main(void) {
    int num_elements = MAX_FILTER_H * MAX_FILTER_W;

    uint8_t *img_r1 = (uint8_t *) malloc(num_elements);
    uint8_t *img_g1 = (uint8_t *) malloc(num_elements);
    uint8_t *img_b1 = (uint8_t *) malloc(num_elements);
    uint8_t *img_r1A = (uint8_t *) malloc(num_elements);
    uint8_t *img_g1A = (uint8_t *) malloc(num_elements);
    uint8_t *img_b1A = (uint8_t *) malloc(num_elements);
    int num;

    std::fstream inFile("inputs/img_r1_121.txt", std::ios_base::in);
    for(int i = 0; i < num_elements; i++) {
        inFile >> num;
        img_r1[i] = (uint8_t) num;
    }
    std::fstream inFile2("inputs/img_g1_121.txt", std::ios_base::in);
    for(int i = 0; i < num_elements; i++) {
        inFile2 >> num;
        img_g1[i] = (uint8_t) num;
    }
    std::fstream inFile3("inputs/img_b1_121.txt", std::ios_base::in);
    for(int i = 0; i < num_elements; i++) {
        inFile3 >> num;
        img_b1[i] = (uint8_t) num;
    }

    memcpy(img_r1A, img_r1, num_elements);
    memcpy(img_g1A, img_g1, num_elements);
    memcpy(img_b1A, img_b1, num_elements);

#if 0
    print_arr(img_r1, num_elements);
    print_arr(img_g1, num_elements);
    print_arr(img_b1, num_elements);
#endif

    uint8_t median;
    median = easy_median(img_r1, (int)(MAX_FILTER_W * MAX_FILTER_H));
    printf("Easy median of img_r1 = %u\n", median);
    median = hard_median(img_r1A, (int)(MAX_FILTER_W * MAX_FILTER_H));
    printf("Hard median of img_r1 = %u\n", median);

    median = easy_median(img_g1, (int)(MAX_FILTER_W * MAX_FILTER_H));
    printf("Easy median of img_g1 = %u\n", median);
    median = hard_median(img_g1A, (int)(MAX_FILTER_W * MAX_FILTER_H));
    printf("Hard median of img_g1 = %u\n", median);

    median = easy_median(img_b1, (int)(MAX_FILTER_W * MAX_FILTER_H));
    printf("Easy median of img_b1 = %u\n", median);
    median = hard_median(img_b1A, (int)(MAX_FILTER_W * MAX_FILTER_H));
    printf("Hard median of img_b1 = %u\n", median);

    free(img_r1);
    free(img_g1);
    free(img_b1);

    return EXIT_SUCCESS;
}

void print_arr(uint8_t *arr, int num_elements) {
    for(int i = 0; i < num_elements; i++) {
        printf("arr[%d] = %u\n", i, arr[i]);
    }
}

uint8_t easy_median(uint8_t *arr, int num_elements) {
    std::sort(arr, arr + num_elements);
    return arr[num_elements >> 1];
}

uint8_t hard_median(uint8_t *arr, int num_elements) {
    // K.I.S.S principle: return the arr_sort[num_elem/2]
    int median_idx = num_elements >> 1;
    int pivot_idx;
    int start = 0;
    int end = num_elements - 1;

    while(1) {
        pivot_idx = partition(arr, start, end);

        if(pivot_idx == median_idx) {
            return arr[median_idx];
        }
        if(pivot_idx > median_idx) {
            end = pivot_idx - 1;
        }
        else {
            start = pivot_idx + 1;
        }
    }
}

int partition(uint8_t *arr, int start, int end) {
    int swap_idx = start;
    int scan_idx = start;
    uint8_t tmp;
    uint8_t pivot = arr[end];

    // 1    5   2   3   4
    // ||                   // swap
    //      ||              // no swap
    //      |   |           // swap
   
    // 1    2   5   3   4
    //          |   |       // swap
   
    // 1    2   3   5   4
    //              |   |   // loop ends, final swap
   
    // 1    2   3  [4]  5   (found the 3rd index)
    while(scan_idx < end) { // still need to analyze full subarray
        // std::cout << "scan_idx: " << scan_idx << std::endl;
        if(arr[scan_idx] < pivot) {
            // printf("arr[swap_idx] = %u\n\n", arr[swap_idx]);
            tmp = arr[scan_idx];
            arr[scan_idx] = arr[swap_idx];
            arr[swap_idx] = tmp;
            swap_idx++;
        }
        scan_idx++;
    }

    // perform the final swap
    arr[end] = arr[swap_idx];
    arr[swap_idx] = pivot;
    return swap_idx;    
}