//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEFORM("Unit1.cpp", Form1);
USEFORM("gameboard.cpp", Form2);
USEFORM("login.cpp", LoginForm);
USEFORM("buddylist.cpp", BuddyListForm);
USEFORM("console.cpp", CForm);
USEFORM("mes.cpp", MesForm);
USEFORM("instanttell.cpp", ITellForm);
USEFORM("compose.cpp", FormCompose);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Reindeer";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TLoginForm), &LoginForm);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TBuddyListForm), &BuddyListForm);
                 Application->CreateForm(__classid(TCForm), &CForm);
                 Application->CreateForm(__classid(TMesForm), &MesForm);
                 Application->CreateForm(__classid(TITellForm), &ITellForm);
                 Application->CreateForm(__classid(TFormCompose), &FormCompose);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
