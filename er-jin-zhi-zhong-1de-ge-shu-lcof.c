/*
剑指 Offer 15. 二进制中1的个数
请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof
执行用时：0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗：5.3 MB, 在所有 C 提交中击败了79.76% 的用户
*/

int hammingWeight(uint32_t n) {
   int i = 0;
   while (n){
     n = n & (n - 1);
     i++;
   } 
   return i;
