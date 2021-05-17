//剑指 Offer 10- II. 青蛙跳台阶问题
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
*/
//执行用时：0 ms, 在所有 C 提交中击败了100.00% 的用户
//内存消耗：5.5 MB, 在所有 C 提交中击败了30.70% 的用户
int numWays(int n){
  int fn;
  if (n < 2){
    fn = 1;
  } else {
    int i = 1;
    int fn_1 = 1, fn_2 = 1;
    while (i < n){
      fn = (fn_1 + fn_2) % 1000000007;
      fn_2 = fn_1;
      fn_1 = fn;
      i++;
    }
  }
  return fn;
}
