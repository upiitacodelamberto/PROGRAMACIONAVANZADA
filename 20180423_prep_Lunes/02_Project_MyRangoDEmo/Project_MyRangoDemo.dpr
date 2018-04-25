program Project_MyRangoDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  LittleLetter = 'a'..'z';

var
  GoodLetters : LittleLetter;

begin
  GoodLetters := 'b';
  WriteLn(GoodLetters);
  ReadLn  {Evitar cierre de la ventana hasta oprimir enter}
end.
 