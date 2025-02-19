#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdbool.h>
#include "weather.h"
#include "array_helpers.h"

int temperatura_minima(WeatherTable a);

void maximaTemp(WeatherTable a, int output[YEARS]);

void max_precipitaciones(WeatherTable a, month_t output2[YEARS]);

#endif //_WEATHER_H
