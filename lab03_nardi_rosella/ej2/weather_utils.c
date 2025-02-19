#include <stdlib.h>
#include <limits.h>
#include "weather.h"
#include "array_helpers.h"
#include "weather_utils.h"


int temperatura_minima(WeatherTable array) {
	
	int minT = array[0][0][0]._min_temp;

  	for(unsigned int year = 0; year < YEARS; ++year) 
  	{
		for(month_t month = january; month <= december; ++month) 
		{
			for(unsigned int day = 0u; day < DAYS; ++day) 
			{
				if(minT > array[year][month][day]._min_temp)
				{
					minT = array[year][month][day]._min_temp;

				}
			}
		}
	}

	// return minT;
}

void maximaTemp (WeatherTable array, int output[YEARS]) {
	
	for (unsigned int year = 0; year < YEARS; year++) {

		int maxT = array[year][0][0]._max_temp;

		for(month_t month = january; month <= december; ++month) 
		{
			for(unsigned int day = 0u; day < DAYS; ++day) 
			{
				if(maxT < array[year][month][day]._max_temp) {

					maxT = array[year][month][day]._max_temp;
					output[year] = maxT;
					
				}
			}
		}
	}
}

void max_precipitaciones(WeatherTable array, month_t output2[YEARS]) {
	
	

	for(unsigned int year = 0; year < YEARS; year++) 
  	{
		int temp_resp = INT_MIN;

		for(month_t month = 0u; month < MONTHS; month++) 
		{
			int rainMonth = 0;
			for(unsigned int day = 0u; day < DAYS; day++) 
			{	
				rainMonth = rainMonth + array[year][month][day]._rainfall;
				if(temp_resp < rainMonth) {

					output2[year] = month;
					temp_resp = rainMonth;

				}
				
			}
		}
	}
}