/*剑指 Offer 11. 旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof

执行用时：4 ms, 在所有 C 提交中击败了97.51% 的用户
内存消耗：5.9 MB, 在所有 C 提交中击败了54.64% 的用户
*/
//特点：数组的最右元素比数组的开始元素小（如果大的话直接就不用找了）
//于是就把它当作是最小的元素，然后继续搜索
//二分查找：选择当前的最小元素和它左起的元素中点，如果中点元素比最小元素小
//那就相当于又找到了一个更小的元素，于是说明更小的元素在中点的左侧
//如果中点元素比最小元素大，那就说明最小元素在中点右侧
//如果中点元素和最小元素相等，那就说明最小元素既可能在左侧，也可能在右侧
//再依次对两侧进行查找，先找左侧，如果左侧找出的最小元素比中点元素更小，那就说明在左边，就不用查找右边了
int binary_search_min(int *numbers, int numbersSize, int current_min){
  if (numbersSize < 2){
    return (numbers[0] < current_min)? numbers[0] : current_min;
  }
  
  int mid = (numbersSize - 1) / 2;
  if (numbers[mid] < current_min){
    current_min = numbers[mid];
    //说明更小的元素在numbers[0,mid - 1],继续进行查找
    if (mid > 0){
      return binary_search_min(numbers, mid, current_min);
    }
  } else if (numbers[mid] > current_min){
    if (numbersSize > mid + 1){
      return binary_search_min(numbers + mid + 1,
        numbersSize - mid - 1, current_min);
    }
  } else {
    int new_min = current_min;
    //如果二者相等，那么更小值可能在mid左侧，也可能在右侧
    if (mid > 0){
      new_min = binary_search_min(numbers, mid, current_min);
      //如果左侧的值更小，就不用找右边了，直接返回
      if (new_min < current_min){
        return new_min;
      }
    }
    if (numbersSize > mid + 1) {
      return binary_search_min(numbers + mid + 1,
        numbersSize - mid - 1, current_min);
    }
  }

  return current_min;
}
int minArray(int* numbers, int numbersSize){
  if (numbersSize <= 1){
    return numbers[0];
  }
  return binary_search_min(numbers, numbersSize - 1,
    numbers[numbersSize - 1]);
}