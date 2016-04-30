#include<iostream>
#include<string.h>
using namespace std;
struct link
{char data;
link *next;
}*head=NULL,*node,*prev;
void create(char data)
{if(head==NULL)
	{head=new link;
	head->data=data;
	head->next=NULL;
	node=head;
	}
	else
	{node->next=new link;
	node=node->next;
	node->data=data;
	node->next=NULL;
	}
}
void removeDuplicates(struct link *start)
{
  struct link *ptr1, *ptr2, *dup;
  ptr1 = start;
 
  /* Pick elements one by one */
  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;
 
     /* Compare the picked element with rest of the elements */
     while(ptr2->next != NULL)
     {
       /* If duplicate then delete it */
       if(ptr1->data == ptr2->next->data)
       {
          /* sequence of steps is important here */
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          delete dup;
       }
       else /* This is tricky */
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}
char compare(char s[],char s1[])
{
for(int i=0;s[i]!='\0';i++)
	{for(int j=0;s1[j]!='\0';j++)
		if(s[i]==s1[j])
			{create(s[i]);
			break;
			}
	}
}
void smrtcompare(char a[])
{link *curr=head;
while(curr!=NULL)
	{int flag=0;
	for(int i=0;a[i]!='\0';i++)
		{if(curr->data==a[i])
				{flag=1;
				}
				if(flag==1)
				break;
		}
		if(flag==0)
		{if(curr==head)
			{head=curr->next;
			delete curr;
			}
			else
			{prev->next=curr->next;
			delete curr;
			}
		}
		prev=curr;
		curr=curr->next;
	}
}
void display()
{link *curr=head;
while(curr!=NULL)
	{cout<<curr->data<<" ";
	curr=curr->next;
	}
}
int main()
{
char arr[10],arr1[15];
gets(arr);
gets(arr1);
compare(arr,arr1);
removeDuplicates(head);
display();
char *s=new char[5];
for(int i=0;i<5;i++)
cin>>*(s+i);
smrtcompare(s);
display();
return 0;
}
