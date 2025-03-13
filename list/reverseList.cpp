struct ListNode {
    int data;
    ListNode *next;
    ListNode(int v):data(v), next(nullptr) {}
};

class Solution_iteratively {
public:
    ListNode *reverseList(ListNode *head)
    {
        // 双指针法/iteratively
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *tmp;
        while (cur)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

class Solution_recursively {
public:
    ListNode *reverse(ListNode *pre, ListNode *cur) {
        if(cur == nullptr) return pre;
        ListNode *tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
    ListNode *reverseList(ListNode *head)
    {
        return reverse(nullptr, head);
    }
};