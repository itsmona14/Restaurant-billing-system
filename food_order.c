#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct menu{
	int item_id;
	char item_name[50];
	int qty;
	int unit_price;
	double tot;
	struct menu *Next;
};

typedef struct menu *PtrToNode;
typedef PtrToNode Menu;
Menu M, P, Temp;

void delete_item(int id);
void mainmenu(void);
void update_item();
void delete_order();
void mainmenu_copy();

void Insert(int id, int quantity, int price, double tot1){
        Temp = (struct menu*)malloc(sizeof(struct menu));
        if(Temp == NULL)
                printf("\nOut of space!!!");
        else{
		switch(id){
			case 1:
				strcpy(Temp -> item_name,"Noodles");
				break;
			case 2:
				strcpy(Temp -> item_name,"Pizza");
				break;
			case 3:
				strcpy(Temp -> item_name,"Burger");
				break;
			case 4:
				strcpy(Temp -> item_name,"Cutlet");
				break;
			case 5:
				strcpy(Temp -> item_name,"Nuggets");
				break;
		}
		Temp -> item_id = id;
		Temp -> qty = quantity;
		Temp -> unit_price = price;
		Temp -> tot = quantity*Temp->unit_price;
		Temp -> Next = NULL;
                if(M == NULL)
                        M = Temp;
                else{
                        P = M;
                        while(P -> Next != NULL)
                                P = P -> Next;
                        P -> Next = Temp;
                }
        }
}

void display_order(){
	int i = 1;
	P = M;	
	if(M == NULL)
		printf("-----Nothing Ordered. Order something-----");
	else{
		printf("\n*******************************************************************************\n");
		printf("S.No\tItem Name\t\t\tQuantity\tUnit_Price\tTotal");
		printf("\n*******************************************************************************\n");
		while(P != NULL){
			printf("%d\t%s\t\t\t\t%d\t\t%d\t\t%.2lf",i, P -> item_name, P -> qty, P -> unit_price, P -> tot);
			P = P -> Next;
			i++;
			printf("\n");
		}
	}
}

void display_menu(){
	char v;
	FILE *vmenu;
	printf("***********************************************\n                VEGETARIAN MENU\n***********************************************\n");
    	vmenu=fopen("vegmenu.txt","rt");
	while((v=getc(vmenu))!=EOF)
        	printf("%c",v);
        fclose(vmenu);
	printf("\n***********************************************");
	printf("\nTake order - '2'");
	printf("\n***********************************************");
	printf("\nTo Order Again - '1' || Preview order - '2'");
	printf("\n***********************************************");
	printf("\n");
}

int cal_price()
{
	P = M;
	double total_price = 0;
	while (P!=NULL)
	{
		total_price = total_price + (P->qty) * (P->unit_price);
		P = P->Next;
	}
	return total_price;
}

