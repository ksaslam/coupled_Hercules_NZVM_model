#include <stdio.h>

double bilinear(double x, double y, 
        double x1, double y1, double x2, double y2, 
        double q11, double q21, double q12, double q22)
{
    double p = (x2 - x1) * (y2 - y1);
    double f1 = (q11 / p) * (x2 - x) * (y2 - y);
    double f2 = (q21 / p) * (x - x1) * (y2 - y);
    double f3 = (q12 / p) * (x2 - x) * (y - y1);
    double f4 = (q22 / p) * (x - x1) * (y - y1);
    return f1 + f2 + f3 + f4;
}

double get_lat(double x, double y) {
    
    // Latitudes of ShakeOut region corners
    return bilinear(x,y,
            0, 0, 600000, 300000,
            34.5, 31.082920, 
            36.621696, 33.122341);
}

double get_lon(double x, double y) {
    
    // Longitudes of ShakeOut region corners
    return bilinear(x,y,
            0, 0, 600000, 300000, 
            -121, -116.032285, 
            -118.951292, -113.943965);
}

int convert(double x, double y) {
    
    double lat, lon;

    // 600km in x direction
    if(x<0 || x>600000){
        fprintf(stderr,"Invalid x, value must be between 0 and 600000: %lf\n",x);
        return 1;
    }

    // 300km in y direction
    if(y<0 || y>300000){
        fprintf(stderr,"Invalid y, value must be between 0 and 300000: %lf\n",y);
        return 1;
    }

    lat = get_lat(x,y);
    lon = get_lon(x,y);

    printf("%.11lf %.11lf\n",lat,lon);

    return 0;
}

void convert_program(double x,double y)
{
//int main(int argc, char **argv) {

    
//    double x, y;
    int res;
    char fname;


    // if(argc!=3 && argc!=1 && argc!=2) {
    //     fprintf(stderr,"Usage: %s [x y]\n\n"
    //             "x = x coordinate in meters\n"
    //             "y = y coordinate in meters\n\n"
    //             "Convert ShakeOut x,y coordinates to lat,lon using "
    //             "bilinear projection\n"
    //             "If 1 argument, it is file name N followed by N-pairs\n"
    //             "If no arguments are provided, input lines are read "
    //             "from stdin in \"x y\" format.\n",argv[0]);
    //     return 1;
    // }

    // // Use arguments if specified
    // if(argc==3){
    //     if(sscanf(argv[1],"%lf",&x)!=1) {
    //         fprintf(stderr,"Invalid x coordinate: %s\n",argv[1]);
    //         return 1;
    //     }

        // if(sscanf(argv[2],"%lf",&y)!=1) {
        //     fprintf(stderr,"Invalid y coordinate: %s\n",argv[2]);
        //     return 1;
        // }

    convert(x,y);
    // }

    // if (argc==2) {
    //     if(sscanf(argv[1],"%s",fname)!=1) {
    //         fprintf(stderr,"Input file problem");
    //         return 1;
    //     }
        
        
    // }
    
    // // Use stdin by default
    // while((res=fscanf(stdin,"%lf %lf",&x,&y))==2) {
    //     if(convert(x,y)>0) return 1;
    // }

    // if(res!=EOF && res<1) {
    //     fprintf(stderr,"Error reading input\n");
    //     if(res!=0) perror("fscanff");
    //     return 1;
    // }

//    return 0;
}
