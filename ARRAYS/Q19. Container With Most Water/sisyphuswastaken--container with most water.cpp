class Solution {
public:
    int maxArea(vector<int>& height) {
        //2 ptr
        int l = 0;
        int r = height.size()-1;
        int area = 0;
        while(l<r){
            int h = min(height[l], height[r]);
            int w = r-l;
            area = max(area, w*h);
            if(h == height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        return area;
    }
};