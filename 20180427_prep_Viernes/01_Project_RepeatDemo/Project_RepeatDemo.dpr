program Project_RepeatDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  I : Char;

begin
  repeat
    Write('Enter a value: ');
    Read(I);
  until (I = 'q') or (I = 'Q');
  ReadLn {evitar cierre hasta oprimir enter}
end.
