//---------------------------------------------------------------------------
/*    aim windows in delphi
 im1 := TChatForm.Create(frmMain);
 im2 := TChatForm.Create(frmMain);
 im3 := TChatForm.Create(frmMain);
*/
#include <vcl.h>
#pragma hdrstop

#include "buddylist.h"
#include "Unit1.h"
#include "console.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBuddyListForm *BuddyListForm;
//---------------------------------------------------------------------------
__fastcall TBuddyListForm::TBuddyListForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBuddyListForm::Finger1Click(TObject *Sender)
{
   handle = NotifyList->Items->Strings[NotifyList->ItemIndex] ;
   Form1->SendCmd("finger "+handle) ;
}
//---------------------------------------------------------------------------

void __fastcall TBuddyListForm::Ping1Click(TObject *Sender)
{
   handle = NotifyList->Items->Strings[NotifyList->ItemIndex] ;
   Form1->SendCmd("ping "+handle) ;
}
//---------------------------------------------------------------------------

void __fastcall TBuddyListForm::Remove1Click(TObject *Sender)
{
   handle = NotifyList->Items->Strings[NotifyList->ItemIndex] ;
   Form1->SendCmd("-notify "+handle) ;
}
//---------------------------------------------------------------------------
void __fastcall TBuddyListForm::SendaTelltoall1Click(TObject *Sender)
{
  AnsiString Message;
  if (InputQuery("Mass Tell Send","Send this message.",Message) )
     for(int i=0;i<NotifyList->Items->Count;i++)
     {
        handle=NotifyList->Items->Strings[i];
        Form1->SendCmd("Tell "+handle+" "+Message) ;
     }

}
//---------------------------------------------------------------------------
void __fastcall TBuddyListForm::MessageAll1Click(TObject *Sender)
{
  AnsiString Message;

  if (PageControl->ActivePage==AllTab)
  {
     if (InputQuery("Mass Message Send","Send to all checked on your notify list",Message))
        for(int i=0;i<AllNotList->Items->Count;i++)
        {
          handle=AllNotList->Items->Strings[i];
          if (AllNotList->Checked[i])
             Form1->SendCmd("message "+handle+" "+Message) ;
        }
  }
  else if (PageControl->ActivePage==OnlineTab)
  {
     if (InputQuery("Mass Message Send","Send to all online",Message))
        for(int i=0;i<NotifyList->Items->Count;i++)
        {
          handle=NotifyList->Items->Strings[i];
          Form1->SendCmd("message "+handle+" "+Message) ;
        }
  }
}
//---------------------------------------------------------------------------
void __fastcall TBuddyListForm::NotifyListDblClick(TObject *Sender)
{
 if (NotifyList->ItemIndex!=-1)
 {
  handle = NotifyList->Items->Strings[NotifyList->ItemIndex];
  CForm->EditSend->Text = "Tell "+handle+" " ;
  CForm->EditSend->SetFocus();
  CForm->EditSend->SelStart = CForm->EditSend->Text.Length();
 }        
}
//---------------------------------------------------------------------------
void __fastcall TBuddyListForm::AddToListButtonClick(TObject *Sender)
{
   AnsiString AddHandle;
   if (InputQuery("Notify List","Add to list",AddHandle))
     Form1->SendCmd("+not "+AddHandle);
}
//---------------------------------------------------------------------------

void __fastcall TBuddyListForm::CheckAll1Click(TObject *Sender)
{
        for(int i=0;i<AllNotList->Items->Count;i++)
        {
           AllNotList->Checked[i]=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TBuddyListForm::UncheckAll1Click(TObject *Sender)
{
        for(int i=0;i<AllNotList->Items->Count;i++)
        {
           AllNotList->Checked[i]=false;
        }
}
//---------------------------------------------------------------------------

