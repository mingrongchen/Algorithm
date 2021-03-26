#include <stdio.h>
#include "binaryLinkedList.c"

#define TRUE 1
#define FALSE 0

typedef struct {
    int other;
    int data[5];    // 数组存储数据元素
    int length;
} SqList;

static void test(SqList A) {
    printf("test list addr : %x ...\n", &A);
    printf("test array list addr : %x ...\n", &(A.data));
    for (int i = 0; i < A.length; i++) {
        A.data[i] = 8;
    }
}

static void test2(SqList *A) {
    printf("test2 list addr : %x ...\n", A);
    printf("test2 array list addr : %x ...\n", &(A->data));
    for (int i = 0; i < A->length; i++) {
        A->data[i] = 18;
    }
}

static void printArray(SqList A) {
    for (int i = 0; i < A.length; i++) {
        printf("array %d is %d ...\n", i, A.data[i]);
    }
}

static void testArray(int A[]) {
    printf("testArray list addr : %x ...\n", A);
    for (int i = 0; i < 5; i++) {
        A[i] = 8;
    }
}

static void printArray2(int A[]) {
    for (int i = 0; i < 5; i++) {
        printf("array %d is %d ...\n", i, A[i]);
    }
}

int main() {
    printf("Main begin ...\n");

    int testArr[5];
    for (int i = 0; i < 5; i++) {
        testArr[i] = 0;
    }
    printf("main list addr : %x ...\n", testArr);

    testArray(testArr);
//    test2(&testList);
    printArray2(testArr);

    printf("Main end ...\n");
    return 0;
}

