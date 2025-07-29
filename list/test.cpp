#include "146_LRUCache.hpp"

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

int main() {
    test_lrucache();

    return 0;
}