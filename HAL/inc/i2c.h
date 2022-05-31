/*
 * i2c.h
 *
 *  Created on: 01.04.2021
 *      Author: Dominik
 */

#ifndef I2C_H_
#define I2C_H_



/*
 * *****************************************************
 *
 * Public function prototypes
 *
 * *****************************************************
 */
void i2c_open(void);
void i2c_slave_address(alt_u8 slave_address);
void i2c_tx(alt_u8 bytes, alt_u8 *data);
void i2c_rx(alt_u8 bytes, alt_u8 *data);

#endif /* I2C_H_ */
