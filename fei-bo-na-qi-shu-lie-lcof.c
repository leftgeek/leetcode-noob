/*
剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.

斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof
执行用时：0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗：5.3 MB, 在所有 C 提交中击败了80.99% 的用户
*/
int fib(int n){
  int fn = n;
  if (n > 1){
    int i = 1;
    int fn_1 = 1, fn_2 = 0;
    while (i < n){
      fn = (fn_1 + fn_2) % 1000000007;
      fn_2 = fn_1;
      fn_1 = fn;
      i++;
    }
  }

  return fn;
}