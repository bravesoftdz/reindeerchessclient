//---------------------------------------------------------------------------

#ifndef loginH
#define loginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Buttons.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TLoginForm : public TForm
{
__published:	// IDE-managed Components
        TButton *CancelButton;
        TGroupBox *MembersGB;
        TEdit *HandleEdit;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *PasswordEdit;
        TCheckBox *SavePWCheckBox;
        TGroupBox *AdvancedGB;
        TComboBox *EditConnect;
        TCSpinEdit *EditPort;
        TLabel *Label3;
        TLabel *Label4;
        TGroupBox *GuestGB;
        TButton *ConnectGuestButton;
        TButton *JoinICCButton;
        TBitBtn *ConnectButton;
        void __fastcall ConnectButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginForm *LoginForm;
//---------------------------------------------------------------------------
#endif
