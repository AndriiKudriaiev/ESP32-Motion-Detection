Hardware:
  ESP32-Wroom-32
  HC-SR501 PIR Motion Sensor Module (VCC 5v, OUT-GPIO23, GND-GND)

How to Build/Upload to board (using PlatformIO):
1. Open cloned directory in VS code. As I have included all needed files for PlatformIO project config, nothing should be added except Bot token, ChatId of Telegram Account on which you want to get updates if Motion was detected. Default GPIO pin is 23 and can be edited.
2. Using build-in PlatformIO Upload command flash software on your board.
   

<img width="3024" height="4032" alt="IMG_2379" src="https://github.com/user-attachments/assets/854cb252-9e44-46ec-af80-c61facf7d465" />
<img width="3024" height="4032" alt="IMG_2380" src="https://github.com/user-attachments/assets/2fe987df-8a80-491c-8dd9-710691f0d881" />
<img width="3024" height="4032" alt="IMG_2381" src="https://github.com/user-attachments/assets/608c9109-de3d-4578-aa84-950e2d9b8a66" />

Troubleshooting:
  if you want to power this setup with power bank, you need to consider checking if it has low-current mode. If not you will need to ad a resistor (100-200 ohm is enough) between 5v and GND pin to make ESP32 not disconecting from power source upon entering low-consumpsion mode.

<img width="1440" height="1920" alt="IMG_2384" src="https://github.com/user-attachments/assets/e937cc3c-9982-440d-b5a0-2b9877b7371e" />
<img width="3024" height="4032" alt="IMG_2383" src="https://github.com/user-attachments/assets/335bd3a9-ab1e-42ee-976e-3df289a469f1" />
