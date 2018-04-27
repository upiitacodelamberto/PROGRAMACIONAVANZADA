program Project_WhileDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  I : Char;
begin
  I := 'A';
  While (I <> 'q') or (I <> 'Q') Do
  begin
    Write('Enter a value: ');
    Read(I);
  end;
  ReadLn {evitar cierre hasta oprimir enter}
end.
