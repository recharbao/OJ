#include<iostream>
#include<stack>
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k);


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



int main()
{
    return 0;
}

//非递归求解
ListNode* reverseKGroup(ListNode* head, int k)
{
    if(k == 1 || head == NULL) return head;
    ListNode* pivot = head;
    ListNode* prepivot = NULL;
    ListNode* PreFis = head;
    ListNode* p = head;
    ListNode* q;
    int count = 0;
    int num = 0;
    while (p != NULL)
    {
        num++;
        p = p -> next;
    }

    p = head -> next;

    int K = num / k;
    int count_K = 0;

    while (p != NULL && count_K ++ < K)
    {
        while (++ count < k)
        {
            q = p -> next;
            pivot -> next = q;
            p -> next = PreFis;
            PreFis = p;
            p = q;
        }

        if(prepivot != NULL)
        {
            prepivot -> next = PreFis;
            prepivot = pivot;
        }

        else
        {
            prepivot = pivot;
            head = PreFis;
        }

        if(count_K < K)
        {
            count = 0;
            pivot = p;
            PreFis = p;
            p = p -> next;
        }
    }
    prepivot -> next = p;

    return head;
}


//递归求解
/*
ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* pivot = head;

    int count = 0;

    while (pivot != NULL && count < k)
    {
        pivot = pivot -> next;
        count ++;
    }
    pivot = head;
    if(count < k)
    {
        return head;
    }
    else
    {
        count = 0;
    }

    ListNode* p = head -> next;
    ListNode* PreFis = head;
    ListNode* q;
    
    while (++ count < k)
    {
        q = p -> next;
        pivot -> next = q;
        p -> next = PreFis;
        PreFis = p;
        p = q;
    }
    
    pivot -> next = reverseKGroup(p,k);

    return PreFis;
}
*/









yh




