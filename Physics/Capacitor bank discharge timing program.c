#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*

calc discharge time using formula: t = -(R * C * log(V_final/V_initial))
used in very epic electromag railguns for timing the current bursts

*/

uint64_t main(uint64_t argc, char *argv[INT8_MAX]) {
  printf("\n\n");

  float capacitance, resistance, start_voltage, safe_voltage;
  
  printf("     Enter capacitance: ");        scanf("%f", &capacitance);
  printf("      Enter resistance: ");        scanf("%f", &resistance);
  printf("Enter starting voltage: ");        scanf("%f", &start_voltage);
  printf("    Enter safe voltage: ");        scanf("%f", &safe_voltage);

  float time_seconds = -1.0f * (resistance * capacitance * log(safe_voltage/start_voltage));
  
  printf("\nDischarge time: [%.5f]s | ", time_seconds);
  printf("[%.5f]mins", time_seconds / 6E1);

  /* 
  // bo IEC 60831 standard - 75V within 3m
  if (time_seconds > 180 && safe_voltage >= 75) {
    printf("exceeded resistance val mf");
  }
  */

  return EXIT_SUCCESS;
}
