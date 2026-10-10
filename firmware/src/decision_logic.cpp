#include "decision_logic.h"

bool shouldAlert(const DetectionResult& result) {
  return (!result.personDetected) && (result.lightOn || result.acOn);
}
