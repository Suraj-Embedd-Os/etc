/*
	largest element in arrary using recursion 
*/
int largest_element(const int arr[],int lowerIndex,int higherIndex)
{
    int max;
    
    if(lowerIndex==higherIndex)
    return arr[lowerIndex];
    else
    {
        max=largest_element(arr,lowerIndex+1,higherIndex);
        
        if(arr[lowerIndex]>=max)
        return arr[lowerIndex];
        else
        return max;
    }
}

/*
	 rev_displayList using recursion 
*/

void rev_displayList( struct node *ptr)
{
   if(ptr!=0){
           
            rev_displayList(ptr->next);
            printf("%d ",ptr->data);
         }
        
}
