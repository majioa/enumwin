//---------------------------------------------------------------------------

#ifndef EnumWinUnitH
#define EnumWinUnitH
//---------------------------------------------------------------------------
#include <winuser.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <clipbrd.hpp>
#include <Grids.hpp>
#include <stdio.h>
#include <ExtCtrls.hpp>
//#include "unit5dll.h" 
//---------------------------------------------------------------------------
typedef BOOL (CALLBACK* WNDSMPLPROC)();

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

class TEnumWinForm : public TForm
{
__published:	// IDE-managed Components
  TButton *EnumWin;
  TEdit *SelectedWindow;
  TStringGrid *StringGrid1;
  TStringGrid *StringGrid2;
  TEdit *LParam;
  TEdit *WParam;
  TButton *Send;
  TComboBox *MsgComboBox;
  void __fastcall EnumWinClick(TObject *Sender);
  void __fastcall SendClick(TObject *Sender);
  void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
  void __fastcall StringGrid2SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
private:	// User declarations
public:		// User declarations
  __fastcall TEnumWinForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEnumWinForm *EnumWinForm;
//---------------------------------------------------------------------------
#endif
