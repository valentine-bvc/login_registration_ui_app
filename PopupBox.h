//---------------------------------------------------------------------------

#ifndef PopupBoxH
#define PopupBoxH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyInfoBox : public TForm
{
__published:	// IDE-managed Components
	TButton *OKButton;
	TLabel *InfoLabel;
	void __fastcall OKButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyInfoBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyInfoBox *MyInfoBox;
//---------------------------------------------------------------------------
#endif
