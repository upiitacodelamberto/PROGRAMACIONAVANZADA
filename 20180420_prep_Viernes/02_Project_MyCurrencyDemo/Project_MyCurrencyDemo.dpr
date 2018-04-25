program Project_MyCurrencyDemo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  TaxRate = 0.0075;
var
  Pay : Currency;
  OverTimePay : Currency;
  GRossPay : Currency;
  NetPay : Currency;

begin
  Pay := 500.55;
  OverTimePay := 100.10;
  GrossPay := Pay + OverTimePay;
  NetPay := GrossPay - (GrossPay * TaxRate);
  WriteLn('The Total Gross Pay is $',GrossPay);
  WriteLn('The total Net Pay is $',NetPay);
  ReadLn {Para evitar el cierre de la ventana hasta oprimir enter}
end.
 