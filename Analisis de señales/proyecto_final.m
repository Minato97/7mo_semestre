%%
[y,Fs] = audioread('9_george_0.wav');
%% calcula tiempo de la señal
muestras = numel(y);
tiempo = muestras/Fs;
ejex = linspace (0,tiempo,muestras);

plot(ejex, y)
title("Señal de audio")
xlabel('t')
ylabel('Amplitud')
sound(y,Fs);
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
%% adiciona ruido a la señal.
noise = rand(numel(y),1);
y_noise = y + noise;
%% 
figure
plot(ejex, y_noise)
title("Señal de audio contaminada con ruido")
xlabel('t')
ylabel('Amplitud')
%% Se filtra la señal en el tiempo y se visualiza.
windowSize = 5; 
b = (1/windowSize)*ones(1,windowSize);
a = 1;
y_filtered = filter(b,a,y_noise);

% visualización de la señal filtrada
figure
plot(ejex, y_filtered)
title("Señal de audio filtrada")
xlabel('t')
ylabel('Amplitud')

%% Aquí pueden pasar el filtro más de una vez por ejemplo
% para lograr mayor atenuación del ruido.
%% Procesamiento en frecuencia

Y = fft(y);
