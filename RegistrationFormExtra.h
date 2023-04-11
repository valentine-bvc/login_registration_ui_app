  //////////////////////////////////////////////////////////////////////////
  /////////EXTRA FUNCTIONS AND VARIABLES FOR *MyRegistrationForm* /////////
  ////////////////////////////////////////////////////////////////////////


#pragma hdrstop

//#include "MainForm.h"
#include "RegistrationForm.h"
#include "PopupBox.h"
#include "encrypter.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

//custom functions
void clear_on_error(); //clears text box if error message is displaying
void clear_all_input();  //clear all fields, activate password and limit age number
bool find_user(std::string); //check if the username is already registered
bool is_digits(const std::string &str);  //check if age field is valid
std::string ansi_to_string(AnsiString st); //convert Ansistring to std::string
bool ready_to_register(const std::string& age);  //check if all fields are valid for registering a new user
void input_required_error (const std::string& age); //handle the fields requiring warning
void reset_opacity();     //reset text opacity to default for all text boxes


//custom variables
const String err_message {"DETAILS REQUIRED"};
const  String err_age {"AGE REQUIRED"};


 ///////////////////////////////////////////////////////////////////////////////


 void clear_on_error(){
 // clears text box if error message is displaying
			 if(MyRegistrationForm->NameEdit->Text == err_message)
				   MyRegistrationForm->NameEdit->Text = "";

			 if(MyRegistrationForm->AgeEdit->Text ==  err_message ||
			    MyRegistrationForm->AgeEdit->Text ==  err_age)  {
				   MyRegistrationForm->AgeEdit->Text = "";
				   MyRegistrationForm->AgeEdit->MaxLength = 2;   }

			 if(MyRegistrationForm->UsernameEdit->Text == err_message)
				   MyRegistrationForm->UsernameEdit->Text = "";

			 if(MyRegistrationForm->PasswordEdit->Text == err_message) {
				MyRegistrationForm->PasswordEdit->Password = true;
				MyRegistrationForm->PasswordEdit->Text = "";

			}

 }






   void clear_all_input(){
	//clear all fields, activate password and limit age number

			MyRegistrationForm->PasswordEdit->Password = true;
			MyRegistrationForm->AgeEdit->MaxLength = 2;
			MyRegistrationForm->NameEdit->Text = "";
			MyRegistrationForm->AgeEdit->Text = "";
			MyRegistrationForm->UsernameEdit->Text = "";
			MyRegistrationForm->PasswordEdit->Text = "";

   }
void __fastcall TMyRegistrationForm::FormClose(TObject *Sender, TCloseAction &Action)

{
		   clear_all_input();

}
//---------------------------------------------------------------------------

bool find_user(std::string target){
//check if the username is already registered
	   std::fstream saved_accounts;
	   saved_accounts.open("Data/accounts.data", ios::in);
	   std::string line {};
	   std::string word {};
	   if(!saved_accounts.is_open())
			return true;


	   while(getline(saved_accounts,line)){

		 std::stringstream ss{decode(line)};
		 for(size_t i {}; i < 3;i++)  {
			  word.clear();
			  getline(ss, word, ',');
		 }
		 if(word == target) {
		 saved_accounts.close();
			return true;
		 }

	   }
			 saved_accounts.close();
			 return false;
}

bool is_digits(const std::string &str)
{
//check if age field is valid
	return str.find_first_not_of("0123456789") == std::string::npos;
}


std::string ansi_to_string(AnsiString st){
//convert Ansistring to std::string
  return std::string(st.c_str());
}

bool ready_to_register(const std::string& age){
//check if all fields are valid for registering a new user

if(MyRegistrationForm->NameEdit->Text != "" &&
   MyRegistrationForm->AgeEdit->Text != "" &&
   MyRegistrationForm->UsernameEdit->Text != "" &&
   MyRegistrationForm->PasswordEdit->Text != "" &&
   MyRegistrationForm->NameEdit->Text != err_message &&
   MyRegistrationForm->AgeEdit->Text != err_message &&
   MyRegistrationForm->UsernameEdit->Text != err_message &&
   MyRegistrationForm->PasswordEdit->Text != err_message &&
   MyRegistrationForm->AgeEdit->Text != err_age &&
   is_digits(age))
	 return true;


 return false;

}

void input_required_error (const std::string& age) {
//handle the fields required warning
				if(MyRegistrationForm->NameEdit->Text == "" ||
				   MyRegistrationForm->NameEdit->Text == err_message) {
					MyRegistrationForm->NameEdit->Opacity = 0.5;
					MyRegistrationForm->NameEdit->Text = err_message;
				 }


				 if(MyRegistrationForm->AgeEdit->Text == "" || !is_digits(age))      {
					MyRegistrationForm->AgeEdit->Opacity = 0.5;
					MyRegistrationForm->AgeEdit->MaxLength = 30;
					MyRegistrationForm->AgeEdit->Text = err_age;
				 }

				 if(MyRegistrationForm->UsernameEdit->Text  == "" ||
				    MyRegistrationForm->UsernameEdit->Text == err_message) {
					MyRegistrationForm->UsernameEdit->Opacity = 0.5;
					MyRegistrationForm->UsernameEdit->Text =  err_message;
				 }

				 if (MyRegistrationForm->PasswordEdit->Text == "" ||
					 MyRegistrationForm->PasswordEdit->Text == err_message)   {
					 MyRegistrationForm->PasswordEdit->Opacity = 0.5;
					 MyRegistrationForm->PasswordEdit->Password = false;
					 MyRegistrationForm->PasswordEdit->Text =   err_message;
				 }
}

void reset_opacity(){
//reset text opacity to default for all text boxes
  MyRegistrationForm->NameEdit->Opacity = 1.0;
  MyRegistrationForm->AgeEdit->Opacity = 1.0;
  MyRegistrationForm->UsernameEdit->Opacity = 1.0;
  MyRegistrationForm->PasswordEdit->Opacity = 1.0;
}



