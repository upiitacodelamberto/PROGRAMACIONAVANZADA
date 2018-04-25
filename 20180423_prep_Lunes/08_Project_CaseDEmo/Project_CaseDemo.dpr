program Project_CaseDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  UserIn : Char;

begin
  WriteLn('Teclee un Char:');
  ReadLn(UserIn);
  Case UserIn of
    'a'      : WriteLn('That is a small a');
    'z','Z'  : WriteLn('That is a small or capital Z')
  else
    WriteLn('That is a character other than a, z, or Z.');
  end;
  ReadLn  {evitar cierre de ventana hasta oprimir enter}
end.
 