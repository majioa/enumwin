//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("EnumWin.res");
USEFORM("EnumWinUnit.cpp", EnumWinForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->CreateForm(__classid(TEnumWinForm), &EnumWinForm);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  return 0;
}
//---------------------------------------------------------------------------
