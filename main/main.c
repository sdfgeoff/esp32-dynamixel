#include <stdio.h>
#include <string.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "esp_event_loop.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"


#include "xl320.h"


esp_err_t event_handler(void *ctx, system_event_t *event) {
	return ESP_OK;
}


void control_task(void *pvParameter){
	servo_init();
	while(1){
		//~ vTaskDelay(1000 / portTICK_PERIOD_MS);
		//~ servo_set_led(2, SERVO_RED);
		//~ servo_set_position(2, 0.0);
		
		//~ vTaskDelay(1000 / portTICK_PERIOD_MS);
		//~ servo_set_led(2, SERVO_GREEN);
		//~ servo_set_position(2, 1.5);
		
		//~ vTaskDelay(1000 / portTICK_PERIOD_MS);
		//~ servo_set_led(2, SERVO_BLUE);
		//~ servo_set_position(2, -1.5);
		
		//~ vTaskDelay(1000 / portTICK_PERIOD_MS);
		//~ servo_set_led(2, SERVO_BLUE | SERVO_GREEN);
		//~ servo_set_position(2, -1.5/2);
		
		vTaskDelay(100 / portTICK_PERIOD_MS);
		float position = 0.0;
		if (servo_get_position(2, &position) == SERVO_OK){
			servo_set_position(2, position);
		}
		if (servo_get_position(1, &position) == SERVO_OK){
			servo_set_position(1, position);
		}
		printf("Position: %f\n", position);
	}
}


void app_main()
{
    xTaskCreate(&control_task, "control_task", configMINIMAL_STACK_SIZE+100, NULL, 5, NULL);
}





