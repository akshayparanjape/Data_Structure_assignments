# include <iostream>
#include <iomanip>
using namespace std;

struct node{
	int number;
	node* next;
};

node* head;
node* headb;
node* headw;
node* last;

int writeData(float per, int visits, int no_alloc)
{
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  cout << per << endl <<  visits << endl << no_alloc << endl;
  return 0;
}

void build_list(int n,int a[]){
	node* tail;
	node* temp= new node;
	temp->number = a[0];
	head=temp;
	last=temp;	
	for(int i=1;i<n;i++)
		{node* temp=new node;
		temp->number = a[i];
		temp->next=NULL;
		last->next=temp;
		last=temp;
		}
}

void build_listb(int n,int a[]){
	node* tail;
	node* temp= new node;
	temp->number = a[0];
	headb=temp;
	last=temp;	
	for(int i=1;i<n;i++)
		{node* temp=new node;
		temp->number = a[i];
		temp->next=NULL;
		last->next=temp;
		last=temp;
		}
}

void build_listw(int n,int a[]){
	node* tail;
	node* temp= new node;
	temp->number = a[0];
	headw=temp;
	last=temp;
	for(int i=1;i<n;i++)
		{node* temp=new node;
		temp->number = a[i];
		temp->next=NULL;
		last->next=temp;
		last=temp;
		}
}

int sum(node* a){
	int sum=0;
	while (a != NULL )
		{
		sum= sum + a->number;
		a = a->next;
		}
	return sum;
}

void First_fit(node* head,int b[],int m){

	int no_allocation=0;
	int count=0;
	node* head1;
	node* headp;
	for (int i=0;i<m;i++)
		{if (b[i]>0)	
			{head1=head;
			headp=NULL;
			while(head1 != NULL)
				{count=count+1;
				if (b[i]< head1->number)
					{int temp=head1->number-b[i];
					head1->number = temp;
					break;}
				else if (b[i]== head1->number)
					{
					if (headp!=NULL)
						{
						head1=head1->next;
					
						headp->next=head1;
			//			delete( headp);
						}
					else 
						{
						head=head->next;
		//				delete(head);
						}	
					break;
					}
				else
					{headp=head1;
					head1=head1->next;}
				}
			if (head1 == NULL)
				{no_allocation= no_allocation + 1;
				}
			}
		}	
	float percentage;
	percentage=((m-no_allocation)*100.00)/m;
	int amount=sum(head);
	writeData(percentage,count,amount);
}

void Best_fit(node* head,int b[],int m){
	int no_allocation=0;
	int count=0;
	node* current;
	node* head1;
	node* headp;
	for (int i=0;i<m;i++)
		{if (b[i]>0)	
			{
			head1=head;
			headp=NULL;
			current=NULL;
			int temp=1000000;
			while(head1!= NULL)
				{count = count +1;
				if ((head1->number>b[i]) && ((head1->number-b[i])< temp))
					{
					current=head1;
					temp=head1->number-b[i];
					headp=head1;
					head1=head1->next;
					}
				else if (head1->number== b[i])
					{
					current=head1;
					if (headp!=NULL)
						{
						head1=head1->next;
						headp->next=head1;
					//	delete( headp);
						}
					else 
						{
						head=head->next;
				//		delete( head);
						}	
					temp=0;
					break;}
				else
					{headp=head1;
					head1=head1->next;}
				}
			if (current != NULL)
				{current -> number = temp;
				}
			else
				{no_allocation=no_allocation+1;}
			}	
		}	
	float percentage;
	percentage=((m-no_allocation)*100.0)/m;
	int amount=sum(headb);
	writeData(percentage,count,amount);	
}

void Worst_fit(node* head,int b[], int m){
	int no_allocation=0;
	int count=0;
	node* current;
	node* current1;
	node* head1;
	node* headp;
	
	for (int i=0;i<m;i++)
		{if (b[i]>0)	
			{
			head1=head;
			current=NULL;
			int temp=0;
			while(head1 != NULL)
				{count = count +1;
				if ((head1->number-b[i]) >= temp)
					{				
					current=head1;				
					temp=head1->number-b[i];			
					current1=headp;				
					head1=head1->next;		
					}
				else
					{headp=head1;
					head1=head1->next;				
					}
				}			
			if (current != NULL)
				{current -> number = temp;
				}
			else
				{no_allocation=no_allocation+1;}
			
			if (current != NULL && current -> number==0)
				{if (current->next == NULL)
					{
					current1->next= NULL;
			//		delete( current1);
					}
				else if (current == head)	
					{
					head=head->next;
		//			delete (head);
					}
				else 
					{
					head1=current->next;
					current1->next=head1;
	//				delete( current1);
					}	
				}
			}			
		}	
	float percentage;
	percentage=((m-no_allocation)*100.00)/m;
	int amount=sum(headw);
	writeData(percentage,count,amount);
}

main(){
	int n,m;
	cin>> n;
	head = NULL;
	headb = NULL;
	headw = NULL;

	cin>>m;
	int memory[n];
	
	for(int i=0;i<n;i++)
		{cin>>memory[i];}
		
	build_list(n,memory);
	build_listb(n,memory);
	build_listw(n,memory);

	int  process[m];
	for(int i=0;i<m;i++)
		{
		cin>>process[i];}	

	First_fit(head,process,m);
	Best_fit(headb,process,m);
	Worst_fit(headw,process,m);
}
