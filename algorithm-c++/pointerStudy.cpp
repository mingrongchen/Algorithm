//
// Created by MingR on 2021/4/27.
//
/**
 * 主要学习指针的使用
 * 常见的有常量指针、指针常量、数组指针、指针数组等常见使用
 */
#include <iostream>
#include <cstdio>

using namespace std;

static void test();
static void constAndPointerTest();
static void pointerPointerTest();
static void arrayAndPointerTest();
static void stringTest(const char**, int);


static void test () {
    arrayAndPointerTest();

}


static void constAndPointerTest() {
    /*
     * 1、指针常量：类型为指针的常量，初始化后不能修改，固定指向某个内存地址
     * 但是可以修改指针指向的内容
     */
    cout << endl << "指针常量测试 start ..." << endl;
    int x_array[] = {1,2,3,4};
    int* const p1 = x_array;    // 指向x_array后,p1地址固定。

    for (auto i = 0; i < 4; i++) {
        //p1++;    // p1地址不能修改,Compile Error
        cout << "data is : " << *(p1 + i) << endl;
    }

    /*
     * 2、常量指针：指向常量数据的指针
     * 格式：const int *p 或者int const *p
     * 指针指向的内容不可以修改，但是可以指向其它位置，但是仍然不能修改指针指向的值
     */
    cout << endl << "常量指针测试 start ..." << endl;
    int x = 1;
    int y = 2;

    const int *p2 = NULL;    // 声明一个空指针
    p2 = &x;    // 指向x
    //*p = 100;    // Compile Error!
    cout << "p = &x p is : " << *p2 << endl;

    p2 = &y;    // 指向y
    cout << "p = &y p is : " << *p2 << endl;
    //*p = 100;    // Compile Error!

    /*
     * 特殊情况
     */
    // cout << "特殊情况1 start ..." << endl;
    const int x_data = 1;
    // int *p3 = &x_data;    // 指向的内容为常量, p3必须为常量指针
} // constPointerTest


static void pointerPointerTest() {
    cout << endl << "指针的指针测试" << endl;
    int x = 10;
    int* p = &x;
    int** p2 = &p;

    printf("p = %x, *P = %d \n", p, *p);
    printf("p2 = %x, *P2 = %x \n", p2, *p2);
    printf("*p = %d, **P2 = %d \n", *p, **p2);
}


static void arrayAndPointerTest() {
    /*
     * 0、数组与指针
     */
    cout << endl << "普通数组和指针测试 start ..." << endl;
    int x[] = {1,2,3,4};
    int y[] = {5,6,7,8};
    int *p = x;    // p的类型是int*，也就是指向一个整数类型，数组名默认指向第一个元素，所以x默认为int*类型
    p++;  // p不是指针常量，可以对p进行重新指向
    //x++;    // x为指针常量，不能修改x的地址，即不能对x进行重新指向

    printf("*x = %d, *(x+1) = %d \n", *x, *(x + 1));
    printf("p = %x, (p + 1) = %x, x addr is %x, x[1] addr is %x \n", p, p + 1, x, &x[1]);


    /*
     * 1、数组指针
     * 数组的指针和数组名不是一个类型，数组指针将整个数组当做一个对象，而不是其中的元素
     */
    cout << endl << "数组指针测试 start ..." << endl;
    /**
     * p2指向一个“数组类型”的类型，与指向“数组元素的类型”区别开
     * *p2是获取该数组，那么(*p2)[i]也就是x[i]
     * p2的目标类型是数组，因此p2++指向的不是数组的下一个元素，而是整个数组之后的位置，超出该数组范围了。
     */
    int (*p2)[4] = &x;


    printf("p2 = %x, *p2 = %x, &x = %x \n", p2, *p2, &x);
    printf("**p2++ = %d, (*p)[1] = %d \n", **p2++, (*p2)[1]);

    // 备注：自增、减运算符和取值运算符同为2级优先级，且从右到左。
    p2 = &y;
    printf("After p2 = &y,p2 = %x, *p2 = %x, &y = %x \n", p2, *p2, &y);
    printf("**p2++ = %d, (*p)[1] = %d \n", **p2++, (*p2)[1]);

    int x_2[][4] = {{1,2,3,4},{11,22,33,44}};
    /*
     * x_2是一个二维数组，x_2默认指向数组第一个元素，也就是{1,2,3,4}，第一个元素不是int，而是一个int[]
     * x_2实际上是一个int(*)[]指针，因此p2=x_2而不是p2=&x_2，不然p2就指向int()[][]了
     */
    cout << endl << "数组指针测试2 p2 指向二维数组 start ..." << endl;
    p2 = x_2;
    printf("p2 = %x, *p2 = %x, &x_2 = %x, [1,3] = %d, [1,3] = %d \n", p2, *p2, x_2, (*(p2 + 1))[3], *(*(p2 + 1) + 3));
    int (*p2_2)[2][4] = &x_2;

    printf("p2_2 = %x, *p2_2 = %x, &x_2 = %x, [1,3] = %d, [1,3] = %d \n", p2_2, *p2_2, x_2, (*(*p2_2 + 1))[3], *(*(*p2_2 + 1) + 3));



    /*
     * 2、指针数组：元素内容类型为指针的数组
     * 通常用来处理交错数组，又称数组的数组，不是二维数组，常见的是字符串数组
     *
     */
    cout << endl << "指针数组测试 start ..." << endl;
    int* p3[] = {x,x+1,x+2,x+3};
    // 备注：()、[]、.、->都为一级优先级，且从左向右结合
    printf("p3 = %x, p3[0] = %x, x = %x, *p3[2] = %d \n", p3, p3[0], x, *p3[2]);

    for (auto i = 0; i < 4; i++) {
        printf("%d \n", *(p3[i]));
    }

    int* ints[] = {NULL, NULL, NULL};
    int x_1[] = {1,2,3,4};
    int y_1[] = {11,22,33,44};
    int z_1[] = {111,222,333,444};
    ints[0] = x_1;
    ints[1] = y_1;
    ints[2] = z_1;

    printf("**ints = %d \n", **ints);
    printf("*(*ints + 1) = %d \n", *(*ints + 1));
    printf("**(ints + 1) = %d \n", **(ints + 1));
    printf("*(*(ints + 1) + 1) = %d \n", *(*(ints + 1) + 1));

    /*
     * 字符串测试，指针数组
     */
    const char* a = "aaa";
    const char* b = "bbb";

    const char* myString[] = {a, b};
    printf("myString = %x, myString[0] = %x, myString[0] = %s \n", myString, myString[0], myString[0]);

    for (auto i = 0; i < 2; ++i) {
        printf("myString: %d = %s \n", i, *(myString+i));
    }

    stringTest(myString, 2);
}

static void stringTest(const char** data, int len) {
    cout << endl << "stringTest start ..." << endl;
    printf("data = %x, data[0] = %x, data[0] = %s \n", data, data[0], data[0]);

    for (auto i = 0; i < len; ++i) {
        printf("stringTest: %d = %s \n", i, *(data+i));
    }
}


