/*
    This code originates from the Getting started with Raspberry Pi Pico document
    https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf
    CC BY-ND Raspberry Pi (Trading) Ltd
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#include <bno085_imu.h>

int main()
{
    bi_decl(bi_program_description("PROJECT DESCRIPTION"));

    stdio_init_all();
    run_bno085();
}
