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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>exist;
        for(int i=0;i<nums.size();i++){
            exist.insert(nums[i]);
        }
        ListNode* nd=head;
        ListNode* tail=nullptr;
        while(nd==head&&nd!=nullptr){
            if(exist.count(nd->val)){
                head=nd->next;
            }
            tail=nd;
            nd=nd->next;
        }
        while(nd!=nullptr){
           
            if(exist.count(nd->val)){
                tail->next=nd->next;
            }
            else{
                tail=nd;
            }
            
            nd=nd->next;
        }
        return head;
    }
};