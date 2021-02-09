/**
 * @版权 : Copyright (c) 
 * @author: mingrongchen
 * @E-mail: 825296313@qq.com
 * @版本: 1.0
 * @创建日期: 2021年2月9日 下午2:18:14
 * @ClassName Recursion
 * @类描述-Description:递归算法
 * @修改记录:
 * @版本: 1.0
 */
public class Recursion {
	public static void test() {
		System.out.println("Recursion factorial test begin ...");
		System.out.println("Recursion factorial result : " + factorialRecursion(5));
		System.out.println("----------------------");
		System.out.println("Recursion fibonacci result : " + fibonacciRecursion(9));
		System.out.println("----------------------");
		System.out.println("Recursion test all end ...");
	}

	public static int factorialRecursion(int n) {
		// 边界条件
		if (n <= 1) {
			return 1;
		}

		// 函数等价关系
		return n * factorialRecursion(n - 1);
	}

	public static int fibonacciRecursion(int n) {
		// 边界条件
		if (n <= 2) {
			return 1;
		}

		// 函数等价关系
		return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
	}

}
