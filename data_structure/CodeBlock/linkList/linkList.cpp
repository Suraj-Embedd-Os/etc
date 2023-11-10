static int getLenghtList(struct Node **head_ptr)
{
    int cnt=0;
    struct Node *temp=*head_ptr;

    while(temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;

}

void displayList(struct Node **head_ptr)
{
    struct Node *temp=*head_ptr;

    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void insertFisrt(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));
    if(new_node==NULL)
    {
       printf("unable to allocate head memory %s %d",__FILE__,__LINE__);
       exit(-1);
    }

    new_node->data=data;
    new_node->next=*head_ptr;
    *head_ptr=new_node;

}
void insertLast(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));
    if(new_node==NULL)
    {
       printf("unable to allocate head memory %s %d",__FILE__,__LINE__);
       exit(-1);
    }

    new_node->data=data;
    new_node->next=NULL;

    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return;
    }

    struct Node *temp=*head_ptr;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new_node;
}
void insertAt(struct Node **head_ptr,int data,int pos)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));
    if(new_node==NULL)
    {
       printf("unable to allocate head memory %s %d",__FILE__,__LINE__);
       exit(-1);
    }
    new_node->data=data;
    new_node->next=NULL;

    struct Node *curr_node=*head_ptr;
    struct Node *prev_node=NULL;
    for(int i=0;i<pos;i++)
    {
        if(i==0 && pos==1)
        {
            new_node->next=*head_ptr;
            *head_ptr=new_node;
        }
        else
        {

            prev_node=curr_node;
            curr_node=curr_node->next;

            if(i==pos-1 && curr_node)
            {
                new_node->next=curr_node;
                prev_node->next=new_node;
            }
            if(curr_node)
            {
                printf("out of index\n");
                return;
            }
        }
    }


}

void deleteFisrt(struct Node **head_ptr)
{
    struct Node *temp=*head_ptr;
    *head_ptr=(*head_ptr)->next;

    free(temp);
}
void deleteLast(struct Node **head_ptr)
{
    struct Node *curr_node=*head_ptr;
    struct Node *prev_node=NULL;

    while(curr_node->next!=NULL)
    {
        prev_node=curr_node;
        curr_node=curr_node->next;
    }

    if(prev_node!=NULL)
    {
        prev_node->next=NULL;
        free(curr_node);
    }
}
void deleteAt(struct Node **head_ptr,int pos)
{
    struct Node *curr_node=*head_ptr;
    struct Node *prev_node=NULL;
    for(int i=0;i<pos;i++)
    {
        if(i==0 && pos==1)
        {
            curr_node=*head_ptr;
            *head_ptr=(*head_ptr)->next;
            free(curr_node);
        }
        else
        {

            prev_node=curr_node;
            curr_node=curr_node->next;

            if(i==pos-1 && curr_node)
            {
                prev_node->next=curr_node->next;
                free(curr_node);
            }
            if(curr_node)
            {
                printf("out of index\n");
                return;
            }
        }
    }
}


int getMaxElement(struct Node **head_ptr)
{

}
int getMinElement(struct Node **head_ptr)
{

}

bool isSortedList(struct Node **head_ptr)
{

}
