#include <iostream>
using std::cout, std::endl;

namespace {
    int num = 1;
}

int num = 2;

void test1() {
    cout << ::num << endl;
        //  << num << endl;
}
int main(void) {
    test1();
    return 0;
}