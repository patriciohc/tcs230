/**
 * 
 * rgb_to_hsv.h
 * 
 * @author Jose Patricio Hijuitl <patriciohc.0@gmail.com>
 */
#define RED 0
#define GREEN 1
#define BLUE 2
/*
*Funcion que regresa el valor maximo de RGB, recibe como parametros
*un array con los valores RGB, y un apuntador a un entero donde se 
*se guarda el color maximo
*/
int maximo(int RGB[], int *color);
/*
*Funcion que regresa el valor minimo de RGB, recibe como parametros
*un array con los valores RGB, y un apuntador a un entero donde se 
*se guarda el color minimo
*/
int minimo(int RGB[], int *color);
/*
*Algoritmo que realiza la conversion de RGB a HSV
*/
void RGB_to_HSV( int RGB[], int *H, float *S, float *V);
