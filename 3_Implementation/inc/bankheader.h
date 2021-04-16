/**
 * @file bankheader.h
 * @author Chinmayi B C (chinmayi1219@gmail.com)
 * @brief defines header files,declares all the structures and functions
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __BANKHEADER_H__
#define __BANKHEADER_H__
/**
 * @brief structure called date
 * 
 */
struct date{
    int month,day,year;

    };
    /**
     * @brief structure called bank
     * 
     */
typedef struct bank {

    char name[60];
    int account_number,age;
    int phone;
    char account_type[10];
    float amount;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }bank;
extern bank add,update,check,rem,transaction;
extern int main_exit;
/**
 * @brief declares all the functions 
 * 
 */
void menu(void);
void create_new_account();
void view_details();
void edit_details(void);
void perform_transaction(void);
void delete_account(void);
char* fun_close(void);

#endif