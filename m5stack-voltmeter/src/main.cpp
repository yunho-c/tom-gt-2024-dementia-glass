#include <Arduino.h>
#include <M5Unified.h>

/*
*******************************************************************************
* Copyright (c) 2023 by M5Stack
* Equipped with M5Core sample source code
* Visit for more information: https://docs.m5stack.com/en/core/gray
*
* Description: Display Example
* Date: 2021/7/21
*******************************************************************************
*/
// #include <M5Stack.h>

/*
 * The program inside the setup() function runs once after M5Core is started or reset.
 */
// Define the analog input pin
#define VOLTAGE_PIN 36  // GPIO36 (VP) is an analog pin on M5Stack

// Voltage reference and scaling
const float ADC_RESOLUTION = 4095.0;  // 12-bit ADC resolution
const float VOLTAGE_REF = 3.3;        // Reference voltage (3.3V for M5Stack)

void setup() {
    M5.begin();        // Initialize M5Stack
    M5.Power.begin();  // Initialize the power module

    // Configure the screen
    M5.Lcd.fillScreen(BLACK);      // Set the screen background color to black
    M5.Lcd.setTextColor(WHITE);    // Set text color to white
    M5.Lcd.setTextSize(2);         // Set text size
    M5.Lcd.setCursor(10, 10);      // Move cursor to start position
    M5.Lcd.printf("Voltmeter\n");  // Display title
}

void loop() {
    // Read the analog input value
    int adcValue = analogRead(VOLTAGE_PIN);

    // Convert the ADC value to voltage
    float voltage = (adcValue / ADC_RESOLUTION) * VOLTAGE_REF;

    // Clear the area where the voltage is displayed
    M5.Lcd.fillRect(10, 50, 300, 30, BLACK);

    // Display the voltage value on the screen
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.printf("Voltage: %.2f V", voltage);

    // Calculate

    M5.Lcd.setCursor(10, 70);
    // float weight_p =
    // M5.Lcd.printf("Weight: %.2f g", weight_p);

    // Wait before reading again
    delay(100);  // Update every 500ms
}
