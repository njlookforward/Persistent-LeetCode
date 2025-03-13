struct ListNode {
    int data;
    ListNode *next;
    ListNode(int v):data(v), next(nullptr) {}
};

class Solution_double_pointer_iteratively {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 双指针法中的快慢指针法
        // 使用虚拟头结点可以使用一套算法删除包括头结点在内的所有有效结点
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *slow = dummyhead,
                 *fast = dummyhead;
        while (n-- && fast)
        {
            // 对于指针一定要小心操作，一定确保指针为有效指针
            // 使用n--，n值是多少就执行多少次循环，这是很清晰的
            fast = fast->next;
        }
        fast = fast->next;  // 因为删除要找到目标结点的前一个结点
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        head = dummyhead->next;
        delete dummyhead;   // 差点忘了删除dummyhead
        return head;
    }
};