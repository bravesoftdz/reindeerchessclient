//---------------------------------------------------------------------------

#ifndef commandnumberH
#define commandnumberH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Trayicon.h"
#include <Buttons.hpp>
#include <Mask.hpp>
#include <ScktComp.hpp>
#include "CSPIN.h"
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTrayIcon *TrayIcon;
        TClientSocket *Client;
        TSpeedButton *ConnectButton;
        TComboBox *EditConnect;
        TCSpinEdit *EditPort;
        TRichEdit *DisplayEdit;
        TListBox *NotifyList;
        TTimer *Timer1;
        TMemo *EditSend;
        TPopupMenu *PopupNotify;
        TMenuItem *Finger1;
        TMenuItem *Ping1;
        TMenuItem *Remove1;
        TMenuItem *N1;
        TMenuItem *SendaTelltoall1;
        TMenuItem *MessageAll1;
        TLabel *Label1;
        TListBox *TellList;
        TLabel *Label2;
        TCheckBox *IdleCheck;
        TTimer *TimerNot;
        TMediaPlayer *SoundPlay;
        TButton *HelpButton;
        TLabel *Label3;
        TStatusBar *StatusBar1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Connect1;
        TMenuItem *N2;
        TMenuItem *Exit1;
        TMenuItem *Edit1;
        TMenuItem *Options1;
        TMenuItem *Greeting1;
        TMenuItem *TellHistory1;
        void __fastcall SendCmd(AnsiString Command);
        int __fastcall GetCN(AnsiString s);
        void __fastcall RefreshBoard(AnsiString s);
        void __fastcall ConnectButtonClick(TObject *Sender);
        void __fastcall ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall CheckNotifyList(AnsiString s);
        void __fastcall CheckTellList(AnsiString s);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall EditSendKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall EditSendKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Finger1Click(TObject *Sender);
        void __fastcall Ping1Click(TObject *Sender);
        void __fastcall Remove1Click(TObject *Sender);
        void __fastcall SendaTelltoall1Click(TObject *Sender);
        void __fastcall MessageAll1Click(TObject *Sender);
        void __fastcall TellListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall NotifyListDblClick(TObject *Sender);
        void __fastcall IdleCheckClick(TObject *Sender);
        void __fastcall TimerNotTimer(TObject *Sender);
        void __fastcall HelpButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall DisplayEditChange(TObject *Sender);
        void __fastcall DisplayEditMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
   int x,y, commandcount;
   bool LoggedIn;
   AnsiString loginhandle, handle, shouthandle, tellhandle, CmdHandle;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
