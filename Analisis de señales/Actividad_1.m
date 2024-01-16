% Definir parámetros
amplitud = 235;
velocidad_angular = 356;

% Crear un vector de tiempo para un periodo
t = linspace(0, .1, 1000);

% Calcular la señal senoidal
v = amplitud * cos(velocidad_angular * t);

% Graficar la señal
figure;
plot(t, v, 'LineWidth', 2);
title('Señal Senoidal: v(t) = 235*cos(356t)');
xlabel('Tiempo (s)');
ylabel('Voltaje');
grid on;