///LeetCode 2. Add Two Numbers C++
///write by LoneWolfL in 16.09.08
/**
test:
2,4,3
5,6,4

9,9,9
1
**/

#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode *l1,ListNode *l2)
    {
        ListNode *ans=NULL,*tail;
        //initialize
        ans=new ListNode(l1->val+l2->val);
        tail=ans;
        int k=tail->val/10;
        tail->val=tail->val%10;
        //calculation
        ListNode *pos_l1=l1->next;
        ListNode *pos_l2=l2->next;
        int val_l1,val_l2;
        while (pos_l1!=NULL||pos_l2!=NULL)
        {
            if (pos_l1!=NULL)
            {
                val_l1=pos_l1->val;
                pos_l1=pos_l1->next;
            }
            else val_l1=0;
            if (pos_l2!=NULL)
            {
                val_l2=pos_l2->val;
                pos_l2=pos_l2->next;
            }
            else val_l2=0;
            tail->next=new ListNode(val_l1+val_l2+k);
            tail=tail->next;
            k=tail->val/10;
            tail->val=tail->val%10;
        }
        if (k!=0)
        {
            tail->next=new ListNode(k);
        }
        return ans;
    }
};
const size_t N = 3;
const size_t M = 1;
int List1[N]={9,9,9};
int List2[M]={1};
int main()
{
    Solution AddTwoNumbers;
    ListNode *l1=NULL,*l2=NULL,*T;
    for (size_t i=0;i<N;i++)
    {
        T=new ListNode(List1[i]);
        T->next=l1;
        l1=T;
    }
    for (size_t i=0;i<M;i++)
    {
        T=new ListNode(List2[i]);
        T->next=l2;
        l2=T;
    }
    ListNode *ans=AddTwoNumbers.addTwoNumbers(l1,l2);
    while (ans!=NULL)
    {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
}
