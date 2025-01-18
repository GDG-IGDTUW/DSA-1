#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool areIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;//case when length of both strings is not equal
    
    //creating maps for tracking character mapping in both directions 
    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];
      
        // Checking if there's a conflict in the mapping
        if ((mapST.count(c1) && mapST[c1] != c2) || 
            (mapTS.count(c2) && mapTS[c2] != c1)) {
            return false;
        }
        // Adding the mappings to the maps created
        mapST[c1] = c2;
        mapTS[c2] = c1;
    }

    return true;
}

int main() {
    string s1 = "egg", t1 = "add";
    cout << boolalpha << isIsomorphic(s1, t1) << endl; // Should give Output: true

    string s2 = "foo", t2 = "bar";
    cout << boolalpha << isIsomorphic(s2, t2) << endl; // Should give Output: false

    return 0;
}
