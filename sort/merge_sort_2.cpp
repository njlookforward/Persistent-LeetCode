/**
 * @brief 归并排序的核心思想就是分治法；分-治-合
 * 南江，心魔一直都在，不要逃避它，不要在意他，让他从自己的心中流走就好
 * 我每天都要一点点地进步，而不要管那些陈芝麻烂谷子的事，只要往前走，别回头
 * 因为世界什么颜色都有，什么口味的巧克力都有，我们只需要去尝试，去接受，然后下一个，不要停留
 * 
 * 南江，我发现了，只要你开始做起来，思路就会源源不断，不要犹豫，直接开干
 */
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void merge(vector<T> &arr, int left, int mid, int right) {
    // 左分支和右分支都已经排好序了，现在只需要进行合并，需要有临时数组
    int nLeft = mid - left + 1;
    int nRight = right - mid;

    vector<T> partLeft(nLeft, 0);
    vector<T> partRight(nRight, 0);

    for(int i = 0; i < nLeft; ++i) partLeft[i] = arr[left+i];
    for(int j = 0; j < nRight; ++j) partRight[j] = arr[mid + 1 + j];

    // 开始合并
    int i = 0, j = 0, k = left;
    while(i < nLeft && j < nRight) {
        if(partLeft[i] <= partRight[j]) {
            arr[k] = partLeft[i++];
        } else {
            arr[k] = partRight[j++];
        }
        ++k;
    }

    // 将剩余部分追加到末尾
    while(i < nLeft) {
        arr[k++] = partLeft[i++];
    }
    while(j < nRight) {
        arr[k++] = partRight[j++];
    }
}

template <typename T>
void mergeSort(vector<T> &arr, int left, int right) {
    // 递归终止条件
    if(left >= right) {
        return;
    }
    // 分
    int mid = left + (right - left) / 2;
    // 治
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    // 合并
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr{38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    for(auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}