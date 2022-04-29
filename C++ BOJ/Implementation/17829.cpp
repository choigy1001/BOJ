#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cnnArray[1024][1024];

int secondMax(int y, int x){
    vector<int> v;
    for(int i=y; i<y+2; i++){
        for(int j=x; j<x+2; j++){
            v.push_back(cnnArray[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[2];
}

int main(){
        
    cin>>N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>cnnArray[i][j];
        }
    }
    
    while(N>1){
        for(int i=0; i<N; i+=2){
            for(int j=0; j<N; j+=2){
                cnnArray[i/2][j/2]=secondMax(i,j);
            }
        }
        N/=2;
    }
    cout<<cnnArray[0][0];
    return 0;
}
