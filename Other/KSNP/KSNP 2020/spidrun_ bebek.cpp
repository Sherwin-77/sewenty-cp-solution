#include <iostream>
#include <vector>

int modifiedBinarySearch(const std::vector<int> &arr, int searchValue){
    int start = 0;
    int end = arr.size()-1;
    while(start <= end){
        int middle = (start+end)/2;
        if(arr[middle] == searchValue){
            return middle+1;
        }
        // Goes to left if value too big. Change this logic if sorted array is descending
        if(arr[middle] > searchValue) end = middle-1;
        else start = middle+1;
    }
    // Default index if no exact value found
    return start;
}


int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    n = flag
    k = ducc 
    line size of n = distance to previous flag / start
    line size of k = max distance of ducc
     */
    int n, k, totalDistance=0, temp;
    vector <int> prefixSum, flag, ducc;
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        totalDistance += temp;
        prefixSum.push_back(totalDistance);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        cout << modifiedBinarySearch(prefixSum, temp) << '\n';
    }
    
}
