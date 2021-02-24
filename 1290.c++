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
    int getDecimalValue(ListNode* head) {
        //First approach find the length of linked list.
        int length=0;
        struct ListNode* temp=head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        cout<<length<<endl;
        long long int ans=0;
        temp=head;
        //Now convert the binary representation into decimal format by using the formula (2^(length-1))*value;
        while(temp!=NULL){
            ans+=(temp->val*pow(2,--length));
            temp=temp->next;
        }
        return ans;
    }
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        //second approach we can use the current value of head and then multiply with that val+next val to get decimal value
        int ans=head->val;
        struct ListNode* temp=head;
        while(temp->next!=NULL){
            ans=2*ans+temp->next->val;
            // or we can use bit manipulation here to find the value
            //ans=(ans << 1) | temp->next->val;
            temp=temp->next;
        }
        return ans;
    }
};

