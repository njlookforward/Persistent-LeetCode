


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 本质仍然是翻转链表，但是需要注意两个点：
 * 1. 要使用虚拟头结点，防止左侧没有节点作为pre
 * 2. 要确定每次进行翻转是否满足k个一组
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 需要先遍历一遍单链表，确定总的节点数量
        int n = 0;
        ListNode *cur = head;
        while (cur)
        {
            n++;
            cur = cur->next;
        }
        // 然后创建虚拟头结点dummy
        ListNode *dummy = new ListNode {0, head};
        // 然后k个一组进行翻转
        ListNode *p0 = nullptr;
        ListNode *pre = nullptr;
        ListNode *nxt = dummy;
        while (n >= k)
        {
            n -= k;
            p0 = nxt;
            cur = p0->next;
            pre = nullptr;
            for(int i = 0; i < k; i++)
            {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
        }

        return dummy->next;
    }
};