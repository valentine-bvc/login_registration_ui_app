//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "PopupBox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyInfoBox *MyInfoBox;
//---------------------------------------------------------------------------
__fastcall TMyInfoBox::TMyInfoBox(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyInfoBox::OKButtonClick(TObject *Sender)
{
   this->Close();
}
//---------------------------------------------------------------------------
