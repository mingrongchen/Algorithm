/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月20日 下午1:38:02
 * @ClassName ShellSort
 * @类描述-Description:希尔排序
 * @修改记录:
 * @版本: 1.0
 */
public class ShellSort {
	public static void test() {
		System.out.println("ShellSort test start ...");
		int[] testData = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		sort(testData);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("ShellSort test end ...");
		System.out.println("----------------------");

	} // test end

	public static void sort(int[] data) {
		int temp;
		// 增量每次都/2
		for (int step = data.length / 2; step > 0; step /= 2) {
			// 从增量那组开始进行插入排序，直至完毕
			for (int i = step; i < data.length; i++) {
				temp = data[i];
				int j = i - step;
				for (; j >= 0 && data[j] > temp; j -= step) {
					// 往后退一个step位置，让当前数据与之前前位进行比较
					data[j + step] = data[j];
				}
				// 退出内层循环，则说明找到了合适的位置，并将当前数据插入合适的位置中
				data[j + step] = temp;
			}
		}
	} // sort end

}
