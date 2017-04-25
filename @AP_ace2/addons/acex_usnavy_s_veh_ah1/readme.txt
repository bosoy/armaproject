stand 12.10. 2009

 all sounds complete new.

i put this in config, its not original BIS.

			class WindNoiseOut {
				sound[] = {"\eliasound_project_x\misc\wind_out.wav", 4.900000, 2.000000,170};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};			

			class WindNoiseIn {
				sound[] = {"\eliasound_project_x\misc\wind_in.wav", 2.900000, 2.000000};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			
			};


after a first bug in the stryker and LB sound i cut lots of the end and beginning of the sounds.
sound need some testing.
