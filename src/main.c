#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"

#define FAN_PIN 29    // GPIO pin connected to the fan's PWM input (blue wire)
#define LED_PIN 25    // Onboard LED for debugging
#define PWM_WRAP 62500  // PWM wrap value for 1kHz frequency

/*
Fan Connection Guide:
- Red wire (U/V, power): Connect to VBUS pin on Pico (5V from USB)
- Black wire (G, ground): Connect to any GND pin on Pico
- Blue wire (P, PWM): Connect to GPIO 29 (or your chosen GPIO pin)
- Yellow wire (F, feedback): Leave unconnected (not used in this code)
*/

void set_fan_speed(uint16_t speed) {
    // speed should be between 0 (off) and 100 (full speed)
    if (speed > 100) speed = 100;
    
    uint16_t pwm_level = (speed * PWM_WRAP) / 100;
    pwm_set_gpio_level(FAN_PIN, pwm_level);
}

int main() {
    stdio_init_all();

    // Initialize the onboard LED for debugging
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Initialize PWM for the fan
    gpio_set_function(FAN_PIN, GPIO_FUNC_PWM);
    unsigned int slice_num = pwm_gpio_to_slice_num(FAN_PIN);
    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_enabled(slice_num, true);

    while (1) {
        // Toggle the LED to indicate the program is running
        gpio_put(LED_PIN, 1);  // Turn LED on
        sleep_ms(250);         // Wait for 250ms
        gpio_put(LED_PIN, 0);  // Turn LED off
        sleep_ms(250);         // Wait for 250ms

        // Gradually increase fan speed
        for (int i = 0; i <= 100; i += 10) {
            set_fan_speed(i);
            sleep_ms(1000);  // Wait for 1 second
        }

        // Gradually decrease fan speed
        for (int i = 100; i >= 0; i -= 10) {
            set_fan_speed(i);
            sleep_ms(1000);  // Wait for 1 second
        }
    }

    return 0;
}
