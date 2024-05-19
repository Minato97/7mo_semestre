function fftshow(f, type)
% muestra la transformada de Fourier a través de imshow.
% type: 'abs' :en este caso se muestra el valor absoluto.
%     : 'log' : se muestra log(1+abs(f)).
% si no se indica el tipo 'log' es el que se asume.
%
% Example:
% c = imread('cameraman.tif');
%cf = fftshift(fft2(c));
% fftshow(cf,'abs');

if nargin < 2
    type ='log';
end

if (type == 'log')
    fl = log(1+abs(f));
    fm = max(fl(:));
    imshow(im2uint8(fl/fm));
elseif (type == 'abs' )
    fa = abs(f);
    fm = max(fa(:));
    imshow(fa/fm)
else
    error('tipo incorrecto');
end;


