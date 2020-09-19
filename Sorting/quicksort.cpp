/*
Name: Quicksort
Time Complexity:
    * Best: O(n log(n))
    * Average: O(n log(n))
    * Worst: O(n^2)
Space Complexity:
    * O(log(n))
*/

/*
pp -> partition
pv -> pivot
l -> left
r -> right
*/

#include <iostream>
#include <algorithm>

using namespace std;

int pp(int array[], int l, int r, int pv) {
    while(l <= r) {
        while(array[l] < pv)
            l++;
        while(array[r] > pv)
            r--;
        if(l <= r) {
            swap(array[l], array[r]);
            l++;
            r--;
        }
    }
    return l;
}

void quicksort(int array[], int l, int r) {
    if(l >= r) return;

    int pv = array[(l + r) / 2];
    int index = pp(array, l, r, pv);
    quicksort(array, l, index - 1);
    quicksort(array, index, r);
}

int main() {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    quicksort(array, 0, 8);
    for(int i = 0; i < 9; i++)
        cout << array[i] << ' ';
    cout << endl;
}