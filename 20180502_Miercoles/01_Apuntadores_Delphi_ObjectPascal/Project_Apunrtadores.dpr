program Project_Apunrtadores;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  IntPointer = ^Integer;

  PersonType = Record
    Nombre : String;
    Edad : Integer;
  end;

  PersonPointer = ^PersonType;

  PersonPointerArray = array [1..3] of PersonPointer;

var
  IntPt : IntPointer;
  PersonPt : PersonPointer;
  PersPointArr : PersonPointerArray;
  index : Integer;

begin
  New(IntPt);
  IntPt^ := 3;
  New(PersonPt);
  WriteLn('IntPt es ',IntPt^);
  PersonPt^.Nombre := 'Ramiro Mendoza';
  PersonPt^.Edad := 20;
  WriteLn('Nombre: ',PersonPt^.Nombre);
  WriteLn('Edad: ',PersonPt^.Edad);
  for index := 1 to 3 do
  begin
    New(PersPointArr[index]);
  end;
  PersPointArr[1]^ := PersonPt^;
  PersPointArr[2]^.Nombre := 'Luis Silva';
  PersPointArr[2]^.Edad := 20;
  WriteLn('|-------------------------------------------------------------|');

  for index := 1 to 2 do
  begin
    WriteLn('Nombre: ',PersPointArr[index]^.Nombre);
    WriteLn('Edad: ',PersPointArr[index]^.Edad);
  end;

  dispose(IntPt);
  dispose(PersonPt);
  for index := 1 to 3 do
  begin
    dispose(PersPointArr[index]);
  end;
  ReadLn { evitar cierre de ventana hasta oprimir Enter }
end.








