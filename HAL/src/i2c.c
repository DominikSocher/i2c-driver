/*
 * i2c.c
 *
 *  Created on: 01.04.2021
 *      Author: Dominik
 */

#include <alt_types.h>
#include <altera_avalon_i2c.h>
#include <io.h>
#include <system.h>
#include <stdio.h>
#include "i2c.h"



static struct 
{
	// Pointer to avalon i2c instance structure
	ALT_AVALON_I2C_DEV_t *i2c_dev; 
	// Variable to hold status codes
	ALT_AVALON_I2C_STATUS_CODE i2c_status; 
}i2c;


/*
 * *********************************************************
 * i2c_open()
 *
 * Description: Function activates i2c device
 * Arguments  : none
 * Returns    : void
 *
 * *********************************************************
 */
void i2c_open(void)
{
	i2c.i2c_dev = alt_avalon_i2c_open("/dev/i2c_0");
    if(!i2c.i2c_dev)
    {
        printf("Error: Cannot find /dev/i2c_0\n");
    }
}

/*
 * *********************************************************
 * i2c_slave_address()
 *
 * Description: Set address of I2C slave
 * Arguments  : slave_address
 * Returns    : void
 *
 * *********************************************************
 */
void i2c_slave_address(alt_u8 slave_address)
{
     alt_avalon_i2c_master_target_set(i2c.i2c_dev, slave_address);
}

/*
 * *********************************************************
 * i2c_tx()
 *
 * Description: Set data to i2c slave, Data to send needs to
 * 				be an array. If only one byte to send data[0]
 * Arguments  : bytes, data
 * Returns    : void
 *
 * *********************************************************
 */
void i2c_tx(alt_u8 bytes, alt_u8 *data)
{
    i2c.i2c_status = alt_avalon_i2c_master_tx(i2c.i2c_dev, data, bytes, ALT_AVALON_I2C_NO_INTERRUPTS);
    //when not i2c status exit function
	if (i2c.i2c_status != ALT_AVALON_I2C_SUCCESS)
	{
		printf("fail to send data\n");
	}
}

/*
 * *********************************************************
 * i2c_rx()
 *
 * Description: receive data from i2c slave. Data to receive
 * 				needs to be an array. If only one byte to receive
 * 				data[0]
 * Arguments  : 
 * Returns    : data
 *
 * *********************************************************
 */
void i2c_rx(alt_u8 bytes, alt_u8 *data)
{
	i2c.i2c_status = alt_avalon_i2c_master_rx (i2c.i2c_dev, data, bytes, ALT_AVALON_I2C_NO_INTERRUPTS);
    //when not i2c status exit function
	if (i2c.i2c_status != ALT_AVALON_I2C_SUCCESS)
	{
		printf("fail to receive data\n");
	}
}
