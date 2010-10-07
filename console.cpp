//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "console.h"
#include "buddylist.h"
#include "gameboard.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCForm *CForm;
//---------------------------------------------------------------------------
__fastcall TCForm::TCForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCForm::EditSendKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
int index = CForm->DisplayEdit->Lines->Count;
  if (Key == VK_UP)
  {
    if (BuddyListForm->NotifyList->ItemIndex != 0)
      BuddyListForm->NotifyList->ItemIndex--;
    ListHandle = BuddyListForm->NotifyList->Items->
        Strings[BuddyListForm->NotifyList->ItemIndex];
     CForm->EditSend->Text = "Tell "+ListHandle+"! ";
     CForm->EditSend->SetFocus();
     CForm->EditSend->SelStart = CForm->EditSend->Text.Length();
  }

  if (Key == VK_DOWN)
  {
      BuddyListForm->NotifyList->ItemIndex++;
      ListHandle = BuddyListForm->NotifyList->Items->
        Strings[BuddyListForm->NotifyList->ItemIndex];
      CForm->EditSend->Text = "Tell "+ListHandle+"! ";
      CForm->EditSend->SetFocus();
      CForm->EditSend->SelStart = CForm->EditSend->Text.Length();
  }

  if (Key == VK_RETURN)
   {

     CForm->EditSend->Text.Trim();
     CForm->DisplayEdit->Lines->Add(CForm->EditSend->Text) ;
     CForm->DisplayEdit->SelStart = CForm->DisplayEdit->Perform(EM_LINEINDEX, index, 0);
     CForm->DisplayEdit->SelLength = CForm->EditSend->Text.Length();
     CForm->DisplayEdit->SelAttributes->Style = TFontStyles() << fsItalic;
     CForm->DisplayEdit->SelAttributes->Color = 0x00FF8000;
     
     Form1->SendCmd(CForm->EditSend->Lines->Strings[0]) ;
     //update the online list if you add someone to it
     CForm->EditSend->Clear() ;

   }
  if ((Key == VK_F5)&&(BuddyListForm->NotifyList->ItemIndex!=-1))
  {
     ListHandle = BuddyListForm->NotifyList->Items->
        Strings[BuddyListForm->NotifyList->ItemIndex];
     CForm->EditSend->Text = "Tell "+ListHandle+"! ";
     CForm->EditSend->SetFocus();
     CForm->EditSend->SelStart = CForm->EditSend->Text.Length();
  }

    if (Key == VK_F9)
  {
     CForm->EditSend->Text = "Tell "+Form1->PersTellHandle+"! ";
     CForm->EditSend->SetFocus();
     CForm->EditSend->SelStart = CForm->EditSend->Text.Length();
  }        
}
//---------------------------------------------------------------------------
void __fastcall TCForm::DisplayEditChange(TObject *Sender)
{
CForm->DisplayEdit->Perform(EM_SCROLLCARET, 0, 0) ;        
}
//---------------------------------------------------------------------------
void __fastcall TCForm::EditSendKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key==VK_RETURN)
      CForm->EditSend->Clear() ;
}
//---------------------------------------------------------------------------

