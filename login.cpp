//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "login.h"
#include "Unit1.h"
#include "buddylist.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TLoginForm *LoginForm;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::ConnectButtonClick(TObject *Sender)
{
   Form1->Client->Host = EditConnect->Text ;
   Form1->Client->Port = StrToInt(EditPort->Text) ;
   Form1->Client->Active = true ;
   LoginForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Form1->Visible=true;
  BuddyListForm->Visible=true;
  BuddyListForm->Height=323;
  BuddyListForm->Width=148;
  BuddyListForm->Left=0 ;
  BuddyListForm->Top=0;
  
}
//---------------------------------------------------------------------------

