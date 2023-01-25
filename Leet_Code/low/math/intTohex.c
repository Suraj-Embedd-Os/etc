void reverse(char *start,char *end)
{
    while(start<end)
    {
        char temp=*start;
        *start++=*end;
        *end--=temp;
    }
}
char * toHex(int num){

    char *hex="0123456789abcdef";
    char *result=(char*)malloc(10);

    unsigned int n=num;

    if(n==0)
    return "0";

    int i=0;
    while(n)
    {
        result[i++]=hex[n%16];
        n/=16;
    } 

    result[i]='\0';

    reverse(result,result+i-1);
    return result;

}

