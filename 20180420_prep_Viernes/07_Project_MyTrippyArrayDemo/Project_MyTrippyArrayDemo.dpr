program Project_MyTrippyArrayDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  SuperArrayType = array [1..3, 1..3] of char;

var
  SuperArray : SuperArrayType;

begin
  SuperArray[1,1] := 'X';
  SuperArray[2,2] := 'X';
  SuperArray[3,3] := 'X';
  SuperArray[3,1] := 'O';
  SuperArray[1,3] := 'O';

  WriteLn(SuperArray[1,1],' ',SuperArray[2,1],' ',SuperArray[3,1]);
  WriteLn(SuperArray[1,2],' ',SuperArray[2,2],' ',SuperArray[3,2]);
  WriteLn(SuperArray[1,3],' ',SuperArray[2,3],' ',SuperArray[3,3]);

  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}

end. {Project_MyTrippyArrayDemo}
 