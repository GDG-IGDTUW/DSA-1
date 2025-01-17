#include<bits/stdc++.h>
using namespace std;


vector<int> deckRevealedIncreasing(vector<int> deck) {
    int n = deck.size();
    queue<int>q;

    for(int i =0 ;i<n;i++){
        q.push(i);
    }

    sort(deck.begin(),deck.end());
    vector<int>ans(n);

    for(int i = 0;i<n;i++){
        ans[q.front()]=deck[i];
        q.pop();

        if(!q.empty()){
            q.push(q.front());
            q.pop();
        }
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the value n : ";
    cin >>n;

    vector<int>deck(n);

    for(int i =0;i<n;i++){
        cin>>deck[i];
    }

    vector<int> ans = deckRevealedIncreasing(deck);

    for(int i = 0 ;i<n;i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;


    return 0;
}