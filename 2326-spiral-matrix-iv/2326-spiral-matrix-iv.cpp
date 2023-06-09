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
        vector<vector<int>> res(m, vector<int>(n, -1));
        
        
        int row = res.size();
        int column = res[0].size();
        
        int startRow = 0, lastRow = row-1, startCol = 0, lastCol = column-1;
        
        while(head != NULL){
            for(int i = startRow; i<=startRow; i++){
                for(int j = startCol; j<=lastCol-1; j++){
                    if(head == NULL) break;
                    res[i][j] = head->val;
                    head = head->next;
                }
            }
            
            
            for(int i = lastCol; i<=lastCol; i++){
                for(int j = startRow; j<=lastRow-1; j++){
                    if(head == NULL) break;
                    res[j][i] = head->val;
                    head = head->next;
                }
            }
            startRow++;
            lastCol--;
            
            for(int i = lastRow; i<=lastRow; i++){
                for(int j = lastCol+1; j>=startCol; j--){
                    if(head == NULL) break;
                    res[i][j] = head->val;
                    head = head->next;
                }
            }
            
            for(int i = startCol; i<=startCol; i++){
                for(int j = lastRow-1; j>=startRow; j--){
                    if(head == NULL) break;
                    res[j][i] = head->val;
                    head = head->next;
                }
            }
            lastRow--;
            startCol++;
        }
        
        return res;
        
    }
};