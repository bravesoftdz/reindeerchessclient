//---------------------------------------------------------------------------

#ifndef consoleH
#define consoleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TCForm : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *DisplayEdit;
        TMemo *EditSend;
        TListBox *TellList;
        void __fastcall EditSendKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DisplayEditChange(TObject *Sender);
        void __fastcall EditSendKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
AnsiString MyHandle, CurGameNum, PersTellHandle, ListHandle;
AnsiString handle, CmdHandle, tellhandle;
        __fastcall TCForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCForm *CForm;
//---------------------------------------------------------------------------
#endif
