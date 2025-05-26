// ECG-like waveform simulation on Arduino analog input A0

// We'll simulate ECG waveform using an array of sample values

const int ECG_samples = 200;  // number of samples in one cycle
int ecgWaveform[ECG_samples];

int sampleIndex = 0;

void setup() {
  Serial.begin(115200);

  // Create a fake ECG waveform array
  // This is a simplified waveform mimicking a heartbeat spike
  for (int i = 0; i < ECG_samples; i++) {
    if (i < 10) ecgWaveform[i] = 512 + 20 * i;          // rising edge
    else if (i < 20) ecgWaveform[i] = 712 - 30 * (i-10); // falling edge (spike)
    else if (i < 50) ecgWaveform[i] = 400 + 5 * (i-20);  // small bump
    else ecgWaveform[i] = 512;                          // baseline
  }
}

void loop() {
  int ecgValue = ecgWaveform[sampleIndex];

  Serial.println(ecgValue);

  sampleIndex++;
  if (sampleIndex >= ECG_samples) sampleIndex = 0;

  delay(5);  // controls speed of waveform
}
#include "main.h"
#include <string.h>
#include <stdio.h>

UART_HandleTypeDef huart2;

const int ECG_samples = 200;
uint16_t ecgWaveform[ECG_samples];

int sampleIndex = 0;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  // Prepare ECG waveform array
  for(int i = 0; i < ECG_samples; i++){
    if(i < 10) ecgWaveform[i] = 512 + 20 * i;
    else if(i < 20) ecgWaveform[i] = 712 - 30 * (i-10);
    else if(i < 50) ecgWaveform[i] = 400 + 5 * (i-20);
    else ecgWaveform[i] = 512;
  }

  char msg[20];

  while (1)
  {
    sprintf(msg, "%d\r\n", ecgWaveform[sampleIndex]);
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

    sampleIndex++;
    if(sampleIndex >= ECG_samples) sampleIndex = 0;

    HAL_Delay(5); // adjust speed
  }
}
