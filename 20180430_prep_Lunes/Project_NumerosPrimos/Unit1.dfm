object Form1: TForm1
  Left = 192
  Top = 124
  Width = 696
  Height = 480
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
    Left = 304
    Top = 96
    Width = 121
    Height = 153
    ItemHeight = 13
    TabOrder = 0
  end
  object Min: TEdit
    Left = 152
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Max: TEdit
    Left = 152
    Top = 168
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 176
    Top = 224
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
    OnClick = Button1Click
  end
end
