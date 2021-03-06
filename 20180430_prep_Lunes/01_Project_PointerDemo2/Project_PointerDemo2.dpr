program Project_PointerDemo2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  PersonType = RECORD
    LastName : String;
    FirstName : String;
    Age : Integer;
  end; {PersonType}

  PersonPointer = ^PersonType;

var
  Person : PersonPointer;

begin
  New (Person);
  Person^.LastName := 'Smith';
  Person^.FirstName := 'James';
  Person^.Age := 35;
  WriteLn('Well ',Person^.FirstName,' ',Person^.LastName,', you are ',
  Person^.Age,' years old.');
  dispose(Person);
  ReadLn {evitar cierre de la ventana hast oprimir enter}
end. {PointerDemo2}
 