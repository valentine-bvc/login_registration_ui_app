//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Types.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TMyLoginForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *UsernameEdit;
	TEdit *PasswordEdit;
	TLabel *UsernameLabel;
	TLabel *PasswordLabel;
	TButton *LoginButton;
	void __fastcall LoginButtonClick(TObject *Sender);
	void __fastcall UsernameEditClick(TObject *Sender);
	void __fastcall PasswordEditClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TMyLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
#endif
