/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月20日 下午2:27:22
 * @ClassName QuickSort
 * @类描述-Description:快速排序
 * @修改记录:
 * @版本: 1.0
 */
public class QuickSort {

	public static void test() {
		System.out.println("SelectSort test start ...");
		int[] testData = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		sort(testData, 0, testData.length - 1);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("SelectSort test end ...");
		System.out.println("----------------------");

	} // test end

	public static void sort(int[] data, int L, int R) {
		System.out.println("sort start, L : " + L + " ,R : " + R);
		int i = L;
		int j = R;

		// 交换的变量
		int temp;
		// 支点
		int pivot = data[L + (R - L) / 2];

		// 左右两端进行扫描，只要两端没有交替，就一直扫描
		while (i <= j) {
			// 左边寻找直到比支点大的数
			while (pivot > data[i]) {
				i++;
			}

			// 右边寻找直到比支点小的数
			while (pivot < data[j]) {
				j--;
			}

			// 此时已经分别找到了比支点小的数（右边）、比支点大的数（左边），它们进行交换
			if (i <= j) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				// 左边右移一位
				i++;
				// 右边左移一位
				j--;
			}
		}
		// 上面一个while保证了第一趟排序支点的左边比支点小，支点的右边比支点大了。

		// 左边再做排序，直到左边剩下一个数（递归出口）
		if (L < j) {
			System.out.println("sort left before, L : " + L + " ,j : " + j);
			sort(data, L, j);
			System.out.println("sort left end, L : " + L + " ,j : " + j);
		}
		// 右边再做排序，直到右边剩下一个数（递归出口）
		if (i < R) {
			System.out.println("sort right before, i : " + i + " ,R : " + R);
			sort(data, i, R);
			System.out.println("sort right end, i : " + i + " ,R : " + R);
		}
	} // sort end

}
