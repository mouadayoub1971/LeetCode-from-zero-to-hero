class Solution {
 public:
     vector<int> twoSum(vector<int>& numbers, int target) {
         int p1 = 0;
         int p2 = numbers.size() - 1;
         
         while (p1 < p2) { // Correct condition
             int sum = numbers[p1] + numbers[p2];
             
             if (sum == target) {
                 return {p1 + 1, p2 + 1}; // Return 1-based indices
             } else if (sum < target) {
                 p1++; // Move left pointer to increase sum
             } else {
                 p2--; // Move right pointer to decrease sum
             }
         }
         
         return {}; // Return empty vector if no solution found
     }
 };
 