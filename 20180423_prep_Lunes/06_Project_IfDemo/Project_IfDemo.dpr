program Project_IfDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  UserInput : Integer;

begin
  Write('How old you are? ');
  ReadLn(UserInput);
  WriteLn('Being ',USerInput,' years old is great!');
  ReadLn  {para evitar el cierre de la ventana hasta oprimir enter}
end.
 