# include <iostream>
# include <vector>
# include <string>
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int n = operations.size();
    int x = 0;
    for (int i = 0; i < n; i ++){
        if(operations[i] == "++X" || operations[i] == "X++"){
            x ++;
        }
        else{
            x --;
        }
    }
    return x;
}

int main(){
    int n;
    cout << "No of elements, n = ";
    cin >> n;
    vector<string> op(n);
    cout << "Elements = ";
    for (int i = 0; i < n; i ++){
        cin >> op[i];
    }
    cout << "FINAL VALUE = " << finalValueAfterOperations(op) << endl;
    return 0;
}

