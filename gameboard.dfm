object Form2: TForm2
  Left = 473
  Top = 67
  BorderStyle = bsSingle
  Caption = '(no game yet)'
  ClientHeight = 602
  ClientWidth = 691
  Color = clBtnFace
  DefaultMonitor = dmDesktop
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object Chessboard: TChessBrd
    Left = 0
    Top = 0
    Width = 464
    Height = 464
    AnimateMoves = False
    AnimationDelay = 0
    BoardLines = False
    BorderColor = clGray
    CastlingAllowed = [WhiteKingSide, WhiteQueenSide, BlackKingSide, BlackQueenSide]
    ComputerPlaysBlack = False
    ComputerPlaysWhite = False
    Thinking = False
    CoordFont.Charset = DEFAULT_CHARSET
    CoordFont.Color = clWhite
    CoordFont.Height = -9
    CoordFont.Name = 'Arial'
    CoordFont.Style = []
    CurrentMove = 1
    DisplayCoords = [West, North, East, South]
    CustomEngine = False
    EnPassant = None
    Position = 'rnbqkbnrpppppppp                                PPPPPPPPRNBQKBNR'
    Resizable = False
    ResizeMinSize = 100
    ResizeMaxSize = 1000
    SearchDepth = 1
    SizeOfBorder = 0
    SizeOfSquare = 58
    SquareColorDark = clGray
    SquareColorLight = clSilver
    WhiteOnTop = False
    WhiteToMove = True
    ThinkingPriority = tpNormal
    DragCursor = crDefault
    OnLegalMove = ChessboardLegalMove
    OnThreefoldPosition = ChessboardThreefoldPosition
  end
  object GameDispEdit: TRichEdit
    Left = 0
    Top = 464
    Width = 691
    Height = 113
    Align = alBottom
    Color = clBlack
    Font.Charset = ANSI_CHARSET
    Font.Color = 1213389
    Font.Height = -11
    Font.Name = 'Fixedsys'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
    OnChange = GameDispEditChange
  end
  object EditGameSend: TMemo
    Left = 0
    Top = 577
    Width = 691
    Height = 25
    Align = alBottom
    TabOrder = 1
    OnKeyDown = EditGameSendKeyDown
    OnKeyUp = EditGameSendKeyUp
  end
  object BackButton: TButton
    Left = 488
    Top = 264
    Width = 33
    Height = 25
    Caption = '3'
    Font.Charset = SYMBOL_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Wingdings 3'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object ForwardButton: TButton
    Left = 576
    Top = 264
    Width = 33
    Height = 25
    Caption = '4'
    Font.Charset = SYMBOL_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Wingdings 3'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
  end
  object TimeBlackLabel: TStaticText
    Left = 512
    Top = 40
    Width = 120
    Height = 58
    Caption = '5:00'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object StaticText1: TStaticText
    Left = 480
    Top = 8
    Width = 111
    Height = 33
    Caption = 'Black (39)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object TimeWhiteLabel: TStaticText
    Left = 504
    Top = 384
    Width = 120
    Height = 58
    Caption = '5:00'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
  end
  object StaticText2: TStaticText
    Left = 480
    Top = 432
    Width = 113
    Height = 33
    Caption = 'White (39)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object ActionButton: TButton
    Left = 480
    Top = 320
    Width = 65
    Height = 33
    Caption = 'Actions'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
  end
  object DrawButton: TButton
    Left = 552
    Top = 320
    Width = 65
    Height = 33
    Caption = 'Draw'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = DrawButtonClick
  end
  object ResignButton: TButton
    Left = 624
    Top = 320
    Width = 65
    Height = 33
    Caption = 'Resign'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    OnClick = ResignButtonClick
  end
  object BlackTimer: TTimer
    Enabled = False
    OnTimer = BlackTimerTimer
    Left = 600
    Top = 16
  end
  object WhiteTimer: TTimer
    Enabled = False
    OnTimer = WhiteTimerTimer
    Left = 640
    Top = 400
  end
end
