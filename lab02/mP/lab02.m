
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

%% Q3.4

data = importdata('field_distance_backup.txt');
n = 0.1;
x = data(:,1)
y = data(:,2)
x_lin = 1./data(:,1).^n;

figure
plot(x_lin,y,'b*');
grid on
hold on

parameter = lsqcurvefit(@f_lin, [0;0], x_lin, y) % 168 and -133 are the value we got at first time with [0;0]

m = parameter(1)
c = parameter(2)

xfit = 14:2:40;
xfit_lin = 1./xfit.^n;
yfit_lin = f_lin(parameter, xfit_lin);

% plot(xfit_lin,yfit_lin,'r','linewidth',2); % plot of data and fit for linear case i.e. when 1/z^n
% hold off

% plots with x = z
figure
plot(x,y,'b*');
hold on
yfit = parameter(1)*f(xfit); % *1000 as we want it in mT, but values are veeery small, try multiplying with 100000000
plot(xfit,yfit,'r','linewidth',2);

function y = f(x)
    D = 0.01;
    R = 0.02;
    y1 = ( (D+x)./sqrt(R^2+(D+x).^2) );
    y2 = ( x./(sqrt(R^2+x.^2)) );
    y = y1 - y2;
end

function y = f_lin(parameter,x)
    y = parameter(1)*x+parameter(2);
end

