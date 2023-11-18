#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gptimer.h"
#include "esp_log.h"

static const char *TAG = "custom_timer";


static gptimer_handle_t gptimer = NULL;
static int counter_0 = 0; // Remove volatile
static int counter_1 = 0; // Remove volatile
static int counter_2 = 0; // Remove volatile
static int counter_3 = 0; // Remove volatile
//static int counter_4 = 0; // Remove volatile



void task1(void *pvParameters) {
    while (1) {
        counter_2++;
        vTaskDelay(pdMS_TO_TICKS(1000));  // Increment counter every 1 second
    }
}

void task2(void *pvParameters) {
    while (1) {
        counter_3++;
        vTaskDelay(pdMS_TO_TICKS(500));  // Increment counter every 0.5 seconds
    }
}


static _Bool IRAM_ATTR example_timer_callback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data) {
    int *counter = (int *)user_data;
    if (counter != NULL) {
        (*counter)++;
        
    }
    return false; // Or true if you want to yield
}


void setup_periodic_timer(uint32_t interval_ms, int *counter) {
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000, // 1MHz, 1 tick = 1us
    };

    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));

    gptimer_alarm_config_t alarm_config = {
        .alarm_count = interval_ms * 1000, // Convert milliseconds to microseconds
        .flags.auto_reload_on_alarm = true, // Enable auto-reload
    };

    ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));

    gptimer_event_callbacks_t cbs = {
        .on_alarm = example_timer_callback,
    };

    ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, counter));

    ESP_ERROR_CHECK(gptimer_enable(gptimer));
    ESP_ERROR_CHECK(gptimer_start(gptimer));
}

void app_main() {
    ESP_LOGI(TAG, "Starting Application");

    // Setup a periodic timer with a 500 ms interval and counter_0
    setup_periodic_timer(500, &counter_0);
    // Setup another periodic timer with a 1000 ms interval and counter_1
    setup_periodic_timer(1000, &counter_1);

    // Create two tasks to increment counters
    xTaskCreate(task1, "Task1", 2048, NULL, 5, NULL);
    xTaskCreate(task2, "Task2", 2048, NULL, 5, NULL);

    while (1) {
        ESP_LOGI(TAG, "GPTimer 0: %d, GPTimer 1: %d, FreeRTOS 2: %d, FreeRTOS 3: %d ", counter_0, counter_1, counter_2, counter_3);
        vTaskDelay(pdMS_TO_TICKS(1000));  // Print counters every 1 second
    }
}
