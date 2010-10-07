// Last Updated: 10-11-02 - 23:07
//
// What was done:
// --Added Message compose that will send another message if it is too big
// --fixed online list and added 
// --added a People that will be notified when you depart list
// --fixed All List
// --Got messages to display correclty in message form
// --Replaced Parsing function
// --moved all constants to ICCINFO.h
// --Removed TMediaPlayer and used a windows function to play the sounds
// --Documented functions and code
// --Implemented Buttons in Message Client
//
// What needs to be done:
// --Finish Implementing observing of games etc
// --Implement looks of different types of text sent from the server
// --Create new window for each tell
//
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <windows.h>
#include <algorithm>
//for sound playing
#include <mmsystem.h>
#include "gameboard.h"
#include <string.h>
#include "login.h"
#include "buddylist.h"
#include "console.h"
#include "mes.h"
#include "instanttell.h"
//include all of the icc constants
#include "iccinfo.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Trayicon"
#pragma link "CSPIN"
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//***********************************************************
//*  This function parses a string and returns a stringlist *
//*  ********************************************************
AnsiString __fastcall TForm1::GetTokens(AnsiString GivenText,
    AnsiString Split1, AnsiString Split2, int amount)
{
    //Step 1: find split1
    //Step 2: Delete everything before and including Split 1
    //Step 3: find split 2
    //Step 4: Copy string from start to split 2 (not including split2)
    //        into a temporary string
    //Step 5: Delete eveyrthing from start to split 2
    //Step 6: Add temporary string to stringlist
    //Step 7 Increment # of strings
    //Step 8: if amount==0then check whether your at the end of the given text
    //Step 9: if # of strings equals amount, return tstringlist
    //        otherwise repeat steps 1-8
    //make sure SentText starts with the pretext deleted
    //(96 {} {   }{wohl})
    // ( , ) , 0
    TStringList *Tokens = new TStringList; // declare the list
    boolean IsEnd=false;
    AnsiString s = GivenText, ts;
    int i=0;

    while (IsEnd==false)
    {
       //steps 1 and 2
       s.Delete(1,s.Pos(Split1)+Split1.Length()-1 );
       //steps 3 and 4
       if (Split2 == "")
          ts = s.SubString(1,s.Pos(Split1)-1);
       else
          ts = s.SubString(1,s.Pos(Split2)-1);
       //steps 6 and 7
       if (ts.Trim()!="")
          Tokens->Add(ts);
       i++;
       //step 5
       if (Split2 == "")
          s.Delete(1,s.Pos(Split1)+Split1.Length()-1);
       else
          s.Delete(1,s.Pos(Split2)+Split2.Length()-1);
       //steps 8 and 9
       if (((amount==0) && (s.Pos(Split1)==0)) || (i==amount))
          IsEnd=true;
    }
    //ShowMessage(Tokens->Text);
    return Tokens->Text;
}

