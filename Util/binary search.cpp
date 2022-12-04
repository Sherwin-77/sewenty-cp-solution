#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &arr, int size, int searchValue){
    int start = 0;
    int end = size-1;
    while(start <= end){
        int middle = (start+end)/2;
        if(arr[middle] == searchValue){
            return middle;
        }
        // Goes to left if value too big. Change this logic if sorted array is descending
        if(arr[middle] > searchValue) end = middle-1;
        else start = middle+1;
    }
    // Default index if no value found
    return -1;
}


int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /* code */
    int n;
    vector <int> arr;
}
