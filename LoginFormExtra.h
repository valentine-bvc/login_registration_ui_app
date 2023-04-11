  //////////////////////////////////////////////////////////////////////////
  /////////EXTRA FUNCTIONS AND VARIABLES FOR *MyLoginForm* /////////
  ////////////////////////////////////////////////////////////////////////






#pragma hdrstop

#include "LoginForm.h"
#include <fstream>
#include "PopupBox.h"
#include "encrypter.h"
#include <sstream>
#include <string>

//custom functions
void clear_on_login_error();  //clears text box if error message is displaying
void clear_all_login_input();  //clear all fields, activate password and limit age number
bool login_check(std::string username, std::string password, bool& wrong_pass); //checks if account and passwords match with user input
void reset_lopacity(); //reset text opacity to default for all text boxes
bool ready_to_login();  //check if all fields are valid for starting the login process
std::string ansi_to_string(AnsiString st); //convert Ansistring to std::string
void input_required_login_error (); //handle the fields requiring warning



//custom variables
const String login_err_message {"DETAILS REQUIRED"};




////////////////////////////////////////////////////////////////////////////

void clear_on_login_error(){
				if(MyLoginForm->UsernameEdit->Text == login_err_message) {
					MyLoginForm->UsernameEdit->Text = "";
					MyLoginForm->UsernameEdit->Opacity = 1.0;
				}


				if(MyLoginForm->PasswordEdit->Text == login_err_message){
					MyLoginForm->PasswordEdit->Text = "";
					MyLoginForm->PasswordEdit->Opacity = 1.0;
				}

}


bool login_check(std::string username, std::string password, bool& wrong_pass){
//checks if account and passwords match with user input
	   std::fstream saved_accounts;
	   saved_accounts.open("Data/accounts.data", ios::in);
	   std::string line {};
	   std::string word {};
	   if(!saved_accounts.is_open()) {
			return false;
	   }

	   while(getline(saved_accounts,line)){

		 std::stringstream ss{decode(line)};
		 for(size_t i {}; i < 3 ; i++)  {
			  word.clear();
			  getline(ss, word, ',');
		 }
		 if(word == username) {
		 std::stringstream ss{decode(line)};
		   for(size_t i {}; i <= 3 ; i++)  {
			  word.clear();
			  getline(ss, word, ',');
		   }

			  if(word == password){
			  saved_accounts.close();
				return true;
			  }
			  else      {
				 wrong_pass = true;
				 return true;
			  }



		 }

	   }
			 saved_accounts.close();
			 return false;
}
   void clear_all_login_input(){
           MyLoginForm->PasswordEdit->Password = true;
			MyLoginForm->UsernameEdit->Text = "";
			MyLoginForm->PasswordEdit->Text = "";

   }




   void reset_lopacity(){
//reset text opacity to default for all text boxes
  MyLoginForm->PasswordEdit->Password = true;
  MyLoginForm->UsernameEdit->Opacity = 1.0;
  MyLoginForm->PasswordEdit->Opacity = 1.0;

}


bool ready_to_login(){
//show message box with custom information
       if(MyLoginForm->UsernameEdit->Text != "" &&
		  MyLoginForm->PasswordEdit->Text != "" &&
		  MyLoginForm->UsernameEdit->Text != login_err_message &&
		  MyLoginForm->PasswordEdit->Text != login_err_message)
			 return true;

	   return false;
}


std::string ansi_to_string(AnsiString st){
//convert Ansistring to std::string
  return std::string(st.c_str());
}

void input_required_login_error (){
 //handle the fields requiring warnin
				if(MyLoginForm->UsernameEdit->Text  == "" ||
				   MyLoginForm->UsernameEdit->Text  == login_err_message){
					MyLoginForm->UsernameEdit->Opacity = 0.5;
					MyLoginForm->UsernameEdit->Text =  login_err_message;
				}

				 if (MyLoginForm->PasswordEdit->Text == "" ||
					 MyLoginForm->PasswordEdit->Text  == login_err_message)   {
					 MyLoginForm->PasswordEdit->Password = false;
					 MyLoginForm->PasswordEdit->Opacity = 0.5;
					 MyLoginForm->PasswordEdit->Text =   login_err_message;
				 }

}
