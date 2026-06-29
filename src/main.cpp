#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid = ""; // add upon use
const char* password = ""; // add upon use

String botToken = ""; // add upon use
String chatID = ""; // add upon use

#define PIR_PIN 23


bool motionSent = false;
unsigned long lastMotionTime = 0;
unsigned long cooldown = 15000;


// Telegram send function
void sendTelegram(const String &text) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected");
    return;
  }

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;
  
  String url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatID + "&text=Motion%20detected!";
  http.begin(client, url);
  http.setTimeout(5000);
  Serial.println(url);


  int code = http.GET();

  Serial.print("HTTP code: ");
  Serial.println(code);

  if (code > 0) {
    Serial.println(http.getString());
  }

  http.end();
}

// Setup
void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);

  Serial.println("\n[SYSTEM] Booting...");

  int attempts = 0;
  WiFi.begin(ssid, password);
  Serial.print("[WiFi] Connecting");

  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n[WiFi] Connected!");
    Serial.print("[WiFi] IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n[WiFi] Connection failed!");
  }

  Serial.println("[SYSTEM] PIR warming up (30s)...");
  delay(30000);
  Serial.println("[SYSTEM] Ready!");
}

// Loop
void loop() {
  int pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH) {
    if (!motionSent && (millis() - lastMotionTime > cooldown)) {
      sendTelegram("Motion detected!");
      motionSent = true;
      lastMotionTime = millis();
    }
  } else {
    motionSent = false;
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected. Reconnecting...");

    WiFi.reconnect();

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi reconnected!");
    } else {
        Serial.println("\nReconnect failed.");
    }
  }
  delay(500);
}
