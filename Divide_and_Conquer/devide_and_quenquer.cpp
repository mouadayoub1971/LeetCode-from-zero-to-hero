class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        mergeSort(nums,left,right);
        return nums;
    }
private:
void merge(vector<int> &nums, int left, int m, int right){
vector<int> sorted (right - left +1);
int i = left ;
int j = m +1;
int k = 0;

while(i <=m && j<=right){
    if(nums[i] <= nums[j]){
        sorted[k++] = nums[i++];
    }else {
        sorted[k++] = nums[j++];
    }
}

while(i <=m){
    sorted[k++] = nums[i++];
}

while(j <=right){
    sorted[k++] = nums[j++];
}

copy(sorted.begin(), sorted.end(), nums.begin() +left);
}
void mergeSort(vector<int> &nums, int left, int right){
if(left >=right){
    return;
}
int m = left + (right - left)/2;
mergeSort(nums, left,m);
mergeSort(nums, m+1, right);
merge(nums, left, m,right);
}
};
