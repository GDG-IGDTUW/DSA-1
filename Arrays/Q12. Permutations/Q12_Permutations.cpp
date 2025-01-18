# include <iostream>
# include <algorithm>
using namespace std;

void Permutations(int arr[], int n){
    do {
        cout << "[";
        for (int i = 0; i < n; i ++){
            cout << arr[i];
            if (i != n - 1)     cout << ", ";
        }
        cout << "]" << endl;
    } while (next_permutation(arr, arr + n) == true);
}

int main(){
    int n;
    cout << "No of elements, n = ";
    cin >> n;
    int arr[n];
    cout << "Elements of Array = ";
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    cout << "[" << endl;
    Permutations(arr, n);
    cout << "]";
    return 0;
}

