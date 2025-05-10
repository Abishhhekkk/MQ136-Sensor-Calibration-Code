# MQ136-Sensor-Calibration-Code
Calibrates Rs/Ro for precise H₂S detection. Clean, serial-based, Arduino IDE-ready. Ideal for IoT, research, and gas monitoring.


🧪 MQ-136 Gas Sensor Calibration Using ESP32
This project performs a step-by-step calibration of the MQ-136 gas sensor, specifically targeting hydrogen sulfide (H₂S) detection, using an ESP32 microcontroller. The aim is to determine the sensor’s baseline resistance (Ro) in clean air and derive a calibration curve for accurate gas concentration estimation (in PPM).

🔧 Key Features
Uses analogRead to acquire voltage output from the MQ-136.

Computes sensor resistance (Rs) using the formula:
![image](https://github.com/user-attachments/assets/d2498bde-b078-4c9a-a963-1b28692e1251)

Averages multiple samples to improve accuracy.

Outputs:

Sensor Voltage (Vout)

Sensor Resistance (Rs)

Rs/Ro ratio, critical for calibration and PPM estimation.

⚙️ Calibration Procedure
Clean Air Calibration:

Power the sensor in clean, dry air.

Run the code for a few minutes until Rs stabilizes.

Record this Rs as Ro (baseline resistance).

Update the Ro value in the code.

Expose to Known Gas Concentrations:

Use known H₂S concentrations (e.g., 20, 50, 100 PPM).

Record Vout and calculate Rs.

Compute Rs/Ro for each gas concentration.

Plot Rs/Ro vs. PPM (on log-log scale):

X-axis: Gas concentration (log scale)

Y-axis: Rs/Ro (log scale)

Fit a power-law curve to derive a formula:

![image](https://github.com/user-attachments/assets/1455d9dc-1c06-49b6-b67f-84ac770bdf05)
 
This becomes your PPM estimation formula for future use.

📈 Applications
Gas leakage detection systems.

Environmental monitoring.

Smart safety systems.

Industrial gas sensing networks.



![image](https://github.com/user-attachments/assets/912915a5-881c-4552-bd06-f9e5f32c0d4f)


