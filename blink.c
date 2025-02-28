#include "hardware/gpio.h"
#include <pico/cyw43_arch.h>
#include <pico/stdlib.h>
#include <task.h>


#define MAIN_LED_DELAY 200

void led_task(void *pvParameters);

void display_task(void *pvParameters);
void display_task1(void *pvParameters);

void start_tasks();

int main() {
    stdio_init_all();  // Initialize

    printf("Main Program Executation start!\n");

      start_tasks();

    return 0;
}

void start_tasks() {
    // Create Your Task
    xTaskCreate(
        display_task,    // Task to be run
        NULL         // Task Handle if available for managing the task
    );
    xTaskCreate(
        led_task,    // Task to be run
        NULL         // Task Handle if available for managing the task
    );

    xTaskCreate(
        display_task1,    // Task to be run
        NULL         // Task Handle if available for managing the task
    );
    // Should start you scheduled Tasks (such as the LED_Task above)
    vTaskStartScheduler();

    while (true) {
        // Your program should never get here
    };
}

void display_task(void *pvParameters) {
	int i=0;
 	while(true){
        vTaskDelay(MAIN_LED_DELAY);  // Delay by TICKS defined by FreeRTOS priorities
	printf("IN TASK 2 %d\n",i++);
        vTaskDelay(MAIN_LED_DELAY);  // Delay by TICKS defined by FreeRTOS priorities
 	}
}

void display_task1(void *pvParameters) {
//  	while(true){
        vTaskDelay(MAIN_LED_DELAY);  // Delay by TICKS defined by FreeRTOS priorities
	printf("IN TASK 3 \n");
        vTaskDelay(MAIN_LED_DELAY);  // Delay by TICKS defined by FreeRTOS priorities
//  	}
}
void led_task(void *pvParameters) {
    bool is_connected = true;
    if (cyw43_arch_init()) {
        printf("WiFi init failed\n");
        is_connected = false;
    }

    while (is_connected) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        printf("LED tuned ON!\n");
        vTaskDelay(MAIN_LED_DELAY);  // Delay by TICKS defined by FreeRTOS priorities
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        printf("LED turned OFF\n");
        vTaskDelay(MAIN_LED_DELAY);
    }
}
