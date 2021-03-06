/*
Name: Bubble Sort
Time Complexity:
    * Best: O(n)
    * Average: O(n^2)
    * Worst: O(n^2)
Space Complexity:
    * O(n) total, O(1) auxiliary
*/

/*
Bubble Sort is an elementary sorting algorithm.
It works by repeatedly exchanging adjacent elements, if necessary.
When no exchanges are required, the file is sorted.
*/

// Resource: http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Sorting/bubbleSort.htm

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    return;
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Approach 1
    // bubble_sort(arr, n);
    
    // Approach 2
    for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(arr[j] < arr[i]) {
				swap(&arr[j], &arr[i]);
			}
		}
	}

    for(int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
    return 0;

}