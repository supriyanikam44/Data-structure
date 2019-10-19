#include <iostream>
using namespace std;

struct node
{
	node *prev;
	int value;
	node *next;

	node(int value)
	{
		this->prev=nullptr;
		this->value=value;
		this->next=nullptr;
	}
};

class DoubleLinkedlist
{
private:
	struct node *Head;
	struct node *Tail;
public:
	
	DoubleLinkedlist():Head(nullptr),Tail(nullptr)
	{
	}

	void addToBack(int value)
	{
		node  *newnode=new node(value);
		newnode->value=value;
		newnode->next=nullptr;
		newnode->prev=nullptr;
		if(nullptr==Head)
		{
			Head=newnode;
		}
		else
		{
			Tail->next=newnode;
			newnode->prev=Tail;
		}
		Tail=newnode;
	}
	
	void addToFront(int value)
	{
		node  *newnode=new node(value);
		newnode->value=value;
		newnode->next=nullptr;
		newnode->prev=nullptr;
		if(nullptr==Head)
		{
			Head=Tail=newnode;
		}
		else
		{
			Head->prev=newnode;
			newnode->next=Head;

		}
		Head=newnode;
	}
	
	bool addAfter(int value,int num)
	{
		for(node *asf=Head;asf;asf=asf->next)
		{
			if(asf->value==value)
			{
				//Only One Node in list
				if(asf==Tail)
				{
					addToBack(num);
					return true;
				}

				//add in between anywhere
				node *newnode=new node(num);
				newnode->value=num;
				newnode->next=nullptr;
				newnode->prev=nullptr;
				newnode->next=asf->next;
				newnode->prev=asf;
				asf->next->prev=newnode;
				asf->next=newnode;
				return true;
			}
		}
		return false;
	}
	
	bool addBefore(int value,int num)
	{
		//add in between;
		for(node *Bef=Head;Bef;Bef=Bef->next)
		{
			if(Bef->value==value)
			{
				//Only One Node in List

				if(Bef==Head&&Bef->next==nullptr)
				{
					addToFront(num);
					return true;
				}

				//Node at first position

				if(Bef==Head)
				{
					addToFront(num);
					return true;
				}

				node *newnode = new node(num);
				newnode->value=num;
				newnode->next=nullptr;
				newnode->prev=nullptr;
				newnode->prev=Bef->prev;
				newnode->next=Bef->prev->next;
				Bef->prev->next=newnode;
				Bef->prev=newnode;
				return true;
			}
		}
		return false;

	}
	
	void PrintForward()
	{
		for(node *current=Head;current;current=current->next)
		{
			cout<<current->value<<"\t";
		}
		cout<<endl;
	}
	
	void Printbackward()
	{
		for(node *current=Tail;current;current=current->prev)
		{
			cout<<current->value<<"\t";
		}
	}

	bool SearchToDelete(int value)
	{
		for (node *p= Head;p;p= p->next)
		{
			if (p->value== value)
			{
				//Only One Node is Present

				if(p== Head && p== Tail)
				{
					delete p;
					Head=nullptr;
					Tail=nullptr;
					return true;
				}

				//When Node Is First

				if(p== Head)
				{
					Head= Head->next;
					delete p;
					Head->prev= nullptr;
					return true;
				}

				//When node is Last

				if (p== Tail)
				{
					Tail=Tail->prev;
					Tail->next=nullptr;
					delete p;
					return true;
				}

				//When node is Between
				p->prev->next=p->next;
				p->next->prev=p->prev;
				delete p;
				return true;
			}
		}
		return false;
	}
	int RemoveAll ()
	{
		int count= 0;
		node *Remove;

		while (Head != nullptr)
		{
			Remove=Head;
			Head=Head->next;
			delete Remove;
			count++;
		}
		Tail=nullptr;
		return count;
	}
};


int main()
{
	int num;
	int value;
	int Bet,ele,Loc,AsF;
	DoubleLinkedlist D1;

	while (cout<<"Enter Elements in List  (0 to stop)"<<endl, cin>>num, num!=0)
	
	{
		D1.addToBack(num);
	}

	D1.addToFront(29);
	D1.PrintForward();

	while (cout<<"Enter Element for before position  (0 to stop)"<<endl, cin>>Bet, Bet!=0)
	{
		cout<<"Enter the value for new node"<<endl;
		cin>>ele;
		D1.addBefore(Bet,ele);
	}

	D1.PrintForward();

	while (cout<<"Enter the location for after insert (0 to stop)"<<endl , cin>>Loc ,Loc!=0)
	{
		cout<<"Enter the value for new node"<<endl;
		cin>>AsF;
		D1.addAfter(Loc,AsF);
	}

	D1.PrintForward ();
	D1.Printbackward ();
	while (cout<<endl<<"Enter Element to delete  (0 to stop)"<<endl, cin>>value, value!=0)
	{
		cout<<endl;
		cout<<D1.SearchToDelete(value)<<"Deleted"<<endl;

	}
	D1.PrintForward ();
	cout<<endl<<"Deleted nodes are "<<D1.RemoveAll()<<endl;
}