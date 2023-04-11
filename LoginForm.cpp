//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop


#include <fstream>
#include <sstream>
#include <string>
#include "PopupBox.h"    //used for information popup box
#include "encrypter.h"
#include "LoginForm.h"
#include "LoginFormExtra.h" //used for extra functions and variables


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyLoginForm *MyLoginForm;


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


		 if(saved_accounts.is_open() && ready_to_login()) {
			 //handle login process if data file is open and input fields meet the requirements

			 reset_lopacity();

			 //variables for loging into an account
			 std::string user = ansi_to_string(UsernameEdit->Text);
			 std::string pass = ansi_to_string(this->PasswordEdit->Text);
			 bool wrong_pass_flag{false};

			 bool found_username = login_check(user, pass, wrong_pass_flag);

			  //check if username is registered in data file
			 if(found_username)  {
				if(wrong_pass_flag) //handle error if password doesn't match with user
					PopupShow("Error!", "Incorrect username or password!");




				else    //login success
				   PopupShow("Success!", "Account found!");



             }


			 else       //handle error if username doesn't match with data file
			   PopupShow("Error", "Incorrect username or password!");



				   clear_all_login_input();
			 }

		   else{
		   //handle error message for missing user information
				input_required_login_error ();
		   }

			saved_accounts.close();
}
//---------------------------------------------------------------------------

void __fastcall TMyLoginForm::UsernameEditClick(TObject *Sender)
{  //clear error message on input box click
				clear_on_login_error();
				reset_lopacity();


}
//---------------------------------------------------------------------------

void __fastcall TMyLoginForm::PasswordEditClick(TObject *Sender)
{   //clear error message on input box click
				clear_on_login_error();
				reset_lopacity();

}
//---------------------------------------------------------------------------

void __fastcall TMyLoginForm::FormClose(TObject *Sender, TCloseAction &Action)
{    //clear text boxes on form close
		   clear_all_login_input();
}
//---------------------------------------------------------------------------

