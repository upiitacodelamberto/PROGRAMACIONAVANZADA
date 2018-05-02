program Project_PointerDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type
  RealPointer = ^Real;

  PersonType = record
    LastName : String;
  end;
  PersonPointer = ^PersonType;

var
  P : RealPointer;   {float *P;}
  Person : PersonPointer;
begin
  New (P);     {P = new float[1];}
  p^ := 21234.65;  {*P = 21.6;}
  WriteLn('STR_1 ',P^ :5:1,' STR_2');
  Dispose(P);
  New (Person);
  Person^.LastName := 'Smith';
  WriteLn(Person^.LastName);
  dispose(Person);
  ReadLn; {eviatr cierre hasta oprimir enter}
end. {PointerDemo}
