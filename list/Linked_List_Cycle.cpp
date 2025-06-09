struct ListNode {
    int data;
    ListNode *next;
    ListNode(int v):data(v), next(nullptr) {}
};

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head)
//     {
//         // 仍然是使用快慢指针去检测
//         ListNode *fast = head,
//                  *slow = head;
//         while (fast && fast->next)  // 这样会更清晰
//         {
//             // Bug: 对于链表指针必须依次进行检查，不能只检查想要的
//             // if(fast->next->next) 出现运行时错误，这是大问题
//             fast = fast->next->next;
//             slow = slow->next;
//             if(fast == slow)
//             {
//                 // 这是相遇节点
//                 ListNode *index1 = fast;
//                 ListNode *index2 = head;
//                 while (index1 != index2)
//                 {
//                     index1 = index1->next;
//                     index2 = index2->next;
//                 }
//                 return index1;
//             }    
//         }
//         return nullptr;
//     }
// };

// class Solution {
// public:
//     bool isCircle()
// };