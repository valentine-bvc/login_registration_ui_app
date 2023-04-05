//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "RegistrationForm.h"
#include "PopupBox.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
const String err_message {"DETAILS REQUIRED"};

void clear_input_boxes();
bool check_user(std::string);
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

			 if(saved_accounts.is_open() &&
			 MyRegistrationForm->NameEdit->Text != "" &&
			 MyRegistrationForm->AgeEdit->Text != "" &&
			 MyRegistrationForm->UsernameEdit->Text != "" &&
			 MyRegistrationForm->PasswordEdit->Text != "" &&
			 MyRegistrationForm->NameEdit->Text != err_message &&
			 MyRegistrationForm->AgeEdit->Text != err_message &&
			 MyRegistrationForm->UsernameEdit->Text != err_message &&
			 MyRegistrationForm->PasswordEdit->Text != err_message) {

			  AnsiString name = MyRegistrationForm->NameEdit->Text;
			  AnsiString age = MyRegistrationForm->AgeEdit->Text;
			  AnsiString username = MyRegistrationForm->UsernameEdit->Text;
			  AnsiString password = MyRegistrationForm->PasswordEdit->Text;

			  std::string target = static_cast<std::string>(username);


			  if(check_user(target) == false){

			  saved_accounts << name << "," << age << "," << username << "," <<password << "\n";
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

			  saved_accounts.close();




			  clear_input_boxes();



			 }

			 else {
				 if(MyRegistrationForm->NameEdit->Text == "")
					MyRegistrationForm->NameEdit->Text = err_message;


				 if(MyRegistrationForm->AgeEdit->Text == "")      {
                    AgeEdit->MaxLength = 30;
					MyRegistrationForm->AgeEdit->Text = err_message;
				 }

				 if(MyRegistrationForm->UsernameEdit->Text  == "")
					MyRegistrationForm->UsernameEdit->Text =  err_message;

				 if (MyRegistrationForm->PasswordEdit->Text == "")   {
					 PasswordEdit->Password = false;
					 MyRegistrationForm->PasswordEdit->Text =   err_message;
				 }
			 }
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::NameEditClick(TObject *Sender)
{
	if(NameEdit->Text == err_message)
		NameEdit->Text = "";

}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::AgeEditClick(TObject *Sender)
{
	  if(AgeEdit->Text ==  err_message)  {
		AgeEdit->Text = "";
		AgeEdit->MaxLength = 2;
	  }
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::UsernameEditClick(TObject *Sender)
{
		   if(UsernameEdit->Text == err_message)
			   UsernameEdit->Text = "";


}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::PasswordEditClick(TObject *Sender)
{
			if(PasswordEdit->Text == err_message) {
				PasswordEdit->Text = "";
				PasswordEdit->Password = true;
            }

}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::AgeEditCanFocus(TObject *Sender, bool &ACanFocus)

{         if(AgeEdit->Text ==  err_message)   {
				AgeEdit->Text = "";
				AgeEdit->MaxLength = 2;
	}
}
//---------------------------------------------------------------------------
   void clear_input_boxes(){

            MyRegistrationForm->PasswordEdit->Password = true;
			MyRegistrationForm->AgeEdit->MaxLength = 2;
			MyRegistrationForm->NameEdit->Text = "";
			MyRegistrationForm->AgeEdit->Text = "";
			MyRegistrationForm->UsernameEdit->Text = "";
			MyRegistrationForm->PasswordEdit->Text = "";

   }
void __fastcall TMyRegistrationForm::FormClose(TObject *Sender, TCloseAction &Action)

{
		   clear_input_boxes();

}
//---------------------------------------------------------------------------

bool check_user(std::string target){
	   std::fstream saved_accounts;
	   saved_accounts.open("Data/accounts.data", ios::in);
	   std::string line {};
	   std::string word {};
	   if(!saved_accounts.is_open()) {
	   saved_accounts.close();
			return true;
	   }

	   while(getline(saved_accounts,line)){

		 std::stringstream ss{line};
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




