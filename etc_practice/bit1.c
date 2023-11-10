void bit_pattern(int a) 
{
    int i,mask; 
    printf ("0b");
    for (i=31; i>=0; i--)
    { 
        
        mask=1<<i; 
        if ( (a&mask) == 0) 
        printf ("0");
        else printf("1");
        
        if(i%4==0)
        printf(", ");
    }
printf("\n");
}
