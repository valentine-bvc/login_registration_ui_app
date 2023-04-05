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

			 if(saved_accounts.is_open()){
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



			 }
}
//---------------------------------------------------------------------------

