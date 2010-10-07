//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "commandnumber.h"
#include <windows.h>
#include <algorithm>
#include "gameboard.h"
#define DG_WHO_AM_I			0
#define DG_PLAYER_ARRIVED		1
#define DG_PLAYER_LEFT			2
#define DG_BULLET			3
#define DG_BLITZ			4
#define DG_STANDARD			5
#define DG_WILD				6
#define DG_BUGHOUSE			7
#define DG_TIMESTAMP			8
#define DG_TITLES			9
#define DG_OPEN				10
#define DG_STATE			11
#define DG_GAME_STARTED			12
#define DG_GAME_RESULT			13
#define DG_EXAMINED_GAME_IS_GONE	14
#define DG_MY_GAME_STARTED		15
#define DG_MY_GAME_RESULT		16
#define DG_MY_GAME_ENDED		17
#define DG_STARTED_OBSERVING		18
#define DG_STOP_OBSERVING		19
#define DG_PLAYERS_IN_MY_GAME		20
#define DG_OFFERS_IN_MY_GAME		21
#define DG_TAKEBACK			22
#define DG_BACKWARD			23
#define DG_SEND_MOVES			24
#define DG_MOVE_LIST			25
#define DG_KIBITZ			26
#define DG_PEOPLE_IN_MY_CHANNEL		27
#define DG_CHANNEL_TELL			28
#define DG_MATCH			29
#define DG_MATCH_REMOVED		30
#define DG_PERSONAL_TELL		31
#define DG_SHOUT			32
#define DG_MOVE_ALGEBRAIC		33
#define DG_MOVE_SMITH			34
#define DG_MOVE_TIME			35
#define DG_MOVE_CLOCK			36
#define DG_BUGHOUSE_HOLDINGS		37
#define DG_SET_CLOCK			38
#define DG_FLIP				39
#define DG_ISOLATED_BOARD		40
#define DG_REFRESH			41
#define DG_ILLEGAL_MOVE			42
#define DG_MY_RELATION_TO_GAME		43
#define DG_PARTNERSHIP			44
#define DG_SEES_SHOUTS			45
#define DG_CHANNELS_SHARED		46
#define DG_MY_VARIABLE			47
#define DG_MY_STRING_VARIABLE		48
#define DG_JBOARD			49
#define DG_SEEK				50
#define DG_SEEK_REMOVED			51
#define DG_MY_RATING			52
#define DG_SOUND			53
#define DG_PLAYER_ARRIVED_SIMPLE	55
#define DG_MSEC				56
#define DG_BUGHOUSE_PASS		57
#define DG_IP				58
#define DG_CIRCLE			59
#define DG_ARROW			60
#define DG_MORETIME			61
#define DG_PERSONAL_TELL_ECHO		62
#define DG_SUGGESTION			63
#define DG_NOTIFY_ARRIVED		64
#define DG_NOTIFY_LEFT			65
#define DG_NOTIFY_OPEN			66
#define DG_NOTIFY_STATE			67
#define DG_MY_NOTIFY_LIST		68
#define DG_LOGIN_FAILED			69
#define DG_FEN				70
#define DG_TOURNEY_MATCH		71
#define DG_GAMELIST_BEGIN		72
#define DG_GAMELIST_ITEM		73
#define DG_IDLE				74
#define DG_ACK_PING			75
#define DG_RATING_TYPE_KEY              76
#define DG_GAME_MESSAGE                 77
#define DG_UNACCENTED                   78
#define DG_STRINGLIST_BEGIN		79
#define DG_STRINGLIST_ITEM		80
#define DG_DUMMY_RESPONSE               81
#define DG_CHANNEL_QTELL                82
#define DG_PERSONAL_QTELL               83
#define DG_SET_BOARD	                84
#define DG_MATCH_ASSESSMENT             85
#define DG_LOG_PGN                      86
#define DG_NEW_MY_RATING                87
#define DG_LOSERS                       88
#define DG_UNCIRCLE			89
#define DG_UNARROW			90
#define DG_WSUGGEST			91
#define DG_TEMPORARY_PASSWORD           93
#define DG_MESSAGELIST_BEGIN            94
#define DG_MESSAGELIST_ITEM             95
#define DG_LIST				96
#define DG_SJI_AD                       97
#define DG_RETRACT                      99
#define DG_MY_GAME_CHANGE               100
#define DG_POSITION_BEGIN               101
#define DG_DIALOG_START                 105
#define DG_DIALOG_DATA                  106
#define DG_DIALOG_DEFAULT               107
#define DG_DIALOG_END                   108
#define DG_DIALOG_RELEASE               109
#define DG_POSITION_BEGIN2              110
#define DG_PAST_MOVE                    111
#define DG_PGN_TAG                      112
#define DG_IS_VARIATION                 113
#define DG_PASSWORD                     114
#define DG_WILD_KEY                     116

