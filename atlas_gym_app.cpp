//atlas gym
#include<iostream>
#include<fstream>
#include <string.h>
#include <limits>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
using namespace std; 
struct Members //set structured data to Members 
{
	//initialize Data here using int and string  
	int  member_id;
	string member_age, member_contactnumber, member_firstname, member_surname, member_address;
}member_poket[100];

int member_pocket_id, found=0; //set member's pocket ID

void Register(){ 
	//Register()function for registering members
	system("cls"); //when user enters to register function clear screen 
	cout<<"\n\tAtlas Gym \t\t\tRegister Member\n\n";
	int member_id, set_member_id;
	member_id = member_pocket_id+1;
	//get & Set id
	cout<<"\tMember ID \t\t\t: ";
	cout<<member_id;
	member_poket[member_pocket_id].member_id = member_id;
	//get & Set first name
	cout<<"\n\tEnter Member First Name \t: ";
	cin>>member_poket[member_pocket_id].member_firstname;
	//get & Set  surname
	cout<<"\tEnter Member Surname \t\t: ";
	cin>>member_poket[member_pocket_id].member_surname;
	//get & Set  age
	cout<<"\tEnter Member Age \t\t: ";
	cin>>member_poket[member_pocket_id].member_age;
	//get & Set  address
	cout<<"\tEnter Member Address \t\t: ";
	cin>>member_poket[member_pocket_id].member_address;
	//get & Set  contact number
	cout<<"\tEnter Member Contact Number \t: ";
	cin>>member_poket[member_pocket_id].member_contactnumber;
	//Display success message to user
	cout<<"\n\tSaved to Data Store.. Thank You";
	cout<<"\n\n\tPlease Press ENTER key for Main Menu";
	member_pocket_id++; //increment member's pocket ID by adding 1 dynamically
	getchar();
	getchar();
	system("cls"); //when user enters clear screen 
}
bool Login(){ 
	//Login() check user is logged or not using bool function
	string login_info[2]; //set login info to string
	int i=0; //set integer for login_info to check line number 
	ifstream log_info_file("log.txt"); //ifstream opens a file called log.txt and set it to log_info_file
	if(log_info_file.is_open())
	{
		while(getline(log_info_file,login_info[i++])); //check for lines on log.txt file
			string login_username;
			char login_password[4];
			cout<<"\n\tAtlas Gym \t\t\tAdmin Login\n";
			cout<<"\n\tEnter Admin Username : ";
			cin>>login_username;
			cout<<"\tEnter Admin Password : ";
			//cin>>login_password;
			for(int p=0;p<5;p++)
		    {
		        login_password[p]=getch();
		        printf("*");
		    }

		if(login_username==login_info[0] && login_password==login_info[1])
			return true;
		else
		cout<<"\n\tPlease Enter Correct Password";
			system("cls");
			Login();
	}
    else
    {
        return false;
    }
}
void View(){ 
	system("cls");
	cout<<"\n\tAtlas Gym \t\t\tView Members\n";
	for(int k=0;k<member_pocket_id;k++)
	{	
		cout<<"\n\tMember			:"<<member_poket[k].member_id;
		cout<<"\n\tFirst Name		:"<<member_poket[k].member_firstname;
		cout<<"\n\tSur Name 		:"<<member_poket[k].member_surname;
		cout<<"\n\tAddress        		:"<<member_poket[k].member_address;
		cout<<"\n\tAge        		:"<<member_poket[k].member_age;
		cout<<"\n\tContact No		:"<<member_poket[k].member_contactnumber;
		cout<<"\n\n";
		
	}
	cout<<"\n\n\tPlease Press ENTER key for Main Menu";
	getchar();
	getchar();
}
void Search(){ 
	system("cls");
	int member_search_id;
	system("cls");
	cout<<"\n\tAtlas Gym \t\t\tSearch Member\n";
	cout<<"\n\tEnter Member ID to Search : ";
	cin>>member_search_id;
	for(int k=0;k<member_pocket_id;k++)
	{
		if(member_search_id==member_poket[k].member_id)
		{
			cout<<"\n\tMember		:"<<member_poket[k].member_id;
			cout<<"\n\tFirst Name	:"<<member_poket[k].member_firstname;
			cout<<"\n\tSurname		:"<<member_poket[k].member_surname;
			cout<<"\n\tAddress		:"<<member_poket[k].member_address;
			cout<<"\n\tAge		:"<<member_poket[k].member_age;
			cout<<"\n\tContact Number	:"<<member_poket[k].member_contactnumber;

			found = 1;
			break;
		}
	}
	if(!found) cout<<"\n\tNo Member Found"<<endl;
	cout<<"\n\n\tPlease Press ENTER key for Main Menu";
	getchar();
	getchar();
}
void Update(){ 
	system("cls");
	
	char choice;
	int found=0;

	do {
		system("cls");
		int m,p;
		cout<<"\n\tAtlas Gym \t\t\tUpdate Member Details\n";
		cout<<"\n\tEnter Member ID to Update : ";
		cin>>m;

		for(int k=0;k<member_pocket_id;k++) {
			if(m==member_poket[k].member_id)
			{
				p=k;
	
				cout<<"\n\tMember  ID \t\t: "<<member_poket[p].member_id;
				cout<<"\n\tFirst Name \t\t: "<<member_poket[p].member_firstname;
				cout<<"\n\tSurname \t\t: "<<member_poket[p].member_surname;
				cout<<"\n\tAddress \t\t: "<<member_poket[p].member_address;
				cout<<"\n\tMember Age \t\t: "<<member_poket[p].member_age;
				cout<<"\n\tMember Contact No \t: "<<member_poket[p].member_contactnumber;
				cout<<"\n\t-----------------------------------------------------\n";
	
	            cout<<"\n\t1 - Change First name ";
	            cout<<"\n\t2 - Change Surname ";
	            cout<<"\n\t3 - Change Address ";
	            cout<<"\n\t4 - Change Age ";
	            cout<<"\n\t5 - Change Contact No ";
	            cout<<"\n\t6 - Enter Different ID";
	            cout<<"\n\t7 - Main Menu";
	            cout<<"\n\n\tEnter the choice    : ";
	
	            cin>>choice;
	
			switch(choice)
			{
				case '1':
					cout<<"\n\tEnter New First Name : ";
					cin>>member_poket[p].member_firstname;
					cout<<"\n\tFirst Name Updated";
					break;
					Update();
				case '2':
					cout<<"\n\tEnter New Surname : ";
					cin>>member_poket[p].member_surname;
					cout<<"\n\tSurname Updated";
					break;
				case '3':
					cout<<"\n\tEnter New Address : ";
		       		cin>>member_poket[p].member_address;
					cout<<"\n\tAddress Updated";
					break;
				case '4':
					cout<<"\n\tEnter the Age : ";
		       		cin>>member_poket[p].member_age;
					cout<<"\n\tupdated successfully";
					break;
				case '5':
					cout<<"\n\tEnter the Contact No : ";
		       		cin>>member_poket[p].member_contactnumber;
					cout<<"\n\tupdated successfully";
					break;
				case '6':
					break;
				
				case '7':
					return;
			}
	        	found = 1;
	            break;
			}
		}
        if(found==0) {
            cout<<"\n\tSorry Member Not Found";
        }
	}while( choice!=7);
	cout<<"\n\treturn home";
	getchar();
	getchar();
}
void Help(){
	system("cls");
	cout<<"\n\tAtlas Gym \t\t\tHelp";
	cout<<"\n\n\t1 - Register Member \n\tYou can Register a Member from this View. After you done adding Member Details \n\tPlease Press ENTER key to Save.";
	cout<<"\n\t-----\n";
	cout<<"\n\t2 - View Member \n\tYou can View All Member from this View. \n\tPlease Press ENTER key to Exit from this View to Main Menu.";
	cout<<"\n\t-----\n";
	cout<<"\n\t3 - Update Member Details \n\tYou can update Members Details from this View.";
	cout<<"\n\t Option 1 - Change First Name - You Can Change First Name of a Member.";
	cout<<"\n\t Option 2 - Change Surname - You Can Change Surname of a Member.";
	cout<<"\n\t Option 3 - Change Address - You Can Change Address of a Member.";
	cout<<"\n\t Option 4 - Change Age - You Can Change Age of a Member.";
	cout<<"\n\t Option 5 - Change Contact Number - You Can Change Contact Number of a Member.";
	cout<<"\n\t Option 6 - Enter Different ID - You Can Enter Different ID for change another Member Details.";
	cout<<"\n\t Option 7 - Main Menu - You Can Go back to Main Menu";
	cout<<"\n\t-----\n";
	cout<<"\n\t4 - Search Member \n\tYou can Simply Search for a Member.";
	cout<<"\n\t-----\n";
	cout<<"\n\t5 - Help \n\tWooha, You are Here For Help.";
	cout<<"\n\t-----\n";
	cout<<"\n\t6 - Exit \n\tSafely Exit from Atlas Gym Application.";
	cout<<"\n\n\tPlease Press ENTER key for Main Menu";
	getchar();
	getchar();	
}
void Error(){
	//Error() checks for cin fails if user type fail will show default error message
	cout << "\n\tPlease Enter Valid Information.\n\n";
	//and this line will clear the code
    cin.clear(); 
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
}

