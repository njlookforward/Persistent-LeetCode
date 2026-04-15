#define SORTLIST_MERGE

#if defined(V1)

#include "146_LRUCache.hpp"

#elif defined(V2)

#include "146_LRUCache_2.hpp"

#elif defined(V3)

#include "146_LRUCache_3.hpp"

#elif defined(SORTLIST)

#include "077_排序链表.hpp"

#elif defined(SORTLIST_MERGE)

#include "077_排序链表_归并排序.hpp"

#endif


#if 0
void test_lrucache() {
    LRUCache *pLRU = new LRUCache(2);
    // pLRU->put(1,1);
    // pLRU->print();
    // pLRU->put(2,2);
    // pLRU->print();
    // int value = pLRU->get(1);
    // cout << "get(1) = " << value << endl << endl;
    // pLRU->put(3,3);
    // pLRU->print();
    // value = pLRU->get(2);
    // cout << "get(2) = " << value << endl << endl;
    // pLRU->put(4,4);
    // pLRU->print();
    // value = pLRU->get(1);
    // cout << "get(1) = " << value << endl << endl;
    // value = pLRU->get(3);
    // cout << "get(3) = " << value << endl << endl;
    // value = pLRU->get(4);
    // cout << "get(4) = " << value << endl << endl;
    pLRU->put(2,1);
    pLRU->print();
    pLRU->put(1,1);
    pLRU->print();
    pLRU->put(2,3);
    pLRU->print();
    pLRU->put(4,1);
    pLRU->print();
    int value = pLRU->get(1);
    cout << "get(1) = " << value << endl << endl;
    value = pLRU->get(2);
    cout << "get(2) = " << value << endl << endl;

    delete pLRU;
}
#endif

#if 0
void test_sortList() {
    SingleList mylist;
    // mylist.insert_tail(4);
    // mylist.insert_tail(2);
    // mylist.insert_tail(1);
    // mylist.insert_tail(3);
    
    // mylist.insert_tail(-1);
    // mylist.insert_tail(5);
    // mylist.insert_tail(3);
    // mylist.insert_tail(4);
    // mylist.insert_tail(0);

    ListNode *newHead = Solution().sortList(mylist._head);
    SingleList newlist;
    newlist._head = newHead;
    newlist.print();
}
#endif

void test_sortList_merge() {
    SingleList mylist;
    // mylist.insert_tail(4);
    // mylist.insert_tail(2);
    // mylist.insert_tail(1);
    // mylist.insert_tail(3);
    
    mylist.insert_tail(-1);
    mylist.insert_tail(5);
    mylist.insert_tail(3);
    mylist.insert_tail(4);
    mylist.insert_tail(0);

    ListNode *newHead = Solution_merge().sortList(mylist._head);
    mylist._head = newHead;
    mylist.print();
}
int main() {
    // test_lrucache();
    // test_sortList();
    test_sortList_merge();

    return 0;
}