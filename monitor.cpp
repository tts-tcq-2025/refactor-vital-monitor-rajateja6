#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
bool isTemperatureOk(float temperature) {
  return temperature >= 95 && temperature <= 102;
}
bool isPulseOk(float pulseRate) {
  return pulseRate >= 60 && pulseRate <= 100;
}
bool isSpO2Ok(float spo2) {
  return spo2 >= 90;
}
VitalStatus checkVitals(float temperature, float pulseRate, float spo2) {
  VitalStatus status;
  status.temperatureOk = isTemperatureOk(temperature);
  status.pulseOk = isPulseOk(pulseRate);
  status.spo2Ok = isSpO2Ok(spo2);
  return status;
}
void blinkAlarm(int times) {
  for (int i = 0; i < times; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
  cout << "\n";
}
void showAlert(const VitalStatus& status) {
  if (!status.temperatureOk) {
    cout << "Temperature is critical!\n";
    blinkAlarm();
  }
  if (!status.pulseOk) {
    cout << "Pulse Rate is out of range!\n";
    blinkAlarm();
  }
  if (!status.spo2Ok) {
    cout << "Oxygen Saturation out of range!\n";
    blinkAlarm();
  }
  if (status.temperatureOk && status.pulseOk && status.spo2Ok) {
    cout << "All vitals are OK.\n";
  }
}
