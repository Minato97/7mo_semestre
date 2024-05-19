%CreaciÛn de figura sintÈtica figura 
f = zeros(30,30); 
f(5:24,13:17) = 1; 
% Aplica la transformada de Fourier 
F = fft2(f,256,256);
F1 = fftshift(F);
%Visualiza 
subplot(3,1,1) 
imshow(f/max(f(:)));title('Imagen Original')
subplot(3,1,2),imshow(log(abs(F)),[-1 5]);title('Transformada de Fourier'), colormap(jet); colorbar
subplot(3,1,3),imshow(log(abs(F1)),[-1 5]);;title('Transformada de Fourier desplazada'),colormap(jet); colorbar
%%
clear all
close all
cm = imread('cameraman.jpg');
imshow(cm)
cf = fftshift(fft2(cm));
figure, fftshow(cf,'log');

%% filtro pasa bajo.

%% se construye el filtro: es una matriz que tiene 1 en el centro
[x, y] = meshgrid(0:511,0:511);
z = sqrt((x-255).^2+(y-255).^2);
c = (z>15);
imshow(c)

%% se filtra la imagen en Fourier.
cfl = cf.*c; % filtro pasa bajo
figure, fftshow(cfl,'log'),title('Filtro pasa bajo en Fourier')
%%
% se halla la transformada inversa y se visualiza.
cfli = ifft2(cfl);
figure, fftshow(cfli,'abs'),title('Filtro pasa bajo en el espacio')
%%
%FILTRO PASA ALTA.
c= z > 15;
% se filtra la imagen en Fourier.
cfh = cf.*c; % filtro pasa alto.
figure, fftshow(cfh,'log'), title('Filtro pasa alta en Fourier')

%% se halla la transformada inversa y se visualiza.
cfhi = ifft2(cfh);
figure, fftshow(cfhi,'abs'), title('Filtro pasa alta en el espacio')
