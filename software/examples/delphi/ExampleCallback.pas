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
    procedure VoltageCB(sender: TObject; const voltage: word);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = 'ABC'; { Change to your UID }

var
  e: TExample;

{ Callback function for voltage callback (parameter has unit mV) }
procedure TExample.VoltageCB(sender: TObject; const voltage: word);
begin
  WriteLn(Format('Voltage: %f V', [voltage/1000.0]));
end;

procedure TExample.Execute;
begin
  { Create IP connection }
  ipcon := TIPConnection.Create();

  { Create device object }
  v := TBrickletVoltage.Create(UID, ipcon);

  { Connect to brickd }
  ipcon.Connect(HOST, PORT);
  { Don't use device before ipcon is connected }

  { Set Period for voltage callback to 1s (1000ms)
    Note: The callback is only called every second if the 
          voltage has changed since the last call! }
  v.SetVoltageCallbackPeriod(1000);

  { Register illuminance callback to procedure IluminanceCB }
  v.OnVoltage := {$ifdef FPC}@{$endif}VoltageCB;

  WriteLn('Press key to exit');
  ReadLn;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
