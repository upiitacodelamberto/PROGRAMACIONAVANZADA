program Project_MyArrayRecordDemo;

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

  MyArrayType = array [1..3] of PersonREcordType;

var
  PersonArray : MyArrayType;

begin
  PersonArray[1].Name := 'Dan Osier';
  PersonArray[1].PhoneNumber := '(916)555-1212';
  PersonArray[1].Age := 32;
  PersonArray[1].Sex := 'M';

  PersonArray[2].Name := 'Susie Smith';
  PersonArray[2].PhoneNumber := '(916)555-9999';
  PersonArray[2].Age := 33;
  PersonArray[2].Sex := 'F';

  PersonArray[3].Name := 'Pat';
  PersonArray[3].PhoneNumber := '(916)555-7766';
  PersonArray[3].Age := 30;
  PersonArray[3].Sex := '?';

  WriteLn('The person 1 name is ',PersonArray[1].Name);
  WriteLn('The person 1 Phone number is ',PersonArray[1].PhoneNumber);
  WriteLn('The person 1 age is ',PersonArray[1].Age);
  WriteLn('The person 1 sex is ',PersonArray[1].Sex);

  WriteLn('The person 2 name is ',PersonArray[1].Name);
  WriteLn('The person 2 Phone number is ',PersonArray[1].PhoneNumber);
  WriteLn('The person 2 age is ',PersonArray[1].Age);
  WriteLn('The person 2 sex is ',PersonArray[1].Sex);

  WriteLn('The person 3 name is ',PersonArray[3].Name);
  WriteLn('The person 3 Phone number is ',PersonArray[3].PhoneNumber);
  WriteLn('The person 3 age is ',PersonArray[3].Age);
  WriteLn('The person 3 sex is ',PersonArray[3].Sex);

  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end. {Project_MyArrayRecordDemo}
