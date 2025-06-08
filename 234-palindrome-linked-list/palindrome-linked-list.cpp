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
    //helper func to reverse the list
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //sec half ko rev karo
        ListNode* secondHalf = reverseList(slow->next);
        //compare first half and sec half
        ListNode *firstHalf=head;
        ListNode *secondHalfCopy=secondHalf;
        while(secondHalf){
            if(firstHalf->val != secondHalf->val){
                return false;
            }
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }
        return true;
    }
};