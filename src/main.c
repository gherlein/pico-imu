/*

*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "pico/types.h"
#include "pico/binary_info.h"
#include "bno_common.h"
#include "bno085_imu.h"
#include "pico-i2clib.h"

i2c_inst_t *i2c;
uint8_t addrs[128];

int main()
{
    uint8_t num_devices = 0;
    bi_decl(bi_program_description("PROJECT DESCRIPTION"));

    stdio_init_all();
    printf("i2c default: %x\n", i2c_default);
    i2c = pico_init_i2c(i2c0, 100 * 1000, 16, 17);
    num_devices = pico_scan_i2c(i2c, addrs);
    printf("detected %d devices\n", num_devices);
    for (int x = 0; x < num_devices; x++)
    {
        printf("%x ", addrs[x]);
    }
    printf("\n");
    sleep_ms(5);
    run_bno085(i2c);
    while (1)
    {

        sleep_ms(1000);
    }
}
