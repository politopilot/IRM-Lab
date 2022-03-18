all: data_acq

data_acq:
	gcc -o hall_daq feather_serial.c hall_sensor.c hall_daq.c -lm

clean:
	rm hall_daq
