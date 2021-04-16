/**
 * @file bank_operations.c
 * @author Chinmayi B C (chinmayi1219@gmail.com)
 * @brief various operations performed on bank account
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//including bankheader.h
#include "bankheader.h"
bank add,update,check,rem,transaction;
int main_exit;
char* display_message;
/**
 * @brief to display menu which lists all the operations available to perform and user can choose any one among them and the system will perform the operation associated with it.
 * 
 */
void menu(void)
{   
    int choice;
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:create_new_account();
        break;
        case 2:edit_details();
        break;
        case 3:perform_transaction();
        break;
        case 4:view_details();
        break;
        case 5:delete_account();
        break;
        case 6: display_message=fun_close();
                printf("%s",display_message);
        break;
        default:printf("Invalid choice");
        break;
    }
}
/**
 * @brief Create a new account. Accepts required information from the user. If account number is new then successfully creates a account else invalid is displayed. 
 * 
 */
void create_new_account()
{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.account_number);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",&add.account_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.phone,add.account_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.account_number==add.account_number)
            {
                printf("Account no. already in use!");
                goto account_no;

            }
    }
    add.account_number=check.account_number;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amount);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.account_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.phone,add.account_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            {
                 display_message=fun_close();
                printf("%s",display_message);
            }
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
/**
 * @brief To display the details of the existing account
 * 
 */
void view_details()
{
     FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    printf("\nACC. NO.\tNAME\t\t\tPHONE\t\t\tBALANCE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d",&add.account_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.phone,add.account_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t%10s\t\t\t%d\t\t\t%.1f",add.account_number,add.name,add.phone,add.amount);
           test++;
       }

    fclose(view);
    if (test==0)
        {  
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            {
                 display_message=fun_close();
                printf("%s",display_message);
            }
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
/**
 * @brief to edit details of the existing account. Account number is taken as input then name or phone number can be changed.
 * 
 */
void edit_details(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account number of the customer whose info you want to change:");
    scanf("%d",&update.account_number);
    while(fscanf(old,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d",&add.account_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.phone,add.account_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.account_number==update.account_number)
        {  
            test=1;
            printf("\nWhich information do you want to change?\n1.Name\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            if(choice==1)
                {printf("Enter the new name:");
                scanf("%s",update.name);
                fprintf(newrec,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,update.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.phone,add.account_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%d",&update.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,update.phone,add.account_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
   
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.phone,add.account_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   
            printf("\nRecord not found!!\a\a\a");
            edit_details_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                {
                 display_message=fun_close();
                printf("%s",display_message);
                }
                else if(main_exit==0)
                    edit_details();
                else
                    {printf("\nInvalid!\a");
                    goto edit_details_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else
            {
                 display_message=fun_close();
                printf("%s",display_message);
            }
        }
}
/**
 * @brief performs transactions like withdraw or deposit only if the account is not fixed
 * 
 */
void perform_transaction(void)
{
int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.account_number);
    while (fscanf(old,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d",&add.account_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.phone,add.account_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.account_number==transaction.account_number)
            {   test=1;
                if(strcmpi(add.account_type,"fixed1")==0||strcmpi(add.account_type,"fixed2")==0||strcmpi(add.account_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                   
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amount);
                    add.amount+=transaction.amount;
                    fprintf(newrec,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.phone,add.account_number,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amount);
                    if(transaction.amount>add.amount)
                    {
                        printf("\n\n Failed to withdraw");
                        menu();
                    }
                    else
                    {
                    add.amount-=transaction.amount;
                    fprintf(newrec,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.phone,add.account_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                    }
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.phone,add.account_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       perform_transaction_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      if (main_exit==0)
        perform_transaction();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
    {
         display_message=fun_close();
        printf("%s",display_message);
    }
        
    else
    {
        printf("\nInvalid!");
        goto perform_transaction_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else
            {
                 display_message=fun_close();
                printf("%s",display_message);
            }
   }

}
/**
 * @brief close function
 * 
 * @return char* 
 */
char* fun_close(void)
{   
    char* message="Have a nice day!";
    return message;
}
/**
 * @brief deletes an existing account
 * 
 */
void delete_account(void)
{
FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.account_number);
    while (fscanf(old,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d",&add.account_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.phone,add.account_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.account_number!=rem.account_number)
            fprintf(newrec,"%d %s %d/%d/%d %d %d %s %f %d/%d/%d\n",add.account_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.phone,add.account_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
            test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            delete_account_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    {
                     display_message=fun_close();
                     printf("%s",display_message);
                    }
                else if(main_exit==0)
                    delete_account();
                else
                    {

                    printf("\nInvalid!\a");
                    goto delete_account_invalid;
                    }
        }
    else
        {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else
             display_message=fun_close();
             printf("%s",display_message);
        }

}