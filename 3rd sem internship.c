#include<stdio.h>
#include<stdlib.h>
void Create();
void Show();
void Add_from_start();
void Add_from_intermediate();
void Add_from_end();
void modify_from_start();
void modify_from_intermediate();
void modify_from_end();
void remove_from_start();
void remove_from_intermediate();
void remove_from_end();
struct sub
{
	int marks;
	struct sub *next;
};
struct sub *start=NULL,*temp,*node,*loc,*t,*s,*r,*afe,*rfs,*pos,*afi;
void main()
{
    int n;
	do
	{
	n=menu();	
	if(n==1)
	  Create();
	else if(n==2)
	  Show();
	else if(n==3)
	  Add_from_start();
	else if(n==4)
	  Add_from_intermediate();
	else if(n==5)
	  Add_from_end();
	else if(n==6)
	  modify_from_start();
	else if(n==7)
	  modify_from_intermediate();
	else if(n==8)
	  modify_from_end();
	else if(n==9)
	  remove_from_start();
	else if(n==10)
	  remove_from_intermediate();
	else if(n==11)
	  remove_from_end();
	else if(n==0)
	  exit;
	else
	   printf("\nInvalid Input !!");
   }while(n!=0);
}

int menu()
{
	int n;
 	printf("\n===============================================\n");
	printf("\nPress 0 for close :");
	printf("\nPress 1 for Create :");
	printf("\nPress 2 for Show :");
 	printf("\n----------------------------------------------");
	printf("\nPress 3 for Add_from_start :");
	printf("\nPress 4 for Add_from_intermediate :");
	printf("\nPress 5 for Add_from_end :");
 	printf("\n----------------------------------------------");
	printf("\nPress 6 for modify_from_start :");
	printf("\nPress 7 for modify_from_intermediate:");
	printf("\nPress 8 for modify_from_end :");
 	printf("\n----------------------------------------------");	
	printf("\nPress 9 for remove_from_start :");
	printf("\nPress 10 for remove_from_intermediate :");
	printf("\nPress 11 for remove_from_end :");
	printf("\n Enter Your Choice :");
	scanf("%d",&n);
 	printf("\n================================================\n");
	return n;
}

void Create()
{
	char ch;
	do
	{
		node=(struct sub*)malloc(sizeof(struct sub));
		printf("\n Enter Your marks:");
		scanf("%d",&node->marks);
		node->next=NULL;
		if(start==NULL)
		{
			temp=node;
			start=node;
		}
		else
		{
			temp->next=node;
			temp=temp->next;
		}
		printf("\n Do You want to create a New Node:");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='Y'||ch=='y');
}

void Show()
{
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		printf("\n%d",temp->marks);
	}
}

void Add_from_start()
{
    t=(struct sub*)malloc(sizeof (struct sub));
    printf("Enter a number :");
    scanf("%d",&t->marks);
    t->next=NULL;
    t->next=start;
    start=t;
    printf("Element Added Successfully");
}

void Add_from_intermediate()
{
    int pos,c=0;
	r=(struct sub*)malloc(sizeof(struct sub));
	printf("Enter a Number:");
	scanf("%d",&r->marks);
	r->next=NULL;
	printf("Enter Position You Want to add:");
	scanf("%d",&pos);
	pos--;
	afi=start;
	for(c=1;c<=pos-1;c++)
	{
	   afi=afi->next;
	   if(afi==NULL)
	   break;	
	}	
	if(afi!=NULL)
	{
		r->next=afi->next;
		afi->next=r;
	}
    printf("Element Added Successfully");
}

void Add_from_end()
{
    s=(struct sub*)malloc(sizeof (struct sub));
    printf("Enter a number :");
    scanf("%d",&s->marks);
    afe=node;
    afe->next=s;
   	s->next=NULL;
   	afe=s;	
    printf("Element Added Successfully");		
}

void modify_from_start()
{
	int value;
	if(start==NULL)
	printf("\n Linked list is Empty");
	else
	{
		printf("\n Enter a Value to Modify: ");
		scanf("%d",&value);
		start->marks=value;
	}
	printf("Marks Modify successfully");
}

void modify_from_intermediate()
{
     int value,pos,f=0,count=0;
	 printf("\nEnter a Value to Modify");
	 scanf("%d",&value);
	 if(start==NULL)
	 printf("\nLinked list is Empty We Can't Modify");
	 else if(start->next==NULL)
	 {
           start->marks=value;	 	
	 }	
	 else
	 {
	 	printf("\nEnter Position  Where You Want to Modify: ");
	 	scanf("%d",&pos);
	 	for(temp=start;temp!=NULL;temp=temp->next)
	 	{
	 		count++;
	 		if(count==pos)
	 		{
	 			f=1;
	 			break;
			}
		 }
		 if(f==1)
		 {
		 	temp->marks=value;
		 	printf("\nSuccessfully Modify Marks at %d Position",pos);
		 }
		 else
		 printf("\n %d Position is not available in Linked list",pos);
	 }
}

void modify_from_end()
{
    int value;
    printf("\nEnter a Value to Modify");
    scanf("%d",&value); 
	if(start==NULL)
	printf("\nLinked list is Empty We Can't Modify");
	else if(start->next==NULL)
	start->marks=value;
	else
	{
		for(temp=start;temp->next!=NULL;temp=temp->next);
		{
		}
		temp->marks=value;
	 } 
	printf("Marks Modify successfully");
}
void remove_from_start()
{
     int i;
	 for(i=1;i<=1;i++)
     {
     temp=start;
     start=start->next;    
     free(temp);
	 }
	 printf("Element Remove Successfully");
}

void remove_from_intermediate()
{
     int pos,f=0,count=0;
     struct sub *p,*temp;
	 if(start==NULL)
	 printf("\nLinked list is Empty We Can't Remove");
	 else if(start->next==NULL)
	 {
            p=start;
			start=NULL;
			free(p);
			printf("First node Successfully Deleted");	 	
	 }	
	 else
	 {
	 	printf("\nEnter Position  Where You Want to Remove Marks: ");
	 	scanf("%d",&pos);
	 	for(temp=start;temp!=NULL;temp=temp->next)
	 	{
	 		count++;
	 		if(count==pos-1)
	 		{
	 			f=1;
	 			break;
			}
		 }
		 if(f==1)
		 {
		 	p=temp->next;
		 	temp->next=temp->next->next;
		 	free(p);
		 	printf("\nSuccessfully Remove Marks at %d Position",pos);
		 }
		 else
		 printf("\n %d Position is not available in Linked list",pos);
	 }	
}
void remove_from_end()
{
   temp=start;
   while(temp->next!=NULL)
   {
   	loc=temp;
   	temp=temp->next;
  }
   loc->next=NULL;
   free(temp);
   printf("Element Remove Successfully");	
}

