program Project_BifurcacionDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  Answer : String;

label ThePlace;

begin
  ThePlace : WriteLn('Helo World');
  WriteLn('Would you like to run this again?');
  ReadLn(Answer);
  If (Answer = 'y') then
    Goto ThePlace;
  ReadLn {evitar cierre hasta oprimir ente}
end.