void __fastcall TForm1::ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
   /*Initializations*/
   TColor linecol=0x000080FF;

   TStringList *DGList = new TStringList; // declare the list

   int DGcode, index = CForm->DisplayEdit->Lines->Count;
   AnsiString item, TrimmedLine, s2, s = Client->Socket->ReceiveText() ;
   s2 = s;
   if (s.Pos("Present company in your notify list:")>0)
      isnotlist=true;
   if (s.Pos("The following will be notified when you depart:")>0)
      isdepartlist=true;
   if (s.Pos("(")>0)
   {
      s2.TrimLeft();
      s2.Delete(1,s2.Pos("(")-1);
      DGList->Text = GetTokens(s2,"(",")", 0) ;
      for (int i=0; i < DGList->Count;i++)
      {
         DGcode = GetDG(DGList->Strings[i]) ;
         ProcessDG(DGcode,DGList->Strings[i]) ;
      }
      CForm->DisplayEdit->Lines->Add(s) ;
   }
   else
      CForm->DisplayEdit->Lines->Add(s);

   CForm->DisplayEdit->SelStart = CForm->DisplayEdit->Perform(EM_LINEINDEX, index, 0);
   CForm->DisplayEdit->SelLength = s.Length();
   CForm->DisplayEdit->SelAttributes->Color = linecol;

}
void __fastcall TForm1::OnServerLogin()
{
  SendCmd("set interface Reindeer 0.9");
  SendCmd("set style 13");
  SendCmd("set-2 68 1");
  SendCmd("z");
  Form1->Caption = "  "+MyHandle+" - "+Form1->Caption ;
  BuddyListForm->Caption = MyHandle+"'s Lists" ;
}
/*************************************************
** This function uses the DG code and processes **
** the actions depending on the code            **
**************************************************/
void __fastcall TForm1::ProcessDG(int DG, AnsiString SentText)
{
   AnsiString s3=SentText, s2=SentText, s=SentText;
   //Set colors and all that type of stuff
   switch(DG)
   {
     //***Examples above case statements***//

     //::(0 BloodLust {})
     case DG_WHO_AM_I:
     {
       s.Delete(1,s.Pos("(0 ")+2) ;
       s.Delete(s.Pos(" {"),s.Length() ) ;
       s.Trim();
       MyHandle = s ;
       OnServerLogin();
     }
       break;
     //Present company in your notify list:
     //(96 {} {   }{sauce})The following will be notified when you depart:
     //(96 {} {   }{sauce})aics%

     case DG_LIST:
     {
        //it is a string list but you can't tell what list it is
        //so must rely  on boolean value from before
        if (isnotlist==true)
        {
           BuddyListForm->NotifyList->Items->Text = GetTokens(s,"{","}",0);
           isnotlist=false;
        }
        if (isdepartlist==true)
        {
           BuddyListForm->DepartList->Items->Text = GetTokens(s,"{","}",0);
           isdepartlist=false;
        }
     }

     break;
     // Called when you log on or enter the command "z"
     case DG_MY_NOTIFY_LIST:
     {
       s.Delete(1,2);
       //ShowMessage(s);
       AnsiString TempBuddyHandle=s.SubString(1,s.Length()-2);
       TempBuddyHandle.Trim() ;
       TempBuddyHandle = TempBuddyHandle.LowerCase ();
       TempBuddyHandle.Delete(TempBuddyHandle.Pos("\n")-1, TempBuddyHandle.Length() ) ;
       AnsiString onlist=s.SubString(s.Length()-1,s.Length());
       //ShowMessage(TempBuddyHandle);
       // ShowMessage(onlist.Trim());
       if (onlist.Trim()=="1")  //if added to list
       {
          BuddyListForm->AllNotList->Items->Add(TempBuddyHandle.TrimLeft() ) ;
       }
       else if (onlist.Trim()=="0")   // if removed from list
       {
          AnsiString item;
         //remove from the All List
          for (int i=0;i<BuddyListForm->AllNotList->Items->Count;i++)
          {
            item = BuddyListForm->AllNotList->Items->Strings[i].LowerCase();
            if (item.Pos(TempBuddyHandle.LowerCase())!=0)
              BuddyListForm->AllNotList->Items->Delete(i) ;
          }
          //Remove from the online list
          for (int i=0;i<BuddyListForm->NotifyList->Items->Count;i++)
          {
             item = BuddyListForm->NotifyList->Items->Strings[i].LowerCase();
             if (item.Pos(TempBuddyHandle.LowerCase())!=0)
             BuddyListForm->NotifyList->Items->Delete(i) ;
          }
       }
     }
     break;

     //(94 {messages  })(95 1 recoil 23:27 21-Aug-02 {hello this is message 1})2. recoil (23:27 21-Aug-02 EDT): hello this is message 2
     case DG_MESSAGELIST_BEGIN:
     {
        MesForm->MesListBox->Clear();
     }
     //(95 2 recoil 23:27 21-Aug-02 {hello this is message 2})aics%
     case DG_MESSAGELIST_ITEM:
     {
        AnsiString mes=SentText;
        mes.Delete(1,2);
        mes.Delete(mes.Pos("{"),2) ;
        mes.Delete(mes.Pos("}"),mes.Length() ) ;
        if (mes.Trim() != "messages")
           MesForm->MesListBox->Items->Add(mes);
        MesForm->Show();
        MesForm->Width = 450;
        MesForm->Height = 250;
     }
     break;
     //(32 pille {C} 1 {California has 2 PM hehe})aics%
     case DG_SHOUT:
     {
       // make it so it looks something like: "pille shouts: Calif..."

     }
     break;




     //                    {text} telltype
     //(31 BloodLust {} {hi} 1)
     case DG_PERSONAL_TELL:
     {
       int TELL_TYPE, index = CForm->DisplayEdit->Lines->Count;
       AnsiString PtH=s, TellText=s, TempS;

       PersTellHandle = GetTokens(s," ","",1);
       PersTellHandle.Delete(PersTellHandle.Length()-1,PersTellHandle.Length());
       PersTellHandle = PersTellHandle.LowerCase();
       PlaySound("tell.wav", 0,
        SND_FILENAME | SND_ASYNC);

       s.Delete(s.Pos(")"), s.Length() ) ;
       TellText.Delete(1,TellText.Pos("{")+1 ) ;
       TellText.Delete(TellText.Pos("}"), TellText.Length() ) ;

       TELL_TYPE=StrToInt (s.SubString( s.Length()-1,s.Length() ) );
       switch(TELL_TYPE)
       {
          //say
          case 0:

          //personal tell
          case 1:
          {
            //need to implement window creation for each tell
            CForm->TellList->Items->Insert(0,
                             (".:: "+FormatDateTime("hh:mm:ss", Now())+" ::.  "+
                              PersTellHandle+" - "+TellText) );
            TempS = PersTellHandle+" tells you: "+TellText;
            CForm->DisplayEdit->Lines->Add(TempS);
            CForm->DisplayEdit->SelStart =
               CForm->DisplayEdit->Perform(EM_LINEINDEX, index, 0);
            CForm->DisplayEdit->SelLength = TempS.Length();
            CForm->DisplayEdit->SelAttributes->Color = clYellow;
          } //end normal tell case
            break;
          //ptell
          case 2:
            break;

          //qtell
          case 3:
            break;

          //atell
          case 4:
            break;
          }//end Tell Switch

     }// end Tell Case
       break;
     //(64 anat)(64 ranchero)(64 TheBohemian)(64 LazyPawn)
     case DG_NOTIFY_ARRIVED:
     {
       s.Delete(1,2);
       AnsiString TempBuddyHandle=s;
       TempBuddyHandle.Trim() ;
       TempBuddyHandle.Delete(TempBuddyHandle.Pos("\n")-1, TempBuddyHandle.Length() ) ;
       BuddyListForm->NotifyList->Items->Add(TempBuddyHandle.TrimLeft() ) ;
       BuddyListForm->NotifyList->Color = clWhite;
       TimerNot->Enabled = true;
       PlaySound("notify.wav", 0,
        SND_FILENAME | SND_ASYNC);

     }
       break;
     //(65 BloodLust)
     case DG_NOTIFY_LEFT:
     {
       s.Delete(1,2);
       s.Delete(s.Pos("\n")-1,s.Length() ) ;
       s.Trim();
       AnsiString item;
       for (int i=0;i<BuddyListForm->NotifyList->Items->Count;i++)
       {
         item = BuddyListForm->NotifyList->Items->Strings[i];
         if (item.Pos(s)!=0)
           BuddyListForm->NotifyList->Items->Delete(i) ;
       }
     }// end case
       break;
     //(24 227 e7e6 298)
     case DG_SEND_MOVES:
     {

       AnsiString Move=SentText ,T=SentText;
       Square oSq, nSq;

       T.Delete(T.Pos(")"),T.Length()  ) ;
       for (int i=0;i<3;i++)
          T.Delete(1,T.Pos(" ") );

       time = StrToIntDef(T,0);

       Move.Delete(1,Move.Pos(CurGameNum)+CurGameNum.Length() ) ;
       Move.Delete(Move.Pos(" "),Move.Length() ) ;
       oSq = Form2->Chessboard->StringToSquare(Move.SubString(1,2) ) ;
       nSq = Form2->Chessboard->StringToSquare(Move.SubString(3,2) ) ;
       Form2->Chessboard->PerformMove(oSq, nSq) ;
       if (time!=0)
       {
          if (Form2->Chessboard->WhiteToMove==false) //white just moved
          {
             Form2->TimeWhiteLabel->Caption =
                IntToStr(time/60)+":"+IntToStr(time%60) ;
             Form2->WhiteTimer->Enabled=false;
             Form2->BlackTimer->Enabled=true;
          }
       }
       else      // black just moved
       {
          Form2->TimeBlackLabel->Caption =
             IntToStr(time/60)+":"+IntToStr(time%60) ;

          Form2->WhiteTimer->Enabled=true;
          Form2->BlackTimer->Enabled=false;
       }

     } // end case
       break;
     //(15 274 BloodLust icc-listings 0 Blitz 0 5 0 5 0 1 {} 2000 2200 1053940195 {} {} 0 0 0 {} 0)
     case DG_MY_GAME_STARTED:
     {
       Form2->Chessboard->NewGame() ;
       Form2->WhiteTimer->Enabled=true;
       s2.Delete(1,s2.Pos("(15 ")+3) ;
       s2.Delete(1,s2.Pos(" "));
       s=s2;
       s3.Delete(1,s3.Pos("(15 ")+3) ;
       s3.Delete(s3.Pos(" "),s3.Length() ) ;
       CurGameNum = s3;

       s2.Delete(s2.Pos(" "), s2.Length() );
       s2.Trim();
       if (s2==MyHandle) // if You are White
       {

          s.Delete(s.Pos(MyHandle), s.Pos(" ") ) ;
          s.Delete(s.Pos(" "),s.Length() ) ;
          Form2->Caption=CurGameNum+" - "+MyHandle+" vs. "+s ;
          Form2->Chessboard->WhiteOnTop=false;
          Form2->Chessboard->ComputerPlaysBlack=false;
          if (EngineOn1->Checked)
             Form2->Chessboard->ComputerPlaysWhite=true;
                    // switch the clocks

          Form2->TimeWhiteLabel->Top = 384 ;
          Form2->TimeBlackLabel->Top = 40 ;
       }
       else // if you are Black
       {
          s.Delete(s.Pos(MyHandle), s.Length() );
          Form2->Caption=CurGameNum+" - "+s+" vs. "+MyHandle ;
          Form2->Chessboard->WhiteOnTop=true;
          // switch the clocks
          int temptop;
          temptop = Form2->TimeWhiteLabel->Top ;
          Form2->TimeWhiteLabel->Top = Form2->TimeBlackLabel->Top ;
          Form2->TimeBlackLabel->Top = temptop;

          Form2->Chessboard->ComputerPlaysWhite=false;
          if (EngineOn1->Checked)
             Form2->Chessboard->ComputerPlaysBlack=true;
       }//end if
     }// end case
     break;
     //(16 504 0 Res 0-1 {White resigns} {E00})Game was not rated.  No rating adjustment.
     case DG_MY_GAME_RESULT:
     {
          Form2->WhiteTimer->Enabled=false;
          Form2->BlackTimer->Enabled=false;
       Form2->Caption = "was game( "+Form2->Caption+" )" ;
       if (EngineOn1->Checked)
       {
         SendCmd("say Thankyou for the game") ;
         SendCmd("say Running on Reindeer created by Bloodlust") ;
         SendCmd("seek 1 1 r");
         SendCmd("seek 3 3 r");
         SendCmd("seek 2 2 r");
       }//end if
     }// end case
     default:
     break;
   }
}
    //
