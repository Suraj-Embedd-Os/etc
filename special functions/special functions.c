
char *getstr(char *src,char *des,char deli)
{
       char *s=src;
       int ch;
       int n=sizeof(src)-1;
       
       while(--n>0 && ((ch=*src++)!=0) && ((*des++=ch))!=deli);
       
       if(ch==deli)
	   {
			*--des='\0';
        return des;
	   }
       else
       {
           *des='\0';
           return NULL;
       }
}