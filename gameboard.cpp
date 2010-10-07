//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "gameboard.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ChessBrd"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::DisplayMove(Square oldSq, Square newSq, AnsiString posi)
{
 Chessboard->CurrentMove++ ;
 Chessboard->Position=posi ;
}

AnsiString __fastcall TForm2::SquareToString(Square Sq)
{
 AnsiString s;
 s.sprintf("%c%c", Chessboard->XPos(Sq) + 'A' - 1, Chessboard->YPos(Sq) + '0');
 return s;
}
void __fastcall TForm2::ChessboardLegalMove(TObject *Sender, Square oldSq,
      Square newSq)
{
   AnsiString olds, news;
   olds=SquareToString(oldSq);
   olds=olds.LowerCase();
   news=SquareToString(newSq);
   news=news.LowerCase();
   //*** Only send moves made by yourself ***
   if (Chessboard->WhiteOnTop)//Is Black
   {
      if (Chessboard->WhiteToMove==true) //Black's turn to move
         Form1->SendCmd(olds+"-"+news);
   }
   else if (Chessboard->WhiteOnTop==false)//Is White
   {
      if (Chessboard->WhiteToMove==false)//White's turn to move
         Form1->SendCmd(olds+"-"+news);
   }//end if
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   Chessboard->NewGame() ;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ChessboardThreefoldPosition(TObject *Sender)
{
   Form1->SendCmd("Draw");        
}
//---------------------------------------------------------------------------


void __fastcall TForm2::WhiteTimerTimer(TObject *Sender)
{
   int sec, min;
   sec =StrToInt(TimeWhiteLabel->Caption.SubString(
      TimeWhiteLabel->Caption.Pos(":")+1,TimeWhiteLabel->Caption.Length() ) ) ;
   min =StrToInt(TimeWhiteLabel->Caption.Delete(
      TimeWhiteLabel->Caption.Pos(":"), TimeWhiteLabel->Caption.Length() ) ) ;
   sec--;
   if (sec<0)
   {
     min--;
     sec=59;
   }
   if (IntToStr(sec).Length()==1)
      TimeWhiteLabel->Caption = IntToStr(min)+":0"+IntToStr(sec);
   else
      TimeWhiteLabel->Caption = IntToStr(min)+":"+IntToStr(sec);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BlackTimerTimer(TObject *Sender)
{
   int sec, min;
   sec =StrToInt(TimeBlackLabel->Caption.SubString(
      TimeBlackLabel->Caption.Pos(":")+1,TimeBlackLabel->Caption.Length() ) ) ;
   min =StrToInt(TimeBlackLabel->Caption.Delete(
      TimeBlackLabel->Caption.Pos(":"), TimeBlackLabel->Caption.Length() ) ) ;
   sec--;
   if (sec<0)
   {
     min--;
     sec=59;
   }
   if (IntToStr(sec).Length()==1)
      TimeBlackLabel->Caption = IntToStr(min)+":0"+IntToStr(sec);
   else
      TimeBlackLabel->Caption = IntToStr(min)+":"+IntToStr(sec);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DrawButtonClick(TObject *Sender)
{
   Form1->SendCmd("draw");        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ResignButtonClick(TObject *Sender)
{
   Form1->SendCmd("resign") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::EditGameSendKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   int index = GameDispEdit->Lines->Count;
   if(Key == VK_RETURN)
   {
     EditGameSend->Text.Trim();
     GameDispEdit->Lines->Add(EditGameSend->Text) ;
     GameDispEdit->SelStart = GameDispEdit->Perform(EM_LINEINDEX, index, 0);
     GameDispEdit->SelLength = GameDispEdit->Text.Length();
     GameDispEdit->SelAttributes->Style = TFontStyles() << fsItalic;
     GameDispEdit->SelAttributes->Color = 0x00FF8000;
     Form1->SendCmd(EditGameSend->Lines->Strings[0]) ;
     EditGameSend->Clear() ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::EditGameSendKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key==VK_RETURN)
      EditGameSend->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::GameDispEditChange(TObject *Sender)
{
  GameDispEdit->Perform(EM_SCROLLCARET, 0, 0) ;
}
//---------------------------------------------------------------------------


