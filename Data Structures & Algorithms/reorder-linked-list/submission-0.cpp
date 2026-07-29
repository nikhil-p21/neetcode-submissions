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
    void reorderList(ListNode* head) {
        
        vector<ListNode*>pointers; 
        ListNode* curr = head; 
        while(curr)
        {
            pointers.push_back(curr); 
            curr = curr->next; 
        }
        int n = pointers.size(); 
        
        int i=0, j=pointers.size()-1; 
        while(i<j)
        {
            pointers[i]->next = pointers[j]; 
            i++; 
            if(i>=j)break; 
            pointers[j]->next = pointers[i]; 
            j--; 
        }

        pointers[i]->next = NULL; 

        
    }
};
