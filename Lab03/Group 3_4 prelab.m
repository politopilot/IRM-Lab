s = tf('s');
G = 1/(s/(2*pi*100)+1);

options = bodeoptions;
options.FreqUnits = 'Hz'; % or 'rad/second', 'rpm', etc.

figure(1)
bode(G,options)
figure(2)
impulse(G)
figure(3)
step(G)


% 3. 90 degrees
% 4. -3.02 dB (0.706 Voltage Gain)
% 5. An ideal filter could completely eliminate a frequency. However, in practice
% that is impossible to achieve. Therefore this low pass filter can only
% attenuate certain frequencies. Hence, the frequency of the input signal
% does not change.