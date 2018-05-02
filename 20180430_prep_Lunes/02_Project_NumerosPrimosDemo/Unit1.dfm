object Form1: TForm1
  Left = 525
  Top = 116
  Width = 488
  Height = 330
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PrimeList: TListBox
    Left = 248
    Top = 56
    Width = 121
    Height = 161
    ItemHeight = 13
    TabOrder = 0
  end
  object Min: TEdit
    Left = 88
    Top = 56
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Max: TEdit
    Left = 88
    Top = 112
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 104
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Find Primes'
    TabOrder = 3
    OnClick = Button1Click
  end
end
