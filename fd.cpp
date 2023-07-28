#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findDuplicateNumber(vector<int>& nums) {
    unordered_set<int> numSet;
    
    for (int num : nums) {
        if (numSet.count(num) > 0) {
            return num;
        }
        numSet.insert(num);
    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> nums[i];
    }
    
    cout << findDuplicateNumber(nums) << endl;
    
    return 0;
}