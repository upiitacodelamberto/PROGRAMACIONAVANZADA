program Project_MyVariantDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  MyInput : Variant;

begin
  MyInput := 3.5555;
  WriteLn(MyInput);
  MyInput := 'Hello, my name is Dan';
  WriteLn(MyInput);
  ReadLn  {evitar cierre hasta oprimir enter}
end.
