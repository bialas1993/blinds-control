#include <VirtualWire.h>

#define resetPin 11
#define ledPin 13  


void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println("Uruchomiono!");
  Serial.println();


  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_rx_start();

  pinMode(resetPin, INPUT_PULLUP);
}

void loop() {
  uint8_t received[VW_MAX_MESSAGE_LEN];
  uint8_t len = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(received, &len)) {
    String message;
    int i;

    for (i = 0; i < len; i++) {
      message += char(received[i]);
    }

    digitalWrite(ledPin, HIGH);

    Serial.print("Message: ");
    Serial.print("" + message);
    Serial.println();
  }
}
