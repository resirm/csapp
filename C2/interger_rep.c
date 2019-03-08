#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
    int i;
    for (i = 0; i < len; ++i){
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

void problem_2_21(){
    printf("Problem 2.21\n");
    printf("-2147483647-1 == 2147483648U: %d\n", -2147483647-1 == 2147483648U);
    printf("-2147483647-1 < 2147483647: %d\n", -2147483647-1 < 2147483647);
    printf("-2147483647-1U < 2147483647: %d\n", -2147483647-1U < 2147483647);
    printf("-2147483647-1 < -2147483647: %d\n", -2147483647-1 < -2147483647);
    printf("-2147483647-1U < -2147483647: %d\n", -2147483647-1U < -2147483647);
}

int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}
int fun2(unsigned word) {
    return ((int) word << 24) >> 24;
}

void loop_2_23(unsigned i){
    printf("fun1(%x): %d\n", i, fun1(i));
    printf("fun2(%x): %d\n", i, fun2(i));
    show_int(fun1(i));
    printf("\n");
    show_int(fun2(i));
    printf("\n");
}

void problem_2_23(){
    printf("Problem 2.23\n");
    unsigned a[] = {0x00000076, 0x87654321, 0x000000C9, 0xEDCBA987};
    int i, len = sizeof(a)/sizeof(unsigned);
    for(i = 0; i < len; ++i){
        loop_2_23(a[i]);
    }
}

int main(){
    // printf("INT_MIN: %d\n", INT_MIN);
    // printf("INT_MAX: %d\n", INT_MAX);
    // printf("INT32_MIN: %d\n", INT32_MIN);
    // printf("INT32_MAX: %d\n", INT32_MAX);
    // printf("INT64_MIN: %lld\n", INT64_MIN);
    // printf("INT64_MAX: %lld\n", INT64_MAX);
    // printf("LONG_MIN: %ld\n", LONG_MIN);
    // printf("LONG_MAX: %ld\n", LONG_MAX);
    // printf("LLONG_MIN: %lld\n", LLONG_MIN);
    // printf("LLONG_MAX: %lld\n", LLONG_MAX);
    // printf("UINT32_MAX: %u\n", UINT32_MAX);
    // printf("UINT64_MAX: %llu\n", UINT64_MAX);
    // int32_t a = 0xfffffe58;
    // printf("0xfffffe58: %d", a);
    // problem_2_21();
    // printf("-1U: %u\n", -1u);
    // problem_2_23();
    // printf("%u\n", (2u-3u));
    // printf("%d\n", (2u<3u));
    // printf("%d\n", (2u-3u<0));
    return 0;
}