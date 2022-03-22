
clear all;
close all;
clc;


%%
% 
% Open MATLAB for data analysis. In MATLAB, load the data from the file voltage_data.txt into a
% Numeric Matrix and plot it. You can use the MATLAB command importdata and plot to plot the
% data. You can visualize now that the sensor output is quite noisy. Calculate and write down the average and
% standard deviation of this dataset.
% 3. Now write a microcontroller (Arduino) code snippet to read in 20 consecutive values of the sensor voltage
% instead of a sigle one like before, average them into a single value and send it through the serial port. Output
% 50 such averaged values to a file as you did before. Import them into MATLAB, and plot the 50 datapoints.
% Calculate and write down the average and standard deviation. Finally, read in 200 consecutive voltage val-
% ues, average them on the microcontroller (Arduino), and save 50 such values into a data file. Again, plot
% your results in MATLAB and compare the average and standard deviation. Explain your observations and
% conclusions.

% load data
% 

% data = importdata('voltage_data.txt');
% figure
% hold on
% plot(data);
% disp(std(data))
% disp(mean(data))
% 
% data_averaged = importdata('voltage_data_averaged.txt');
% 
% plot(data_averaged);
% disp(std(data_averaged))
% disp(mean(data_averaged))
% 
% data_averaged_200 = importdata('voltage_data_averaged_200.txt');
% 
% plot(data_averaged_200);
% disp(std(data_averaged_200))
% disp(mean(data_averaged_200))
% 
% data_averaged_200_2 = importdata('voltage_data_averaged_200_2.txt');
% disp(mean(data_averaged_200_2))
% 
% qui = importdata('quiescent_voltage.txt');
% disp(mean(qui))

D = 0.01;
R = 0.02;

data = importdata('field_distance_backup.txt');
z = data(:,1)
B = data(:,2)

fun = @(Br,z)(Br(1)*0.5*((D+z)./sqrt(R.^2+(D+z).^2)-(z./sqrt(R.^2+z.^2))));
z0 = 176;
Br = lsqcurvefit(fun,z0,z,B)

hold on
plot(data(:,1), data(:,2));
fplot(fun);



