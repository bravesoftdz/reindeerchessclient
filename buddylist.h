//---------------------------------------------------------------------------

#ifndef buddylistH
#define buddylistH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TBuddyListForm : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *PopupNotify;
        TMenuItem *Finger1;
        TMenuItem *Ping1;
        TMenuItem *Remove1;
        TMenuItem *N1;
        TMenuItem *SendaTelltoall1;
        TMenuItem *MessageAll1;
        TPanel *Panel1;
        TSpeedButton *TellAllButton;
        TSpeedButton *MessAllButton;
        TSpeedButton *AddToListButton;
        TSpeedButton *RemoveFromListButton;
        TPageControl *PageControl;
        TTabSheet *OnlineTab;
        TTabSheet *AllTab;
        TListBox *NotifyList;
        TCheckListBox *AllNotList;
        TPopupMenu *PopupAll;
        TMenuItem *CheckAll1;
        TMenuItem *UncheckAll1;
        TMenuItem *Masscommand1;
        TMenuItem *N2;
        TTabSheet *YourOnSheet;
        TListBox *DepartList;
        void __fastcall Finger1Click(TObject *Sender);
        void __fastcall Ping1Click(TObject *Sender);
        void __fastcall Remove1Click(TObject *Sender);
        void __fastcall SendaTelltoall1Click(TObject *Sender);
        void __fastcall MessageAll1Click(TObject *Sender);
        void __fastcall NotifyListDblClick(TObject *Sender);
        void __fastcall AddToListButtonClick(TObject *Sender);
        void __fastcall CheckAll1Click(TObject *Sender);
        void __fastcall UncheckAll1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  AnsiString handle;
        __fastcall TBuddyListForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBuddyListForm *BuddyListForm;
//---------------------------------------------------------------------------
#endif
