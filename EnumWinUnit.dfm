object EnumWinForm: TEnumWinForm
  Left = 192
  Top = 107
  Width = 836
  Height = 354
  Caption = 'EnumWinForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object EnumWin: TButton
    Left = 8
    Top = 296
    Width = 97
    Height = 25
    Caption = 'Enum Windows'
    TabOrder = 0
    OnClick = EnumWinClick
  end
  object SelectedWindow: TEdit
    Left = 416
    Top = 8
    Width = 401
    Height = 21
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 8
    Width = 405
    Height = 281
    ColCount = 3
    DefaultColWidth = 128
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 2
    ScrollBars = ssVertical
    TabOrder = 2
    OnSelectCell = StringGrid1SelectCell
  end
  object StringGrid2: TStringGrid
    Left = 416
    Top = 32
    Width = 405
    Height = 257
    ColCount = 3
    DefaultColWidth = 128
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 2
    ScrollBars = ssVertical
    TabOrder = 3
    OnSelectCell = StringGrid2SelectCell
  end
  object LParam: TEdit
    Left = 616
    Top = 296
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object WParam: TEdit
    Left = 488
    Top = 296
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object Send: TButton
    Left = 744
    Top = 296
    Width = 75
    Height = 25
    Caption = 'Send'
    TabOrder = 6
    OnClick = SendClick
  end
  object MsgComboBox: TComboBox
    Left = 256
    Top = 296
    Width = 225
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 7
  end
end
