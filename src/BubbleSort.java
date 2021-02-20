/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月19日 下午5:18:24
 * @ClassName BubbleSort
 * @类描述-Description:冒泡排序
 * @修改记录:
 * @版本: 1.0
 */
public class BubbleSort {

	public static void test() {
		System.out.println("BubbleSort test start ...");
		int[] testData = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		sort(testData);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("BubbleSort test end ...");
		System.out.println("----------------------");
		System.out.println("Better BubbleSort test start ...");
		int[] testDataTwo = { 1, 3, 2, 4, 5, 6, 7, 8, 9, 10, 11 };
		betterSort(testDataTwo);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("Better BubbleSort test end ...");

	} // test end

	public static void sort(int[] data) {
		// 测试用，记录执行了多少趟
		int num = 0;
		// 装载临时变量
		int temp;
		// 外层是排序的趟数
		for (int i = 0; i < data.length - 1; i++) {
			// 内层循环是当前趟数需要比较的次数
			for (int j = 0; j < data.length - i - 1; j++) {
				// 前一位与后一位相比较，如果前一位比后一位要大，则交换
				if (data[j + 1] < data[j]) {
					temp = data[j + 1];
					data[j + 1] = data[j];
					data[j] = temp;
				}
			}
			num++;
		}
		System.out.println("Sort run frequency is : " + num);
	} // sort end

	public static void betterSort(int[] data) {
		// 测试用，记录执行了多少趟
		int num = 0;
		// 装载临时变量
		int temp;
		// 记录是否发生了置换，0代表没有发生置换，1代表发生了置换
		int isChange;
		// 外层是排序的趟数
		for (int i = 0; i < data.length - 1; i++) {
			// 每比较一趟就重新初始化为0
			isChange = 0;
			// 内层循环是当前趟数需要比较的次数
			for (int j = 0; j < data.length - i - 1; j++) {
				// 前一位与后一位相比较，如果前一位比后一位要大，则交换
				if (data[j + 1] < data[j]) {
					temp = data[j + 1];
					data[j + 1] = data[j];
					data[j] = temp;

					// 如果进到这里面了，说明发生了置换
					isChange = 1;
				}
			}
			// 如果比较完一趟没有发生置换，那么说明已经排好序了，不需要再执行下去了
			if (isChange == 0) {
				break;
			}
			num++;
		}
		System.out.println("betterSort run frequency is : " + num);
	} // better sort end

}
