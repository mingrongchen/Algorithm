//
// Created by MingR on 2022/3/4.
//
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:

    /**
     * 快速排序,nlogn,不稳定
     * 递归分治法
     */
    void quickSort(int a[], int low, int high) {
        if (low < high) {
            int middlePosition = split(a, low, high);
            quickSort(a, low, middlePosition - 1);
            quickSort(a, middlePosition + 1, high);
        }

    }

    int split(int a[], int low, int high) {
        int part_element = a[low]; // 第一个元素作为枢纽,对表进行划分

        while (low < high) {
            // 从右到左,将右边比枢纽值小的移动到左边
            while (low < high && part_element < a[high]) --high;
            a[low] = a[high];

            // 从左到右,将左边比枢纽值大的移动到右边
            while (low < high && part_element > a[low]) ++low;
            a[high] = a[low];
        }

        a[low] = part_element;     // 将枢纽存放到最终位置
        return low;    // 返回枢纽存放的最终位置
    }


    void quickSortTest() {
        printf("\nquickSortTest begin ...\n");
        int a[] = {1,3,4,2,6,5,8,7,9,0};
        int a_size = sizeof(a)/ sizeof(int);
        printf("test a size : %d ...\n", a_size);
        quickSort(a, 0, a_size - 1);

        print(a, a_size);
    }

    void print(int a[], int size) {
        for(int i = 0; i < size; i++) {
            printf(" %d \t", a[i]);
        }
        printf("\n");
    }

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    /**
     * 冒泡排序,n2,稳定
     */
    void bubbleSort(int a[], int n) {
        for (int i = 0; i < n; i++) {
            bool flag = false;// 表示本趟冒泡是否发生交换

            for (int j = n - 1; j > i; j--) {// 从后往前冒泡,最小的冒泡到前面

                if (a[j-1] > a[j]) { // 前面的数较大则交换
                    swap(a[j-1], a[j]);
                    flag = true;
                }

            }// in for

            if (!flag) return;    // 如果没有发生交换则代表有序了
        } // out for
    } // bubbleSort end

    void bubbleSortTest() {
        printf("\nbubbleSortTest begin ...\n");
        int a[] = {1,3,4,2,6,5,8,7,9,0};
        int a_size = sizeof(a)/ sizeof(int);
        printf("test a size : %d ...\n", a_size);
        bubbleSort(a, a_size);

        print(a, a_size);
    }

    /**
     * 简单选择排序,n2,不稳定
     * 在第i趟找到最小元素后,和第i个元素交换
     * 稳定性:不稳定
     */
     void selectSort(int a[], int n) {
         for (int i = 0; i < n; i++) {  // 一共进行n-1次
             int minPosition = i;    // 记录最小元素的位置

             for (int j = i + 1; j < n; j++) {
                 if (a[j] < a[minPosition]) {
                     minPosition = j;    // 更新最小元素位置
                 }
             }// in for

             if (minPosition != i) swap(a[minPosition], a[i]);

         }// out for

     } // selectSort end

     void selectSortTest() {
         printf("\nselectSortTest begin ...\n");
         int a[] = {1,3,4,2,6,5,8,7,9,0};
         int a_size = sizeof(a)/ sizeof(int);
         printf("test a size : %d ...\n", a_size);
         selectSort(a, a_size);

         print(a, a_size);
     }

     /**
      * 堆排序,nlogn,不稳定
      * 将一维数组看做一个完全二叉树,算法关键是如何调整为堆
      *
      */
     void heapSort(int a[], int n) {
         buildMaxHeap(a, n);//初始建立大顶堆
         for (int i = n-1; i >= 0; i--) {    // 从后往前,建立大顶堆,并将最大的数放到最后
             swap(a[i], a[0]);    // 将顶堆元素与末尾元素交换
             HeadAdjust(a, 0, i - 1);
         }
     } // heapSort end

     // 建立初始堆
     void buildMaxHeap(int a[], int len) {
         for (int i = len/2 - 1; i >= 0; i--) {// 从下标0开始,从有子树的最小子树(len/2 - 1到0)开始向上调整
             HeadAdjust(a, i, len - 1);
         }
     } // buildMinHeap end

     void HeadAdjust(int a[], int k, int len) {
         int tmp = a[k];

         for (int i = 2 * k + 1; i < len; i *= 2) {// 从下标0开始,k节点的左孩子为K*2 + 1,右孩子为K*2 + 2
             if (i < len && a[i] < a[i+1]) {//若右孩子更大则调整当前值i为右孩子
                 i += 1;
             }

             if (tmp >= a[i]){// 若当前父节点比左右子树都大则不用调整
                 break;
             } else {
                 a[k] = a[i];//把父节点调整为最大的值
                 k = i;//继续向下调整
             }

         } // for end

         a[k] = tmp; // 被筛选节点的值放入最终位置
     } // HeadAdjust end

     void heapSortTest() {
         printf("\nheapSortTest begin ...\n");
         int a[] = {1,3,4,2,6,5,8,7,9,0};
         int a_size = sizeof(a)/ sizeof(int);
         printf("test a size : %d ...\n", a_size);
         heapSort(a, a_size);

         print(a, a_size);
     } // heapSortTest end

     /**
      * 插入排序,n2,稳定
      *
      */
     void insertSort(int a[], int n) {
         for (int i = 1; i < n; i++) {
             if (a[i] < a[i-1]) {// 若未排序第一个数,比排序好序列的最后一个数小,则插入
                 int tmp = a[i];
                 int j;
                 for (j = i - 1; tmp < a[j]; j--) {
                     a[j+1] = a[j];    // 向后挪位置
                 }// in for end

                 a[j+1] = tmp;
             }
         } // out for end
     } // inserSort end

    void insertSortTest() {
        printf("\ninsertSortTest begin ...\n");
        int a[] = {1,3,4,2,6,5,8,7,9,0};
        int a_size = sizeof(a)/ sizeof(int);
        printf("test a size : %d ...\n", a_size);
        insertSort(a, a_size);

        print(a, a_size);
    } // heapSortTest end

    /**
     * 希尔排序,n2,不稳定
     */
     void shellSort(int a[], int n) {
         for (int dk = n/2; dk > 0; dk = dk/2) {// 定义步长为2
             for (int i = dk + 1; i < n; i++) {
                 if (a[i] < a[i - dk]) {//将a[i]插入有序增量子表,若未排序第一个数,比排序好zi子序列的最后一个数小,则插入
                     int tmp = a[i];
                     int j;
                     for (j = i - dk; j >= 0 && tmp < a[j]; j -= dk) {
                         a[j + dk] = a[j];    // 记录后移
                     }

                     a[j+dk] = tmp;
                 }
             }
         }
     } // shellSort end

    void shellSortTest() {
        printf("\nshellSort begin ...\n");
        int a[] = {1,3,4,2,6,5,8,7,9,0};
        int a_size = sizeof(a)/ sizeof(int);
        printf("test a size : %d ...\n", a_size);
        shellSort(a, a_size);

        print(a, a_size);
    } // heapSortTest end

};

static int practice_test() {
    cout << "sort question begin ..." << endl;
    Solution solution;
//    solution.quickSortTest();    // 快排测试
//    solution.bubbleSortTest();   // 冒泡测试
//    solution.selectSortTest();   // 选择排序测试
//    solution.heapSortTest();        // 堆排序测试
//    solution.insertSortTest();    //插入排序测试
    solution.shellSortTest();       //希尔排序测试
}


