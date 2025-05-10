/*
  📏 Step-by-Step Calibration Process:

  Expose the MQ-136 sensor to known H₂S concentrations (e.g., 20 PPM, 50 PPM, 100 PPM).
  Record the sensor's output voltage (Vout) at each concentration.
  Calculate sensor resistance (Rs) using:
      Rs = ((Vc - Vout) / Vout) * RL
      - Vc = Supply Voltage (typically 3.3V or 5V)
      - Vout = Measured voltage from sensor
      - RL = Load resistor (e.g., 10kΩ)
  Compute Rs/Ro for each concentration (Ro is Rs in clean air).
  Plot Rs/Ro vs. PPM on a log-log scale.
  Derive a curve or equation for gas PPM estimation using the graph.
*/

const int analogPin = 34;     // MQ136 AO → ESP32 ADC input
const float R_LOAD = 10.0;    // Load resistor in kΩ (adjust based on your setup)
const int samples = 10;       // Number of samples to average

float Ro = 1.0;               // Initial Ro value (to be calibrated)

void setup() {
  Serial.begin(115200);
  Serial.println(" MQ-136 Sensor Calibration Started...");
  delay(1000);
}

void loop() {
  float totalVoltage = 0.0;

  // Take multiple readings for accuracy
  for (int i = 0; i < samples; i++) {
    int rawADC = analogRead(analogPin);
    float voltage = rawADC * (3.3 / 4095.0);  // Convert ADC to voltage (ESP32: 12-bit)
    totalVoltage += voltage;
    delay(10);
  }

  float Vout = totalVoltage / samples;           // Average sensor voltage
  float Rs = ((3.3 - Vout) / Vout) * R_LOAD;     // Calculate sensor resistance
  float ratio = Rs / Ro;                         // Calculate Rs/Ro ratio

  // Display results
  Serial.print("Voltage: ");
  Serial.print(Vout, 3);
  Serial.print(" V | Rs: ");
  Serial.print(Rs, 2);
  Serial.print(" kΩ | Rs/Ro: ");
  Serial.println(ratio, 2);

  delay(2000);  // Wait before next reading
}
