program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

Function Square(TheInput : Real) : Real;

  begin
    Square := TheInput * TheInput;
  end;

var UserInput : Real;
begin
  Write('Enter the number you want to square: ');
  readLn(UserInput);
  WriteLn(UserInput, ' squared is equal to ',Square(UserInput));
  {WriteLn('Texto',Square); esta linea es invalida}
  ReadLn {evitar cierre hasta oprimir enter}
end.  {Project1}
