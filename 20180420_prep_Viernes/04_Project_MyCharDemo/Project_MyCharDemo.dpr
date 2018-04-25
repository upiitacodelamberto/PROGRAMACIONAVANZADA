program Project_MyCharDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  Answer : Char;
  Question : Char;

begin
  Question := 'A';
  Answer := 'B';WriteLn('Question is ',Question);
  WriteLn('Answer is ',Answer);

  Answer := Question;
  Question := #66;

  WriteLn('Question now is ',Question);
  WriteLn('Answer now is ',Answer);


  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end. {MyCharDemo}
 