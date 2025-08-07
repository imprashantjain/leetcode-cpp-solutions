#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;
class Solution {
public:
    int mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;
        int mid = l + (r - l) / 2;
        int cnt = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);
        int j = mid + 1;
        for(int i = l; i <= mid; i++) {
            while(j <= r && (long long)nums[i] > 2LL * nums[j]) j++;
            cnt += (j - (mid + 1));
        }
        inplace_merge(nums.begin() + l, nums.begin() + mid + 1, nums.begin() + r + 1);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Reverse Pairs: " << sol.reversePairs(nums) << endl;
    return 0;
} 