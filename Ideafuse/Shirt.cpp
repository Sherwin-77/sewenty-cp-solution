#include <iostream>


int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /* code */
    int temp, n;
    int arr[10];
    int best, count;
    cin >> n;
    for(int i = 0; i < n; i++){
        fill(arr, arr+10, 0);
        best = -1;
        count = 0;
        for(int j = 0; j < 3; j++){
            cin >> temp;
            arr[temp] += 1;
            if (arr[temp] > count){
                best = temp;
                count = arr[temp];
            }
        }   
        cout << "Case #" << i+1 << ": "<< 3-count << '\n';
    }
}
