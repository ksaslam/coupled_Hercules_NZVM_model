#ifndef XYtoLL_H
#define XYtoLL_H

double bilinear(double x, double y, 
        double x1, double y1, double x2, double y2, 
        double q11, double q21, double q12, double q22);

double get_lat(double x, double y);

double get_lon(double x, double y);

int convert(double x, double y);

void convert_program(double x,double y);

#endif


