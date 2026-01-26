class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            unordered_map<int, int> count;
            int left = 0;
            int maxLen = 0;
    
            for (int right = 0; right < fruits.size(); right++) {
                count[fruits[right]]++;
    
                while (count.size() > 2) {
                    count[fruits[left]]--;
                    
                    if (count[fruits[left]] == 0) {
                        count.erase(fruits[left]);
                    }
                    left++;
                }
    
                maxLen = max(maxLen, right - left + 1);
            }
    
            return maxLen;
        }
    };
    