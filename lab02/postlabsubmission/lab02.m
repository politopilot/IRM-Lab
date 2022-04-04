%% Postlab02 Report Group 3_4
clear all;
close all;
clc;

%% Q2

data = importdata('voltage_data.txt');
figure
plot(data);
title('Voltage Data Points not Averaged');
ylabel('voltage (V)');
disp(std(data))
disp(mean(data))

data_averaged = importdata('voltage_data_averaged.txt');
figure
plot(data_averaged);
title('Voltage Data Points Averaged (50 Values)');
ylabel('voltage (V)');
disp(std(data_averaged))
disp(mean(data_averaged))


data_averaged_200 = importdata('voltage_data_averaged_200.txt');
figure
plot(data_averaged_200);
title('Voltage Data Points Averaged (200 Values)');
ylabel('voltage (V)');
disp(std(data_averaged_200))
disp(mean(data_averaged_200))

% data_averaged_200_2 = importdata('voltage_data_averaged_200_2.txt');
% disp(mean(data_averaged_200_2))

% calculate quiescent voltage:
qui = importdata('quiescent_voltage.txt');
% disp(mean(qui));
disp('-------------');

%% Q3

fielddata = importdata('field_distance_backup.txt');
n = 0.1;
x = fielddata(:,1)./1000; % in m
y = fielddata(:,2) % in mT

% substitute and plot
x_lin = 1./x.^n;
figure
plot(x_lin,y,'b*');
xlabel('1/z^n');
ylabel('magnetic field (mT)')
grid on
hold on

parameter = lsqcurvefit(@f_lin, [0;0], x_lin, y);
m = parameter(1) % corresponds to Br
c = parameter(2)

% Calculate Br
xfit = 0.016:0.002:0.040; % in m
xfit_lin = 1./xfit.^n;
yfit_lin = f_lin(parameter, xfit_lin);

plot(xfit_lin,yfit_lin,'r','linewidth',2); % plot of data and fit for linear case i.e. when 1/z^n
hold off

Br = lsqcurvefit(@f, 0, x, y); 
  
figure
plot(x,y,'b*');
hold on
yfit = f(Br,xfit); 
plot(xfit,yfit,'r','linewidth',2);
xlabel('z (m)');
ylabel('magnetic field (mT)')

function y = f(Br, x) % x in m
    D = 0.01;
    R = 0.02;
    y1 = ( (D+x)./sqrt(R^2+(D+x).^2) );
    y2 = ( x./(sqrt(R^2+x.^2)) );
    y = Br * 0.5 * (y1 - y2); % B field in T
end

function y = f_lin(parameter,x) % x in m
    y = parameter(1)*x+parameter(2); % in mT
end

