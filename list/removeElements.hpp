// definition of a single_linked listnode
// struct ListNode
// {
//     ListNode() = default;
//     ListNode(int v): val(v) {}
//     ListNode(int v, ListNode *n): val(v), next(n) {} 

//     int val = 0;            // data domain
//     ListNode *next = nullptr;     // pointer domain
// };

// // no dummyhead version
// class Solution_head {
// public:
//     ListNode *removeElements(ListNode *head, int val)
//     {
//         // 对于头结点单独进行处理
//         while (head && head->val == val)
//         {
//             ListNode *temp = head;
//             head = head->next;
//             delete temp;
//         }
        
//         // 对于非头结点的处理
//         ListNode *cur = head;
//         while (cur && cur->next)    // 为什么需要判断cur, 因为可能在之前的头结点处理过程中删除了所有结点
//         {
//             if(cur->next->val == val)
//             {
//                 ListNode *temp = cur->next;
//                 cur->next = cur->next->next;
//                 delete temp;
//             } else
//                 cur = cur->next;
//         }
//         return head;    // 记住最后返回的是头结点
//     }
// };

// class Solution_dummyhead {
// public:
//     ListNode *removeElements(ListNode *head, int val)
//     {
//         ListNode *dummyhead = new ListNode(0);
//         dummyhead->next = head;
//         ListNode *cur = dummyhead;
//         while (cur->next)
//         {
//             if(cur->next->val == val)
//             {
//                 ListNode *temp = cur->next;
//                 cur->next = cur->next->next;
//                 delete temp;        
//             } else
//                 cur = cur->next;
//         }
        
//         head = dummyhead->next; // 绝对不可以忘记更新head指针
//         delete dummyhead;
//         return head;
//     }
// };

// 第二遍练习删除链表中的元素