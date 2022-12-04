#include <iostream>
#include <assert.h>
#include <math.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int number;
    cin >> number;
    assert (1 <= number < 100000);
    // First solution use if else
    // if (number < 10){
    //     cout << "satuan";
    // } else if (number < 100){
    //     cout << "puluhan";
    // } else if (number < 1000){
    //     cout << "ratusan";
    // } else if (number < 10000){
    //     cout << "ribuan";
    // } else if (number < 100000){
    //     cout << "puluhribuan";
    // }

    // Second solution use math and switch case
    int result = (int) log10(number);
    switch (result){
        case 0:
            cout << "satuan";
            break;
        case 1:
            cout << "puluhan";
            break;
        case 2:
            cout << "ratusan";
            break;
        case 3:
            cout << "ribuan";
            break;
        case 4:
            cout << "puluhribuan";
            break;
    }


}