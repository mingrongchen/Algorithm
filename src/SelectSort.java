/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月20日 下午2:04:35
 * @ClassName SelectSort
 * @类描述-Description:选择排序
 * @修改记录:
 * @版本: 1.0
 */
public class SelectSort {
	public static void test() {
		System.out.println("SelectSort test start ...");
		int[] testData = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		sort(testData);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("SelectSort test end ...");
		System.out.println("----------------------");

	} // test end

	public static void sort(int[] data) {
		// 记录当前趟数的最小值的角标
		int minPos;
		// 交换的变量
		int temp;
		for (int i = 0; i < data.length; i++) {
			// 新的趟数的起点
			minPos = i;
			// 选出之后排序中值最小的位置
			for (int j = i + 1; j < data.length; j++) {
				if (data[j] < data[i]) {
					minPos = j;
				}
			}
			// 最小值不等于当前值时进行交换
			if (minPos != i) {
				temp = data[i];
				data[i] = data[minPos];
				data[minPos] = temp;
			}
		}
	} // sort end

}
