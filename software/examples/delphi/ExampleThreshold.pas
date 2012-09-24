program ExampleThreshold;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletVoltage;

type
  TExample = class
  private
    ipcon: TIPConnection;
    v: TBrickletVoltage;
  public
    procedure ReachedCB(const voltage: word);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = 'ABC'; { Change to your UID }

var
  e: TExample;

{ Callback for voltage smaller than 5V }
procedure TExample.ReachedCB(const voltage: word);
begin
  WriteLn(Format('Voltage dropped below 5V: %f', [voltage/1000.0]));
end;

procedure TExample.Execute;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  v := TBrickletVoltage.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(v);
  { Don't use device before it is added to a connection }

  { Get threshold callbacks with a debounce time of 10 seconds (10000ms) }
  v.SetDebouncePeriod(10000);

  { Register threshold reached callback to procedure ReachedCB }
  v.OnVoltageReached := {$ifdef FPC}@{$endif}ReachedCB;

  { Configure threshold for "greater than 200 Lux" (unit is Lux/10) }
  v.SetVoltageCallbackThreshold('<', 5*1000, 0);

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.