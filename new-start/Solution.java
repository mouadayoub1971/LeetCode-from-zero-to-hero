import java.util.HashSet;

public class Solution {
 public int lengthOfLongestSubstring(String s) {
  int leftPointer = 0;
  int maxLength = 0;
  HashSet<Character> mySet = new HashSet<>();
  for (int rightPointer = 0; rightPointer < s.length(); rightPointer++) {
   Character current = s.charAt(rightPointer);
   while (mySet.contains(current)) {
    mySet.remove(s.charAt(leftPointer++));
   }
   mySet.add(current);
   maxLength = Math.max(maxLength, rightPointer - leftPointer + 1);
  }
 
  return maxLength;
 }
}
