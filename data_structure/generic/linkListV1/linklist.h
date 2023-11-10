
#ifndef __LINKLIST
#define __LINKLIST

#include <iostream>

template<class T>
class LinkList
{
	private:
	struct Node
	{
		public:
		T data;
		Node *next;
		
		Node():data(0),next(NULL){}
		Node(T _data):data(_data),next(NULL){}
		
	};
	Node *head;
	public:
	
	LinkList():head(NULL){};
	
	LinkList * getHead()const { return head;}
	int getLength();
	void insertLast(T _data);
	void insertFirst(T _data);
	void insertAt(T _data,int pos);
	void deleteLast();
	void deleteFirst();
	void deleteAt(int pos);
	
	void display()
	{
	    Node *temp=head;
	    while(temp){
	    std::cout<<temp->data<<" ";
	    temp=temp->next;
	    }
	    std::cout<<std::endl;
	}
	
	//sorting linklist
	void insertionSortList();
	void bubleSortList();
	
	
};




/***************************************************************/

template<class T>
int LinkList<T>::getLength()
{
    int cnt=0;
    Node * temp=head;
    while(temp)
    cnt++;
    
    return cnt;
}

template<class T>
void LinkList<T>::insertLast(T _data)
{
    Node *new_node =new Node(_data);
    if(new_node==NULL)
    {
            std::cout<<"New failed \n";
            exit(-1);
    }
    
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=new_node;
    }
}

template<class T>
void LinkList<T>::insertFirst(T _data)
{
        Node *new_node =new Node(_data);
        if(new_node==NULL)
        {
            std::cout<<"New failed \n";
            exit(-1);
        }
        
        new_node->next=head;
        head=new_node;
}

template<class T>
void LinkList<T>::insertAt(T _data,int pos)
{
    Node *new_node =new Node(_data);
    Node *curr=head;
    Node *prev=NULL;
    if(new_node==NULL)
    {
            std::cout<<"New failed \n";
            exit(-1);
    }
    
    for(int i=0;i<pos;i++)
    {
        if(pos==1 && i==0)
        {
            new_node->next=head;
            head=new_node;
        }
        else
        {
            if(prev && i==pos-1)
            {
                new_node->next=curr;
                prev->next=new_node;
                return;
            }
            prev=curr;
            curr=curr->next;
            
            if(curr==NULL)
            {
                std::cout<<"out of index\n";
                return;
            }
        }
    }
}
	
template<class T>
void LinkList<T>::deleteLast()
{
    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        return;
    }
    Node *temp=head;
     Node *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
    temp=temp->next;
    
    }
    
    prev->next=NULL;
    delete temp;
}
	
template<class T>	
void LinkList<T>::deleteFirst()
{
    if(head!=NULL)
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
}
	
template<class T>
void LinkList<T>::deleteAt(int pos)
{
    Node *curr=head;
    Node *prev=NULL;
    for(int i=0;i<pos;i++)
    {
        if(pos==1 && i==0)
        {
            head=head->next;
            delete curr;
            return;
        }
        else
        {
           if(prev && i==pos-1)
           {
               prev->next=curr->next;
               delete curr;
               return;
           }
           prev=curr;
           curr=curr->next;
           
           if(curr==NULL)
           {
               std::cout<<"Out of index \n";
               return;
           }
        }
    }
}



#endif