/*************************************************
** This function gets the DG code from the      **
** command sent and converts it to an integer   **
** to be then processed by ProcessDG()          **
**************************************************/
int __fastcall TForm1::GetDG(AnsiString SentText)
{
   AnsiString s=SentText;
   s.Delete(s.Pos(" "), s.Length() ) ;
   return StrToIntDef(s, 999);
}

/*************************************************
** This function just keeps you from idling     **
**************************************************/
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   SendCmd("z") ;
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------

void __fastcall TForm1::TellListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key==VK_DELETE)
   {
      CForm->TellList->Items->Delete(CForm->TellList->ItemIndex) ;
      CForm->TellList->ItemIndex++;
   }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::TimerNotTimer(TObject *Sender)
{
   BuddyListForm->NotifyList->Color = clBlack ;
   CForm->TellList->Color = clBlack ;
   TimerNot->Enabled = false;
}
//---------------------------------------------------------------------------


/*************************************************
** This function sets all of the level2settings **
** that need to be set before entering your     **
** username and password.. read help plugins    **
**************************************************/
void __fastcall TForm1::ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  AnsiString level2code;
  char l2settings[117], dest[200]="level2settings=";

  //*** Set to all 0's ***
  for (int i=0;i<117;i++)
    l2settings[i] = '0';
  l2settings[DG_WHO_AM_I]='1';
  l2settings[DG_SEND_MOVES]='1';
  l2settings[DG_MOVE_SMITH]='1';
  l2settings[DG_MOVE_CLOCK]='1';
  l2settings[DG_MY_GAME_STARTED]='1';
  l2settings[DG_MY_GAME_RESULT]='1';
  l2settings[DG_MY_GAME_ENDED]='1';
  l2settings[DG_PERSONAL_TELL]='1';
  l2settings[DG_SHOUT]='1';
  l2settings[DG_NOTIFY_ARRIVED]='1';
  l2settings[DG_NOTIFY_LEFT]='1';
  l2settings[DG_MATCH]='1';
  l2settings[DG_MATCH_REMOVED]='1';
 // l2settings[DG_MY_NOTIFY_LIST]='1';  switch to onconnect instead
  l2settings[DG_LIST]='1';
  l2settings[DG_MESSAGELIST_BEGIN]='1';
  l2settings[DG_MESSAGELIST_ITEM]='1';
  l2settings[DG_STRINGLIST_BEGIN]='1';
  l2settings[DG_STRINGLIST_ITEM]='1';
  l2settings[DG_NOTIFY_STATE]='0';

  strcat(dest,l2settings);
  level2code=dest;
  level2code.Delete(level2code.Length()-2,level2code.Length() ) ;
  SendCmd(level2code);

  SendCmd(LoginForm->HandleEdit->Text);
  SendCmd(LoginForm->PasswordEdit->Text);



}
//---------------------------------------------------------------------------

