//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EnumWinUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEnumWinForm *EnumWinForm;
//---------------------------------------------------------------------------
__fastcall TEnumWinForm::TEnumWinForm(TComponent* Owner)
  : TForm(Owner)
{
  TStringList *list = new TStringList();
  list->LoadFromFile("winmsgs.txt");
  AnsiString str;
  int k;
  for(int i = 0; i < list->Count; i++)
    {
    str.SetLength(100);
    sscanf(list->Strings[i].c_str(),"%s %X\n",str.c_str(),&k);
    MsgComboBox->Items->AddObject(str,(TObject *)k);
    }
  delete list;
  MsgComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------


void __fastcall TEnumWinForm::EnumWinClick(TObject *Sender)
{
//  SendMessage(Edit1->Handle,EM_SETSEL,0,-1);
//  SendMessage(Edit1->Handle,WM_PASTE,0,0);
  StringGrid1->Tag = 0;
  EnumWindows((WNDSMPLPROC)EnumWindowsProc,(int)StringGrid1);
  StringGrid1->RowCount = StringGrid1->Tag + 1;
}
//---------------------------------------------------------------------------

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
  TStringGrid *grid = (TStringGrid *)lParam;
  AnsiString str, cname, caption;
  str.SetLength(1024);
  GetClassName(hwnd,str.c_str(),1023);
  cname = str;
  str.SetLength(1024);
  GetWindowText(hwnd,str.c_str(),1023);
  caption = str;
  grid->Tag++;
  grid->Rows[grid->Tag]->Text = "0x" + IntToHex((int)hwnd,6) + "\n" + cname + "\n" + caption;
  grid->Rows[grid->Tag]->Objects[0] = (TObject *)hwnd;
  return true;
}



void __fastcall TEnumWinForm::SendClick(TObject *Sender)
{
  HWND hwnd = (HWND)SelectedWindow->Tag;
  int msg = (int)MsgComboBox->Items->Objects[MsgComboBox->ItemIndex];
  int lParam = LParam->Text.ToIntDef(0), wParam = WParam->Text.ToIntDef(0);
  SendMessage(hwnd,msg,wParam,lParam);
}
//---------------------------------------------------------------------------


void __fastcall TEnumWinForm::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
  StringGrid2->Tag = 0;
  SelectedWindow->Text = StringGrid1->Rows[ARow]->Text;
  SelectedWindow->Tag = (int)StringGrid1->Rows[ARow]->Objects[0];
  EnumChildWindows(StringGrid1->Rows[ARow]->Objects[0], (WNDSMPLPROC)EnumWindowsProc,(int)StringGrid2);
  if(StringGrid2->Tag)
    StringGrid2->RowCount = StringGrid2->Tag + 1;
  else
    {
    StringGrid2->RowCount = 2;
    StringGrid2->Rows[1]->Text = "";
    }
}
//---------------------------------------------------------------------------


void __fastcall TEnumWinForm::StringGrid2SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
  SelectedWindow->Text = StringGrid2->Rows[ARow]->Text;
  SelectedWindow->Tag = (int)StringGrid2->Rows[ARow]->Objects[0];
}
//---------------------------------------------------------------------------


