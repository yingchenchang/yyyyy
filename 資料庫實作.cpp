#include <iostream>
using namespace std;

struct Node
{
	char name[8];
	int id;
	int grade;
	Node *next;	
}*head;

void addNode(void)
{
	Node *newptr,*ptr,*befptr;
	bool flag=false;
	newptr=new Node;
	cout<<"---------------------\n";
	cout<<"請輸入學生學號";
	cin>>newptr->id;
	cout<<"請輸入學生姓名:";
	cin>>newptr->name;
	cout<<"請輸入學生所屬年級:";
	cin>>newptr->grade;
	cout<<"---------------------\n";
	ptr=befptr=head;
	if(head==NULL)
	{
		head=newptr;
		head->next=NULL;
	}
	else
	{
		while(ptr!=NULL)
		{
			if(newptr->grade>ptr->grade)
			{
				flag=true;
				break;
			}
			befptr=ptr;
			ptr=ptr->next;
		} 
		if(flag==false)
		{
			newptr->next=NULL;
			befptr->next=newptr;
		}
		else
		{
			if(ptr==head){
				newptr->next=head;
				head=newptr;
			}
			else
			{
				newptr->next=ptr;
				befptr->next=newptr;
			}
		}
		
	}		
}
void delNode(void)
{
Node *ptr, *befptr;
bool flag=false;
int id;
	
cout<<"輸入要刪除的學號:";
cin>>id;
ptr=befptr=head;
while(ptr!=NULL)
{
	if(id==ptr->id)
	{
		flag=true;
		break;
	}
	befptr=ptr;
	ptr=ptr->next;
}
if(flag==false)
{
	cout<<"無此學號\n";
}
else
{
	cout<<"刪除學號為"<<ptr->id<<"之資料\n";
	if(ptr==head)
	{
		head=ptr->next;
	}
	else if(ptr->next==NULL){
		befptr->next=NULL; 
	}	
	else
	{
		befptr->next=ptr->next;
    }
    delete ptr;
}
}
void showNode(void)
{
 Node *node=head;
 
 cout<<"--------------------\n";
 cout<<"學號:\t 姓名:\t 年級:\n";
 while(node!=NULL)
 {
 	cout<<node->id<<'\t'<<node->name<<'\t'<<node->grade<<endl;
 	node=node->next;
 }
 cout<<"--------------------\n";
}

int main(int argc,char**argv)
{
	char op;
	Node *temp,*ptr;
	head=NULL;
	
	while(1)
	{
		cout<<"--------------------\n";
		cout<<"<1>新增資料\n";
		cout<<"<2>刪除資料\n";
		cout<<"<3>顯示資料串列\n";
		cout<<"<4>結束程式\n";
		cout<<"請輸入1-4:";
		cin>>op;
		switch(op)
		{
			case('1'):
				addNode();
				break;
			case('2'):
				delNode();
				break;
			case ('3'):
				showNode();
				break;
			case('4'):
				ptr=head;
				while(ptr!=NULL)
				{
					temp=ptr;
					delete ptr;
					ptr=temp->next;
				}
				system("PAUSE");
				return 0;
				break;
			default:
				continue;
		}	
	}
}
