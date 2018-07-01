#include<utility>
#include<iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot_val = arr[low];

    int left = low + 1;
    int right = high;

    /**
     * 1.  The left pointer should be able to range from [low + 1, high]
     * 2.  The right pointer should be able to range from [low, high]
     * 2a. The right pointer ending up at low indicates that the pivot is lower
     *     than all other elements
     * 3.  The left pointer terminating at high indicates that the pivot is higher
     *     than all other elements. It also means that left and right are going to
     *     be equal and break the loop.
     * 4.  right will always end up to the "left" of left OR on the same spot.
     */
    while (true) {
        while(arr[left] < pivot_val && left < high) left++;
        while(arr[right] > pivot_val && right > low) right--;
        if (left < right) {
            swap(arr[left], arr[right]);
            left++, right--;
        } else {
            break;
        }
    }
    
    swap(arr[low], arr[right]);
    return right;
}

void quick_sort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = partition(arr, low, high);

    quick_sort(arr, low, pivot -1);
    quick_sort(arr, pivot + 1, high);
}

void quick_sort(int arr[], int size) {
    quick_sort(arr, 0, size - 1);    
}

int main(int argc, char const *argv[]) {
    int a[] = {0, 33, 6, 21, 12, 19, 29, 38, 22, 14, 40, 0, 0, 0, 0, 0};
    /* int a[] = {4, 0, 2, 1}; */

    cout<<"Before Sorting"<<endl;
    for (int i : a) {
        cout << i << ",";
    }
    cout << endl;

    quick_sort(a, sizeof(a)/sizeof(int));

    cout << endl<<"After Sorting"<<endl;
    for (int i : a) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
}
