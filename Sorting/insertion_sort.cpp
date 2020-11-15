/*
Name: Insertion Sort
Time Complexity:
    * Best: O(n)
    * Average: O(n^2)
    * Worst: O(n^2)
Space Complexity:
    * O(1)
*/

/*
Insertion sort is basically sorting poker cards on hand.
We pick a card(number) and see if there is any previous card bigger than
that one. If yes, we just put the card there and all the cards on the right
gets shifted right by one card.
*/

// Resource: http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Sorting/insertionSort.htm

/* procedure insertion sort(a1, a2, ...an: real numbers with n >= 2)
 * for i := 2 to n
 * 	key = ai
 * 	j = i-1
 * 	while j >= 0 and aj > key
 * 		aj+1 = aj
 * 		j := j-1
 * 	j := j+1
 * 	aj = key
 * {a1, a2, ... , an is in increasing order}
 *
 */



#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 and arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
