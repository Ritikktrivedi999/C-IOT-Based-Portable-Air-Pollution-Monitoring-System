#include <ESP8266WiFi.h>
#include <ThingSpeak.h> // Include ThingSpeak library
//ThingSpeak Details
const char *ssid = "";
const char *password = "";
const char *thingSpeakApiKey = "";
const unsigned long channelNumber = ""; // Replace with your ThingSpeak channel number

WiFiClient client; // Declare WiFiClient object

void setup() {
  Serial.begin(9600);
  connectToWiFi();

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read sensor data from Arduino
  String sensorData = readSensorData();

  // Parse the sensor data
  float mq2Value = parseSensorValue(sensorData, "MQ2:");
  float mq135Value = parseSensorValue(sensorData, "MQ135:");
  float mq7Value = parseSensorValue(sensorData, "MQ7:");
  float mq4Value = parseSensorValue(sensorData, "MQ4:");
  float mq5Value = parseSensorValue(sensorData, "MQ5:");

  // Print the parsed sensor values to Serial for debugging
  Serial.print("MQ2: ");
  Serial.println(mq2Value);
  Serial.print("MQ135: ");
  Serial.println(mq135Value);
  Serial.print("MQ7: ");
  Serial.println(mq7Value);
  Serial.print("MQ4: ");
  Serial.println(mq4Value);
  Serial.print("MQ5: ");
  Serial.println(mq5Value);

  // Send data to ThingSpeak
  ThingSpeak.setField(1, mq2Value);
  ThingSpeak.setField(2, mq135Value);
  ThingSpeak.setField(3, mq7Value);
  ThingSpeak.setField(4, mq4Value);
  ThingSpeak.setField(5, mq5Value);

  int x = ThingSpeak.writeFields(channelNumber, thingSpeakApiKey);

  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  delay(15000); // Delay before next readings
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

String readSensorData() {
  String data = "";
  while (Serial.available() == 0) {
    // Wait for data from Arduino
  }
  while (Serial.available() > 0) {
    char ch = static_cast<char>(Serial.read());
    data += ch;
  }
  return data;
}

float parseSensorValue(String data, String sensor) {
  int sensorIndex = data.indexOf(sensor);
  if (sensorIndex != -1) {
    int valueIndex = sensorIndex + sensor.length();
    int commaIndex = data.indexOf(',', valueIndex);
    if (commaIndex == -1) {
      commaIndex = data.length();
    }
    String valueString = data.substring(valueIndex, commaIndex);
    valueString.trim(); // Remove any leading/trailing whitespace
    return valueString.toFloat();
  }
  return -1.0; // Return -1 if sensor data not found
}
