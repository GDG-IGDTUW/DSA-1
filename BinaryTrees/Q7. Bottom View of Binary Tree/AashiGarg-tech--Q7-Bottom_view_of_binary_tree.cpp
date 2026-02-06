/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
      vector<int> bottomView(Node *root) {
          vector<int> ans;
          if (!root) return ans;
  
          map<int, int> mp;
  
          queue<pair<Node*, int>> q;
          q.push({root, 0});
  
          while (!q.empty()) {
              auto curr = q.front();
              q.pop();
  
              Node* node = curr.first;
              int hd = curr.second;
  
              mp[hd] = node->data;
  
              if (node->left)
                  q.push({node->left, hd - 1});
  
              if (node->right)
                  q.push({node->right, hd + 1});
          }
  
          for (auto &x : mp) {
              ans.push_back(x.second);
          }
  
          return ans;
      }
  };
  