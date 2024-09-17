#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define LED_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

void main(void)
{
    if (!device_is_ready(led.port)) {
        return;
    }

    gpio_pin_configure_dt(&led, GPIO_OUTPUT);

    while (1) {
        gpio_pin_toggle_dt(&led);
        k_msleep(1000);

    }
}