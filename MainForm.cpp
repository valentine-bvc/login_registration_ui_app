//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "RegistrationForm.h"
#include "LoginForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyMainForm *MyMainForm;
//---------------------------------------------------------------------------
__fastcall TMyMainForm::TMyMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyMainForm::RegisterButtonClick(TObject *Sender)
{
		MyLoginForm->Close();
		MyRegistrationForm->Show();


}
//---------------------------------------------------------------------------

void __fastcall TMyMainForm::LoginButtonClick(TObject *Sender)
{
		 MyRegistrationForm->Close();
		 MyLoginForm->Show();

}
//---------------------------------------------------------------------------


