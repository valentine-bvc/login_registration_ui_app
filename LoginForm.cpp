//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "LoginForm.h"
#include <fstream>
#include "PopupBox.h"
#include "encrypter.h"
#include <sstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyLoginForm *MyLoginForm;
const String err_message {"DETAILS REQUIRED"};


void PopupShow(String ucaption, String umessage);
bool login_check(std::string username, std::string password, bool& wrong_pass);
void clear_input_boxes();
//---------------------------------------------------------------------------
__fastcall TMyLoginForm::TMyLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyLoginForm::LoginButtonClick(TObject *Sender)
{
        std::fstream saved_accounts;
			 saved_accounts.open("Data/accounts.data", ios::in);


		 if(saved_accounts.is_open() &&
			 MyLoginForm->UsernameEdit->Text != "" &&
			 MyLoginForm->PasswordEdit->Text != "" &&
			 MyLoginForm->UsernameEdit->Text != err_message &&
			 MyLoginForm->PasswordEdit->Text != err_message) {

			 MyLoginForm->UsernameEdit->Opacity = 1.0;
			 MyLoginForm->PasswordEdit->Opacity = 1.0;


			 AnsiString user = this->UsernameEdit->Text;
			 AnsiString pass = this->PasswordEdit->Text;
			 bool wrong_pass_flag{false};

			 bool found_username = login_check(static_cast<std::string>(user), static_cast<std::string>(pass), wrong_pass_flag);


			 if(found_username)  {
				if(wrong_pass_flag)
					PopupShow("Error!", "Incorrect password!");




				else
				   PopupShow("Success!", "Account found!");



             }


			 else
			   PopupShow("Error", "Account not found!");



				   clear_input_boxes();
			 }

		   else{
				if(MyLoginForm->UsernameEdit->Text  == ""){
					MyLoginForm->UsernameEdit->Opacity = 0.5;
					MyLoginForm->UsernameEdit->Text =  err_message;
				}

				 if (MyLoginForm->PasswordEdit->Text == "")   {
					 MyLoginForm->PasswordEdit->Password = false;
					 MyLoginForm->PasswordEdit->Opacity = 0.5;
					 MyLoginForm->PasswordEdit->Text =   err_message;
				 }
		   }

			saved_accounts.close();
}
//---------------------------------------------------------------------------

void PopupShow(String ucaption, String umessage) {
	MyInfoBox->Caption = ucaption;
	MyInfoBox->InfoLabel->Text = umessage;
	MyInfoBox->Show();
}




bool login_check(std::string username, std::string password, bool& wrong_pass){
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



   void clear_input_boxes(){

			MyLoginForm->PasswordEdit->Password = true;;
			MyLoginForm->UsernameEdit->Text = "";
			MyLoginForm->PasswordEdit->Text = "";

   }
void __fastcall TMyLoginForm::UsernameEditClick(TObject *Sender)
{
				if(MyLoginForm->UsernameEdit->Text == err_message) {
					MyLoginForm->UsernameEdit->Text = "";
					MyLoginForm->UsernameEdit->Opacity = 1.0;
				}


				if(MyLoginForm->PasswordEdit->Text == err_message){
					MyLoginForm->PasswordEdit->Text = "";
					MyLoginForm->PasswordEdit->Opacity = 1.0;
				}


}
//---------------------------------------------------------------------------

void __fastcall TMyLoginForm::PasswordEditClick(TObject *Sender)
{
				if(MyLoginForm->UsernameEdit->Text == err_message) {
					MyLoginForm->UsernameEdit->Text = "";
					MyLoginForm->UsernameEdit->Opacity = 1.0;
				}


				if(MyLoginForm->PasswordEdit->Text == err_message){
					MyLoginForm->PasswordEdit->Text = "";
					MyLoginForm->PasswordEdit->Opacity = 1.0;
				}

}
//---------------------------------------------------------------------------

