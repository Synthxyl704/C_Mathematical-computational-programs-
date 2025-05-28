#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*

implement a function that reads analog voltage from a position sensor
and converts it to a linear displacement value using the linear interpolation formula
maybe used in vSLAMs

*/

uint64_t main(uint64_t argc, char *argv[]) {
  printf("\n\n");

  // all example values only, please replace w your og/req ones

  float minVoltRange = 0.0f;          // x1 
  float maxVoltRange = 10.0f;         // x2 
  float minPhysicalPos = 0.0f;        // y1 
  float maxPhysicalPos = 100.0f;      // y2 
  float sensorVoltReading = 2.5f;     // x aka analog volt

  float voltReadingAvg = (sensorVoltReading - minVoltRange) / (maxVoltRange - minVoltRange);
  float displacementVal = (maxPhysicalPos - minPhysicalPos);

  float calcPhysicalPos = minPhysicalPos + (voltReadingAvg * displacementVal);

  printf("Linear displacement value: [%.6f]mm\n\n\n", calcPhysicalPos); // just enough for no data truncation
  return EXIT_SUCCESS;
}
