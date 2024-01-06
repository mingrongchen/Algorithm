#include <stdio.h>
#include <stdint.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
//#include "data_structure/linearLinkedList.c"
//#include "practice/practice.c"

#define TRUE 1
#define FALSE 0

typedef int BOOL;

#define PRT(format,...)  printf("\n[File:%s, Line:%d]: \n"format, __FILE__, __LINE__, ##__VA_ARGS__)

typedef void(func_t)();
typedef void(*func_ptr_t)();
#define pp() ({ \
printf("%s: x = %d(%p), y = %d(%p), s = %s(%p);\n", __func__, x, &x, y, &y, s, s); \
})


void test(int** x) {
    printf("&x is %x\n", &x);
    printf("x is %x\n", x);
    int *p = malloc(sizeof(int));
    printf("test &p is %x\n", &p);
    printf("test *p is %d\n", *p);


    *p = 123;
    printf("test *p is %d\n", *p);
    *x = p;
    printf("after **x is %d\n", **x);//123
    printf("after *x is %d\n", *x);//123
    printf("after &x is %x\n", &x);//63fdf0
    printf("after x is %x\n", x);//63fe18
}

void test20(int n) {
    int x[n];
    for (int i = 0; i < n; i++) {
        x[i] = i;
    }

    struct data {int x[n];}d;
    printf("data length %d\n", sizeof(d));
}


void func2() {
    printf("__FUNCTION__ is %s\n", __FUNCTION__);
    printf("__PRETTY_FUNCTION__ is %s\n", __PRETTY_FUNCTION__);
}

size_t get_len (const char* s) {

    printf("%s\n",__func__);
    return strlen(s);

}

void test1(int len, int x[]) {
    int i;
    for (i = 0; i< len; i++) {
        printf("x[%d] = %d;", i, x[i]);
    }
    printf("\n");
}

void test2(int len, int* x) {
    int i;
    for (i = 0; i< len; i++) {
        printf("x[%d] = %d;", i, *(x + 1));
    }
    printf("\n");
}

// 数组指针：数组名默认指向第一元素指针，&array则是获得整个数组指针
void test3(int len,  int (*x)[len]) {
    int i;
    printf("test3 &x is %x .\n", &x);
    for (i = 0; i< len; i++) {
        printf("x[%d] = %d;", i, (*x)[i]);
    }
    printf("\n");
}

// 多维数组：数组名默认指向第一元素指针，也就是int(*)[],必须声明列个数
void test4(int r, int c,  int y[][c]) {
    printf("test4 &x is %y .\n", &y);

    for (int a = 0; a < r; a++) {
        for (int b = 0; b < c; b++) {
            printf("y[%d][%d] = %d ;", a, b, y[a][b]);
        }
    }

    printf("\n");
}

// 同test4
void test5(int r, int c,  int (*y)[c]) {
    printf("test5 &x is %y .\n", &y);

    for (int a = 0; a < r; a++) {
        for (int b = 0; b < c; b++) {
            printf("y[%d][%d] = %d ;", a, b, (*y)[b]);
        }

        y++;//注意指针数组y+1，y是数组指针，及指向数组的指针
    }

    printf("\n");
}

// 多维数组
void test6(int r, int c,  int (*y)[][c]) {
    printf("test6 &x is %y .\n", &y);

    for (int a = 0; a < r; a++) {
        for (int b = 0; b < c; b++) {
            printf("y[%d][%d] = %d ;", a, b, (*y)[a][b]);
        }

    }

    printf("\n");
}

// 元素为指针的指针数组，相当于test8
void test7(int count, char** s) {
    for (int i = 0; i < count; i++) {
        printf("%s; ", *(s++));
    }

    printf("\n");
}

void test8(int count, char* s[count]) {
    for (int i = 0; i < count; i++) {
        printf("%s; ", s[i]);
    }

    printf("\n");
}

// 以NULL结尾的指针数组
void test9(int** x) {
    int* p;
    while ((p = *x) != NULL) {
        printf("%d; ", *p);
        x++;
    }

    printf("\n");
}

void test81(void* p, size_t len) {
    unsigned char* cp = p;

    for (int i = 0; i < len; ++i) {
        printf("%02x ", *(cp + i));

    }
    printf("\n");
}

