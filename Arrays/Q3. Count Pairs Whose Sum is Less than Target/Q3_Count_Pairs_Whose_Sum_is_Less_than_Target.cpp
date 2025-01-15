# include <iostream>
# include <vector>
using namespace std;

int countPairs(int nums[], int n, int target) {
    int cnt = 0; 
    for (int i = 0; i < n - 1; i ++){
        for (int j = i + 1; j < n; j ++){
            if (nums[i] + nums[j] < target){
                cnt ++;
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    cout << "No of elements, n = ";
    cin >> n;
    int nums[n];
    cout << "Elements of nums = ";
    for (int i = 0; i < n; i ++){
        cin >> nums[i];
    }
    int target;
    cout << "target = ";
    cin >> target;
    cout << countPairs(nums, n, target) << endl;
    return 0;
}