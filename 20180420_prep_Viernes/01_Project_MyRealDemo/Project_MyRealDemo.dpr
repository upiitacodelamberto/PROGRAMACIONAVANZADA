program Project_MyRealDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  TaxRate = 0.075;
var
  Pay : Single;
  OverTimePay : Single;
  GRossPay : Single;
  NetPay : Single;

begin
  Pay := 500.55;
  OverTimePay := 100.10;
  GrossPay := Pay + OverTimePay;
  NetPay := GrossPay - (GrossPay * TaxRate);
  WriteLn('The Total Gross Pay is $',GrossPay);
  WriteLn('The total Net Pay is $',NetPay);
  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end.
 