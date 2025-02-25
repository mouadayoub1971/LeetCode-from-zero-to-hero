#include <queue>
#include <vector>

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    int kthSize;

    KthLargest(int k, std::vector<int>& nums) {
        kthSize = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kthSize) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

