#ifndef __MENU_H__
#define __MENU_H__

#include "DataBase.h"

#define MAX_STRING_SIZE 120//max size of strings in this program.

//main class - provide the main menu for the user to activate and manage the Employess database.
class Menu{
      public:
             typedef enum {ADD_EMPLOYEE = 1, REMOVE_EMPLOYEE, PRINT_ALL_EMPLOYEES, PROMOTE_EMPLOYEE, EXIT} MenuOption;
             //enum of menu options.
             void mainMenu();//the methods that run the main menu for this program. Resposible to input / ouput with the user.
             
      private:
             DataBase db;//an object of class DataBase
      
      //private menthods:
                void printOptions() const;//print all the menu options to screen.
                void addEmp();//input all the nessesary data to create a new Employess and add it to the Data-Base
                void removeEmp();//input the index and remove the asked Employee fro mthe database
                void printDB() const;//print the entire database
                void promoteEmp();//input the index and promote the asked Employee in the database.
};

#endif //__MENU_H__


