#pragma once
#include <string>

struct VitalStatus {
  bool temperatureOk;
  bool pulseOk;
  bool spo2Ok;
};

VitalStatus checkVitals(float temperature, float pulseRate, float spo2);
void showAlert(const VitalStatus& status);
void blinkAlarm(int times = 6);

bool isTemperatureOk(float temperature);
bool isPulseOk(float pulseRate);
bool isSpO2Ok(float spo2);
