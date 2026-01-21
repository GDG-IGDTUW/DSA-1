class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size(),cnt=0;
        if(m==1){
            if(n==1 and flowerbed[0]==0)return true;
            else if(n==0) return true;
            else return false;
        }
        for(int i=0;i<m;i++){
            if(flowerbed[i]==0){
                if(i!=0 and i!=m-1 and flowerbed[i-1]==0 and flowerbed[i+1]==0 ){cnt++; flowerbed[i]=1;}
                else if(i==0 and flowerbed[i+1]==0){cnt++; flowerbed[i]=1;}
                else if(i==m-1 and flowerbed[i-1]==0){cnt++; flowerbed[i]=1;}
            }
        }
        if(cnt>=n)return true;
        return false;
    }
};