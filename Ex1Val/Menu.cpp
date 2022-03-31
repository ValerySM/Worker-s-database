#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h" //this class header - no need to others since they will be included in the database header

#include <iostream> //for output / input
using namespace std;

//Main and only public method of this class - run the entire program.
void Menu::mainMenu() {
     bool run = true;//do we want another iteration?
     int option;//the choosen option for the menu.
     while(run) {//while we still want to run:
                printOptions();//print the menu
                cin>>option;//get the user choise
                switch(option) {//act accordingly:
                               case ADD_EMPLOYEE: //if we want to add a new employee
                                    addEmp();//activate the methods that resposible for it
                                    break;//end of this iteration
                               case REMOVE_EMPLOYEE:
                                    removeEmp();//a private method in menu class that remove employees from the database
                                    break;
                               case PRINT_ALL_EMPLOYEES:
                                    printDB();//menu private method that print the database
                                    break;
                               case PROMOTE_EMPLOYEE:
                                    promoteEmp();//menu private method that promote a given employee
                                    break;
                               case EXIT: run = false; //we want to stop running.
                                    cout<<"Goodbye!\n";//tell the user goodbye.
                                    //since DataBase wasn't dynamically allocated, its Dtor will clean everything for us.
                                    break;
                               default: cout<<"Wrong option. Please try again!\n"; //not a supported option
                }//end switch
                  
     }//end while(run)
}//end method Menu::mainMenu()


////////////////  Private Methods:      //////////////////
//A method that print the menu to screen.
void Menu::printOptions() const {//use the enum so in case of a change we want have to change it.
     cout<<"Please choose one of the following options:\n Press\n"
         <<"----------------------------------------------------------------------\n"
         <<ADD_EMPLOYEE<<" in order to add an employee to the database."<<endl
         <<REMOVE_EMPLOYEE<<" in order to remove an employee from the database."<<endl
         <<PRINT_ALL_EMPLOYEES<<" in order to print the database."<<endl
         <<PROMOTE_EMPLOYEE<<" in order to promote an employee."<<endl
         <<EXIT<<" in order to quite the program."<<endl
         <<"----------------------------------------------------------------------\n";
}//end method Menu::printOptions()

//a method to get all the needed data to create a new Emloyee and add it to the Database.
//NOTICE: this method can be written much more efficienty, but it will demand several
//extra methods in class Employee, and I didn't want to force the class design on you.
void Menu::addEmp(){
     //variables to keep information in order to create an employee:
     char firstName[MAX_STRING_SIZE], lastName[MAX_STRING_SIZE];
     int day, month, year;
     int id, status;
     double salary;
     
     //let the user know what we need:
     cout<<"Please enter all the needed detailed in order to add a new Employee to the database\n";
     cout<<"Please enter the employee first and last name\n";
     cin>>firstName>>lastName;//get names as char*
     
     cout<<"Please enter the employess date of birth(day, month and then year)";
     cin>>day>>month>>year;//gets date for the birth date
     Date bod(day,month,year);//create the date as object
     
     cout<<"Please enter the employee ID number\n";
     cin>>id;//get user id
     
     cout<<"Please enter the employess first date of work(day, month and then year)";
     cin>>day>>month>>year;//get the date for the "starting work" date.
     Date workStarting(day,month,year);//create the date object

     cout<<"Please enter the employee salary\n";
     cin>>salary;//get salary
     
     cout<<"Please enter the employee state\n";
     cin>>status;//get status as int (index 0 for Secretary... ect...)
     
     Employee* newEmp = new Employee(firstName,lastName,bod,id,workStarting,salary,status);
               //create the new Employee dynamically - make sure you have the proper Ctor!
     
     db.addEmployee(*newEmp);//add the new employ to the database!
}//end method Menu::addEmp()

//This method input the user index and remove the asked employee from the database
void Menu::removeEmp() {
     int index;
     const Date today(4,4,2021);
     cout<<"Please enter the index of the employee you wish to remove\n";
     cin>>index;//get the index
     Employee* removed = db.removeEmployee(index);//remove the employee
     if (removed == NULL)//if it wasn't a valid index
        cout<<"Wrong index. No employee was removed\n";//alart the user
     else {
         cout<<"You just removed employee:\n";
         removed->print(today);//let the user know who was removed
         delete removed;//release the memory we accupied in the addEmp method.
     }
}//end method Menu::removeEmp()

//The method print all the database
void Menu::printDB() const {
     const Date today(4,4,2021);//current date - so it can calculate age and working lenght for all the Employess
     db.print(today);//print all the data
}//end method Menu::printDB()

//The method get the asked index and promote the asked Employee. If the index isn't valid it alart the user
void Menu::promoteEmp() {
     int index;
     const Date today(4,4,2021);
     cout<<"Please enter the index of the employee you wish to promote\n";
     cin>>index;//get the index
     Employee* promote = db.getEmployee(index);//get a pointer to that Employee
     if (promote == NULL)//if the index wasn't valid:
        cout<<"Wrong index. No employee was promoted\n";//alart the user
     else {//index valid:
          promote->promotion();//promote the Employee
          cout<<"You just promoted employee:\n";//inform the user which Employee was promoted:
          promote->print(today);
     }
}//end method Menu::promoteEmp()
