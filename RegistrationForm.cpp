//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "RegistrationForm.h"
#include "PopupBox.h"
#include <fstream>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
const String err_message {"DETAILS REQUIRED"};

void clear_input_boxes();
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
			 MyRegistrationForm->PasswordEdit->Text != err_message){
			  AnsiString name = MyRegistrationForm->NameEdit->Text;
			  AnsiString age = MyRegistrationForm->AgeEdit->Text;
			  AnsiString username = MyRegistrationForm->UsernameEdit->Text;
			  AnsiString password = MyRegistrationForm->PasswordEdit->Text;


			  saved_accounts << name << "," << age << "," << username << "," <<password;

			  saved_accounts.close();

			   MyInfoBox->Caption =  "Success!";
			  MyInfoBox->InfoLabel->Text =  "Account registered!";

			  MyInfoBox->Show();

			  this->Close();
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
			MyRegistrationForm->NameEdit->Text = "";
			MyRegistrationForm->AgeEdit->Text = "";
			MyRegistrationForm->UsernameEdit->Text = "";
			MyRegistrationForm->PasswordEdit->Text = "";
   }
