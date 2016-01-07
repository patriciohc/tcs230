/**
 * rgb_to_hsv.c
 * 
 * @author Jose Patricio Hijuitl <patriciohc.0@gmail.com>
 */

#include "rgb_to_hsv.h"

/*
*Funcion que regresa el valor maximo de RGB, recibe como parametros
*un array con los valores RGB, y un apuntador a un entero donde se 
*se guarda el color maximo
*/
int maximo(int RGB[], int *color)
{
	int max = RGB[RED];
	*color = RED;
	if(RGB[GREEN] > max){
		max = RGB[GREEN];
		*color = GREEN;
	}
	if(RGB[BLUE] > max){
		max = RGB[BLUE];
		*color = BLUE;
	}
	return max;
}
/*
*Funcion que regresa el valor minimo de RGB, recibe como parametros
*un array con los valores RGB, y un apuntador a un entero donde se 
*se guarda el color minimo
*/
int minimo(int RGB[], int *color)
{
	int min = RGB[RED];
	*color = RED;
	if(RGB[GREEN] < min){
		min = RGB[GREEN];
		*color = GREEN;
	}
	if(RGB[BLUE] < min){
		min = RGB[BLUE];
		*color = BLUE;
	}
	return min;
}
/*
*Algoritmo que realiza la conversion de RGB a HSV
*/
void RGB_to_HSV( int RGB[], int *H, float *S, float *V){
	int col_max;
	int col_min;
	float val_max = maximo(RGB, &col_max);
	float val_min = minimo(RGB, &col_min);
	if(col_max == RED){
		*H = 60 * (RGB[GREEN] - RGB[BLUE])/(val_max - val_min);
		if(RGB[GREEN] < RGB[BLUE]){
			*H = *H + 360;
		}
	}else if(col_max == GREEN){
		*H = 60 * (RGB[BLUE] - RGB[RED])/(val_max - val_min) + 120;
	}else if(col_max == BLUE){
		*H = 60 * (RGB[RED] - RGB[GREEN])/(val_max - val_min) + 240;
	}
	if(val_max == 0){
		*S = 0;
	}else{
		*S = 1.0 - val_min/val_max;
	}
	*V = val_max/255.0;
}

/*test del algoritmo
int main(){
	int RGB[3];
	int H;
	float S;
	float V;
	printf("introduce color RGV -> ");
	scanf("%d %d %d", &RGB[0], &RGB[1], &RGB[2]);
	RGB_to_HSV(RGB,&H,&S,&V);
	printf("HSV= %d %f %f \n---------------\n",H,S,V);
	return 0;
}
*/
