
#include <stdio.h>

void resetMostSetBit(int a)
{
    a=a&(a-1);
    printf("%b\n",a);
}

int main()
{
    int a=5;
    printf("%b\n",a);
    resetMostSetBit(a);

    return 0;
}


#include <stdio.h>

int rotateLeft(int n,int pos)
{
   return (n<<pos)|n>>(8-pos);
}

int rotateRight(int n,int pos)
{
  return (n>>pos)|n<<(8-pos); 
}

int main()
{
   unsigned char a=5;
    printf("Left rotate by 2: \n original :%b\n result:%b\n right rotate by 2:\n original:%b\n result:%b\n",a,rotateLeft(a,2),a,rotateRight(a,2));

    return 0;
}
