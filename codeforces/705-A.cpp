#include <iostream>
#include <algorithm>


using namespace std;
int main(){
    int n;
    int j = 0;
    cin>>n;
    string s;
    while(j != n){
        if(j % 2 == 1){
            s += "I love that ";
        }
        else{
            s += "I hate that ";
        }
        ++j;
    }
    int i = 5;
    while(i){
        s.pop_back();
        --i;
    }
    cout<<s<<"it";

    return 0;
}