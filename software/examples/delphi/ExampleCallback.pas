program ExampleCallback;

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
    procedure VoltageCB(const voltage: word);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = 'ABC'; { Change to your UID }

var
  e: TExample;

{ Callback function for voltage callback (parameter has unit mV) }
procedure TExample.VoltageCB(const voltage: word);
begin
  WriteLn(Format('Voltage: %f V', [voltage/1000.0]));
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

  { Set Period for voltage callback to 1s (1000ms)
    Note: The callback is only called every second if the 
          voltage has changed since the last call! }
  v.SetVoltageCallbackPeriod(1000);

  { Register illuminance callback to procedure IluminanceCB }
  v.OnVoltage := {$ifdef FPC}@{$endif}VoltageCB;

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
