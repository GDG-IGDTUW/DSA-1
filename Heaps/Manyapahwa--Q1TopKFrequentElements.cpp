#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Create buckets for frequencies
        int n = nums.size(); // Maximum frequency is bounded by the size of nums
        vector<vector<int>> buckets(n + 1);
        for (unordered_map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
            int num = it->first;
            int freq = it->second;
            buckets[freq].push_back(num); // Place each number into its respective frequency bucket
        }

        // Step 3: Collect the top K frequent elements
        vector<int> result;
        for (int i = n; i > 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Taking input for the array of numbers and the value of k
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    // Get the result from the topKFrequent function
    vector<int> result = sol.topKFrequent(nums, k);

    // Output the result
    cout << "The " << k << " most frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