// 一个为多字节，一个为单字节，给多字节赋不为0的值
BOOL IsBigEndian() {
    union NUM {
        int a;
        char b;
    }num;
    printf("union length is : %d\n", sizeof(num));
    num.a = 0x1234;

    if (num.b == 0x12) {
        return TRUE;
    }

    return FALSE;
}

union U {
    int i;
    char c;

}u;
BOOL IsBigEndian2() {
    u.i = 1;

    if (u.c == 1) {
        return FALSE;
    }

    return TRUE;
}

size_t strlen(const char *s) {
//    size_t n = 0;
//
//    while (*s++) {
//        n++;
//    }
//
//
//    return n;
    printf("strlen \n");
    const char *p = s;

    while (*s) {
        s++;
    }
    printf("p:%x \n", p);
    printf("s:%x \n", s);
    printf("s+1:%x \n", s+1);
    printf("*s+1:%x \n", *(s+1));
    printf("s - p is %d \n", s - p);

    return s - p;

}



int main2() {
    printf("Main begin ...\n");

//    int x[] = { 1, 2, 3, 4 };
//
//    int len = sizeof(x) / sizeof(int);
//    test1(len, x);
//    test2(len, x);
//    test3(len, &x);
//
//    int y[][2] =
//            {
//                    {10, 11},
//                    {20, 21},
//                    {30, 31}
//            };
//
//    int col = 2;
//    int row = sizeof(y) / (sizeof(int) * 2);
//    test4(row, col, y);
//    test5(row, col, y);
//    test6(row, col, &y);
//
//    char* s[] = {"aaa", "bbb", "ccc"};
//    printf("s length is : %d ...\n", sizeof(s));
//    test7(sizeof(s) / sizeof(char*), s);
//    test8(sizeof(s) / sizeof(char*), s);

//    char name[200];
//    unsigned int * addr_p = NULL;
//    addr_p =  memset(name, 0, sizeof(name));
//    strcpy(name, "hello, xiaoqiu");
//
//    printf("&name is : %x \n", &name);
//    printf("addr_p is : %x \n", addr_p);
//    printf("name length is : %d \n", sizeof(name));
//    printf("%s \n", name);
//
//    /**
//     *
//     */

//    typedef struct {
//        int length;
//        char chars[];
//    } string;
//
//    printf("string length is : %d\n", sizeof(string));
//    int len = sizeof(string) + 10;
//    char buf[len];
//
//    printf("buf addr is : %x\n", buf);
//    printf("buf length is : %d\n", sizeof(buf));
//    string *s = (string*)buf;
//
//    s->length = 9;
//    strcpy(s->chars, "123456789");
//    printf("s addr is : %x\n", s);
//    printf("s->length addr is : %x\n", &(s->length));
//    printf("s->chars addr is : %x\n", s->chars);
//
//    printf("%d, %s \n", s->length, s->chars);

//    int a[12] = {10,20,30,40,50,60,70,80,90,100,110,120};
//    int (*p_array)[12] = &a;
//    int *p = a;
//
//    printf("&a %x \n", &a);
//    printf("p_array %x \n", p_array);
//    printf("p %x \n", p);
//
//    printf("%d \n", p[0]);
//    printf("%d \n", *p_array[0]);
//
//    printf("%d \n", a[1]);
//    printf("%d \n", *(p+1));
//    printf("%d \n", (*p_array)[1]);
//    printf("%d \n", p_array[0][1]);


//    char a1[] = "i'm a Chinese.";
//    char a2[] = "i come from Beijing.";
//    char a3[] = "i like computer.";
//    char a4[] = "Programming is fun.";
//
//    int length = strlen(a1);
//
//    printf("a1 length is : %d \n", length);
//    printf("a1 length is : %d \n", sizeof(a1));

    int b[] = {14,23,33,43,53,63};
    int* a = b;

    const int *p = a;

    size_t n = 0;

    for (int i = 0; i < 6; i++) {
        a++;
    }

    while (*a) {
        a++;
    }

    printf("p:%x \n", p);
    printf("a:%x \n", a);
    printf("a:%x \n", a+1);
    printf("a - p is %d \n", a - p);
    printf("*(a+1):%x \n", *(a+1));

//    while (*a) {
//        printf("*a:%d \n", *a);
//        a++;
//    }

//    for (int i = 0; i < 6; i++) {
//        printf("a:%d \n", a);
//        a++;
//    }



    return 0;
}



