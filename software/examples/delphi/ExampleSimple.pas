program ExampleSimple;

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
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = 'ABC';

var
  e: TExample;

procedure TExample.Execute;
var voltage: word;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  v := TBrickletVoltage.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(v);
  { Don't use device before it is added to a connection }

  { Get current voltage (unit is mV) }
  voltage := v.GetVoltage;
  WriteLn(Format('Voltage: %f V', [voltage/1000.0]));

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
