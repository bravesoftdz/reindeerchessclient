//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "compose.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCompose *FormCompose;
//---------------------------------------------------------------------------
__fastcall TFormCompose::TFormCompose(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCompose::ButtonSendClick(TObject *Sender)
{
  if (MemoMessage->Text.Length()>300)
      ShowMessage("The following will be sent in more than one message");
   AnsiString temp=MemoMessage->Text;
   for (int i=0;i<temp.Length();i++)
      if (temp[i+1]=='\n')   temp[i+1]=' ';
      
   while (temp!="")
   {

      Form1->SendCmd("mes "+EditTo->Text+" "+temp.SubString(1,300));
      temp.Delete(1,300);
   }
   MemoMessage->Clear();
   EditTo->Clear();
   Close();
}
//---------------------------------------------------------------------------
