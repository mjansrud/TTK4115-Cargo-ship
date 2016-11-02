%%Task 1b
clear all;
clc;

load('data_w1_smooth');
load('data_w2_smooth');

w1_max = max(w1_smooth.signals.values);
w1_min = min(w1_smooth.signals.values);  
w2_max = max(w2_smooth.signals.values);
w2_min = min(w2_smooth.signals.values); 
 
w1 = 0.005;
w2 = 0.05;  
A1 = (w1_max-w1_min)/2; 
A2 = (w2_max-w2_min)/2; 

T = sqrt((A1^2*w1^2 - A2^2*w2^2)/(A2^2*w2^4 - A1^2*w1^4));
K = A1*w1*sqrt(T^2*w1^2+1);

%%Task 2a
load('data_wave'); 
x = psi_w(2,:);
window = 4096;
noverlap = [];
nttf = []; 
fs = 10;

[pxx,f] = pwelch(x, window, noverlap, nttf , fs); 

%Scaling to s/rad & rad/s
pxx = pxx/(2*pi);
f = f*2*pi;

plot(f, pxx);