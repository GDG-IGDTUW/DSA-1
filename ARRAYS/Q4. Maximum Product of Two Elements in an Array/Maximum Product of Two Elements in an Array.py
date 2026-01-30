class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1=INT_MIN, num2=INT_MIN;
        for (int dig : nums) {
            if (dig>=num1) {
                num2=num1;
                num1=dig;
            }
            else if (dig<=num1 && dig>=num2){
                num2=dig;
            }
        }
        return (num1-1)*(num2-1);
    }
};
