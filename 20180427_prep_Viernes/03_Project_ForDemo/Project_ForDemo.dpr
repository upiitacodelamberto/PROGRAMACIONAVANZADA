program Project_ForDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  Count : Integer;

begin
  For Count := 1 to 10 do
    WriteLn('HELLO ',Count);
  ReadLn {evitar cierre hasta oprimir enter}
end.
