class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0, length=0;
        //iterating the vector for each element
      
        for (int n: nums){
            length = log10(n)+1;   //length of each element              
            
            if (length %2==0){
                count+=1;           // if length is even, increment count
            }
        }
        return count;        
    }
};
