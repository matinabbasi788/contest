#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        int onesComp1 = 0, onesComp2 = 0;
        for (int i = 0; i < n; i++) {
            int pos = i + 1;
            if(pos % 2 == 1) {
                if(a[i] == '1')
                    onesComp1++;
            } else {
                if(a[i] == '1')
                    onesComp2++;
            }
        }

        for (int i = 0; i < n; i++) {
            int pos = i + 1;
            if(pos % 2 == 1) {
                if(b[i] == '1')
                    onesComp2++;
            } else {
                if(b[i] == '1')
                    onesComp1++;
            }
        }

        int capComp1 = n / 2;
        int capComp2 = n - (n / 2);

        cout << (onesComp1 <= capComp1 && onesComp2 <= capComp2 ? "YES" : "NO") << endl;
    }
    return 0;
}
