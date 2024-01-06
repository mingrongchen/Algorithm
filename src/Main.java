/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021-2-8 23:46:39
 * @ClassName Main
 * @类描述-Description: 测试入口
 * @修改记录:
 * @版本: 1.0
 */

public class Main {

	static void sleepTask(int ms) {
		try {
			Thread.currentThread();
			Thread.sleep(ms);
		} catch (InterruptedException e) {
			e.printStackTrace();
			Thread.currentThread().interrupt();
		}
	}

	public static void main(String[] args) {
		System.out.println("Main begin ...");
		// MergeSort.test();

		// for (int i = 0; i < 3; i++) {
		// System.out.println("Main : " + i + " ,time : " +
		// System.currentTimeMillis());
		// sleepTask(2000);
		// }

		int test[] = new int[10];

		if (test == null) {
			System.out.println("test is null ...");
		} else {
			System.out.println("test is not null ...");
		}
		System.out.println("Main end ...");

	}
}
