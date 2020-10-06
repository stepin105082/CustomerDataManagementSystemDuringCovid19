/**
*@file manage.h
*@brief CUSTOMER MANAGEMENT SYSTEM DURING COVID-19
*/

#ifndef __MANAGE_H__
#define __MANAGE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/** @brief shop struct that contains the name of the shop and the maximum no: of allowable persons*/
struct shop
{
    int shop_count;
    char shop_name[30];
};


/** @brief Employee struct with username and password */
struct Employee       
{
    char user[10];
    char pass[6];
};

/** Customer struct including name, phone, date and time
*/
struct Customer
{
    char name[20];
    char phone[10];
    char *date;
};


/** @brief function to login using user-name and password for the employee
 * @param[in] object of employee struct
 * @return 1 if login is successful
 */
int LoginCheck(char user[], char pass[]);

/**
 * @brief function to provide the local time and date
 * @return local time and date
 */

char* local_time();

/**
 * @brief function to check the no: of digits in the phone number of the customer is equal to 10
 *
 * @param[in]  object of struct Customer
 * @return  1 if TRUE
 * @note return 0 if FALSE
 */


int phone_check(struct Customer c);

/**
 * @brief To check the sanitization due to the lack of electronic components
 * @return 1 for s=1 (TRUE)
 *
 */

int sanitize();

/**
 * @brief Temperature check function
 * @return 1 if (temp<= 40) (in degree Celsius)
 *
 */

int temp_check();

#endif  /* #define __MANAGE_H__ */
