//---------------------------------------------------------------------------

#ifndef composeH
#define composeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormCompose : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditTo;
        TLabel *Label1;
        TMemo *MemoMessage;
        TBitBtn *ButtonSend;
        void __fastcall ButtonSendClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormCompose(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCompose *FormCompose;
//---------------------------------------------------------------------------
#endif
