object LoginForm: TLoginForm
  Left = 423
  Top = 213
  ActiveControl = ConnectButton
  BorderStyle = bsDialog
  Caption = 'Login'
  ClientHeight = 254
  ClientWidth = 417
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object CancelButton: TButton
    Left = 360
    Top = 224
    Width = 49
    Height = 25
    Caption = 'Cancel'
    TabOrder = 0
  end
  object MembersGB: TGroupBox
    Left = 8
    Top = 104
    Width = 281
    Height = 145
    Caption = 'Members'
    TabOrder = 1
    object Label1: TLabel
      Left = 136
      Top = 32
      Width = 117
      Height = 13
      Caption = 'Handle (your login name)'
    end
    object Label2: TLabel
      Left = 136
      Top = 60
      Width = 49
      Height = 13
      Caption = 'Password '
    end
    object HandleEdit: TEdit
      Left = 8
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
      Text = 'Recoil'
    end
    object PasswordEdit: TEdit
      Left = 8
      Top = 52
      Width = 121
      Height = 19
      Font.Charset = SYMBOL_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Wingdings 2'
      Font.Style = []
      ParentFont = False
      PasswordChar = '·'
      TabOrder = 1
    end
    object SavePWCheckBox: TCheckBox
      Left = 8
      Top = 80
      Width = 97
      Height = 17
      Caption = 'Save Password'
      TabOrder = 2
    end
    object ConnectButton: TBitBtn
      Left = 8
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Connect'
      TabOrder = 3
      OnClick = ConnectButtonClick
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
    end
  end
  object AdvancedGB: TGroupBox
    Left = 168
    Top = 8
    Width = 241
    Height = 89
    Caption = 'Advanced options'
    TabOrder = 2
    object Label3: TLabel
      Left = 160
      Top = 24
      Width = 66
      Height = 13
      Caption = 'ICC hostname'
    end
    object Label4: TLabel
      Left = 104
      Top = 56
      Width = 57
      Height = 13
      Caption = 'Port number'
    end
    object EditConnect: TComboBox
      Left = 8
      Top = 16
      Width = 145
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
      Left = 8
      Top = 48
      Width = 81
      Height = 22
      TabStop = True
      ParentColor = False
      TabOrder = 1
      Value = 5000
    end
  end
  object GuestGB: TGroupBox
    Left = 8
    Top = 8
    Width = 145
    Height = 89
    Caption = 'Guests'
    TabOrder = 3
    object ConnectGuestButton: TButton
      Left = 8
      Top = 24
      Width = 97
      Height = 25
      Caption = 'Connect as guest'
      TabOrder = 0
    end
    object JoinICCButton: TButton
      Left = 8
      Top = 56
      Width = 57
      Height = 25
      Caption = 'Join ICC'
      TabOrder = 1
    end
  end
end
