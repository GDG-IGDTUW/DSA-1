class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int max1 = 0, max2 = 0;
            for (int x : nums) {
                if (x > max1) {
                    max2 = max1;
                    max1 = x;
                } else if (x > max2) {
                    max2 = x;
                }
            }
            return (max1 - 1) * (max2 - 1);
        }
    };