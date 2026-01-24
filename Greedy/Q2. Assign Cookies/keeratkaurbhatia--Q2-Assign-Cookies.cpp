//TC: O(n log n + m log m) due to sorting
//SC: O(1) as the sorting is in-place

/*
approach:
1. sort the greed factors of children and the sizes of cookies.
2. use two pointers: i for children and j for cookies
3. try to assign the smallest available cookie that can satisfy the current child.
4. continue until either all children or all cookies are exhausted.

why greedy?
assigning the smallest possible cookie to the least greedy child preserves larger cookies for greedier children.
and any larger cookie used earlier would only reduce future options and cannot increase the total number of satisfied children.
*/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0; //pointers

        //until either of the vector is exhausted
        while (i < g.size() && j < s.size()) 
        {
            if (s[j] >= g[i]) i++;  //cookie satisfies, move to the next child
            j++;                   //whether satisfied or not, move to next cookie regardless
        }
        return i; //number of satisfied children, as i is incremented only after the child is satisfied
    }
};
