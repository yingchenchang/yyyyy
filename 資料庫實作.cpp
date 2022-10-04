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
	cout<<"�п�J�ǥ;Ǹ�";
	cin>>newptr->id;
	cout<<"�п�J�ǥͩm�W:";
	cin>>newptr->name;
	cout<<"�п�J�ǥͩ��ݦ~��:";
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
	
cout<<"��J�n�R�����Ǹ�:";
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
	cout<<"�L���Ǹ�\n";
}
else
{
	cout<<"�R���Ǹ���"<<ptr->id<<"�����\n";
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
 cout<<"�Ǹ�:\t �m�W:\t �~��:\n";
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
		cout<<"<1>�s�W���\n";
		cout<<"<2>�R�����\n";
		cout<<"<3>��ܸ�Ʀ�C\n";
		cout<<"<4>�����{��\n";
		cout<<"�п�J1-4:";
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
