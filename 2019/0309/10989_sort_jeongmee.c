#include <stdio.h>
int d[10001] = {0, };
int main(){
    
    int n, data;
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d",&data);
        d[data]+=1;
    }
    
    for(int i = 1; i <= 10000; i++)
        if(d[i] > 0){
            for(int j = 1; j <= d[i]; j++)
                printf("%d\n",i); 
        }
    
    return 0;
}
