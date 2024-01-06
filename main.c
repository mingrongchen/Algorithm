//
// Created by MingR on 2023/12/9.
//

#include <stdio.h>
#include <malloc.h>

#define SQURE(X) X*X

void swap(int *a, int *b);
void sort(int a[], int length);
void print(int a[], int length);

void test00(int a[]) {
    printf("a is : %x \n", a);
    printf("a size : %d \n", sizeof(a));
    printf("a size 2: %d \n", sizeof(a)/ sizeof(a[0]));

    for (int i = 0; i < (sizeof(a)/ sizeof(a[0])); i++) {
        printf("%d, ", a[i]);
    }
}
void test002(int *a) {
    printf("a is : %x \n", a);
    printf("a size : %d \n", sizeof(a));
    printf("a size 2: %d \n", sizeof(a)/ sizeof(a[0]));

    for (int i = 0; i < (sizeof(a)/ sizeof(a[0])); i++) {
        printf("%d, ", a[i]);
    }
}


void main() {

//    int b[] = {63,53,43,33,23,13};
    int b[] = {13,53,63,83,23,93};
//    sort(b, sizeof(b)/ sizeof(b[0]));
//    print(b, sizeof(b)/ sizeof(b[0]));
    printf("b is : %x \n", b);
    printf("b size : %d \n", sizeof(b));
    printf("b size 2: %d \n", sizeof(b)/ sizeof(b[0]));
    test002(b);

    int c = 2;
    int *p = c;
    printf("p is : %x \n", b);
    printf("p size : %d \n", sizeof(p));




    return;
}

void print(int a[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d , ", a[i]);
    }
}


void swap(int *a, int *b) {
            int temp = *a;
    *a = * b;
    *b = temp;
}

//void sort(int a[], int length) {
//    int pos;
//    for (int i = 0; i < length; i++) {
//        pos = i;
//        for (int j = i + 1; j < length; j++) {
//            if (a[j] < a[i]) {
//                pos = j;
//            }
//        }
//
//        if (pos != i) {
//            swap(&a[i], &a[pos]);
//        }
//    }
//}

//void sort(int a[], int length) {
//    for (int i = 0; i < length - 1; i++) {
//
//        int flag = 0;
//
//        for (int j = 0; j < length - 1 - i; j++) {
//            if (a[j + 1] < a[j]) {
//                swap(&a[j+1], &a[j]);
//                flag = 1;
//            }
//        }
//
//        if (flag == 0) break;
//    }
//}

void sort(int a[], int length) {
    for (int i = 0; i < length; i++) {
        int temp = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > temp; j--) {
            a[j+1] = a[j];
        }

        a[j+1] = temp;
    }
}



