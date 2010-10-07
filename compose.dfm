object FormCompose: TFormCompose
  Left = 265
  Top = 329
  BorderStyle = bsToolWindow
  Caption = 'Compose Message'
  ClientHeight = 296
  ClientWidth = 276
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 16
    Height = 13
    Caption = 'To:'
  end
  object EditTo: TEdit
    Left = 32
    Top = 8
    Width = 121
    Height = 21
    MaxLength = 15
    TabOrder = 2
    Text = 'BloodLust'
  end
  object MemoMessage: TMemo
    Left = 0
    Top = 40
    Width = 276
    Height = 256
    Align = alBottom
    MaxLength = 3000
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object ButtonSend: TBitBtn
    Left = 160
    Top = 8
    Width = 105
    Height = 25
    Caption = 'Send Message'
    TabOrder = 1
    OnClick = ButtonSendClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00550B30555000
      0000557F57F557777777550B305508888880557F57F575555557550B30508888
      8805557F57F7FFFFFF75550B300000000055557F5777777777F5550300000000
      0055557F7777777777F55500780F0F0F70555F777577F7F7F7F50078880F0F0F
      705577755577F7F7F7F50888880F0F0F70557F555F77F7F7F7F50888080F0F0F
      70557F557F77F7F7F7F50888980F0F0F70557F557F77F7F7F7F5088898007070
      70557F557F77F757575508889880077705557F5F7F5775FF7555089998888000
      55557F777F555777555508999888075555557577755F77555555508888075555
      5555575FFF775555555555000755555555555577775555555555}
    NumGlyphs = 2
  end
end
