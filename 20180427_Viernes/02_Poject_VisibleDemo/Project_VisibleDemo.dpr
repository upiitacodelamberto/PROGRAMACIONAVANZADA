program Project_VisibleDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  A : Integer;

  procedure Outer;
    var B : Integer;

    procedure Inner;
      var C : Integer;

      begin
        C := 3;
        B := 8;
        A := 4; {Se puede ver A de las declaraciones ndel programa principal}
      end;
    begin
      B := 5;
      {C := 5; Esto sria ilegal, se puede ver solo hacia Outer, no hacia Inner}
      A := 9; {A esta declarado en el programa principal}
    end; {procedure Outer}

  procedure AnotherOne;
    var
      D : Integer;

    begin
      D := 9;
      A := 55; {A declarado en el programa principañ}
      {B := 4; Esto seria ilegal}
      {C := 5;  Esto seria ilegal}
    end;
begin
  A := 1;
  {No podemos referenciar ninguna variable local a ningun procedimiento
   desde aqui, No son visibles}
   ReadLn {evitar cierre hasta oprimir enter}
end.