/*************************************************
** This function sends the command to the       **
** server, and automatically sends the          **
** necessary "\n\r"                             **
**************************************************/
void __fastcall TForm1::SendCmd(AnsiString Command)
{
   Client->Socket->SendText(Command+"\n\r");
   //test what was sent
     if (Command.Pos("+not")>0)
        Form1->SendCmd("z");
     if (Command.Pos("-not")>0)
        Form1->SendCmd("z");
}




void __fastcall TForm1::EngineOn1Click(TObject *Sender)
{
   if (EngineOn1->Checked)
      EngineOn1->Checked = false ;
   else
      EngineOn1->Checked = true ;
}
//---------------------------------------------------------------------------
/*************************************************
** These next functions change the level of the **
** automatic computer engine                    **
**************************************************/
//  *****     ******      *******     ******       ******//
void __fastcall TForm1::N11Click(TObject *Sender)
{
   if (N11->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 1;
      N11->Checked = true ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
   if (N21->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 2;
      N21->Checked = true ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
   if (N31->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 3;
      N31->Checked = true ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
   if (N41->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 4;
      N41->Checked = true ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N51Click(TObject *Sender)
{
   if (N51->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 5;
      N51->Checked = true ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N61Click(TObject *Sender)
{
   if (N61->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 6;
      N61->Checked = true ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N71Click(TObject *Sender)
{
   if (N71->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 1;
      N71->Checked = true ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N81Click(TObject *Sender)
{
   if (N81->Checked)
     z = 0 ;
   else
   {
      Form2->Chessboard->SearchDepth  = 8;
      N81->Checked = true ;
   }
}
//  *****     ******      *******     ******       ******//
//---------------------------------------------------------------------------





/*************************************************
** This function automatically  starts the login**
** form on startup                              **
**************************************************/
void __fastcall TForm1::StartupTimerTimer(TObject *Sender)
{
   LoginForm->SetFocus();
   Form1->Hide();
   StartupTimer->Enabled=false;
   Form2->Close();
   MesForm->Hide();
}
//---------------------------------------------------------------------------

/*************************************************
** This function opens up the buddylist         **
**************************************************/
void __fastcall TForm1::BuddyList1Click(TObject *Sender)
{
   BuddyListForm->Visible=true ;        
}
//---------------------------------------------------------------------------

/*************************************************
** This function opens up chessnotes.txt        **
**************************************************/
void __fastcall TForm1::TButtonNotesClick(TObject *Sender)
{
   //Open up chessnotes.txt with shellexecute        
}
//---------------------------------------------------------------------------

/*************************************************
** this function shows the seek graph           **
**************************************************/
void __fastcall TForm1::TButtonSeekGraphClick(TObject *Sender)
{
  //turn on seek Datagrams and show seek graph        
}
//---------------------------------------------------------------------------
/*************************************************
** this function sends the question to ch 1     **
**************************************************/
void __fastcall TForm1::TButtonHelpClick(TObject *Sender)
{
  // call an inputquery to send a tell to channel 1        
}
//---------------------------------------------------------------------------

/*************************************************
** this function shows the message client       **
**************************************************/
void __fastcall TForm1::Messages1Click(TObject *Sender)
{
   SendCmd("mes");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chessboard1Click(TObject *Sender)
{
   ITellForm->Show();
}
//---------------------------------------------------------------------------



