//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "RegistrationForm.h"
#include "RegistrationFormExtra.h"    //used for extra functions and variables
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
			 const std::string age_check =  ansi_to_string(MyRegistrationForm->AgeEdit->Text);


			 if(saved_accounts.is_open() && ready_to_register(age_check) ) {
				//handle account registering and adding data to file

			  std::string name = ansi_to_string(NameEdit->Text);
			  std::string age = ansi_to_string(AgeEdit->Text);
			  std::string username = ansi_to_string(UsernameEdit->Text);
			  std::string password = ansi_to_string(PasswordEdit->Text);



			  if(find_user(username) == false){
			  //finish registration if username is not already in data
				std::string send =  name + "," + age + "," + username + "," + password;
				saved_accounts << encode(send) << "\n";
				MyInfoBox->Caption =  "Success!";
				MyInfoBox->InfoLabel->Text =  "Account registered!";
				MyInfoBox->Show();

			  this->Close();
			   }
			   else {
				  //handle error message if username is already in data
				  MyInfoBox->Caption =  "Error!";
				  MyInfoBox->InfoLabel->Text =  "Username already registered!";
				  MyInfoBox->Show();

               }

				  clear_input();
			 }

			 else {
				 input_required_error (age_check);


			 }
			  saved_accounts.close();

}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::NameEditClick(TObject *Sender)
{
//clear error message on input box click
			 clear_on_error();
			 reset_opacity();
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::AgeEditClick(TObject *Sender)
{
//clear error message on input box click
			 clear_on_error();
			 reset_opacity();
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::UsernameEditClick(TObject *Sender)
{
//clear error message on input box click
			 clear_on_error();
			 reset_opacity();
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::PasswordEditClick(TObject *Sender)
{
//clear error message on input box click
			 clear_on_error();
			 reset_opacity();

}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::AgeEditCanFocus(TObject *Sender, bool &ACanFocus)

{
//clear error message on input box tab press
		if(AgeEdit->Text ==  err_age)   {
				AgeEdit->Text = "";
				AgeEdit->MaxLength = 2;
	}
}
//---------------------------------------------------------------------------

