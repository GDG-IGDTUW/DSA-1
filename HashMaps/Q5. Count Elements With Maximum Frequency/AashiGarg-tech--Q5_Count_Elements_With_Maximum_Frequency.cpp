class Solution {
    public:
        int maxFrequencyElements(vector<int>& nums) {
            unordered_map <int,int> freq;
            int num=0;
            for(int i=0;i<nums.size();i++){
                freq[nums[i]]++;
                if(freq[nums[i]]>num){
                    num=freq[nums[i]];
                }
            }
            int sum=0;
            for(auto it:freq){
                if(it.second==num){
                    sum+=num;
                }
            }
            return sum;
        }
    };