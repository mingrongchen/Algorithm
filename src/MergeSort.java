/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月20日 下午4:51:06
 * @ClassName MergeSort
 * @类描述-Description:归并排序
 * @修改记录:
 * @版本: 1.0
 */
public class MergeSort {

	public static void test() {
		System.out.println("MergeSort test start ...");
		int[] testData = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		sort(testData, 0, testData.length - 1);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("MergeSort test end ...");
		System.out.println("----------------------");

	} // test end

	/**
	 * 
	 * @Title: sort
	 * @Description: 归并排序
	 * @param data:数组
	 * @param L:指向数组第一个元素
	 * @param R :指向数组最后一个元素
	 * @return void  返回类型
	 * @throws
	 */
	public static void sort(int[] data, int L, int R) {
		// 如果只有一个元素，那就不用排序了
		if (L == R) {
			return;
		} else {
			// 取中间的数，进行拆分
			int M = L + (R - L) / 2;

			System.out.println("sort left before, L : " + L + " ,M : " + M);
			// 左边的数不断进行拆分
			sort(data, L, M);
			System.out.println("sort left end, L : " + L + " ,M : " + M);

			System.out.println("sort right before, M+1 : " + (M + 1) + " ,R : " + R);
			// 右边的数不断进行拆分
			sort(data, M + 1, R);
			System.out.println("sort right end, M+1 : " + (M + 1) + " ,R : " + R);

			System.out.println("merge before, L: " + L + ", M+1 : " + (M + 1) + " ,R : " + R);
			// 合并
			merge(data, L, M + 1, R);
			System.out.println("merge end, L: " + L + ", M+1 : " + (M + 1) + " ,R : " + R);
		}
	} // sort end

	/**
	 * 
	 * @Title: merge
	 * @Description:合并数组
	 * @param data:数组
	 * @param L:指向数组第一个元素
	 * @param M:指向数组分隔元素
	 * @param R:指向数组最后一个元素
	 * @return void  返回类型
	 * @throws
	 */
	public static void merge(int[] data, int L, int M, int R) {
		// 左边数组的大小
		int[] leftData = new int[M - L];

		// 右边数组的大小
		int[] rightData = new int[R - M + 1];

		// 往这两个数组填充数据
		for (int i = L; i < M; i++) {
			leftData[i - L] = data[i];
		}

		for (int i = M; i <= R; i++) {
			rightData[i - M] = data[i];
		}

		int i = 0, j = 0;
		// data数组的第一个元素
		int k = L;

		// 比较两个数组的值，哪个小，就往数组上放
		while (i < leftData.length && j < rightData.length) {
			// 谁比较小，谁将元素放入大数组中，移动指针，继续比较下一个
			if (leftData[i] < rightData[j]) {
				data[k] = leftData[i];

				i++;
				k++;
			} else {
				data[k] = rightData[j];

				j++;
				k++;
			}
		}

		// 如果左边数组没有比较完，右边数组已经完了，那么将左边数组复制到大数组中（剩下的都是大数字）
		while (i < leftData.length) {
			data[k] = leftData[i];

			i++;
			k++;
		}

		// 如果右边数组没有比较完，左边数组已经完了，那么将右边数组复制到大数组中（剩下的都是大数字）
		while (j < rightData.length) {
			data[k] = rightData[j];

			j++;
			k++;
		}

	} // merge end

}
