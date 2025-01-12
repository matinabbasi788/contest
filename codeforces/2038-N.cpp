#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

void solve(){
    ios_base::sync_with_stdio(false);
    int n  ;
    cin >> n;
    for (int i ; i<n ; i++ ){
        string s ;
        getline(cin ,s, '');
        cin >> s ;
        if (s.find("<") ) {
            vector<string> v ;
            v = s.s;
         }
        if (s.find(">") ) {
            int x  = s.find(">");
        }
        if (s.find("=") ) {
            int x  = s.find("=");
            
        }
        
    }
    
}


int main()
{
    solve();
    return 0;
}
