Given an array of strings, group the anagrams together.

Example :

Input: strs = ["eat","tea","tan","ate","nat","bat"]  
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Link to question : https://leetcode.com/problems/group-anagrams/

Provide a screenshot of the accepted solution on Leetcode, including the left pane in the description of pull request and push the solution.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
the code is as follows:


unordered_map<string, vector<string>> words;
for (int i = 0; i < strs.size(); i++) {
    string key = strs[i];        
    sort(key.begin(), key.end()); 
    words[key].push_back(strs[i]);
}
vector<vector<string>> result;
for (auto it : words) {
  result.push_back(it.second);
}
return result;
