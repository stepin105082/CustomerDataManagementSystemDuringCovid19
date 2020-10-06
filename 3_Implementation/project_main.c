/**
* project_main.c
*@brief Main file for Customer Management System
*/
#include "manage.h"

static int count=0;
static int max_count=0;   
static int option_flag=0;
static int customer_flag=0;
static char s_name[30];
static int login_flag=0;

void new_customer();
void view();
void count_check();
void anyone_left();
void customer_mgmt();
void options();

/** @brief Function to enter employee details*/
void write_emp_details()
{
    struct Employee e;
    int n,i=1;
    char ch[40];
    FILE *fptr;
    fptr=fopen("emp_cred.txt","w");
    printf("\n\tEnter number of employees : ");
    scanf("%d",&n);
    getchar();
    while(i<=n)
    {
    system("cls");
    printf("\n\tEnter employee %d username: ",i);
    scanf("%s",&e.user);///
    printf("\n\tEnter new password: ");
    scanf("%s",&e.pass);///  
    if(i==1)
        fprintf(fptr," %s%s\n",e.user,e.pass); 
    else
        fprintf(fptr,"%s%s\n",e.user,e.pass);
    i++;
    }
    fclose(fptr);
}

/**@brief function to enter shop details like name and maximum count of allowable persons*/
void write_shop_details()
{   
    system("cls");
    struct shop s;
    printf("\n\n\t\tEnter shop name :");
    //getchar();
    scanf("%[^\n]%*c",&s.shop_name);////
    printf("\n\t\tEnter allowbale customer count :");
    scanf("%d",&s.shop_count);
    FILE *fptr;
    fptr=fopen("shop_details.txt","w");
    fprintf(fptr," %d\n%s\n",s.shop_count,s.shop_name);
    fclose(fptr);
}


void view_shop_details()
{   
    FILE *fp;
    fp=fopen("shop_details.txt","r+");
    if(fp==NULL)
        printf("\n Failed");
    fscanf(fp,"%d\n",&max_count);
    fgets(s_name,30,fp);
    fclose(fp);
      
}

/**< function to go back to options in between entering new customer details */

int go_back()
{
    if(count!=0)
    {
        char ch1;
        printf("\nDo you want to go back to options menu? (y/n) :");
        scanf("%s",&ch1);
        if(ch1=='Y' || ch1=='y')
            return 1;
    }
    return 0;
}

/** checks the no:of persons inside the shop is less than or equal to 5
 *
 */

void count_check()
{
    anyone_left();
    if (count<max_count)
    {
        if(option_flag==0 && customer_flag==1)
        {
            printf("You can enter \n");
            count++;
            customer_flag=0;
        }
        else
            option_flag=0;
        int f=go_back();
        if(f==1)
            options();
        else
            new_customer();
    }
    else
    {
        printf("Entry restricted\n");
        while(count==max_count)
        {
            count_check();
        }
    }
}

/** The function to check whether any  of the customers has left the shop */

void anyone_left()
{
    char ch='y';
    while((ch=='y' || ch=='Y') && count!=0)
    {
        printf("Has anyone left?");
        scanf("%s", &ch);
        if(ch=='Y'||ch=='y')
            if(count!=0)
                count--;
       
    }
}

/** List of options */
void options()
{   system("cls");
    int n;
    option_flag=1;
    printf("\n\t\t   Welcome to ");
    puts(s_name);
    printf("\n\t\t\t Select option ");
    printf("\n\n\t 1.New Customer details entry");
    printf("\n\t 2.View Customer details");
    printf("\n\t 3.Exit");
    printf("\n\n\t Enter an option: ");
    scanf("%d", &n);
    system("cls");

    switch(n)
    {
        case 1:
        {
           customer_mgmt();
           break;
        }
         case 2:
         {
             view();
             break;
         }
         case 3:
         {
            system("cls");
         }
    }
}


void customer_mgmt()             /**< option 1 */
{
    if (count<1)
        new_customer();
    else
        count_check();
}

/** the function to enter new customer details */

void new_customer()
{
    if(count<=5)
    {
        struct Customer c;
        printf("Enter name:");
        getchar();
        gets(c.name);
        printf("Enter phone number:");
        scanf("%s",&c.phone);
        while(!phone_check(c))
        {
            printf("Enter a valid phone number:");
            scanf("%s",&c.phone);
        }
        c.date=local_time();
        FILE *fptr;
        fptr = fopen ("Customer_details.csv", "a+");
        if (fptr == NULL)
        {
            fprintf(stderr, "\nError in opening file\n");
            exit(1);
        }

        fprintf(fptr,"%s%s,%s,%s%s","",c.date,c.name,c.phone,"\n");
        customer_flag=1;
        fclose(fptr);
        if(!temp_check())
            customer_mgmt();
    }
    option_flag=0;
    count_check();

}

/** function to view the details of customers - option 2 */

void view()
{
    FILE *fptr;
    fptr=fopen("Customer_details.csv","r");
    char buffer[100];
    if(fptr==NULL)
    {
        printf("Error in opening file");
        exit(1);
    }
    while(fgets(buffer, 100, fptr))
    {
        printf("%s\n",buffer);
    }
    fclose(fptr);
    system("pause");
    options();
}

/** @brief main function
 *
 * @param void
 * @return 0
 *
 */


int main()
{
    system("cls");

    FILE *f;
    f=fopen("emp_cred.txt","r");
    if(f==NULL)
        write_emp_details();
    fclose(f);

    FILE *fp;
    fp=fopen("shop_details.txt","r");
    if(fp==NULL)
    {
        write_shop_details();
        login_flag=1;
    }
    fclose(fp);
     int x=0;
    do                                     // Finite attempts to login (3)...
    {   struct Employee e;
     if(login_flag==1)
          getchar();
    printf("\n\t\t\tUsername : ");
    scanf("%s",&e.user);
    printf("\t\t\tPassword : ");
    scanf("%s",&e.pass);
    system("cls");
    int l=LoginCheck(e.user,e.pass);
    if(l)  //login Successful
    {
        view_shop_details();
        options();
    }
    else
        printf("\nLogin Failed !");
	x++;
    }while(x<3);
    return 0;  
}