double price=0;
void customer_menu(){
	int choice, again, quantity;
	double total=0,price1;
    	printf("\nEnter What You Want :");
	scanf("%d",&choice);
	if(choice==1){
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 80*(quantity);
		//price = price + total;
		Insert(1, quantity, 80, total);
		printf("\nEnter Your Choice (Order again/Preview order): ");
		scanf("%d",&again);
		if(again==1)
		{
			customer_menu();
		}
		else if(again==2){
			display_order();
			printf("\n*******************************************************************************\n");
			price1 = cal_price();
			printf("Grand total : %.2lf",price1);
			printf("\n*******************************************************************************\n");
			printf("Display menu - '1' || Take order - '2' || Alter menu - '3' || View order - '4'");
			printf("\n*******************************************************************************\n"
			);
			//printf("Grand total : %.2lf",price);
		}
	}
	else if(choice==2){
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 140*(quantity);
		//price = price + total;
		Insert(2, quantity, 140, total);
		printf("\nEnter Your Choice (Order again/Preview order): ");
		scanf("%d",&again);
		if(again==1)
		{
			customer_menu();
		}
		else if(again==2)
		{
			display_order();
			printf("\n*******************************************************************************\n");
			price1 = cal_price();
			printf("Grand total : %.2lf",price1);
			printf("\n*******************************************************************************\n");
			printf("Display menu - '1' || Take order - '2' || Alter menu - '3' || View order - '4'");
			printf("\n*******************************************************************************\n"
			);
			//printf("Grand total : %.2lf",price);
		}
	}
	else if(choice==3)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 160*(quantity);
		//price = price + total;
		Insert(3, quantity, 160, total);
		printf("\nEnter Your Choice (Order again/Preview order): ");
		scanf("%d",&again);
		if(again==1)
		{
			customer_menu();
		}
		else if(again==2)
		{
			display_order();
			printf("\n*******************************************************************************\n");
			price1 = cal_price();
			printf("Grand total : %.2lf",price1);
			printf("\n*******************************************************************************\n");
			printf("Display menu - '1' || Take order - '2' || Alter menu - '3' || View order - '4'");
			printf("\n*******************************************************************************\n"
			);
			//printf("Grand total : %.2lf",price);
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 70*(quantity);
		//price = price + total;
		Insert(4, quantity, 70, total);
		printf("\nEnter Your Choice (Order again/Preview order): ");
		scanf("%d",&again);
		if(again==1)
		{
			customer_menu();
		}
		else if(again==2)
		{
			display_order();
			printf("\n*******************************************************************************\n");
			price1 = cal_price();
			printf("Grand total : %.2lf",price1);
			printf("\n*******************************************************************************\n");
			printf("Display menu - '1' || Take order - '2' || Alter menu - '3' || View order - '4'");
			printf("\n*******************************************************************************\n"
			);
			//printf("Grand total : %.2lf",price);
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 120*(quantity);
		//price = price + total;
		printf("\nEnter Your Choice (Order again/Preview order): ");
		scanf("%d",&again);
		//price = price + total;
		Insert(5, quantity, 120, total);
		if(again==1)
		{
			customer_menu();
		}
		else if(again==2)
		{
			display_order();
			printf("\n*******************************************************************************\n");
			price1 = cal_price();
			printf("Grand total : %.2lf",price1);
			printf("\n*******************************************************************************\n");
			printf("Display menu - '1' || Take order - '2' || Alter menu - '3' || View order - '4'");
			printf("\n*******************************************************************************\n"
			);
			//printf("Grand total : %.2lf",price);
		}
			
	}
	/*else if(choice==6)
	{
		system("cls");
		customer();
	}*/
	else{
		printf("Wrong Input! Re-enter THe Correct Option\n");
		customer_menu();
		}
}

void alter_menu()
{
	int id;
	P = M;
	if (P==NULL)
	{
		printf("\nNothing Ordered. Order something");
	}
	else
	{
		printf("\n*******************");
		printf("\n    ALTER MENU    ");
		printf("\n*******************");
		printf("\n 1.DELETE AN ITEM \n 2.UPDATE AN ITEM \n 3.DELETE ORDER \n 4.EXIT \n");
		printf("*******************\n\n");
		int option;
		while(1)
		{
			printf("Enter your option: ");
			scanf("%d",&option);
			if (option==1)
			{
				printf("Enter the item to be deleted: ");
				scanf("%d",&id);
				delete_item(id);
			}
			
			else if (option==2)
			{
				update_item();
			}
			
			else if(option==3)
			{
				delete_order();
			}
			
			else if(option==4)
			{
				mainmenu_copy();
			}
			
			else
			{
				printf("Enter valid number\n");
			}
		}
	}
}


void mainmenu(void)
{
	printf("\n\n***************************************************************\n");
	printf("                 WELCOME TO FOOD ORDER SYSTEM\n");
	printf("***************************************************************\n");
	printf("  1. DISPLAY MENU--> \n\n  2. CUSTOMER ORDER--> \n\n  3. ALTER MENU--> \n\n  4. DISPLAY ORDER--> \n\n  5. EXIT--> \n");
	printf("***************************************************************\n");
	while(1){
		int choice;double price1;
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				display_menu();
				break;
			case 2:
				customer_menu();
				break;
			case 3:
				alter_menu();
				break;
			case 4:
				display_order();
				printf("\n*******************************************************************************\n");
				price1 = cal_price();
				printf("Grand total : %.2lf",price1);
				mainmenu_copy();
				break;
			case 5:
				printf("\n");
				printf("**************************THANK YOU****************************\n\n");
				exit(0);
			default:
				printf("\nEnter valid choice!!!");
		}
	}
}

void mainmenu_copy()
{
	printf("\n*******************************************************************************\n");
	printf("Display menu - '1' || Take order - '2' || Alter menu - '3' || View order - '4'");
	printf("\n*******************************************************************************\n");
	while(1){
		int choice;double price1;
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				display_menu();
				break;
			case 2:
				customer_menu();
				break;
			case 3:
				alter_menu();
				break;
			case 4:
				display_order();
				printf("\n*******************************************************************************\n");
				price1 = cal_price();
				printf("Grand total : %.2lf",price1);
				mainmenu_copy();
				break;
			case 5:
				printf("\n");
				printf("**************************THANK YOU****************************\n\n");
				exit(0);
			default:
				printf("\nEnter valid choice!!!");
		}
	}
}

void delete_item(int id)
{
	int num,i=1;
	struct menu *Pre;
	num = id;
	P = M;
	Pre = P;
	if(P == NULL)
	{
		printf("Order not found\n");
	}
	else
	{
		if (i==num)
		{
			M = M->Next;
			free(P);
		}
		else
		{
			while(i!=num)
			{
				Pre = P;
				P = P->Next;
				i++;
			}
			Pre->Next = P->Next;
			free(P);
		}
		printf("Element '%d' is deleted\n",num);
	}
	mainmenu_copy();
}

void update_item()
{
	int new_qty,n,i=1;
	P = M;
	if (P==NULL)
	{
		printf("Order not found\n");
	}		
	else
	{
		printf("Enter the item: ");
		scanf("%d",&n);
		printf("Enter the new quantity: ");
		scanf("%d",&new_qty);
		
		/*if (isempty())
		{
			printf("Order is empty\n");
		}
		else
		{*/
		if (i==n)
		{
			P -> qty = new_qty;
			P -> tot =(new_qty)*(P->unit_price);
		}
		else
		{
			while (i!=n)
			{
				P = P->Next;
				i++;
			}
			P->qty =  new_qty;
			P -> tot =(new_qty)*(P->unit_price);
		}
		printf("Order updated\n");
		}
	mainmenu_copy();
}

void delete_order()
{
	struct menu *Pre;
	P = M;
	while(P->Next!=NULL)
	{
		Pre = P;
		P = P->Next;
		Pre->Next = NULL;
		free(Pre);
	}
	M = NULL;
	printf("Order deleted\n");
	mainmenu_copy();
	
}

void main()
{
	M = (struct menu*)malloc(sizeof(struct menu));
	M = NULL;
	mainmenu();
}

