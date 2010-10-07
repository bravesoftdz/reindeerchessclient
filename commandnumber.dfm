object Form1: TForm1
  Left = 231
  Top = 153
  Width = 705
  Height = 561
  Caption = 'Reindeer 0.4b           ..::: BloodLust :::..'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ConnectButton: TSpeedButton
    Left = 336
    Top = 8
    Width = 23
    Height = 22
    Hint = 'Connect to server'
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333333333333333333333333333333FFF333333333333000333333333
      3333777FFF3FFFFF33330B000300000333337F777F777773F333000E00BFBFB0
      3333777F773333F7F333000E0BFBF0003333777F7F3337773F33000E0FBFBFBF
      0333777F7F3333FF7FFF000E0BFBF0000003777F7F3337777773000E0FBFBFBF
      BFB0777F7F33FFFFFFF7000E0BF000000003777F7FF777777773000000BFB033
      33337777773FF733333333333300033333333333337773333333333333333333
      3333333333333333333333333333333333333333333333333333333333333333
      3333333333333333333333333333333333333333333333333333}
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    OnClick = ConnectButtonClick
  end
  object Label1: TLabel
    Left = 592
    Top = 48
    Width = 82
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Buddies Online'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 133
    Top = 48
    Width = 64
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Tell History'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 96
    Top = 32
    Width = 32
    Height = 13
    Caption = 'Label3'
  end
  object EditConnect: TComboBox
    Left = 16
    Top = 8
    Width = 209
    Height = 21
    Hint = 'Server (only supports icc servers)'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 0
    Text = 'chessclub.com'
  end
  object EditPort: TCSpinEdit
    Left = 240
    Top = 8
    Width = 81
    Height = 22
    TabStop = True
    ParentColor = False
    TabOrder = 1
    Value = 5000
  end
  object DisplayEdit: TRichEdit
    Left = 0
    Top = 144
    Width = 585
    Height = 334
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clBlack
    Font.Charset = ANSI_CHARSET
    Font.Color = 12615680
    Font.Height = -9
    Font.Name = 'Fixedsys'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 2
    OnChange = DisplayEditChange
    OnMouseUp = DisplayEditMouseUp
  end
  object NotifyList: TListBox
    Left = 584
    Top = 64
    Width = 113
    Height = 414
    Anchors = [akTop, akRight, akBottom]
    Color = clBlack
    Font.Charset = ANSI_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ItemHeight = 13
    ParentFont = False
    PopupMenu = PopupNotify
    Sorted = True
    TabOrder = 3
    OnDblClick = NotifyListDblClick
  end
  object EditSend: TMemo
    Left = 0
    Top = 474
    Width = 697
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Color = clWhite
    Lines.Strings = (
      'BloodLust')
    TabOrder = 4
    OnKeyDown = EditSendKeyDown
    OnKeyUp = EditSendKeyUp
  end
  object TellList: TListBox
    Left = 0
    Top = 64
    Width = 585
    Height = 81
    Anchors = [akLeft, akTop, akRight]
    BiDiMode = bdLeftToRight
    Color = -1
    Font.Charset = ANSI_CHARSET
    Font.Color = clYellow
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ItemHeight = 13
    ParentBiDiMode = False
    ParentFont = False
    TabOrder = 5
    OnKeyDown = TellListKeyDown
  end
  object IdleCheck: TCheckBox
    Left = 16
    Top = 32
    Width = 57
    Height = 17
    Caption = 'No Idle'
    TabOrder = 6
    OnClick = IdleCheckClick
  end
  object SoundPlay: TMediaPlayer
    Left = 552
    Top = 8
    Width = 29
    Height = 30
    VisibleButtons = [btPlay]
    AutoOpen = True
    FileName = 'notify.wav'
    Visible = False
    TabOrder = 7
  end
  object HelpButton: TButton
    Left = 680
    Top = 0
    Width = 17
    Height = 17
    Cursor = crHelp
    Anchors = [akTop, akRight]
    Caption = '?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = HelpButtonClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 496
    Width = 697
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object TrayIcon: TTrayIcon
    Visible = True
    Hide = True
    RestoreOn = imDoubleClick
    PopupMenuOn = imNone
    Left = 736
    Top = 8
  end
  object Client: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientConnect
    OnRead = ClientRead
    Left = 376
    Top = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = Timer1Timer
    Left = 496
    Top = 8
  end
  object PopupNotify: TPopupMenu
    Left = 344
    Top = 88
    object Finger1: TMenuItem
      Caption = 'Finger'
      OnClick = Finger1Click
    end
    object Ping1: TMenuItem
      Caption = 'Ping'
      OnClick = Ping1Click
    end
    object Remove1: TMenuItem
      Caption = 'Remove'
      OnClick = Remove1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object SendaTelltoall1: TMenuItem
      Caption = 'Tell All'
      OnClick = SendaTelltoall1Click
    end
    object MessageAll1: TMenuItem
      Caption = 'Message All'
      OnClick = MessageAll1Click
    end
  end
  object TimerNot: TTimer
    Enabled = False
    Interval = 90
    OnTimer = TimerNotTimer
    Left = 432
    Top = 24
  end
  object MainMenu1: TMainMenu
    Left = 112
    Top = 216
    object File1: TMenuItem
      Caption = 'File'
      object Connect1: TMenuItem
        Caption = 'Connect'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
      object Options1: TMenuItem
        Caption = 'Set'
        object Greeting1: TMenuItem
          Caption = 'Notify Greeting'
        end
        object TellHistory1: TMenuItem
          Caption = 'Tell History #'
        end
      end
    end
  end
end
