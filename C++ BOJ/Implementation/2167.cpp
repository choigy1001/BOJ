//
//  2차원 배열의 합.cpp
//  practice
//
//  Created by 최근영 on 2022/04/29.
//

#include <iostream>

using namespace std;

int N, M, K;
int arr[301][301];
int main(){
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    cin>>K;
    int i,j,x,y;
    for(int a=0; a<K; a++){
        cin>>i>>j>>x>>y;
            
        int result=0;
        for(int c=i; c<=x; c++){
            for(int d=j; d<=y; d++){
                    result+=arr[c-1][d-1];
            }
        }
        cout<<result<<"\n";
        
    }
    
    
    return 0;
}
