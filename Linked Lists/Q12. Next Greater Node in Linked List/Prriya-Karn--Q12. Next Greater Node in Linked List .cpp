/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        vector<int> resArr;
        ListNode* temp = head;
        stack<int> st;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = arr.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                resArr.push_back(0);
                st.push(arr[i]);
            } else if (st.top() > arr[i]) {
                resArr.push_back(st.top());
                st.push(arr[i]);
            } else {
                st.push(arr[i]);
                resArr.push_back(0);
            }
        }

        reverse(resArr.begin(), resArr.end());
        return resArr;
    }
};