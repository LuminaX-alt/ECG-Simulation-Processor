# Soil-Moisture-Sensors
This project simulates an ECG (Electrocardiogram) waveform generator using an STM32 Nucleo development board (STM32F103RB) on the Wokwi online simulator platform. The simulation outputs an ECG-like signal through a PWM (Pulse Width Modulation) pin, which can be observed on a connected virtual oscilloscope in Wokwi.
Hardware Platform
Microcontroller: STM32F103RB (ARM Cortex-M3 based MCU on STM32 Nucleo board)

Output Pin: PA8 configured as TIM1 Channel 1 PWM output

Simulation Environment: Wokwi online STM32 simulator

Key Components and Functionality
ECG Waveform Lookup Table:

The ECG signal is approximated by a predefined lookup table (ecg_waveform[]), which contains discrete amplitude values representing one ECG cycle. These values are normalized to an 8-bit range (0-255), which corresponds to PWM duty cycle values.

Timer Configuration and PWM Generation:

Timer Used: TIM1 configured for PWM mode.

PWM Resolution: 8-bit resolution with a period of 255 counts.

PWM Output Pin: PA8 (Alternate function push-pull).

The timer's PWM duty cycle is updated at a fixed interval based on the lookup table values to simulate the varying amplitude of the ECG waveform.

Signal Generation Loop:

The main program enters an infinite loop where it iterates through the ECG samples in the lookup table. For each sample, the PWM duty cycle is updated to the corresponding amplitude value.

A delay of 10 milliseconds (HAL_Delay(10)) between updates controls the effective sampling rate of approximately 100 Hz, which simulates the timing of a typical ECG waveform.

System Clock Configuration:

The STM32 clock is configured to run at 72 MHz using the external high-speed oscillator (HSE) and the PLL. This ensures stable timer operation and accurate PWM signal generation.

Applications
This simulation can be used for educational purposes to understand how ECG signals can be generated and visualized using microcontroller PWM outputs.

It forms a basic foundation for building more advanced ECG signal processing and analysis systems using embedded platforms.

The approach is easily extendable to real hardware with DAC output or ADC input for further signal manipulation.
Potential Improvements
Use a DAC peripheral instead of PWM for higher fidelity ECG signal output.

Implement interrupts or timer callbacks for precise timing instead of using blocking delay.

Increase the resolution and size of the ECG lookup table to simulate a more realistic waveform.

Add real-time signal filtering and analysis modules.




![image](https://github.com/user-attachments/assets/96dafa22-2823-4881-b4e2-652a6f15c920)
