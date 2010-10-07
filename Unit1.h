//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "trayicon.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton1;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton7;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton0;
        TToolButton *ToolButton10;
        TToolButton *TButtonNotes;
        TToolButton *TButtonSeekGraph;
        TToolButton *TButtonHelp;
        TTrayIcon *TrayIcon;
        TClientSocket *Client;
        TTimer *Timer1;
        TTimer *TimerNot;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Connect1;
        TMenuItem *N2;
        TMenuItem *Exit1;
        TMenuItem *Edit1;
        TMenuItem *Options1;
        TMenuItem *Greeting1;
        TMenuItem *TellHistory1;
        TMenuItem *Thankyoumessage1;
        TMenuItem *NoIdleCommand1;
        TMenuItem *Setcommand1;
        TMenuItem *Setcommand2;
        TMenuItem *N3;
        TMenuItem *NoIdleon1;
        TMenuItem *NoIdleoff1;
        TMenuItem *ComputerOptions1;
        TMenuItem *EngineOn1;
        TMenuItem *EngineDepth1;
        TMenuItem *N11;
        TMenuItem *N21;
        TMenuItem *N31;
        TMenuItem *N41;
        TMenuItem *N51;
        TMenuItem *N61;
        TMenuItem *N71;
        TMenuItem *N81;
        TMenuItem *View1;
        TMenuItem *BuddyList1;
        TMenuItem *Messages1;
        TMenuItem *Chessboard1;
        TTimer *StartupTimer;
        TImageList *ButtonImageList;
void __fastcall ClientRead(TObject *Sender,
      TCustomWinSocket *Socket);
void __fastcall ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket);
void __fastcall Timer1Timer(TObject *Sender);

void __fastcall TellListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift);
void __fastcall TimerNotTimer(TObject *Sender);
void __fastcall EngineOn1Click(TObject *Sender);
void __fastcall N11Click(TObject *Sender);
void __fastcall N21Click(TObject *Sender);
void __fastcall N31Click(TObject *Sender);
void __fastcall N41Click(TObject *Sender);
void __fastcall N51Click(TObject *Sender);
void __fastcall N61Click(TObject *Sender);
void __fastcall N71Click(TObject *Sender);
void __fastcall N81Click(TObject *Sender);
void __fastcall StartupTimerTimer(TObject *Sender);
void __fastcall BuddyList1Click(TObject *Sender);
void __fastcall TButtonNotesClick(TObject *Sender);
void __fastcall TButtonSeekGraphClick(TObject *Sender);
void __fastcall TButtonHelpClick(TObject *Sender);
void __fastcall Messages1Click(TObject *Sender);
void __fastcall Chessboard1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        AnsiString __fastcall GetTokens(AnsiString GivenText,
                AnsiString Split1, AnsiString Split2, int amount);
        void __fastcall OnServerLogin();
        void __fastcall ProcessDG(int DG, AnsiString SentText);
        int __fastcall GetDG(AnsiString SentText);
        void __fastcall SendCmd(AnsiString Command);

        bool isnotlist;
        bool isdepartlist;
        String MyHandle;
        String PersTellHandle;
        String CurGameNum;
        String z;
        int time;
        

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
