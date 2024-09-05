/*

*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "bno_common.h"
#include "bno085_imu.h"
#include "pico-i2clib.h"

i2c_inst_t *i2c;

int main()
{
    bi_decl(bi_program_description("PROJECT DESCRIPTION"));

    stdio_init_all();
    i2c = pico_init_i2c(i2c_default, 100 * 1000, PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN);
    pico_scan_i2c(i2c);
    // run_bno085(i2c);
}
