program Project_MyBooleanDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  OKtoGo : Boolean;
  MyFlag : Boolean;

begin
  OKtoGo := FALSE;
  MyFlag := not OKtoGo;
  WriteLn('OKtoGo flag is set to ',OKtoGo);
  WriteLn('MyFlag is set to ',MyFlag);
  WriteLn('These two flags logically or ed is ',OKtoGo or MyFlag);
  WriteLn('These two flags logically and d is ',OKtoGo and MyFlag);
  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end. {MyBooleanDemo}
 