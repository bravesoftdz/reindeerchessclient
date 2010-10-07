object BuddyListForm: TBuddyListForm
  Left = 626
  Top = 86
  Width = 156
  Height = 348
  BorderStyle = bsSizeToolWin
  Caption = 'My Lists'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 295
    Width = 148
    Height = 26
    Align = alBottom
    AutoSize = True
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = clActiveBorder
    TabOrder = 0
    object TellAllButton: TSpeedButton
      Left = 4
      Top = 2
      Width = 23
      Height = 22
      Hint = 'Send a mass tell to all'
      Anchors = [akLeft, akBottom]
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00500000000055
        555557777777775F55550FFFFFFFFF0555557F5555555F7FFF5F0FEEEEEE0000
        05007F555555777775770FFFFFF0BFBFB00E7F5F5557FFF557770F0EEEE000FB
        FB0E7F75FF57775555770FF00F0FBFBFBF0E7F57757FFFF555770FE0B00000FB
        FB0E7F575777775555770FFF0FBFBFBFBF0E7F5575FFFFFFF5770FEEE0000000
        FB0E7F555777777755770FFFFF0B00BFB0007F55557577FFF7770FEEEEE0B000
        05557F555557577775550FFFFFFF0B0555557FF5F5F57575F55500F0F0F0F0B0
        555577F7F7F7F7F75F5550707070700B055557F7F7F7F7757FF5507070707050
        9055575757575757775505050505055505557575757575557555}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = SendaTelltoall1Click
    end
    object MessAllButton: TSpeedButton
      Left = 34
      Top = 2
      Width = 23
      Height = 22
      Hint = 'Message all people in your buddy list'
      Anchors = [akLeft, akBottom]
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333333333333333333FFFFFFFFFFFFFFF000000000000
        000077777777777777770FFFFFFFFFFFFFF07F3333FFF33333370FFFF777FFFF
        FFF07F333777333333370FFFFFFFFFFFFFF07F3333FFFFFF33370FFFF777777F
        FFF07F33377777733FF70FFFFFFFFFFF99907F3FFF33333377770F777FFFFFFF
        9CA07F77733333337F370FFFFFFFFFFF9A907FFFFFFFFFFF7FF7000000000000
        0000777777777777777733333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = MessageAll1Click
    end
    object AddToListButton: TSpeedButton
      Left = 66
      Top = 2
      Width = 23
      Height = 22
      Hint = 'Add new player to notify list'
      Anchors = [akLeft, akBottom]
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33033333333333333F7F3333333333333000333333333333F777333333333333
        000333333333333F777333333333333000333333333333F77733333333333300
        033333333FFF3F777333333700073B703333333F7773F77733333307777700B3
        33333377333777733333307F8F8F7033333337F333F337F3333377F8F9F8F773
        3333373337F3373F3333078F898F870333337F33F7FFF37F333307F99999F703
        33337F377777337F3333078F898F8703333373F337F33373333377F8F9F8F773
        333337F3373337F33333307F8F8F70333333373FF333F7333333330777770333
        333333773FF77333333333370007333333333333777333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = AddToListButtonClick
    end
    object RemoveFromListButton: TSpeedButton
      Left = 98
      Top = 2
      Width = 23
      Height = 22
      Hint = 'Remove from notify list'
      Anchors = [akLeft, akBottom]
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33033333333333333F7F3333333333333000333333333333F777333333333333
        000333333333333F777333333333333000333333333333F77733333333333300
        033333333FFF3F777333333700073B703333333F7773F77733333307777700B3
        333333773337777333333078F8F87033333337F3333337F33333778F8F8F8773
        333337333333373F333307F8F8F8F70333337F33FFFFF37F3333078999998703
        33337F377777337F333307F8F8F8F703333373F3333333733333778F8F8F8773
        333337F3333337F333333078F8F870333333373FF333F7333333330777770333
        333333773FF77333333333370007333333333333777333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = Remove1Click
    end
  end
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 148
    Height = 295
    ActivePage = OnlineTab
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object OnlineTab: TTabSheet
      Hint = 'People that are online on your notify list'
      Caption = 'Online'
      ParentShowHint = False
      ShowHint = True
      object NotifyList: TListBox
        Left = 0
        Top = 0
        Width = 140
        Height = 268
        Align = alClient
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
        Style = lbOwnerDrawFixed
        TabOrder = 0
        OnDblClick = NotifyListDblClick
      end
    end
    object AllTab: TTabSheet
      Hint = 'Your whole notify list'
      Caption = 'All'
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = True
      object AllNotList: TCheckListBox
        Left = 0
        Top = 0
        Width = 140
        Height = 268
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        PopupMenu = PopupAll
        TabOrder = 0
      end
    end
    object YourOnSheet: TTabSheet
      Hint = 'People that are notified when you depart'
      Caption = 'Depart'
      ImageIndex = 2
      ParentShowHint = False
      ShowHint = True
      object DepartList: TListBox
        Left = 0
        Top = 0
        Width = 140
        Height = 268
        Align = alClient
        Color = clBlack
        Font.Charset = ANSI_CHARSET
        Font.Color = clAqua
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        Sorted = True
        Style = lbOwnerDrawFixed
        TabOrder = 0
      end
    end
  end
  object PopupNotify: TPopupMenu
    Left = 48
    Top = 128
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
  object PopupAll: TPopupMenu
    Left = 68
    Top = 71
    object CheckAll1: TMenuItem
      Caption = 'Check All'
      OnClick = CheckAll1Click
    end
    object UncheckAll1: TMenuItem
      Caption = 'Uncheck All'
      OnClick = UncheckAll1Click
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object Masscommand1: TMenuItem
      Caption = 'Mass command'
    end
  end
end
