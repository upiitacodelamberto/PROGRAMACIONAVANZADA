program Project_JunkDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  UsersNumber : Integer;
  UsersString : String;
procedure Junk(Number : Integer; Stuff : String);

begin
  WriteLn('El numero es ',Number);
  WriteLn('El String es ',Stuff);
end; {procedure Junk}
begin
  Write('Enter your string : ');
  ReadLn(UsersString);
  Write('Enter your number : ');
  ReadLn(UsersNumber);
  Junk(UsersNumber,UsersString);
  ReadLn {evitar cierre hasta oprimir enter}
end. {program JunkDemo}
