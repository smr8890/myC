#include <stdio.h>
//#include <unordered_map>
#include <algorithm>
#include <string.h>
#include <math.h>
typedef __int64 ll;
using namespace std;
ll x,y; //x表示行，y表示列
void TX(ll n,ll k){
    ll i,j,w;
    if(n!=0){
        j=pow(2,2*(n-1));
        w=pow(2,n-1);
//		printf("j=%I64d\n",j);
        for(i=1;i<=4;i++){
            if(i*j>=k) break;
        }
        k-=(i-1)*j;
//		printf("k=%I64d\n",k);
        if(i==1){

        }
        else if(i==2){
            y=y+w;
        }
        else if(i==3){
            x=x+w;
        }
        else if(i==4){
            x=x+w;
            y=y+w;
        }
        TX(n-1,k);
    }
}
int main(){
    ll N,k,n;
    ll i,j;
    scanf("%I64d",&N);
    while(N--){
        x=1;
        y=1;
        scanf("%I64d",&k);
        for(i=0;i<=60;i++){
            j=pow(2,2*i);
            if(j>=k)
            {
                n=i;
                break;
            }
        }
//		printf("n=%I64d\n",n);
        TX(n,k);
        printf("%I64d %I64d\n",x,y);
    }

}