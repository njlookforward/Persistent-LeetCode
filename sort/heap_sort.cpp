/**
 * @brief 堆排序就是实现堆化
 * 模板编程
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// arr是数组，n是数组大小，也是数据的边界，i是此时的根节点
template <typename T>
void heapify(vector<T> &arr, size_t n, size_t i) {
    size_t largest = i;     // 记录最大值所在的索引
    size_t left = 2 * i + 1;    // 左节点
    size_t right = 2 * i + 2;   // 右节点

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);   // 这是递归得到的
    }
}

template <typename T>
void heapSort(vector<T> &arr) {
    size_t n = arr.size();
    if(n <= 1) return;
    // 建大顶堆
    for(int i = static_cast<int>(n) / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    // 从后进行排序
    for(size_t i = n - 1; i > 0; --i) {
        std::swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr{12, 11, 13, 5, 6, 7};

    // heapSort(arr);

    // 使用STL提供的标准库函数
    // 堆化
    std::make_heap(arr.begin(), arr.end());

    // 堆排序
    std::sort_heap(arr.begin(), arr.end());

    for(auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}