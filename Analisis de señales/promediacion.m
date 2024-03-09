
%% Example of system.

%

close all

clear all

 %% 
 

% Generate a random signal.

 

x = rand(1, 200);

close all

plot(x);title('x[n]');

 

%  the system is y[n] = 1/5 (x[n+2] + x[n+1] + x[n] + x[n-1]+ x[n-2] )

 

h = [1 1 1 1 1]./5

y = filter(h,1,x);

 

figure plot(y); title('y[n]');

 

%% Aplica nuevamente el filtro.

y1 = filter(h,1,y);

 

figure plot(y1); title('y1[n]');

 

%% otra vez

y2 = filter(h,1,y1);

 

figure plot(y2); title('y2[n]');