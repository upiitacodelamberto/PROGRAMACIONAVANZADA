program Project_SetDEmoProgram;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  KeysValues = 1..9;
  CharValues = 'a'..'z';
  {OtherChars = '*'..'#';}
  KeysType = set of KeysValues;
  CharKey = set of CharValues;
  {SomeChars = set of OtherChars;}

var
  Keys : KeysType;
  APossibleUserInput : KeysType;
  APosibChKey : CharKey;
  UserInput : Char;

begin
  {Read(UserInput);}
  APossibleUserInput := [];
  If 1 in APossibleUserInput then
    WriteLn('That value was OK');
  Keys := [2,4,6];
  If 0 in Keys then
    WriteLn('0 is in Keys');

  If 2 in Keys then
    WriteLn('That value was OK_1');

  APosibChKey := ['a','e','i','o','u'];
  {WriteLn('Inserte un Char:');}
  {Read(UserInput);}
  UserInput := 'a';
  If UserInput in APosibChKey then
    WriteLn('That value was OK_2');

  {SomeCharrs := ['A','B','*'];}
  UserInput := '*';
  {If UserInput in SomeChars then
    WriteLn('That value was OK_3');}

  ReadLn {Evita que la ventana se ciere hasta que se oprima enter}
end.
