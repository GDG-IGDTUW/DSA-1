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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int topRow = 0, bottomRow = m - 1, leftColumn = 0, rightColumn = n - 1;
        
        while (head) {
            // Fill top row
            for (int col = leftColumn; col <= rightColumn && head; ++col) {
                matrix[topRow][col] = head->val;
                head = head->next;
            }
            topRow++;
            
            // Fill right column
            for (int row = topRow; row <= bottomRow && head; ++row) {
                matrix[row][rightColumn] = head->val;
                head = head->next;
            }
            rightColumn--;
            
            // Fill bottom row
            for (int col = rightColumn; col >= leftColumn && head; --col) {
                matrix[bottomRow][col] = head->val;
                head = head->next;
            }
            bottomRow--;
            
            // Fill left column
            for (int row = bottomRow; row >= topRow && head; --row) {
                matrix[row][leftColumn] = head->val;
                head = head->next;
            }
            leftColumn++;
        }
        
        return matrix;
    }
};
