#include <iostream>
#include <string>
#include <vector>

using namespace std;

char forcedLetter(char a, char b) {
    if((a=='L' && b=='I') || (a=='I' && b=='L')) return 'T';
    if((a=='L' && b=='T') || (a=='T' && b=='L')) return 'I';
    return 'L';
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int initLen = n;
        
        int cntL = 0, cntI = 0, cntT = 0;
        for(char c : s) {
            if(c=='L') cntL++;
            else if(c=='I') cntI++;
            else if(c=='T') cntT++;
        }
        
        if(cntL==cntI && cntI==cntT) {
            cout << "0\n";
            continue;
        }
        
        if(initLen == 1) {
            cout << "-1\n";
            continue;
        }
        
        int mChosen = -1, target = -1;
        for(int m = 0; m <= 2*n; m++) {
            if((initLen + m) % 3 != 0) continue;
            int targ = (initLen + m) / 3;
            if(targ >= cntL && targ >= cntI && targ >= cntT) {
                mChosen = m;
                target = targ;
                break;
            }
        }
        
        if(mChosen == -1) {
            cout << "-1\n";
            continue;
        }
        
        int reqL = target - cntL;
        int reqI = target - cntI;
        int reqT = target - cntT;
        vector<int> ops;
        int curLen = initLen;
        
        for(int op = 0; op < mChosen; op++) {
            bool found = false;
            for(int i = 0; i < curLen - 1; i++) {
                if(s[i] == s[i+1]) continue;
                char x = forcedLetter(s[i], s[i+1]);
                if((x=='L' && reqL > 0) || (x=='I' && reqI > 0) || (x=='T' && reqT > 0)) {
                    ops.push_back(i + 1);
                    s.insert(i + 1, 1, x);
                    curLen++;
                    if(x=='L') reqL--;
                    else if(x=='I') reqI--;
                    else if(x=='T') reqT--;
                    found = true;
                    break;
                }
            }
            if(!found) break;
        }
        
        int finalL = 0, finalI = 0, finalT = 0;
        for(char c : s) {
            if(c=='L') finalL++;
            else if(c=='I') finalI++;
            else if(c=='T') finalT++;
        }
        
        if(finalL == target && finalI == target && finalT == target && ops.size() == mChosen) {
            cout << ops.size() << "\n";
            for(int pos : ops) cout << pos << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
