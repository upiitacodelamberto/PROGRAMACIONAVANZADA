unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    PrimeList: TListBox;
    Min: TEdit;
    Max: TEdit;
    Button1: TButton;
    procedure Button1Click(Sender : TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}
procedure TForm1.Button1Click(Sender : TObject);
var
  Low, High, Count, Count2 : Integer;
begin
  PrimeList.Items.Clear;
  {Obtiene los limites del ciclo de los cuadros de edicion}
  Low := strtoint(Min.Text);
  High := strtoint(Max.Text);

  {Efectua la iteracion para los numeros en el rango}
  for Count := Low to High do
  begin
    Count2 := 2;
    {Determina si el numero se divide entero o si hemos lelgado al limite}
    while(Count2 < Count) and not (Count mod Count2 = 0) do
      inc(Count2);
    {Si el numero es primo, incorporelo al cuadro de la lista}
    If (Count=Count2) then
      PrimeList.Items.Add(inttostr(Count));
  end; {for}
end; {del procedimiento}

end. {del programa}
