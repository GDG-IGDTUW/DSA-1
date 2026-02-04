class Solution {
    public  static int maxArea(int[] height) {
        int maxwidth=height.length-1;
        int c=height.length;
        int maxarea=1;
        int left=0;
        int right=height.length-1;
        int count=0;
        for(int i = 0 ; i <height.length;i++){
            if(height[i] ==  0){ count++;}
        }
        while(left<right){
                if( count !=0 &&(count==c || count == c-1)) return 0;
              else if(height[left]<height[right]){
                int maxareacal= height[left]*maxwidth;
                if(maxareacal>=maxarea) maxarea=maxareacal;
                maxwidth--;
                left++;
            }
            else if(height[left]>height[right]){
                int  maxareacal= height[right]*maxwidth;
                if(maxareacal>=maxarea) maxarea=maxareacal;
                maxwidth--;
                right--;
            }
             else if(height[left]==height[right]){
                 int  maxareacal= height[right]*maxwidth;
                if(maxareacal>=maxarea) maxarea=maxareacal;
                left++;
                maxwidth--;
            }
            
        }
        return maxarea;
    }
}