#include <iostream>
#include <vector>

using namespace std;

int min_subarray(const vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0;
    int length = n + 1;
    int sum = 0;
    
    for (int right = 0; right < n; ++right) {
        sum += nums[right];
        
        while (sum >= k) {
            length = min(length, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    
    return length;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = min_subarray(nums, k);
    
    cout << result << endl;
    
    return 0;
}