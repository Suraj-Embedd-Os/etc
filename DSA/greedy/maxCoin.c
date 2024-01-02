
#include <stdio.h>

int maxCoin(int *coin,int n,int amount)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(coin[i]<=amount)
        {
            int c=amount/coin[i];
            
            amount=amount-c*coin[i];
            
            res +=c;
        }
        if(amount==0)
        break;
    }
    
    return res;
}

int main()
{
    int coin[]={10,5,2,1};
    
    printf("%d ",maxCoin(coin,4,52));

    return 0;
}
