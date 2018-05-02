program ProjectUnitDemo;

{$APPTYPE CONSOLE}

uses
  Sysutils,
  MathStuff in 'MathStuff.pas';

var
  A,B : Integer;
begin
  A := 1;
  B := 2;
  WriteLn('La suma de ',A,' y ',B,' es ',AddTwoNumbers(A,B));
  WriteLn('La resta de ',A,' y ',B,' es ',SubstractTwoNumbers(A,B));
  WriteLn('La multiplicacion de ',A,' y ',B,' es ',MultiplyTwoNumbers(A,B));
  PositiveKarma;
  ReadLn {evitar cierre hasta oprimir enter}
end.
 