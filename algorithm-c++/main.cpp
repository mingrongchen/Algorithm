#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#include <vector>
#include <list>
#include <iterator>
#include <string>

int k = 300;
const int i = 100;
#define n 10
const int j = 200;

void fun(int i, int j) {
    const int k =3;
    static int l =0;
    char *p = new char[n+1];
    char *p2 = "123456";
    char ch[] = "abcdefd";

    int m = 0;
    for (;m < n;m++) {
        p[m]='A'+m;
    }
    p[m]='\0';
    printf("&fun : %x \n",&fun);
    cout<<"fun addr: "<<&fun<<endl;
    cout<<"Address of fun parameter variable : " << endl;
    cout<<"int&i: "<<&i<<"\t int&j: "<<&j<<endl;
    cout<<"Address of parameter variable : "<<endl;
    cout<<"const int&k: "<<&k<<"\t char*&p: "<<&p<<"\t int&m: "<<&m<<endl;
    cout<<"Address of static local variable : " << endl;
    cout<<"static&l: "<< &l<<endl;
    cout<<"Address of heap p: "<<(void*)p<<endl;
    cout<<"Address of *p2=\"123456\" : "<<(void*)p2<<endl;
    cout<<"Address of ch[] = \"abcdefd\" : "<<(void*)ch<<endl;
    cout<<"Address of ch[] = \"abcdefd\" : "<<(void*)(&ch[1])<<endl;
    cout<<"Address of ch[] = \"abcdefd\" : "<<(void*)(&ch[2])<<endl;
    cout<<"before delete p: "<<p<<endl;
    delete[] p;

    cout<<"After delete: "<<(void*)p<<endl;
    cout<<"p: " << p<<endl;

}


int main() {

    fun(1,2);
    cout<<"Address of global variable: "<<endl;
    cout<<"globla const int &i: "<<&i<<"\t global const int &j: "<<&j<<"\t global int &k: "<<&k<<endl;
    cout<<"Address of function: "<<endl;
    cout<<"&fun: "<<&fun<<"\t &main: "<<&main<<endl;
    printf("&fun : %x, &main: %x \n",&fun,&main);

    return 0;
}