//define ID for student loop
int id;
int main(){
	//check user logged or not 
	if(Login()) {
		system("cls"); //when user enters clear screen 
		int check_menu_exit; //menu exit int
		id=0; //add start point id for check_menu_exit
		do //start menu in do 
		{
			system("cls");
			cout<<"\n\tAtlas Gym \t\t\tGet in the Best Shape of your Life.";
			cout<<"\n";
			cout<<"\n\t1 - Register Member";
			cout<<"\n\t2 - View Members";
			cout<<"\n\t3 - Update Member Details";
			cout<<"\n\t4 - Search Member";
			cout<<"\n\t5 - Help";
			cout<<"\n\t6 - Exit";
			cout<<"\n\n\tEnter Your Choice: ";
			cin>>check_menu_exit; //set choice to check_menu_exit
			system("cls"); //clear the screen 
			//switch case check what user enters
			switch(check_menu_exit)
			{
				//if case 1 do this function 
				case 1:
				Register();
				break;
				
				//if case 2 do this function 
				case 2:
				View();
				break;
				
				//if case 3 do this function 
				case 3:
				Update();
				break;
				
				//if case 4 do this function 
				case 4:
				Search();
				break;
				
				//if case 5 do this function 
				case 5:
				Help();
				break;
				
				//if case 6 do this function 
				case 6:
				break;
			}
			if (cin.fail()) //if user pressed deadly answer show error message 
			{
				Error(); //error message set to a function so called here 
			}
		}
		//exit when 6 pressed 
		while(check_menu_exit!=6);
	}
    return 0;
	getchar();
	getchar();
}
