/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月20日 下午3:25:03
 * @ClassName RadixSort
 * @类描述-Description:基数排序、桶排序
 * @修改记录:
 * @版本: 1.0
 */
public class RadixSort {

	public static void test() {
		System.out.println("RadixSort test start ...");
		int[] testData = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		sort(testData);
		for (int i = 0; i < testData.length; i++) {
			System.out.println("data : " + testData[i]);
		}
		System.out.println("RadixSort test end ...");
		System.out.println("----------------------");

	} // test end

	public static void sort(int[] data) {
		if (data.length <= 1) {
			return;
		}

		// 取得数组中最大的数，并取得位数
		int max = 0;
		for (int i = 0; i < data.length; i++) {
			if (max < data[i]) {
				max = data[i];
			}
		}
		// 位数计算
		int maxDigit = 1;
		while (max / 10 > 0) {
			maxDigit++;
			max = max / 10;
		}

		// 申请一个桶空间，二维数组
		int[][] buckets = new int[10][data.length];
		int base = 10;

		// 从低位到高位，对每一位遍历，将所有元素分配到桶中
		for (int i = 0; i < maxDigit; i++) {
			// 存储各个桶中存储元素的数量
			int[] bktLen = new int[10];

			// 分配，将所有元素分配到桶中
			for (int j = 0; j < data.length; j++) {
				int whichBucket = (data[j] % base) / (base / 10);
				buckets[whichBucket][bktLen[whichBucket]] = data[j];
				bktLen[whichBucket]++;
			}

			// 收集，将不同桶里的数据挨个捞出来，为下一轮高位排序做准备，由于靠近桶底的元素排名靠前，因此从桶底先捞
			int k = 0;
			for (int b = 0; b < buckets.length; b++) {
				for (int p = 0; p < bktLen[b]; p++) {
					data[k++] = buckets[b][p];
				}
			}
			base *= 10;
		}
	} // sort end

}