#define SCN_UNKNOWN                    0
#define SCN_ILLEGAL_MOVE               1
#define SCN_MOVE                       2
#define SCN_EDIT_EXAMINED              3
#define SCN_PING_RESPONSE             10
#define SCN_WEIRD                     11
#define SCN_REALLY_LOG_IN             12
#define SCN_MOED                      13
#define SCN_EVENTS                    14
#define SCN_NEWS                      15
#define SCN_LOGOUT                    16
#define SCN_TIMEOUT                   17
#define SCN_CONNECT                   18
#define SCN_REALLY_QUIT               19
#define SCN_LOGIN                     20
#define SCN_PASSWORD                  21
#define SCN_REGISTRATION              22
#define SCN_EXTENSION                 23
#define SCN_AUTHENTICATION            24
#define SCN_BAD                       25
#define SCN_AUTOMATIC                 26
#define SCN_CONFIRM                   27

#define CN_TELL                      101
#define CN_I                         102
#define CN_SHOUT                     103
#define CN_SHOUT0                    104
#define CN_SLASH                     105
#define CN_WHO                       106
#define CN_SET                       107
#define CN_FLAG                      108
#define CN_SAY                       109
#define CN_CHANNELTELL               110
#define CN_SSHOUT                    111
#define CN_BAD                       112
#define CN_KIBITZ                    113
#define CN_WHISPER                   114
#define CN_EXAMINE                   115
#define CN_MEXAMINE                  116
#define CN_COPYGAME0                 117
#define CN_COPYGAME                  118
#define CN_FORWARD                   119
#define CN_BACK                      120
#define CN_MATCH                     121
#define CN_MATCH0                    122
#define CN_ACCEPT                    123
#define CN_HELP0                     124
#define CN_HELP                      125
#define CN_MORE                      126
#define CN_NEWS                      127
#define CN_NEWS0                     128
#define CN_HISTORY                   129
#define CN_FINGER                    130
#define CN_VARS                      131
#define CN_UPSTATISTICS              132
#define CN_UNEXAMINE                 133
#define CN_ADJOURN                   134
#define CN_ASSESS                    135
#define CN_OBSERVE0                  136
#define CN_OBSERVE                   137
#define CN_FOLLOW0                   138
#define CN_FOLLOW                    139
#define CN_ECO                       140
#define CN_STYLE                     141
#define CN_BELL                      142
#define CN_OPEN                      143
#define CN_DECLINE                   144
#define CN_REFRESH                   145
#define CN_RESIGNADJ                 146
#define CN_REVERT                    147
#define CN_RATED                     148
#define CN_RANK                      149
#define CN_MOVES                     150
#define CN_MAILOLDMOVES              151
#define CN_MAILSTORED                152
#define CN_MAILHELP                  153
#define CN_PENDING                   154
#define CN_GAMES                     155
#define CN_ABORT                     156
#define CN_ALLOBSERVERS              157
#define CN_INCHANNEL                 158
#define CN_INFO                      159
#define CN_MORETIME                  160
#define CN_BEST                      161
#define CN_QUIT                      162
#define CN_QUOTA                     163
#define CN_LLOGONS                   164
#define CN_LHISTORY                  165
#define CN_LOGONS                    166
#define CN_TIME                      167
#define CN_TAKEBACK                  168
#define CN_SEARCH                    169
#define CN_SEARCH0                   170
#define CN_SMOVES                    171
#define CN_SPOSITION                 172
#define CN_PASSWORD                  173
#define CN_MESSAGE                   174
#define CN_MESSAGE0                  175
#define CN_CLEARMESSAGES             176
#define CN_DATE                      177
#define CN_LIST                      178
#define CN_PLUS                      179
#define CN_MINUS                     180
#define CN_ZNOTL                     181
#define CN_FLIP                      182
#define CN_PROMOTE                   183
#define CN_EXPUNGE                   184
#define CN_IWCMATCH                  185
#define CN_LIMITS                    186
#define CN_PING                      187
#define CN_EXTEND                    188
#define CN_QTELL                     189
#define CN_GETPI                     190
#define CN_STARTSIMUL                191
#define CN_GOTO                      192
#define CN_SETCLOCK                  193
#define CN_LIBLIST                   194
#define CN_LIBSAVE                   195
#define CN_LIBDELETE                 196
#define CN_LIBANNOTATE               197
#define CN_LIBKEEPEXAM               198
#define CN_PARTNER                   199
#define CN_PARTNER0                  200
#define CN_PTELL                     201
#define CN_BUGWHO                    202
#define CN_WILDRANK                  204
#define CN_XOBSERVE                  205
#define CN_PRIMARY                   206
#define CN_DRAW                      207
#define CN_RESIGN                    208
#define CN_STATISTICS                209
#define CN_STORED                    210
#define CN_CHANNELQTELL              211
#define CN_XPARTNER                  212
#define CN_YFINGER                   213
#define CN_SEEKING                   214
#define CN_SOUGHT                    215
#define CN_SET2                      216     
#define CN_PLAY                      217
#define CN_UNSEEKING                 218
#define CN_AWAY                      219
#define CN_LAGSTATS                  220
#define CN_COMMANDS                  221
#define CN_REMATCH                   222
#define CN_REGISTER                  223
#define CN_RESUME                    224
#define CN_CIRCLE                    225
#define CN_ARROW                     226
#define CN_BLANKING                  227
#define CN_RELAY                     228
#define CN_LOADGAME                  229
#define CN_DRAWADJ                   230
#define CN_ABORTADJ                  231
#define CN_MAILNEWS		     232
#define CN_QSET			     233
#define CN_CC_START                  234
#define CN_CC_LIST                   235
#define CN_CC_MOVE                   236
#define CN_CC_DELETE                 237
#define CN_CC_QSTART                 238
#define CN_CC_QLIST                  239
#define CN_CC_QLABEL                 240
#define CN_CC_QDELETE                241
#define CN_CC_QADJUDICATE            242
#define CN_CC_ASK_DIRECTOR           243
#define CN_LOADFEN		     244
#define CN_GETPX                     245
#define CN_UNRELAYED		     246
#define CN_NORELAY                   247
#define CN_REFER                     248
#define CN_PGN                       249
#define CN_SPGN                      250
#define CN_QFOLLOW                   251
#define CN_QUNFOLLOW                 252
#define CN_QMATCH                    253
#define CN_QPARTNER                  254
#define CN_ISREGNAME                 255
#define CN_REQUIRETICKET             256
#define CN_ANNOTATE                  257
#define CN_CLEARBOARD                258
#define CN_REQUEST_WIN               259
#define CN_REQUEST_DRAW              260
#define CN_REQUEST_ABORT             261
#define CN_LOGPGN                    262
#define CN_RESULT                    263
#define CN_FEN                       264
#define CN_SFEN                      265


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Trayicon"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConnectButtonClick(TObject *Sender)
{
   Client->Host = EditConnect->Text ;
   Client->Port = StrToInt(EditPort->Text) ;
   Client->Active = true ;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
   /*Initializations*/
   TColor linecol=0x000080FF;
   int index = DisplayEdit->Lines->Count;
   AnsiString item, TrimmedLine, s = Client->Socket->ReceiveText() ;
   s.Delete(s.Pos("aics%")-2,s.Length());
   TrimmedLine = s;
   TrimmedLine.Delete(TrimmedLine.Pos("["),TrimmedLine.Pos("\n")) ;
   TrimmedLine.Delete(TrimmedLine.Pos("]"),2) ;
   TrimmedLine.Trim() ;
   Label3->Caption=s.SubString(1,s.Pos("\n")) ;
   if (TrimmedLine.Pos("Invalid password.")==1)
       commandcount=0;
   /*Begin*/
   CheckNotifyList(TrimmedLine);
   CheckTellList(TrimmedLine);



   DisplayEdit->Lines->Add(TrimmedLine);
   //*****   Change Color of Last line *********//

   if (LoggedIn)
   {
      switch(GetCN(s))
      {
         case SCN_MOVE :
         case CN_ACCEPT:
         case CN_MATCH0:
         case CN_MATCH : RefreshBoard(TrimmedLine);
                          break;
         case CN_TELL : 
                        if (TrimmedLine.Pos("tells you: ")!=0)
                        {
                           SoundPlay->FileName = "tell.wav" ;
                           SoundPlay->Open();
                           SoundPlay->Play();
                           tellhandle=CmdHandle;
                           TellList->Items->Insert(0,
                             (".:: "+FormatDateTime("hh:mm:ss", Now())+" ::.  "+
                             TrimmedLine.SubString(1,TrimmedLine.Length()-2)));
                        }
         case CN_PTELL:
         case CN_SAY  :
                              linecol=clYellow;
                              break;
         case CN_I      :
         case CN_SHOUT  :     linecol=clAqua;
                              break;
         case 307 /*Announcement*/:
         case CN_SSHOUT  :    linecol=clWhite;
                              break;
         case CN_KIBITZ   :
         case CN_WHISPER  :   linecol=clGray;
                              break;
         case CN_PLUS :
         case CN_MINUS:       SendCmd("z");
                              break;
         case SCN_REALLY_LOG_IN :
                                  NotifyList->Color = clWhite;
                                  TimerNot->Enabled = true;
                                  SoundPlay->FileName = "notify.wav" ;
                                  SoundPlay->Open();
                                  SoundPlay->Play();
                                  NotifyList->Items->Add(CmdHandle);
                                  break;
         case SCN_REALLY_QUIT :
                    for(int i=0;i< NotifyList->Items->Count;i++)
                    {
                        item = NotifyList->Items->Strings[i];
                        // item = item.LowerCase();
                        if (item.Pos(CmdHandle)!=0)
                           NotifyList->Items->Delete(i) ;
                     }
         default: linecol=0x000080FF;
      }
   }
   DisplayEdit->SelStart = DisplayEdit->Perform(EM_LINEINDEX, index, 0);
   DisplayEdit->SelLength = s.Length();
   DisplayEdit->SelAttributes->Color = linecol;

}

