# TEST PLAN

*	Features to be tested
   a)	A valid login by the employee.\
   b)	Checking the body temperature of the customer and proper sanitization.\
   c)	Proper social distance monitoring.\
   d)	Ensure the proper addition access of the document containing data.
   
   
   
   ## TEST CASES
   
   |**TEST CASE ID** |**ACTION**                                                    |**INPUTS**                              |**ACTUAL OUTPUT**                             |**EXPECTED OUTPUT**                             |**STATUS**|
   |-----------------|--------------------------------------------------------------|----------------------------------------|----------------------------------------------------|------------------------------------------------|--------  |
   |TC_01            |Employee Login                                                |User-name='mec' Password='123'          |“Login successful"                             |“Login successful”                              |PASS      |
   |TC_02            |Employee Login                                                |User-name='mac' Password='456'          |“Invalid Login, Please try again”             |“Invalid Login, Please try again”               |PASS      |
   |TC_03            |Enter new customer details page:- phone number check function |User enters- ‘0123456789’               |Valid Number                                    |Valid Number                                    |PASS      |
   |TC_04            |Enter new customer details page:- temperature check function  |The value of temperature=38<sup>o</sup>C|Below 41<sup>o</sup>C:- function returns value 1     |Below 41<sup>o</sup>C:- function returns value 1|PASS      |
   |TC_05            |Enter new customer details page:- sanitization check function |Yes                                     |Returns True                                    |Returns True                                    |PASS      |



### OUTPUT
![Test output](https://github.com/stepin105082/CustomerDataManagementSystemDuringCovid19/blob/master/4_TestPlanAndOutput/test_op.png)


