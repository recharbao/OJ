#include<iostream>
#include<vector>
#include<queue>

using namespace std;

ListNode* merge_list(int left,int right,vector<ListNode*>& lists);
ListNode* mergeKLists(vector<ListNode>& lists);
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };



ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int k = lists.size();
    int MAXCOUNT;
    ListNode* head = NULL;
    ListNode* pre = NULL;
    bool flage = true;

    while (flage)
    {
        int MAX = INT_MAX;
        ListNode* SML;
        int count = 0;
        while (count < k)
        {
            if(lists[count] != NULL && lists[count] -> val < MAX)
            {
                MAX = lists[count] -> val;
                SML = lists[count];
                MAXCOUNT = count;
            }
            count++;
        }

        if(MAX == INT_MAX) break;

        if(pre == NULL)
        {
            pre = SML;
            head = pre;
            lists[MAXCOUNT] = SML -> next;
        }
        else
        {
            pre -> next = SML;
            pre = SML;
            lists[MAXCOUNT] = SML -> next;
        }    
    }
    return head;
}

  
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    ListNode* head =NULL;
    if(lists.size() == 0) return head;
    return merge_list(0,lists.size() - 1,lists);
}



ListNode* merge_list(int left,int right,vector<ListNode*>& lists)
{
    if(left >= right) return lists[left];

    int mid = left + (right - left) / 2;

    ListNode* p = merge_list(left,mid,lists);
    ListNode* q = merge_list(mid + 1,right,lists);

    if(p == NULL && q == NULL) return NULL;

    ListNode* head = NULL;

    if(q == NULL)
    {
        head = p;
        p = p -> next;
    }
    else if(p == NULL)
    {
        head = q;
        q = q -> next;
    }
    else
    {
        if(p -> val <= q -> val)
        {
            head = p;
            p = p -> next;
        }
        else
        {
             head = q;
             q = q -> next;
        }
    }
    

    ListNode* h = head;

    while (p != NULL && q != NULL)
    {

        if(p -> val <= q -> val)
        {
            h -> next = p;
            p = p -> next;
        }
        else
        {
            h -> next = q;
            q = q -> next;
        }
        h = h -> next;
    }

    if(q != NULL) p = q;
    if(h != NULL)  h -> next = p;

    return head;
}

class Solution {
public:
    
    struct cmp
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for(auto i : lists)
        {
            if(i)  q.push(i);
        }
        
        ListNode dummy(-1);
        ListNode* p = &dummy;

        while (!q.empty())
        {
            ListNode* top =q.top(); q.pop();
            p -> next = top;
            p = p -> next;
            if(p -> next != NULL)q.push(p -> next);
        }
        return dummy.next;
    }
};



class Solution {
public:
    // 小根堆的回调函数
    struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       };:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
        // 建立大小为k的小根堆
        for(auto elem : lists){
            if(elem) pri_queue.push(elem);
        }
        // 可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 开始出队
        while(!pri_queue.empty()){
            ListNode* top = pri_queue.top(); pri_queue.pop();
            p->next = top; p = top;
            if(top->next) pri_queue.push(top->next);
        }
        return dummy.next;  
    }
};

