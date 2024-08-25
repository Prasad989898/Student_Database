#include<iostream>
#include<cstring>

using namespace std;

class node
{
	public:
		int roll,ind;
		string name;
		float m,cpp,c,avg,sp;
		node *next;
};


class list :public node
{
	node *head;
			
	public:
		
		list()
		{
			head=NULL;
		}	
		
		node* insert(node *head);
		void traverse(node *head);
		node* remove(node *head);
		node* result(node *head);
	
};

node* list::result(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		if(p->ind==0)
		{
			p->avg=(p->m+p->cpp+p->c+p->sp)/4;
			p->ind=1;
		}
		p=p->next;
		}
	return head;
}

void list::traverse(node *head)
{
	node *p;
	p=head;
	cout<<"p->value head"<<p->roll<<endl;
	while(p!=NULL)
	{
		cout<<"name="<<p->name<<endl;
		cout<<"id="<<p->roll<<endl;
		cout<<"result="<<p->avg<<endl;
		p=p->next;
	}
}

	
node* list::insert(node *head)
{
	node *p;
	p=head;
	node *temp=new node;
	
	temp->ind=0;
	cout<<"Enter name"<<endl;
	cin>>temp->name;
	cout<<"Enter id "<<endl;
	cin>>temp->roll;
	cout<<"Enter student marks in maths"<<endl;
	cin>>temp->m;
	cout<<"Enter student marks in cpp"<<endl;
	cin>>temp->cpp;
	cout<<"Enter student marks in chemistry"<<endl;
	cin>>temp->c;
	cout<<"Enter student score in sports"<<endl;
	cin>>temp->sp;
	
	
	while(p->next!=NULL)
	{
		p=p->next;
	}
	
	p->next=temp;
	temp->next=NULL;
	
	return head;
}
		
node* list::remove(node *head)
{
		int i=1,a;
		cout<<"Enter the id u want to remove"<<endl;
		cin>>a;
		
	node *p,*temp;
	temp=head;

	if(temp->next==NULL)			//if only one data is there
	{
		if(temp->roll==a)
		{
			delete temp;
		}
		
		else
		cout<<"data not found"<<endl;
	}
	
	else							
	{
		p=head;
		temp=head;
		
		if(temp->roll==a)					//if more no;of data is there and req data is in head
		{
			head=temp->next;
			delete temp;
		}
		
		else 							//if more no;of data is there and req is at somewhere
		{								//other than head
			
			while(i)
			{
				temp=p;
				if(p->next->roll==a)
				{
					i=0;
				}
				p=p->next;
			}
			temp->next=p->next;
			delete p;
		}
	}
	
	return head;
}

int main()
{
	list l;
	
	int m,k;
	string name;
	char ch;
	cout<<"Enter the number of details u want to enter"<<endl;
	cin>>m;
	
	node *head,*p;
	for(int i=0;i<m;i++)
	{
		
		if(i==0)
		{
			head=new node;
			p=head;
		}	
		else
		{
			p->next=new node;
			p=p->next;
		}
		
		cout<<"Enter name of student"<<endl;
		cin>>p->name;
		p->ind=0;
		cout<<"ENter student id"<<endl;
		cin>>p->roll;
		cout<<"Enter student marks in maths"<<endl;
		cin>>p->m;
		cout<<"Enter student marks in cpp"<<endl;
		cin>>p->cpp;
		cout<<"Enter student marks in chemistry"<<endl;
		cin>>p->c;
		cout<<"Enter student score in sports"<<endl;
		cin>>p->sp;
	}
	p->next=NULL;
	
	cout<<"Enter the choice"<<endl;

	do
	{
		cout<<"1.enter data"<<endl<<"2.remove data"<<endl<<"3.show data"<<endl<<"4.calculate result"<<endl;
		cin>>m;
		
		switch(m)
		{
			case 1:	head=l.insert(head);
					break;
					
			case 2: head=l.remove(head);
					break;
			case 3:	cout<<"Data after modification is"<<endl;
					l.traverse(head);
					break;
			case 4:	head=l.result(head);
					break;
			default: cout<<"Invalid choice"<<endl;
						
		}
		cout<<"Enter y to continue"<<endl;
		cin>>ch;	
	}while(ch=='y');
	
}


