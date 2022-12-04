#include <iostream>
#include <string>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /* code */
    int n;
    cin >> n;

    string real, modified;
    char addedChar;
    bool added, noRepeat;
    int lastPositionj, lastPositionk;
    int j, k;

    bool isPalindrome;

    for(int i = 0; i < n; i++){
        cin >> real;
        modified = real;

        isPalindrome = true;
        added = false;
        noRepeat = false;
        j = 0;
        k = real.length() - 1;

        while(j < k || (added && j <= k)){
            if(real[j] == real[k]){
                j++;
                k--;
            } else if (added && !noRepeat)
            {
                j = lastPositionj;
                k = lastPositionk;
                if (real[j] == addedChar){ 
                    addedChar = real[k];
                    j++;
                } else {
                    addedChar = real[j];
                    k--;
                }
                noRepeat = true;
            } else if (added && noRepeat){
                isPalindrome = false;
                break;
            } else {
                lastPositionj = j;
                lastPositionk = k;
                added = true;
                if(real[j] < real[k]){
                    addedChar = real[j];
                    k--;
                } else {
                    addedChar = real[k];
                    j++;
                }
            }
        }
        if(added){
            if(added == real[lastPositionj]){
                modified = real.substr(0, lastPositionk + 1) + addedChar + real.substr(lastPositionk + 1, real.length() - lastPositionk);
            } else {
                modified = real.substr(0, lastPositionj + 1) + addedChar + real.substr(lastPositionj + 1, real.length() - lastPositionj);
            }
            
        }

        if(isPalindrome) cout << "Case #" << i+1 << ": " << modified << '\n';
        else cout << "Case #" << i+1 << ": -1\n";
    }
}
