//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "RegistrationForm.h"
#include "PopupBox.h"
#include "encrypter.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
const String err_message {"DETAILS REQUIRED"};

void clear_input();
bool check_user(std::string);
bool is_digits(const std::string &str);
//---------------------------------------------------------------------------
__fastcall TMyRegistrationForm::TMyRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyRegistrationForm::RegisterButtonClick(TObject *Sender)
{
			 std::fstream saved_accounts;
			 saved_accounts.open("Data/accounts.data", ios::app);
			 AnsiString age_c = MyRegistrationForm->AgeEdit->Text;
			 const std::string age_check =  static_cast<std::string>(age_c);

			 if(saved_accounts.is_open() &&
			 MyRegistrationForm->NameEdit->Text != "" &&
			 MyRegistrationForm->AgeEdit->Text != "" &&
			 MyRegistrationForm->UsernameEdit->Text != "" &&
			 MyRegistrationForm->PasswordEdit->Text != "" &&
			 MyRegistrationForm->NameEdit->Text != err_message &&
			 MyRegistrationForm->AgeEdit->Text != err_message &&
			 MyRegistrationForm->UsernameEdit->Text != err_message &&
			 MyRegistrationForm->PasswordEdit->Text != err_message &&
			 is_digits(age_check)) {



			  AnsiString name = MyRegistrationForm->NameEdit->Text;
			  AnsiString age = MyRegistrationForm->AgeEdit->Text;
			  AnsiString username = MyRegistrationForm->UsernameEdit->Text;
			  AnsiString password = MyRegistrationForm->PasswordEdit->Text;

			  std::string target = static_cast<std::string>(username);



			  if(check_user(target) == false){
				std::string send =  static_cast<std::string>(name) + "," + static_cast<std::string>(age) + "," + static_cast<std::string>(username) + "," + static_cast<std::string>(password);
			  saved_accounts << encode(send) << "\n";
			  MyInfoBox->Caption =  "Success!";
			  MyInfoBox->InfoLabel->Text =  "Account registered!";
			  MyInfoBox->Show();

			  this->Close();
			   }
			   else {
				  MyInfoBox->Caption =  "Error!";
			  MyInfoBox->InfoLabel->Text =  "Username already registered!";
			  MyInfoBox->Show();



               }




				  clear_input();





			 }

			 else {
				 if(MyRegistrationForm->NameEdit->Text == "") {
					MyRegistrationForm->NameEdit->Opacity = 0.5;
					MyRegistrationForm->NameEdit->Text = err_message;
				 }


				 if(MyRegistrationForm->AgeEdit->Text == "" || !is_digits(age_check))      {
					MyRegistrationForm->AgeEdit->Opacity = 0.5;
					AgeEdit->MaxLength = 30;
					if(is_digits(age_check))
						MyRegistrationForm->AgeEdit->Text = err_message;
					else
						 MyRegistrationForm->AgeEdit->Text = "NUMBERS REQUIRED";
				 }

				 if(MyRegistrationForm->UsernameEdit->Text  == "") {
					MyRegistrationForm->UsernameEdit->Opacity = 0.5;
					MyRegistrationForm->UsernameEdit->Text =  err_message;
				 }

				 if (MyRegistrationForm->PasswordEdit->Text == "")   {
					 MyRegistrationForm->PasswordEdit->Opacity = 0.5;
					 MyRegistrationForm->PasswordEdit->Password = false;
					 MyRegistrationForm->PasswordEdit->Text =   err_message;
				 }


			 }
			  saved_accounts.close();

}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::NameEditClick(TObject *Sender)
{
	if(MyRegistrationForm->NameEdit->Text == err_message)
				   MyRegistrationForm->NameEdit->Text = "";

			 if(MyRegistrationForm->AgeEdit->Text ==  err_message)  {
				   MyRegistrationForm->AgeEdit->Text = "";
				   MyRegistrationForm->AgeEdit->MaxLength = 2;   }

			 if(MyRegistrationForm->UsernameEdit->Text == err_message)
				   MyRegistrationForm->UsernameEdit->Text = "";

			 if(MyRegistrationForm->PasswordEdit->Text == err_message) {
				MyRegistrationForm->PasswordEdit->Text = "";
				MyRegistrationForm->PasswordEdit->Password = true;
			}
			 MyRegistrationForm->NameEdit->Opacity = 1.0;
			 MyRegistrationForm->AgeEdit->Opacity = 1.0;
			 MyRegistrationForm->UsernameEdit->Opacity = 1.0;
			 MyRegistrationForm->PasswordEdit->Opacity = 1.0;
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::AgeEditClick(TObject *Sender)
{
	 if(MyRegistrationForm->NameEdit->Text == err_message)
				   MyRegistrationForm->NameEdit->Text = "";

			 if(MyRegistrationForm->AgeEdit->Text ==  err_message ||
			MyRegistrationForm->AgeEdit->Text ==  "NUMBERS REQUIRED" )  {
				   MyRegistrationForm->AgeEdit->Text = "";
				   MyRegistrationForm->AgeEdit->MaxLength = 2;   }

			 if(MyRegistrationForm->UsernameEdit->Text == err_message)
				   MyRegistrationForm->UsernameEdit->Text = "";

			 if(MyRegistrationForm->PasswordEdit->Text == err_message) {
				MyRegistrationForm->PasswordEdit->Text = "";
				MyRegistrationForm->PasswordEdit->Password = true;
			}

			 MyRegistrationForm->NameEdit->Opacity = 1.0;
			 MyRegistrationForm->AgeEdit->Opacity = 1.0;
			 MyRegistrationForm->UsernameEdit->Opacity = 1.0;
			 MyRegistrationForm->PasswordEdit->Opacity = 1.0;
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::UsernameEditClick(TObject *Sender)
{
		if(MyRegistrationForm->NameEdit->Text == err_message)
				   MyRegistrationForm->NameEdit->Text = "";

			 if(MyRegistrationForm->AgeEdit->Text ==  err_message)  {
				   MyRegistrationForm->AgeEdit->Text = "";
				   MyRegistrationForm->AgeEdit->MaxLength = 2;   }

			 if(MyRegistrationForm->UsernameEdit->Text == err_message)
				   MyRegistrationForm->UsernameEdit->Text = "";

			 if(MyRegistrationForm->PasswordEdit->Text == err_message) {
				MyRegistrationForm->PasswordEdit->Text = "";
				MyRegistrationForm->PasswordEdit->Password = true;
			}

			 MyRegistrationForm->NameEdit->Opacity = 1.0;
			 MyRegistrationForm->AgeEdit->Opacity = 1.0;
			 MyRegistrationForm->UsernameEdit->Opacity = 1.0;
			 MyRegistrationForm->PasswordEdit->Opacity = 1.0;
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::PasswordEditClick(TObject *Sender)
{
		if(MyRegistrationForm->NameEdit->Text == err_message)
				   MyRegistrationForm->NameEdit->Text = "";

			 if(MyRegistrationForm->AgeEdit->Text ==  err_message)  {
				   MyRegistrationForm->AgeEdit->Text = "";
				   MyRegistrationForm->AgeEdit->MaxLength = 2;   }

			 if(MyRegistrationForm->UsernameEdit->Text == err_message)
				   MyRegistrationForm->UsernameEdit->Text = "";

			 if(MyRegistrationForm->PasswordEdit->Text == err_message) {
				MyRegistrationForm->PasswordEdit->Text = "";
				MyRegistrationForm->PasswordEdit->Password = true;
			}


			 MyRegistrationForm->NameEdit->Opacity = 1.0;
			 MyRegistrationForm->AgeEdit->Opacity = 1.0;
			 MyRegistrationForm->UsernameEdit->Opacity = 1.0;
			 MyRegistrationForm->PasswordEdit->Opacity = 1.0;

}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::AgeEditCanFocus(TObject *Sender, bool &ACanFocus)

{         if(AgeEdit->Text ==  err_message)   {
				MyRegistrationForm->AgeEdit->Text = "";
				MyRegistrationForm->AgeEdit->MaxLength = 2;
	}
}
//---------------------------------------------------------------------------
   void clear_input(){

			MyRegistrationForm->PasswordEdit->Password = true;
			MyRegistrationForm->AgeEdit->MaxLength = 2;
			MyRegistrationForm->NameEdit->Text = "";
			MyRegistrationForm->AgeEdit->Text = "";
			MyRegistrationForm->UsernameEdit->Text = "";
			MyRegistrationForm->PasswordEdit->Text = "";

   }
void __fastcall TMyRegistrationForm::FormClose(TObject *Sender, TCloseAction &Action)

{
		   clear_input();

}
//---------------------------------------------------------------------------

bool check_user(std::string target){
	   std::fstream saved_accounts;
	   saved_accounts.open("Data/accounts.data", ios::in);
	   std::string line {};
	   std::string word {};
	   if(!saved_accounts.is_open()) {
	   //saved_accounts.close();
			return true;
	   }

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
    return str.find_first_not_of("0123456789") == std::string::npos;
}


