program Project_MyRecordDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  PersonRecordType = Record
    Name : String[30];
    PhoneNumber : String[13];
    Age : Integer;
    Sex : Char;
  end;

var
  Person : PersonRecordType;

begin
  Person.Name := 'Dan Osier';
  Person.PhoneNumber := '(916)555-1212';
  Person.Age := 32;
  Person.Sex := 'M';

  WriteLn('The person''s name is ',Person.Name);
  WriteLn('The person''s Phone number is ',Person.PhoneNumber);
  WriteLn('The person''s age is ',Person.Age);
  WriteLn('The person''s sex is ',Person.Sex);

  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end. {Project_MyRecordDemo}
