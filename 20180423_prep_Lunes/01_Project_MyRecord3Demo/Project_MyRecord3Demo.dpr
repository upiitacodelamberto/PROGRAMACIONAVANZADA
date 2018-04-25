program Project_MyRecord3Demo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  AddressType = record
    Street : String[50];
    City : String[20];
    State : String[2];
    ZipCode : String[10];
  end; {AddressType}

  PersonType = record
    LastName : String[20];
    FirstName : String[10];
    EmployeeNumber : Integer;
    HomeAddress : AddressType;
    WorkAddress : AddressType;
  end; {PersonType}

var
  Employee : PersonType;

begin
  with Employee do
  begin   {the with stuff}
    LastName := 'Osler';
    FirstName := 'Don';
    EmployeeNumber := 16253;
  end;  {with Employee}

  with Employee.HomeAddress do
  begin
    Street := '1313 Your St.';
    City := 'MyTown';
    State := 'CA';
    ZipCode := '95630-0011';
  end;  {with Employee.HomeAddress}

  with Employee.WorkAddress do
  begin
    Street := '14 Big Bussines Road';
    City := 'NoOzone';
    State := 'CA';
    ZipCode := '95636-2211';
  end; {with Employee.WorkAddress}

  with Employee do
  begin
    WriteLn(LastName);
    WriteLn(FirstName);
    WriteLn(EmployeeNumber);
  end; {with Employee}

  with Employee.HomeAddress do
  begin
    WriteLn(Street);
    WriteLn(City);
    WriteLn(State);
    WriteLn(ZipCode);
  end; {with Employee.HomeAddress}

  with Employee.WorkAddress do
  begin
    WriteLn(Street);
    WriteLn(City);
    WriteLn(State);
    WriteLn(ZipCode);
  end; {with Employee.WorkAddress}

  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end.
