Hardware:
  ESP32-Wroom-32
  HC-SR501 PIR Motion Sensor Module (VCC 5v, OUT-GPIO23, GND-GND)

How to Build/Upload to board (using PlatformIO):
1. Open cloned directory in VS code. As I have included all needed files for PlatformIO project config, nothing should be added except Bot token, ChatId of Telegram Account on which you want to get updates if Motion was detected. Default GPIO pin is 23 and can be edited.
2. Using build-in PlatformIO Upload command flash software on your board.
   
