%%
clc
close all
clear all

[y,Fs] = audioread('5_lucas_3.wav');
%% calcula tiempo de la señal
muestras = numel(y);
tiempo = muestras/Fs;
ejex = linspace (0,tiempo,muestras);

plot(ejex, y)
title("Señal de audio")
xlabel('t')
ylabel('Amplitud')
sound(y,Fs);
legend('5 lucas 3');
grid on;
%% calcula máxima y mínima amplitud
[maximo,Indmax] = max(y);
[minimo,Indmin] = min(y);
% busca correspondencia entre los índices y el tiempo
t_for_max = Indmax * tiempo/muestras;
t_for_min = Indmin * tiempo/muestras;
%% dibuja mínima y máxima amplitud
hold on
plot(t_for_min, minimo, 'r*')
plot(t_for_max, maximo, 'g*')
legend('Audio 5 Lucas','Minimo','Máximo');
%% adiciona ruido a la señal.
%noise = rand(numel(y),1);
%y_noise = y + noise;

% Parámetros del ruido gaussiano
media = 0;
desviacion_estandar = 0.2;
% Generar ruido gaussiano
noise = desviacion_estandar * randn(size(y)) + media;
% Añadir ruido a la señal
y_noise = y + noise;
figure
plot(ejex, y_noise)
title("Señal de audio contaminada con ruido")
xlabel('t')
ylabel('Amplitud')
grid on;
%% Se filtra la señal en el tiempo y se visualiza.
windowSize = 5; 
b = (1/windowSize)*ones(1,windowSize);
a = 1;
y_filtered = filter(b,a,y_noise);
y_filtered = filter(b,a,y_filtered);
y_filtered = filter(b,a,y_filtered);
y_filtered = filter(b,a,y_filtered);

% visualización de la señal filtrada
figure
plot(ejex, y_filtered)
title("Señal de audio filtrada")
xlabel('t')
ylabel('Amplitud')
grid on;
%% Aquí pueden pasar el filtro más de una vez por ejemplo
% para lograr mayor atenuación del ruido.


%% Procesamiento en frecuencia

Y = fft(y);
Y_noise = fft(y_noise);

%% Construyendo eje de frecuencias
f_max = Fs/2;
eje_f = (linspace (0,f_max*2,numel(y)))';
%%
figure
subplot(1,2,1)
plot(eje_f,abs(Y))
xlabel("Hertz");
ylabel("|F|")
title("Y")
subplot(1,2,2)
plot(eje_f,abs(Y_noise))
title("Y\_noise")
xlabel("Hertz");
ylabel("|F|")
%% Revisa que se logra con la transformada inversa
figure
% Regresamos al tiempo. Comparemos y_noise y y_IFFT_noise
y_IFFT_noise = ifft(Y_noise);
subplot(1,2,1)
plot(ejex, y_noise)
xlabel('t')
ylabel('Amplitud')
subplot(1,2,2)
plot(ejex, y_IFFT_noise)
xlabel('t')
ylabel('Amplitud')

%% Filtrar la señal en el espacio de Fourier.
% Definir las frecuencias de corte
f_min = 50; % Frecuencia mínima deseada (en Hz)
f_max = 150; % Frecuencia máxima deseada (en Hz)

% Crear un filtro que tenga valores altos en el rango deseado y valores bajos en el resto
filter_F = ([zeros(1, f_min - 1), ones(1, f_max - f_min + 1), zeros(1, numel(y) - f_max)])';
filterd_signal_F = Y_noise .* filter_F;
y_IFFT = ifft(filterd_signal_F);
% Visualiza la señal filtradas en Fourier y compara con la
% señal filtrada en el tiempo y el proceso que conllevó.
figure
subplot(1,2,1)
plot(ejex, y_IFFT)
xlabel('t')
ylabel('Amplitud')
title('y\_IFFT')
subplot(1,2,2)
plot(ejex, y_filtered)
xlabel('t')
ylabel('Amplitud')
title('y\_filtered')

%%