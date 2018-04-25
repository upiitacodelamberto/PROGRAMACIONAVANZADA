program Project_IfDemo2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  UserInput : Integer;

begin
  Write('How old you are? ');
  ReadLn(UserInput);
  If (UserInput < 1) or (UserInput > 130) Then
     WriteLn('You are not telling the truth.')
  else
    WriteLn('Being ',UserInput,' years old is great!');

  ReadLn {evitar cierre hasta oprimir enter};
end.
 