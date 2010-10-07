//---------------------------------------------------------------------------

#ifndef mesH
#define mesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMesForm : public TForm
{
__published:	// IDE-managed Components
        TCheckListBox *MesListBox;
        TPanel *Panel1;
        TBitBtn *ComposeButton;
        TBitBtn *ForwardButton;
        TBitBtn *DeleteButton;
        TBitBtn *ReplyButton;
        TPanel *PreviewPanel;
        TRichEdit *MemoView;
        void __fastcall DeleteButtonClick(TObject *Sender);
        void __fastcall ComposeButtonClick(TObject *Sender);
        void __fastcall ReplyButtonClick(TObject *Sender);
        void __fastcall ForwardButtonClick(TObject *Sender);
        void __fastcall MesListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMesForm *MesForm;
//---------------------------------------------------------------------------
#endif