int __fastcall TForm1::GetCN(AnsiString s)
{
   AnsiString CN=s, CH;
   if (s.Pos("[")>0)
   {
      CN.Delete(CN.Pos("["), 2);
      CH = CN;
      CH.Delete(1,CH.Pos(" ") ) ;
      CH.Delete(CH.Pos("\n")-1, CH.Length() );  //Assign handle of command to CH
      CN.Delete(CN.Pos(" "),CN.Length() );   // Assign Command Number to CN
      if (CH!="*")
         CmdHandle = CH;
   }else CN="0";
   return StrToInt(CN) ;
}

void __fastcall TForm1::RefreshBoard(AnsiString s)
{
   /*
   <10>
|rnbqkbnr|
|pppppppp|
|        |
|        |
|    P   |
|        |
|PPPP PPP|
|RNBQKBNR|

   */
   Square oldSq, newSq;
   AnsiString olds, news, posi, positemp;
   s.Delete(1,2);
   posi = s ;
   if (s.Pos("<10>")!=0)
   {
      posi.Delete(1, posi.Pos("|")) ;
      for (int i=0;i<14;i++)
         posi.Delete(posi.Pos("|"), 1) ;
      positemp = posi;
      ShowMessage(positemp);

      posi.Delete(posi.Pos("|"),posi.Length() ) ;

      //std::reverse(posi.c_str(), posi.c_str() + posi.Length());
      //ShowMessage(posi);
      //Form2->DisplayMove(oldSq, newSq, posi) ;
      //Form2->Chessboard->Position = posi;

      //** This Gets the Old Square and Newsquare
      olds=positemp.SubString(s.Pos("/")+1,2) ;
      news = positemp.SubString(s.Pos("-")+1,2);
      olds = olds.UpperCase();
      news = news.UpperCase();
      oldSq = Form2->Chessboard->StringToSquare(olds);
      newSq = Form2->Chessboard->StringToSquare(news);
      Form2->Chessboard->PerformMove(oldSq,newSq);

   }
}
//*******************************************************
//**** This function Checks whether when starting a   ***
//**** game, you are white or black, and then sets up ***
//**** the pieces accordingly                         ***
//*******************************************************
void __fastcall TForm1::CheckTellList(AnsiString s)
{
    AnsiString matchstr;
    s.Delete(1,2);
 //*** When a game starts, check whether you are white or black ***
    matchstr = s ;
   // make sure style is set to 11
   if (s.Pos("{Game")>=1)
   {
      Form2->Caption= matchstr ;
      matchstr.Delete(1,matchstr.Pos("vs. ")+3);
      matchstr.Delete(matchstr.Pos(")"),matchstr.Length() ) ;
      matchstr.Trim() ;
      if (matchstr==loginhandle)
      {
         Form2->Chessboard->WhiteOnTop = true ;
         Form2->Chessboard->ComputerPlaysBlack = true ;
         Form2->Chessboard->ComputerPlaysWhite = false ;
      }else
      {
         Form2->Chessboard->ComputerPlaysWhite= true ;
         Form2->Chessboard->ComputerPlaysBlack= false ;
      }
   }
 //*****************************************************************




}
void __fastcall TForm1::CheckNotifyList(AnsiString s)
{
   AnsiString item, L, L2, token;
   boolean enuf=false;
   L=s;
   /*********DO THESE COMMANDS ON CONNECT************/
   if (L.Pos("A note to chessclub.com members:")!=0)
     {
      LoggedIn = true;
      Form1->Caption = Form1->Caption+"    "+loginhandle
         +" logged in.  " ;
      SendCmd("z");
      
      //SendCmd("set level1 1");
     // SendCmd("set style 10");
      SendCmd("set interface Reindeer") ;

     }
   /*********GET ONLINE NOTIFY LIST AND UPDATE TO LISTBOX*********/
   if (L.Pos("Present company in your notify list:")!=0)
   {
      NotifyList->Clear();
      L.Delete(1,40) ;
      L.Delete(L.Pos("The fol")-2,L.Length());
      L.Delete(L.Pos("There are games")-2,L.Length());
      L2=L;
      while (enuf==false)
      {
        L.Delete(L.Pos(" "),L.Length());//delete all but first token
        L2.Delete(1,L2.Pos(" ")); //delete first token
        token = L;
        if ((token.Trim()!=""))
          NotifyList->Items->Add(token);
        if (L==L2)
           enuf=true;
        L=L2;  // copy everything but first token into L

      }
   NotifyList->ItemIndex = 0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   SendCmd("z") ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::EditSendKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  int index = DisplayEdit->Lines->Count;
  if (Key == VK_UP)
    NotifyList->ItemIndex--;
  if (Key == VK_DOWN)
    NotifyList->ItemIndex++;

  if (Key == VK_RETURN)
   {

     EditSend->Text.Trim();
     if (commandcount==0)
     {
        loginhandle = EditSend->Text ;
        loginhandle.Delete(loginhandle.Length()-1,loginhandle.Length() ) ;
     }
     DisplayEdit->Lines->Add(EditSend->Text) ;
     DisplayEdit->SelStart = DisplayEdit->Perform(EM_LINEINDEX, index, 0);
     DisplayEdit->SelLength = EditSend->Text.Length();
     DisplayEdit->SelAttributes->Style = TFontStyles() << fsItalic;
     DisplayEdit->SelAttributes->Color = 0x00FF8000;
     SendCmd(EditSend->Lines->Strings[0]) ;
     commandcount++;
     EditSend->Clear() ;

   }
  if ((Key == VK_F5)&&(NotifyList->ItemIndex!=-1))
  {
     handle = NotifyList->Items->Strings[NotifyList->ItemIndex];
     EditSend->Text = "Tell "+handle+" ";
     EditSend->SetFocus();
     EditSend->SelStart = EditSend->Text.Length();
  }
  if (Key == VK_F6)
  {
     EditSend->Text = "Tell "+CmdHandle+" ";
     EditSend->SetFocus();
     EditSend->SelStart = EditSend->Text.Length();
  }
    if (Key == VK_F9)
  {
     EditSend->Text = "Tell "+tellhandle+" ";
     EditSend->SetFocus();
     EditSend->SelStart = EditSend->Text.Length();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditSendKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)   EditSend->Clear() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Finger1Click(TObject *Sender)
{
   handle = NotifyList->Items->Strings[NotifyList->ItemIndex] ;
   SendCmd("finger "+handle) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ping1Click(TObject *Sender)
{
   handle = NotifyList->Items->Strings[NotifyList->ItemIndex] ;
   SendCmd("ping "+handle) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Remove1Click(TObject *Sender)
{
   handle = NotifyList->Items->Strings[NotifyList->ItemIndex] ;
   SendCmd("-notify "+handle) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SendaTelltoall1Click(TObject *Sender)
{
   AnsiString s, message;
   message=InputBox("Enter Text","Send to all",message);
   if (message!="")
   {
     for (int i=0;i<NotifyList->Items->Count;i++)
     {
      handle = NotifyList->Items->Strings[i];
      SendCmd("tell "+handle+" "+message) ;
     }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MessageAll1Click(TObject *Sender)
{
   AnsiString s, message;
   message=InputBox("Enter Text","Send to all",message);
   if (message!="")
   {
     for (int i=0;i<NotifyList->Items->Count;i++)
     {
      handle = NotifyList->Items->Strings[i];
      SendCmd("message "+handle+" "+message) ;
     }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TellListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key==VK_DELETE)
   {
      TellList->Items->Delete(TellList->ItemIndex) ;
      TellList->ItemIndex++;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NotifyListDblClick(TObject *Sender)
{
 if (NotifyList->ItemIndex!=-1)
 {
  handle = NotifyList->Items->Strings[NotifyList->ItemIndex];
  EditSend->Text = "Tell "+handle+" " ;
  EditSend->SetFocus();
  EditSend->SelStart = EditSend->Text.Length();
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::IdleCheckClick(TObject *Sender)
{
   if (IdleCheck->Checked)
      Timer1->Enabled=true;
   else
      Timer1->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerNotTimer(TObject *Sender)
{
   NotifyList->Color = clBlack ;
   TellList->Color = clBlack ;
   TimerNot->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HelpButtonClick(TObject *Sender)
{
  ShowMessage("                    *** Help ***                   \n"
              "Hotkeys: \n"
              "F5: Initiate Tell to Current highlighted Buddy  \n"
              "F6: Initiate Tell to Handle last seen on screen  \n"
              "F9: Initiate Tell to Handle that last sent you tell  \n"
              "Every time the command ''z'' gets sent, the Buddies  \n"
              "Online Listbox gets updated.") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   commandcount = 0 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
   SendCmd("level2settings=10000000000000111111011111011111010101101000000000000000011000110011");
   //Client->Socket->SendText("set level1 1\n\r") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DisplayEditChange(TObject *Sender)
{
   DisplayEdit->Perform(EM_SCROLLCARET, 0, 0) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SendCmd(AnsiString Command)
{
   Client->Socket->SendText(Command+"\n\r");
}


void __fastcall TForm1::DisplayEditMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
     EditSend->SetFocus();
     EditSend->SelStart = EditSend->Text.Length();
}
//---------------------------------------------------------------------------

