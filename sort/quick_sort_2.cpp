#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// partition就是使用双指针法进行移动
template <typename T>
int manualPartition(vector<T> &arr, int low, int high) {
    // 这里默认low < high，因此只管使用双指针法进行移动即可
    T pivot = arr[high];

    // i是小于pivot的最后一个元素的索引
    int i = low - 1;

    for(int j = low; j < high; ++j) {
        if(arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i+1;
}

template <typename T>
void quickSort(vector<T> &arr, int low, int high) {
    if(low >= high)
        return;
    int middle = manualPartition(arr, low, high);

    quickSort(arr, low, middle-1);
    quickSort(arr, middle+1, high);
}

int main() {
    vector<int> arr{9, 7, 5, 11, 12, 2, 14, 3, 10, 6};

    quickSort(arr, 0, arr.size()-1);

    for(auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}