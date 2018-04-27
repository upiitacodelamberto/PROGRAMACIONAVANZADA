program Project_ParamDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  Number : Integer;

procedure DoVerticals(HowMAnyTimes : Integer);
  var Count : Integer;
  begin
    for Count := 1 to HowMAnyTimes do
      If ((Count mod 2) = 1) then
        WriteLn('   |   |   ')
      else
        WriteLn('-----------');
      {end; }
  end; {Procedure DoVerticals}

begin
  WriteLn('How many sets of vertical lines would you like to print?: ');
  ReadLn(Number);
  DoVerticals(Number);
  If Number mod 2 = 1 then
    DoVerticals(Number);
  ReadLn {evitar cierre hasta oprimir enter}
end.
