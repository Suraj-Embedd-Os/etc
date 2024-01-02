#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *img1=fopen("../photo.jpg","rb");
    FILE *img2=fopen("photo_copy.jpg","wb");
    int value=0;
    if(img1==NULL || img2==NULL)
    {
        perror("fopen\n");
    }
    while((value=getw(img1))!=EOF)
    {
        fwrite(&value,4,1,img2);
    }

    fclose(img1);
    fclose(img2);
    return 0;
}
