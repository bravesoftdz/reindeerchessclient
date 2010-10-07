//---------------------------------------------------------------------------

#ifndef instanttellH
#define instanttellH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TITellForm : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *TellDispEdit;
        TRichEdit *TellSendEdit;
        TPanel *Panel1;
        TSpeedButton *AddButton;
        TSpeedButton *RemoveButton;
        TSpeedButton *CensorButton;
        TSpeedButton *FingerButton;
        TSpeedButton *MatchButton;
        TSpeedButton *MessageButton;
private:	// User declarations
public:		// User declarations
        __fastcall TITellForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TITellForm *ITellForm;
//---------------------------------------------------------------------------
#endif
