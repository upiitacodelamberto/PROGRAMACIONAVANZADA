program Project_TypedConstantDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  MyName : String = 'Dan Osier';

begin
  WriteLn('My name is ',MyName);
  MyName := 'Jim Fischer';        {Esta l\'inea produce un error}
  WriteLn('My new name is',MyName);
  ReadLn {hasta opriir enter}
end.
