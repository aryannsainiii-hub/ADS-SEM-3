#include<bits/stdc++.h>
using namespace std;

int twosum(int n){
    if(n==0){
        return 0;
    }
    return (n%10)+twosum(n/10);
}
int main(){
    int value;
    cin>>value;
    cout<<twosum(value);

}