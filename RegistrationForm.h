//---------------------------------------------------------------------------

#ifndef RegistrationFormH
#define RegistrationFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *NameLabel;
	TEdit *AgeEdit;
	TEdit *UsernameEdit;
	TEdit *PasswordEdit;
	TLabel *AgeLabel;
	TLabel *UsernameLabel;
	TLabel *PasswordLabel;
	TButton *RegisterButton;
	TEdit *NameEdit;
	void __fastcall RegisterButtonClick(TObject *Sender);
	void __fastcall NameEditClick(TObject *Sender);
	void __fastcall AgeEditClick(TObject *Sender);
	void __fastcall UsernameEditClick(TObject *Sender);
	void __fastcall PasswordEditClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TMyRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
#endif
