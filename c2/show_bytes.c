#include <stdio.h>
#include <string.h>

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

void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void problem_2_5(){
    printf("Problem 2.5\n");
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp,1); /* A. */
    show_bytes(valp,2); /* B. */
    show_bytes(valp,3); /* C. */
}

void problem_2_6(){
    printf("Problem 2.6\n");
    int val = 3510593;
    float fval = (float) val;
    show_int(val);
    show_float(fval);
}

void problem_2_7(){
    printf("Problem 2.7\n");
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s)+1);
}

void inplace_swap(int *x, int *y) {
    printf("x: %d, y: %d\n", *x, *y);
    *y = *x ^ *y; /* Step 1 */
    printf("x: %d, y: %d\n", *x, *y);
    *x = *x ^ *y; /* Step 2 */
    printf("x: %d, y: %d\n", *x, *y);
    *y = *x ^ *y; /* Step 3 */
    printf("x: %d, y: %d\n", *x, *y);
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt-1; first < last; first++,last--)
        inplace_swap(&a[first], &a[last]);
}

void problem_2_11(){
    printf("Problem 2.11\n");
    int ia[5] = {1,2,3,4,5};
    int len = sizeof(ia)/sizeof(int);
    printf("size of ia: %d\n", len);
    reverse_array(ia, len);
    int beg;
    for(beg = 0; beg < len; ++beg)
        printf("%d,", ia[beg]);
}

void problem_2_12(){
    printf("Problem 2.12\n");
    int val = 0x87654321;
    long long mask = 0xff;
    printf("%x, ", val&mask); /* A. */
    printf("%x, ", ~val^mask); /* B. */
    printf("%x, ", val|mask); /* C. */
}

int bis(int x, int m){
    return x|m;
}

int bic(int x, int m){
    return x&~m;
}

int bool_or(int x, int y){
    return bis(x, y);
}

int bool_xor(int x, int y){
    return bis(bic(x, y), bic(y, x));
}

void problem_2_13(){
    printf("Problem 2.13\n");
    int x = 0x0021, y = 0x0033;
    printf("x: %x, y: %x\n", x, y);
    printf("bool_or: %x\n", bool_or(x, y));
    printf("or: %x\n", x|y);
    printf("bool_xor: %x\n", bool_xor(x, y));
    printf("xor: %x\n", x^y);
}

void problem_2_14(){
    printf("Problem 2.14\n");
    int x = 0x66, y = 0x39;
    int a = x&&y, b = x||y, c = !x||!y, d = x&&~y;
    int e = x&y, f = x|y, g = !x|!y, h = x&~y;
    printf("x&&y: %x, x||y: %x, !x||!y: %x, x&&~y: %x\n", a, b, c, d);
    printf("x&y: %x, x|y: %x, !x|!y: %x, x&~y: %x\n", e, f, g, h);
}

int equal(int x, int y){
    return !(x^y);
}

void problem_2_15(){
    printf("Problem 2.15\n");
    int x = 0x33, y = 0x34, z = 0x33;
    printf("%x, %x\n", equal(x,y), equal(x,z));
}

void test_shift(){
    int i = ~0;
    unsigned int ui = ~0;
    printf("int: %x, unsigned: %x\n", i >> sizeof(int)*8-1, ui >> sizeof(unsigned)*8-1);
}

int main(){
    // int i = 12345;
    // test_show_bytes(i);
    // problem_2_5();
    // problem_2_6();
    // problem_2_7();
    // problem_2_11();
    // problem_2_12();
    // problem_2_13();
    // problem_2_14();
    // problem_2_15();
    test_shift();
    return 0;
}