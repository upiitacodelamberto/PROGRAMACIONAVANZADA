unit MyIntegerDemo;

interface

uses
  Forms;

implementation

var
  Pay : Integer;
  OverTimePay : Integer;
  TotalPay : Integer;

begin
  Pay:=500;
  OverTimePay:=100;
  TotalPay:=Pay+OverTimePay;
  WriteLn('The total Pay is $',TotalPay);
  Readln {Para evitar el cierre de la ventana hasta oprimir enter}
end. {MyIntegerDemo}
