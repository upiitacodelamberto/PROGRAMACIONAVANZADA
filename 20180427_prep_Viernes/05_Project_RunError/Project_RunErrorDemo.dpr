program Project_RunErrorDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  I : Char;
  Count : Integer;

begin
  repeat
    Write('Enter a value: ');
    Read(I);
    If (I = 'Q') Then
      RunError (50);
  Until FALSE;
  ReadLn {evitar cierre hasta oprimir enter}
end.
