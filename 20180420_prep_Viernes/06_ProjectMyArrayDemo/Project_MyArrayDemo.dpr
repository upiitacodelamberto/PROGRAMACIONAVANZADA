program Project_MyArrayDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  MyArrayType = array [1..5] of Real;
type
  MyNewType = array [6..10] of Integer;

var
  PersonScores : MyArrayType;
  PersonAges : MyNewType;

begin

  PersonScores[1] := 55.6;
  PersonScores[2] := 79.7;
  PersonScores[3] := 42.2;
  PersonScores[4] := 100.0;
  PersonScores[5] := 34.9;

  WriteLn(PersonScores[1]);
  WriteLn(PersonScores[2]);
  WriteLn(PersonScores[3]);
  WriteLn(PersonScores[4]);
  WriteLn(PersonScores[5]);

  PersonAges[6] := 20;
  PersonAges[7] := 34;
  PersonAges[8] := 39;
  PersonAges[9] := 41;
  PersonAges[10] := 47;
  WriteLn(PersonAges[6]);
  WriteLn(PersonAges[7]);
  WriteLn(PersonAges[8]);
  WriteLn(PersonAges[9]);
  WriteLn(PersonAges[10]);

  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end.
