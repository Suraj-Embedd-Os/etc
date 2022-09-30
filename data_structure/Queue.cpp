
#include <iostream>
#include<stdbool.h>

using namespace std;



class Queue
{
     private:
    struct Node
    {
        int data;
        struct Node *next;
        
        
        Node():data(0),next(nullptr){}
        Node(int _data):data(_data),next(nullptr){}
    };
    struct Node *head;
	int length;
    public:
    void enqueue(int data);
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
	Q1.enqueue(5);
	Q1.enqueue(50);
	Q1.displayQueue();
	
	cout<<"..........\n";
	cout<<Q1.dequeue()<<endl;
	cout<<Q1.dequeue()<<endl;
	cout<<Q1.dequeue()<<endl;
	cout<<Q1.dequeue()<<endl;
	
    return 0;
}


void Queue::enqueue(int data)
{
	struct Node *new_node=new Node(data);
	if(head==nullptr)
	{
		head=new_node;
		length++;
		return;
	}
	struct Node *temp=head;
	while(temp->next!=nullptr)
		temp=temp->next;
	
	temp->next=new_node;
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



