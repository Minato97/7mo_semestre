clear all
close all
clc

% Parámetros:
Fs = 48000;
duration = 4;
alpha = 0.9785;
gain = [1.0; 1.0; 1.0; 1.0]; % Ajustado para tener 4 elementos
nbsample_chord = Fs * duration;

% Frecuencias de las notas do, mi y sol (acorde de do mayor)
F0_do_mayor = [261.63; 329.63; 392.00]; % do4, mi4, sol4

% Frecuencias de las notas la, do y mi (acorde de la menor)
F0_la_menor = [220.00; 293.66; 349.23]; % la3, do4, mi4

% Frecuencias de las notas re, fa# y la (acorde de re menor)
F0_re_menor = [293.66; 369.99; 440.00]; % re4, fa#4, la4

% Frecuencias de las notas sol, si, re y fa (acorde de sol séptima)
F0_sol_septima = [392.00; 493.88; 587.33; 698.46]; % sol4, si4, re5, fa5

% Función para generar un acorde
generate_chord_function = @(F0) generate_chord(F0, gain, nbsample_chord, Fs, alpha);

% Reproducir acorde de do mayor
chord_do_mayor = generate_chord_function(F0_do_mayor);
soundsc(chord_do_mayor, Fs);

% Pausa de 2 segundos
pause(2);

% Reproducir acorde de la menor
chord_la_menor = generate_chord_function(F0_la_menor);
soundsc(chord_la_menor, Fs);

% Pausa de 2 segundos
pause(2);

% Reproducir acorde de re menor
chord_re_menor = generate_chord_function(F0_re_menor);
soundsc(chord_re_menor, Fs);

% Pausa de 2 segundos
pause(2);

% Reproducir acorde de sol séptima
chord_sol_septima = generate_chord_function(F0_sol_septima);
soundsc(chord_sol_septima, Fs);

% Pausa de 2 segundos
pause(2);

% Reproducir acorde de do mayor nuevamente
chord_do_mayor = generate_chord_function(F0_do_mayor);
soundsc(chord_do_mayor, Fs);

function chord = generate_chord(F0, gain, nbsample_chord, Fs, alpha)
    chord = zeros(nbsample_chord, 1);
    for i = 1:length(F0)
        % Obtener M y duración del parámetro
        current_M = round(Fs / F0(i));
        current_duration = ceil(nbsample_chord / current_M);
        % Corregir alpha actual para que todas las notas decaigan juntas (con la misma tasa de decaimiento)
        first_duration = ceil(nbsample_chord / round(Fs / F0(1)));
        current_alpha = alpha^(first_duration / current_duration);
        % Generar entrada y salida del algoritmo KS
        x = rand(current_M, 1);
        y = ks(x, current_alpha, current_duration);
        y = y(1:nbsample_chord);
        % Construir el acorde sumando la nota generada (con la ganancia apropiada)
        chord = chord + gain(i) * y;
    end
end
