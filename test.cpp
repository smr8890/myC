#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
typedef __int64 ll;
using namespace std;
char num2[10005][35];
char num3[10005][35];
ll num[10005];
int main(){
    ll N,k,n;
    ll i,j,t;
    scanf("%I64d",&N);
    while(N--){
        scanf("%I64d%I64d",&n,&k);
        memset(num,0,sizeof(num));
        memset(num2,'\0',sizeof(num2));
        for(i=0;i<n;i++){
            scanf("%I64d",&t);
            num[i]=t;
        }
//		for(i=0;i<n;i++){
//		printf("%s\n",num2[i]);
//		}
        for(i=0;i<n;i++){//转二进制
            itoa(num[i],num2[i],2);
//			printf("%s\n",num2[i]);
        }
        memset(num3,'0',sizeof(num3));
        for(j=0;j<n;j++){//按位对齐
            t=0;
            for(i=34;i>=0;i--){
                if(num2[j][i]!='\0'){
                    num3[j][t]=num2[j][i];
                    t++;
                }
            }
        }
//		for(j=0;j<n;j++){
//		for(i=0;i<34;i++){
//			printf("%c ",num3[j][i]);
//		}
//		 printf("\n");
//		}
        ll l=0,r=0,cnt,ans=0,maxans=0;
        for(i=0;i<=32;i++){
            cnt=0;
            ans=0;
            l=0;
            r=0;
            while(r<n) {
                if(num3[r][i] == '0') {
                    cnt++;
                }
                while(cnt>k) {
                    if(num3[l][i] == '0') {
                        cnt--;
                    }
                    l++;
                }
                if(ans<(r-l+1)) ans=r-l+1;
                r++;
            }
            if(ans>maxans) maxans=ans;
        }
        printf("%I64d\n",maxans);
    }

}