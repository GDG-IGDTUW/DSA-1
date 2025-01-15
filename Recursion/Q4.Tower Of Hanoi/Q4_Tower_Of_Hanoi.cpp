# include <iostream>
# include <string>
using namespace std;

void TowerOfHanoi(int n, string from, string to, string aux, int &cnt){
    // Base Case
    if (n == 0){
        return;
    }

    // Recursive Case
    TowerOfHanoi(n - 1, from, aux, to, cnt);
    cnt ++;
    TowerOfHanoi(n - 1, aux, to, from, cnt);
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    int cnt = 0;
    // R1 : Rod 1(from), R2 : Rod 2(to), R3 : Rod 3(aux)
    TowerOfHanoi(n, "R1", "R2", "R3", cnt);
    cout << cnt << endl;
    return 0;
}