/*
剑指 Offer 03. 数组中重复的数字
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
执行用时：44 ms, 在所有 C 提交中击败了37.49% 的用户
内存消耗：10.1 MB, 在所有 C 提交中击败了81.83% 的用户
*/
int findRepeatNumber(int* nums, int numsSize){
  int buckets[numsSize];
  int i;

  if (!nums || numsSize <= 0){
    return 0; 
  }
  for (i = 0; i < numsSize; i++){
    buckets[i] = 0; 
  }
  for (i = 0; i < numsSize; i++){
    buckets[nums[i]]++; 
    if (buckets[nums[i]] > 1){
      break;
    }
  }
  return nums[i];
}