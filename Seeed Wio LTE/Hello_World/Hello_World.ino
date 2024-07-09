

void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(115200);
  delay(2000);

  SerialUSB.println("\n\nStarting!");
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialUSB.println("Hello World!");
  delay(1000);
}
