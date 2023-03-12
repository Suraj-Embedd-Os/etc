
#include <stdio.h>

int leftRotate(int n,int kth,int size)
{
    for(int i=0;i<kth;i++)
    {
       int flag=0;
       if(n & (1<< (size-1)))
        flag=1;
        n=n<<1;
        
        if(flag)
        n=n^1;
    }
    return n;
}

int rightRotate(int n,int kth,int size)
{
    for(int i=0;i<kth;i++)
    {
       int flag=0;
       if(n & 1)
        flag=1;
        n=n>>1;
        
        if(flag)
        n=n^(1<<(size-1));
    }
    return n;
}

int main()
{
    unsigned char a=0xF0;
    
    printf("%x ",(unsigned char)rightRotate(a,2,sizeof(a)));
    
    return 0;
}
