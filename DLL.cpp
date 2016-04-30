#include<iostream>
using namespace std;
typedef int type;
struct node
{
	type data;
	node* next;
	node* pre;
};
class list
{
	private:
		node* head;
		node* last;
		node* temp;
		int sz;
	public:
		list();
		void push_back(type k);
		type pop_back();
		void push_front(type k);
		type pop_front();
		void push_pos(int pos,type k);
		int size();
		void swap(int i,int j);
		type element(int pos);
		//bool end(node* t);
		node* begin();
		void erase_pos(int k);
		void erase_element(type k);
		void print();
		int search(type k);
		void modify(int pos,type k);
};
list::list()
{
	head=new node;
	head->data=0;                                   // specific for Integers
	head->next=NULL;
	head->pre=NULL;                   
	sz=0;
}
node* list::begin()
{
	return head->next;
} 
void list::push_back(type k)
{
	temp=head;  node *temp1;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=new node;
	temp1=temp;
	temp=temp->next;
	temp->data=k;
	temp->next=NULL;
	temp->pre=temp1;
	sz++;
}
type list::pop_back()
{
	temp=head;       type save;
	node* temp1;
	while(temp->next!=NULL)
	{   temp1=temp;		temp=temp->next;	}
	temp1->next=NULL;	
	save=temp->data;
	delete temp;
	sz--;
	return save;
}
void list::push_front(type k)
{
	temp=head->next;
	head->next=new node;
	head->next->data=k;
	head->next->next=temp;
	sz++;
}
type list::pop_front()
{
	type save;
	temp=head->next;
	head->next=temp->next;
	save=temp->data;
	delete temp;
	sz--;
	return save;
}
void list::push_pos(int pos,type k)
{
	temp=head;
	for(int i=1;i<pos;i++)
		temp=temp->next;
	node* temp1=new node;
	temp1->data=k;
	temp1->next=temp->next;
	temp->next=temp1;
	sz++;
}
int list::size()
{
	return sz;
}
void list::swap(int i,int j)
{
	node *temp1 , *temp2;
	int save1,save2;
	temp1=temp2=head;
	for(int k=1;k<=i;k++)
		temp1=temp1->next;
	save1=temp1->data;
	for(int k=1;k<=j;k++)
		temp2=temp2->next;
	save2=temp2->data;
	temp2->data=save1;
	temp1->data=save2;
}
void list::erase_pos(int pos)
{
	temp=head;
	for(int i=1;i<pos;i++)
		temp=temp->next;
	node* temp1=temp->next;
	temp->next=temp1->next;
	delete temp1;
	sz--;
}
void list::erase_element(type k)
{
	temp=head;
	node *temp1;
	while(temp->next!=NULL)
	{
		if(temp->data==k)
			break;
		temp1=temp;
		temp=temp->next;
	}
	node *temp2=temp1->next;
	temp1->next=temp2->next;
	delete temp2;
	sz--;
}
void list::print()
{
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		cout<<temp->data<<" -> ";
	}
	cout<<endl;
}
int list::search(type k)
{
	temp=head->next; int pos=0;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==k)
			return pos;
		temp=temp->next;
	}
	
	return -1;
}
type list::element(int pos)
{
	temp=head;
	for(int i=1;i<=pos;i++)
	temp=temp->next;
	return temp->data;
}
void list::modify(int pos,type k)
{
	temp=head;
	for(int i=1;i<=pos;i++)
	temp=temp->next;
	temp->data=k;
}
int main()
{
}
