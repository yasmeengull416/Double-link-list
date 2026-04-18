#include<iostream>
//#include <cstdlib>

using namespace std;

struct node
{
	int value;
	node*next;
	node*pre;
};

node* head=NULL ;
node* tail=NULL ;

void createDLL()
{
	node* newNode = new node();
	cout<<"Enter Value You Wanna insert in node: "; 
	cin>>newNode->value;
	newNode->next=NULL;
	newNode->pre=NULL;

	if(head==NULL)
	{
		head= newNode;
		tail= newNode;
	}
	else
	{
		newNode->next=NULL;
		newNode->pre=tail;
		tail->next=newNode;
		tail=newNode;
	}
}

void insertAtHead()
{
	node* newNode = new node();
	cout<<"Enter Value You Wanna insert in new head node: "; 
	cin>>newNode->value;
	newNode->pre=NULL;
	newNode->next = head;
	head->pre=newNode;
	head=newNode;
}

void insertAtEnd()
{
	node* newNode = new node();
	cout<<"Enter Value You Wanna insert in new end node: ";
	cin>>newNode->value;
	newNode->next=NULL;
	newNode->pre=tail;
	tail->next=newNode;
	tail=newNode;
}

int lengthLL()
{
	int size = 0;
	node* treverse  ;
	treverse = head;

	while(treverse!=NULL)
	{
		size++; 
		treverse=treverse->next;
	}
	return size;
}

void insertAfterPosition()
{ 
	int pos;
	int i = 1;
	int l = lengthLL();
	node*temp;
	temp= head;
	cout<<"Enter position you wanna insert new Node: ";
	cin>>pos;
	node* newNode = new node();
	cout<<"Enter Value You Wanna insert in new end node: ";
	cin>>newNode->value;

	if(pos<1 || pos>l)
	{
		cout<<"Invalid position";
		return;
	}
	
	while(i<pos)
	{
		temp=temp->next;
		i++;
	}

	newNode->pre=temp; 
	newNode->next=temp->next;
	temp->next=newNode;
	newNode->next->pre=newNode;
}

void insertBeforePosition()
{
	int pos;
	int i = 1;
	int l = lengthLL();
	node*temp;
	temp= head;
	cout<<"Enter position you wanna insert new Node: ";
	cin>>pos;
	
	if(pos<1 || pos>l)
	{
		cout<<"Invalid position";
		return;
	}
	
	if(pos==1) 
	{
		insertAtHead();
		return;
	}
	
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	
	if(temp->next==NULL)
	{
		insertAtEnd();
		return;
	}
	
	node* newNode = new node();
	cout<<"Enter Value You Wanna insert in new end node: ";
	cin>>newNode->value;
	newNode->pre=temp;
	newNode->next=temp->next;
	temp->next=newNode; 
	newNode->next->pre=newNode;
}

void printForward(node* head)
{
	node* treverse  ;
	treverse = head;

	while(treverse!=NULL)
	{
		cout<<treverse->value<<" ";
		treverse=treverse->next;
	}
	cout<<endl;
}

void printReverse(node* tail)
{
	node* treverse  ;
	treverse = tail;

	while(treverse!=NULL)
	{ 
		cout<<treverse->value<<" ";
		treverse=treverse->pre;
	}
	cout<<endl;
}

void delHead()
{
	node*temp;
	temp=head;
	head=head->next;
	head->pre=NULL;
	delete temp;
}

void delTail()
{
	node* temp;
	temp = tail;
	tail=tail->pre;
	tail->next=NULL;
	delete temp; 
}

void delAtPosition()
{
	int pos ;
	int i = 1 ;
	int l = lengthLL();
	cout<<"Enter Position of node you wanna Delete: ";
	cin>>pos;
	node*temp ;
	temp = head ;

	if(pos<1 || pos>l)
	{
		cout<<"Invalid Position ";
		return;
	}

	if(pos==1)
	{
		delHead();
	}

	while(i<pos)
	{ 
		temp=temp->next;
		i++;
	}

	if(temp->next==NULL)
	{
		delTail();
		return;
	}
	temp->pre->next=temp->next;
	temp->next->pre=temp->pre;
	delete temp;
}

	void tailtohead()
	{
		tail->next=head;
		head->pre=tail;
		tail=tail->pre;
		tail->next->pre=NULL;
		tail->next=NULL;
		head=head->pre;
		
	}

	void headtotail()
	{
		tail->next=head;
		head->pre=tail;
		head=head->next;
		tail->next->next=NULL;
		head->pre=NULL;
		tail=tail->next;
	}



void insertAfterEven() 
{
    if (head == NULL) 
	{
	    cout << "There is no value in the list ";

        return;
    }

    node* current = head;
    while (current != NULL) 
	{
        if (current->value % 2 == 0)
		{
            node* newNode = new node();
            newNode->value = 15;
			newNode->next=current -> next;
			newNode->pre=current;      
            
            if (current->next) 
			{
                current->next->pre = newNode;
            }
            current->next = newNode;
            current = newNode->next;
        } 
		else 
		{
            current = current->next;
        }
    }
}


int main(int argc, char** argv) {
	
    
	createDLL();
	createDLL();
	createDLL();
	createDLL();
	createDLL();

	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	insertAtHead();
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	insertAfterPosition();
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	insertBeforePosition();
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	delAtPosition(); 
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	return 0;
}
