/*
MS5611.h - Header file for the MS5611 Barometric Pressure & Temperature Sensor Library.
*/

#ifndef MS5611_h
#define MS5611_h

#include <stdint.h>
#include <stdbool.h>

#define MS5611_ADDRESS                (0x77)

#define MS5611_CMD_ADC_READ           (0x00)
#define MS5611_CMD_RESET              (0x1E)
#define MS5611_CMD_CONV_D1            (0x40)
#define MS5611_CMD_CONV_D2            (0x50)
#define MS5611_CMD_READ_PROM          (0xA2)

typedef enum
{
    MS5611_ULTRA_HIGH_RES   = 0x08,
    MS5611_HIGH_RES         = 0x06,
    MS5611_STANDARD         = 0x04,
    MS5611_LOW_POWER        = 0x02,
    MS5611_ULTRA_LOW_POWER  = 0x00
} ms5611_osr_t;

	bool MS5611begin(ms5611_osr_t osr);// = MS5611_HIGH_RES
	float MS5611readTemperature(void);// = false
	int32_t MS5611readPressure(void);// = false
	float MS5611getAltitude(float pressure, float seaLevelPressure);// = 101325
	float MS5611getSeaLevel(float pressure, float altitude);
	void MS5611setOversampling(ms5611_osr_t osr);
	ms5611_osr_t MS5611getOversampling(void);

#endif
