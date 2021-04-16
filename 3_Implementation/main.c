/**
 * @file main.c
 * @author Chinmayi B C(chinmayi1219@gmail.com)
 * @brief includes header file, password to login and all the functions are called
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "bankheader.h"
int main_exit;
char* display_message;
int main()
{
     char pass[10],password[10]="stepin";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {
        printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            printf(".");
        }
               
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        main();
                    }

            else if (main_exit==0)
                    {
                    display_message=fun_close();
                    printf("%s",display_message);
                    }
            else
                    {
                    printf("\nInvalid!");
                    goto login_try;
                    }

        }
        return 0;

}