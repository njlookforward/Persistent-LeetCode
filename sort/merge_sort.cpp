#include <iostream>
#include <vector>
#include <array>

using std::cout, std::cin, std::endl;
using std::vector;

// 归并排序，是自顶向下的思维去排序
void merge(int *arr, int left, int mid, int right);
void merge_sort(int *arr, int left, int right) {
    if(left >= right)
        return;
    // 先分成两份，分别排序，然后再合并
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void merge(int *arr, int left, int mid, int right) {
    vector<int> ivec {right - left + 1};
    int index1 = left, index2= mid+1;
    int cur = 0;
    while(index1 <= mid && index2 <= right) {
        if(arr[index1] <= arr[index2]) {
            ivec[cur++] = arr[index1++];
        } else
            ivec[cur++] = arr[index2++];
    }
    while(index1 <= mid) {
        ivec[cur++] = arr[index1++];
    }

    while(index2 <= right) {
        ivec[cur++] = arr[index2++];
    }

    for(int i = left, j = 0; i <= right; ) {
        arr[i++] = ivec[j++];
    }
}
void test1() {
std::array<int, 10> iarr = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    int *parr = iarr.data();

    cout << "before sort: ";
    for (int i : iarr)
    {
        cout << i << " ";
    }
    cout << endl;

    merge_sort(parr, 0, iarr.size() - 1);

    cout << "after sort: ";
    for(int i : iarr) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    test1();

    return 0;
}