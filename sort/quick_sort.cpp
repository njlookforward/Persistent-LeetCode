#include <iostream>
#include <array>

// 无论是多么难的题，只要大胆去想，大胆去尝试，真的可以解决的，相信自己

using std::cout, std::endl;

int divide(int *arr, int left, int right);
void quickSort(int *arr, int left, int right) {
    if(left >= right)   return;
    int mid = divide(arr, left, right);
    quickSort(arr, left, mid - 1);
    quickSort(arr, mid + 1, right);
}

int divide(int *arr, int left, int right) {
    int pivot = arr[left];
    while(left < right) {
        while (left < right && arr[right] >= pivot)
        {
            --right;
        }
        if(left < right)
            arr[left] = arr[right];
        while(left < right && arr[left] <= pivot) {
            ++left;
        }
        if(left < right)
            arr[right] = arr[left];
    }

    arr[left] = pivot;
    return left;
}

void test() {
    std::array<int, 10> iarr = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    int *parr = iarr.data();

    cout << "before sort: ";
    for (int i : iarr)
    {
        cout << i << " ";
    }
    cout << endl;

    quickSort(parr, 0, iarr.size() - 1);

    cout << "after sort: ";
    for(int i : iarr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    test();

    return 0;
}