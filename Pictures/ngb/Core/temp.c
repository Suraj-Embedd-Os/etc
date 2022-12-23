

Calibaration:
(this step happen only once)
{
->First accumulate square adc sample (eg: adc_sqr_sample +=sqr(ADCSAMPLE -AVG_OF_ADC_SAMPEL))
->Accumulate upto desire NO_OF_SAMPLE;

-> AVG_OF_ADC_SAMPEL=(v1+v2+v2.....vn)/n ,where n=no of sample

->Then calulate multiplication factor  by seting voltage and current and in code 
		eg: let for 230v
		multiplication_factor=23000/sqroot(adc_sqr_sample)
		
		eg: let for 5A
		multiplication_factor=5000/sqroot(adc_sqr_sample)
		}

(repeat process)
{
->First accumulate square adc sample (eg: adc_sqr_sample +=sqr(ADCSAMPLE -AVG_OF_ADC_SAMPEL))
->Accumulate upto desire NO_OF_SAMPLE;
->Now use this multiplication factor to calulate RMS value

	eg RMS =sqroot(adc_sqr_sample)*multiplication_factor;
	
}