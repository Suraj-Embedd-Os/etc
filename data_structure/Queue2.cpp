
#include <iostream>
#include<stdbool.h>

using namespace std;

struct Node
{
        int data;
        struct Node *next;
        Node():data(0),next(nullptr){}
        Node(int _data):data(_data),next(nullptr){}
};

class Queue
{
     private:
     struct Node *head;
	 int length;
    public:
    void enqueue(struct Node *ptr);
    int dequeue();
    int peek();
    void initialize();
    bool isfull();
    bool isempty();
	void displayQueue();
    
    Queue():head(nullptr),length(0){}
	~Queue(){}
    
};

int main()
{
	Queue Q1;
	struct Node N1[5]={4,5,6,7,8};
	
	for(int i=0;i<5;i++)
	Q1.enqueue(&N1[i]);
	
	//for(int i=0;i<5;i++)
	Q1.displayQueue();
	
    return 0;
}


void Queue::enqueue(struct Node *ptr)
{

	if(head==nullptr)
	{
		head=ptr;
		length++;
		return;
	}
	struct Node *temp=head;
	while(temp->next!=nullptr)
		temp=temp->next;
	
	temp->next=ptr;
	length++;
}

int Queue::dequeue()
{
	int data;
	if(!isempty())
	{
		struct Node *temp=head;
		data=head->data;
		head=head->next;
		free(temp);
		length--;
		return data;
		
	}
	else
	{
		cout<<"queue is empty\n";
		return -1;
	}
	
	
}

int Queue::peek()
{
	if(!isempty())
	return (head->data);
	else
		return -1;
}

void Queue::initialize()
{
	
}

bool Queue::isfull()
{
	return false;
}

bool Queue::isempty()
{
	return (length==0);
	
}


void Queue::displayQueue()
{
	if(!isempty())
	{
		struct Node *temp=head;
		while(temp!=nullptr)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}





