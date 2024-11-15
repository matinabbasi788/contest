// بهداشت و سلامت https://quera.org/problemset/51865

#include <iostream>
using namespace std;

int main(){
    int X, N;
    cin>>X;
    cin>>N;
    if(N==0){
        cout<<20;
    }else if(N==7){
        cout<<X;
    }else{
        cout<<max(0, X-N);
    }
}