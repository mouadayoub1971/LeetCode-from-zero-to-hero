import java.util.HashSet;

public class Solution {
 public int[] twoSum(int[] numbers, int target) {
  int rightPointer = 0;
  int leftPointer = numbers.length - 1;
  while (rightPointer < leftPointer) {
   if (numbers[rightPointer] + numbers[leftPointer] == target) {
    return new int[] {rightPointer, leftPointer};
   } else if( rightPointer + leftPointer < target){
    rightPointer++;
   } else if( rightPointer + leftPointer > target){
    leftPointer--;
   }
  }
  return null; 
 }
}
