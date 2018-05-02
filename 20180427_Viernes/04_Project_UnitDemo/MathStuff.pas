unit MathStuff;

interface
  function AddTwoNumbers(One,Two : Integer) : Integer;
  function SubstractTwoNumbers(One,Two : Integer) : Integer;
  function MultiplyTwoNumbers(One,Two : Integer) : Integer;
  procedure PositiveKarma;

implementation
  function AddTwoNumbers(One,Two : Integer) : Integer;
    begin
      AddTwoNumbers := One + Two;
    end;

  function SubstractTwoNumbers(One,Two : Integer) : Integer;
    begin
      SubstractTwoNumbers := One - Two;
    end;

  function MultiplyTwoNumbers(One,Two : Integer) : Integer;
    begin
      MultiplyTwoNumbers := One * Two;
    end;

  procedure PositiveKarma;
  begin
    writeLn('You can do it, math is not hard!');
  end;
end.
