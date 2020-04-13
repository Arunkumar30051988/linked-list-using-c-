#include<iostream>
using namespace std;
class link
{
	public:
		int data;
		link *Next;
	public:
		void linkedlist_init();
		link *InsertFirst(link *head,int data);
		int DeleteNode(link *head,int data);
		int ShowLinkedList(link *head);
};
void link:: linkedlist_init()
{
		//printf("Linked list init \n");
}
link* link::InsertFirst(link* head, int data)
{
	link *current;
	if(head == NULL)
	{
		head = new link ();
		if(head == NULL)
		{
			//printf("unable to allocate memory");
			cout << "unable to allocate memory" << "\n";
		}
		head->data=data;
		head->Next=NULL;
	}
	else
	{
		current = new link ();
		current->data = data;
		current->Next = head;
		head=current;
	}
	return head;
}
int link :: ShowLinkedList(link *head)
{
	link *current= head;
	if(current== NULL)
	{
		return 0;
	}
	int count=0;
	while(current!=NULL)
	{
//		printf("data : %d \n",current->data);
		cout << "data :"<< current->data << "Address : %x "<< current <<"\n";
		current=current->Next;
		count++;
	}
}
int link:: DeleteNode(link *head,int data)
{
	cout <<"Function: " << __FUNCTION__ << "\n";

	link *Current=head;
	link *temp=NULL;
	if (head==NULL)
	{
		return 0;
	}
	if(head->data== data)
	{
		temp=head->Next;
		delete head;
		head=temp;
		return 0;
	}

	while(Current!=NULL)
	{
		if(Current->data==data)
		{
			temp=Current;
			break;
		}
		else
		{
			Current=Current->Next;
		}
	}
	Current=head;
	while(Current->Next !=NULL &&Current->Next != temp)
	{
		Current=Current->Next;
	}
	cout << "Address :%x "<< Current->Next << "\n";
	
	if(Current->Next!=NULL)
	{
		Current->Next= Current->Next->Next;
		cout << "Address :%x "<< Current->Next << "\n";
	
	}
	
	delete temp;


}
int main()
{
	link *header=NULL;
	link obj;
	header=obj.InsertFirst(header,5);
	header=obj.InsertFirst(header,6);
	header=obj.InsertFirst(header,7);
	obj.ShowLinkedList(header);
	obj.DeleteNode(header,5);
	obj.ShowLinkedList(header);
	
}
	

