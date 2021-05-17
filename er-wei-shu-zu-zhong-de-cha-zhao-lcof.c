/*
剑指 Offer 04. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
执行用时：40 ms, 在所有 C 提交中击败了65.16% 的用户
内存消耗：8.1 MB, 在所有 C 提交中击败了76.16% 的用户
*/

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
  //从右上角的元素开始比较，如果该元素比target大，则说明最右的一列中没有target，可排除
  //如果该元素比target小，说明该元素所在的一行中没有target，可排除
  //如果该元素==target，则返回
  //依此类推
  int last_row, last_col;
  int row;
  if (!matrixSize || (*matrixColSize == 0)){
    return false;
  }

  last_col = (*matrixColSize) - 1;
  last_row = matrixSize - 1;

  for (row = 0; row <= last_row;){
    if (matrix[row][last_col] == target){
      return true;
    }
    
    if (matrix[row][last_col] < target){
      row++;
    } else if (matrix[row][last_col] > target){
      if (last_col == 0){
        break;
      }
      last_col--;
    }
  }

  return false;
}