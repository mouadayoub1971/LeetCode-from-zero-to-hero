class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>  res ;
        vector<int> sol ;
        back(nums, res, sol, 0, n) ;
        return res;
    }
private:
void back(vector<int> &nums, vector<vector<int>> &res, vector<int> &sol, int start , int size){
    if (start == size){
        res.push_back(sol);
        return ;
    }
    back(nums, res, sol, start+1, size);
    sol.push_back(nums[start]);
    back(nums, res, sol, start+1, size);
    sol.pop_back();

}

};
