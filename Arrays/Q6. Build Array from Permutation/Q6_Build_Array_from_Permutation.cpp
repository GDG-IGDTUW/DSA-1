# include <iostream>
# include <vector>
using namespace std;

void buildArray(int nums[], int n) {       
    for(int i = 0; i < n; i ++){            
        nums[i] = nums[i] + n * (nums[nums[i]] % n);       
    }
    for(int i = 0; i < n; i ++){
        nums[i] /= n;
    }       
}

int main(){
    int n;
    cout << "Enter the no of elements, n = ";
    cin >> n;
    int nums[n];
    cout << "Enter the elements of nums = ";
    for (int i = 0; i < n; i ++){
        cin >> nums[i];
    }
    buildArray(nums, n);
    cout << "[";
    for (int i = 0; i < n; i ++){
        cout << nums[i];
        if (i != n - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}