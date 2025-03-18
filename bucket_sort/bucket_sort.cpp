#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {
    if(arr.empty()) return ;
    int numBucket = arr.size();
    vector<vector<float>> buckets(numBucket);
    float minVal = *min_element(arr.begin(), arr.end());
    float maxVal = *max_element(arr.begin(), arr.end());
    float range = maxVal - minVal ;
    if (range == 0) return ;
    for(float num : arr) {
        int index = (num - minVal) / range * (numBucket - 1);
        buckets[index].push_back(num);
    }
    for(auto& bucket: buckets){
        sort(bucket.begin(), bucket.end());
    }
    int index = 0; 
    for(auto& bucket: buckets){
        for(float num: bucket){
            arr[index++] = num;
        }
    }
}

int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    bucketSort(arr);

    for (float num : arr) {
        cout << num << " ";
    }
    return 0;
}
