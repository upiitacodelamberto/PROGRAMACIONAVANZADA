program Project_MyEnumerateDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  StopLightColors = (Red, Yellow, Green);
var
  MyLight : StopLightColors;

begin
  MyLight := Red;
  WriteLn('My light is currently ',Integer(MyLight));
  MyLight := Green;
  WriteLn('My new light is currently ',Integer(MyLight));
  ReadLn  {evitar ciere hasta opriir enter}
end.
 