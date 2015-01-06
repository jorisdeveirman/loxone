# Loxone

Various tips and tricks for Loxone.

## Elsner Weather Station
[elsner-weather-station.c](/elsner-weather-station.c) is an improved script that offers the same functionality as the RS-485 Elsner Weather Station template.
Main reason to use this script is because the standard RS-485 parsing is limited and return incorrect values in some cases, e.g. wrong windspeed in case of no sunshine.

### How to use this script
1. Add an RS-485 Device (if not done already) and name it '*Elsner Weather Station*'
1. Set the following parameters:
  1. Baudrate: 19200
  1. Databits: 8
  1. Stopbits: 1
  1. Parity: None
1. Add a new '*Program with 16 in/out*'
1. Copy/Paste the content of [elsner-weather-station.c](/elsner-weather-station.c) in the Program Code

### Using the Program

The following outputs are used:

1. Temperature in °C
1. Lightvalue South in kLux
1. Lightvalue West in kLux
1. Lightvalue East in kLux
1. Daylightvalue Lux
1. Dawn, 1 if Dawn, 0 otherwise
1. Windspeed in km/hr
1. Rain, 1 on Rain, 0 if dry
