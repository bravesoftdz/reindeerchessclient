//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mes.h"
#include "Unit1.h"
#include "compose.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMesForm *MesForm;
//---------------------------------------------------------------------------
__fastcall TMesForm::TMesForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMesForm::DeleteButtonClick(TObject *Sender)
{
   AnsiString CurMesText=MesListBox->Items->Strings[MesListBox->ItemIndex];
   AnsiString ts=Form1->GetTokens(CurMesText," "," ",1);
   int mesnum=StrToInt(ts.Trim());
   Form1->SendCmd("clearmessages "+IntToStr(mesnum));
   MesListBox->Items->Delete(MesListBox->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TMesForm::ComposeButtonClick(TObject *Sender)
{
   FormCompose->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TMesForm::ReplyButtonClick(TObject *Sender)
{
   AnsiString ReplyHandle = MesListBox->Items->Strings[MesListBox->ItemIndex];
   ReplyHandle.Delete(1,3);
   ReplyHandle.Delete(ReplyHandle.Pos(" "),ReplyHandle.Length() );
   FormCompose->Show();
   FormCompose->EditTo->Text = ReplyHandle;
}
//---------------------------------------------------------------------------

void __fastcall TMesForm::ForwardButtonClick(TObject *Sender)
{
   AnsiString FMes=MesListBox->Items->Strings[MesListBox->ItemIndex];
   FMes.Delete(1,3);
   FormCompose->Show();
   FormCompose->MemoMessage->Text = "Forward: <<"+FMes+">>";
}
//---------------------------------------------------------------------------

void __fastcall TMesForm::MesListBoxClick(TObject *Sender)
{
   AnsiString Mes=MesListBox->Items->Strings[MesListBox->ItemIndex];
   AnsiString Handle=Mes, Date=Mes;
   Mes.Delete(1,2);
   Handle = Form1->GetTokens(Mes," "," ",1);
   Mes.Delete(1,Mes.Pos(" "));
   //ShowMessage(Mes);
   Date = Mes.SubString(Mes.Pos(" ")+1,Mes.Length());
   Date.Insert("::",Date.Pos(" "));
   Date.Delete(Date.Pos(" "),1);
   Date.Delete(Date.Pos(" "),Date.Length());
   Mes.Delete(1,Mes.Pos(" "));
   Mes.Delete(1,Mes.Pos(" "));
   Mes.Delete(1,Mes.Pos(" "));
   Handle.Delete(Handle.Length()-1,2);
   Mes.Trim();
   MemoView->Clear();
   MemoView->Lines->Add("From:         "+Handle);
   MemoView->Lines->Add("Date Sent: "+Date);
   MemoView->Lines->Add("Message:   ");
   MemoView->Lines->Add("-----------------------------------------------"
                        "-----------------------------------------------");
   MemoView->Lines->Add(Mes);

}
//---------------------------------------------------------------------------

