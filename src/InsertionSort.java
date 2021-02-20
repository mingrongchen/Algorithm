/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月20日 上午9:56:34
 * @ClassName InsertionSort
 * @类描述-Description:插入排序
 * @修改记录:
 * @版本: 1.0
 */
public class InsertionSort {
	public static void test() {
		System.out.println("InsertionSort test start ...");
		int[] testData = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		sort(testData);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("InsertionSort test end ...");
		System.out.println("----------------------");
		System.out.println("InsertionSort two test start ...");
		sortTwo(testData);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("InsertionSort two test end ...");

	} // test end

	// 通过将较大的元素都向右移动而不总是交换两个元素
	public static void sort(int[] data) {
		// 装载临时变量
		int temp;
		for (int i = 1; i < data.length; i++) {
			temp = data[i];
			int j = i - 1;
			// 如果前一位比当前数据要大，那么进入循环比较
			for (; j >= 0 && data[j] > temp; j--) {
				// 往后退一个位置，让当前数据与之前前位进行比较
				data[j + 1] = data[j];
			}
			// 退出内层循环，则说明找到了合适的位置，并将当前数据插入合适的位置中
			data[j + 1] = temp;
		}
	} // sort end

	// 通过交换进行插入排序，借鉴冒泡排序
	public static void sortTwo(int[] data) {
		// 装载临时变量
		int temp;
		for (int i = 1; i < data.length; i++) {
			// 如果前一位比当前数据要大，那么进入循环比较，并两两交换，参考冒泡排序
			for (int j = i - 1; j >= 0 && data[j] > data[j + 1]; j--) {
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
	} // sortTwo end

}
