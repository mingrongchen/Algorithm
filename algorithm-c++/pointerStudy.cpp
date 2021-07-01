//
// Created by MingR on 2021/4/27.
//
/**
 * ��Ҫѧϰָ���ʹ��
 * �������г���ָ�롢ָ�볣��������ָ�롢ָ������ȳ���ʹ��
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
     * 1��ָ�볣��������Ϊָ��ĳ�������ʼ�������޸ģ��̶�ָ��ĳ���ڴ��ַ
     * ���ǿ����޸�ָ��ָ�������
     */
    cout << endl << "ָ�볣������ start ..." << endl;
    int x_array[] = {1,2,3,4};
    int* const p1 = x_array;    // ָ��x_array��,p1��ַ�̶���

    for (auto i = 0; i < 4; i++) {
        //p1++;    // p1��ַ�����޸�,Compile Error
        cout << "data is : " << *(p1 + i) << endl;
    }

    /*
     * 2������ָ�룺ָ�������ݵ�ָ��
     * ��ʽ��const int *p ����int const *p
     * ָ��ָ������ݲ������޸ģ����ǿ���ָ������λ�ã�������Ȼ�����޸�ָ��ָ���ֵ
     */
    cout << endl << "����ָ����� start ..." << endl;
    int x = 1;
    int y = 2;

    const int *p2 = NULL;    // ����һ����ָ��
    p2 = &x;    // ָ��x
    //*p = 100;    // Compile Error!
    cout << "p = &x p is : " << *p2 << endl;

    p2 = &y;    // ָ��y
    cout << "p = &y p is : " << *p2 << endl;
    //*p = 100;    // Compile Error!

    /*
     * �������
     */
    // cout << "�������1 start ..." << endl;
    const int x_data = 1;
    // int *p3 = &x_data;    // ָ�������Ϊ����, p3����Ϊ����ָ��
} // constPointerTest


static void pointerPointerTest() {
    cout << endl << "ָ���ָ�����" << endl;
    int x = 10;
    int* p = &x;
    int** p2 = &p;

    printf("p = %x, *P = %d \n", p, *p);
    printf("p2 = %x, *P2 = %x \n", p2, *p2);
    printf("*p = %d, **P2 = %d \n", *p, **p2);
}


static void arrayAndPointerTest() {
    /*
     * 0��������ָ��
     */
    cout << endl << "��ͨ�����ָ����� start ..." << endl;
    int x[] = {1,2,3,4};
    int y[] = {5,6,7,8};
    int *p = x;    // p��������int*��Ҳ����ָ��һ���������ͣ�������Ĭ��ָ���һ��Ԫ�أ�����xĬ��Ϊint*����
    p++;  // p����ָ�볣�������Զ�p��������ָ��
    //x++;    // xΪָ�볣���������޸�x�ĵ�ַ�������ܶ�x��������ָ��

    printf("*x = %d, *(x+1) = %d \n", *x, *(x + 1));
    printf("p = %x, (p + 1) = %x, x addr is %x, x[1] addr is %x \n", p, p + 1, x, &x[1]);


    /*
     * 1������ָ��
     * �����ָ�������������һ�����ͣ�����ָ�뽫�������鵱��һ�����󣬶��������е�Ԫ��
     */
    cout << endl << "����ָ����� start ..." << endl;
    /**
     * p2ָ��һ�����������͡������ͣ���ָ������Ԫ�ص����͡�����
     * *p2�ǻ�ȡ�����飬��ô(*p2)[i]Ҳ����x[i]
     * p2��Ŀ�����������飬���p2++ָ��Ĳ����������һ��Ԫ�أ�������������֮���λ�ã����������鷶Χ�ˡ�
     */
    int (*p2)[4] = &x;


    printf("p2 = %x, *p2 = %x, &x = %x \n", p2, *p2, &x);
    printf("**p2++ = %d, (*p)[1] = %d \n", **p2++, (*p2)[1]);

    // ��ע�����������������ȡֵ�����ͬΪ2�����ȼ����Ҵ��ҵ���
    p2 = &y;
    printf("After p2 = &y,p2 = %x, *p2 = %x, &y = %x \n", p2, *p2, &y);
    printf("**p2++ = %d, (*p)[1] = %d \n", **p2++, (*p2)[1]);

    int x_2[][4] = {{1,2,3,4},{11,22,33,44}};
    /*
     * x_2��һ����ά���飬x_2Ĭ��ָ�������һ��Ԫ�أ�Ҳ����{1,2,3,4}����һ��Ԫ�ز���int������һ��int[]
     * x_2ʵ������һ��int(*)[]ָ�룬���p2=x_2������p2=&x_2����Ȼp2��ָ��int()[][]��
     */
    cout << endl << "����ָ�����2 p2 ָ���ά���� start ..." << endl;
    p2 = x_2;
    printf("p2 = %x, *p2 = %x, &x_2 = %x, [1,3] = %d, [1,3] = %d \n", p2, *p2, x_2, (*(p2 + 1))[3], *(*(p2 + 1) + 3));
    int (*p2_2)[2][4] = &x_2;

    printf("p2_2 = %x, *p2_2 = %x, &x_2 = %x, [1,3] = %d, [1,3] = %d \n", p2_2, *p2_2, x_2, (*(*p2_2 + 1))[3], *(*(*p2_2 + 1) + 3));



    /*
     * 2��ָ�����飺Ԫ����������Ϊָ�������
     * ͨ���������������飬�ֳ���������飬���Ƕ�ά���飬���������ַ�������
     *
     */
    cout << endl << "ָ��������� start ..." << endl;
    int* p3[] = {x,x+1,x+2,x+3};
    // ��ע��()��[]��.��->��Ϊһ�����ȼ����Ҵ������ҽ��
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
     * �ַ������ԣ�ָ������
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


