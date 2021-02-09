/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021-2-8 23:47:30
 * @ClassName BinarySearch
 * @类描述-Description: 二分查找算法
 * @修改记录:
 * @版本: 1.0
 */
public class BinarySearch {
	public static void test() {
		System.out.println("BinarySearch with no recursion test begin ...");
		int[] testData = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		int out = BinarySearch.binarySearch(testData, 2);
		System.out.println("out index : " + out + " ,data:" + testData[out]);
		System.out.println("----------------------");
		System.out.println("BinarySearch with recursion test begin ...");
		int outRecursion = BinarySearch.binarySearchRecursion(testData, 0, testData.length, 11);
		System.out.println("out index : " + outRecursion + " ,data:" + testData[outRecursion]);
		System.out.println("----------------------");
		System.out.println("BinarySearch test end ...");

	}

	public static int binarySearch(int[] nums, int target) {
		// 初始化左右指针, [left, right]
		int left = 0;
		int right = nums.length - 1;

		// 循环遍历
		while (left <= right) {
			// (right + left) / 2
			// 目的:防止溢出
			int mid = left + (right - left) / 2;

			if (nums[mid] == target) {
				// 返回该数值的位置
				return mid;
			} else if (nums[mid] < target) {
				// 目标值在右边,移动左指针
				left = mid + 1;
			} else if (nums[mid] > target) {
				// 目标值在左边,移动右指针
				right = mid - 1;
			}
		} // whild end
			// 未找到这个值
		return -1;
	} // binarySearch end

	public static int binarySearchRecursion(int[] nums, int left, int right, int target) {
		if (left <= right) {
			// 目的:防止溢出
			int mid = left + (right - left) / 2;

			if (nums[mid] == target) {
				return mid;
			}

			if (nums[mid] < target) {
				// 目标值在右边,向右递归
				return binarySearchRecursion(nums, mid + 1, right, target);
			} else if (nums[mid] > target) {
				// 目标值在左边,向左递归
				return binarySearchRecursion(nums, left, mid - 1, target);
			}
		}

		return -1;
	}

}
