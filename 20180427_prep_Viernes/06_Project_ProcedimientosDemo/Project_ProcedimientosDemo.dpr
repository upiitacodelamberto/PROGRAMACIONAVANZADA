program Project_ProcedimientosDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

procedure DoVerticals;
  begin
    WriteLn('   |   |   ');
  end;
procedure DoHorizontals;
  begin
    WriteLn('------------');
  end;
begin
  DoVerticals;
  DoHorizontals;
  DoVerticals;
  DoHorizontals;
  DoVerticals;
  ReadLn {evitar cierre hasta oprimir enter}
end.
 