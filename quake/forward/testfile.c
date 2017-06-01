
//
//  main.c
//  CVMversions
//
//  Created by Ethan M. Thomson on 19/06/14.
//  Copyright (c) 2014 Dept. Civil Engineering. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#ifndef _AIX
#include <getopt.h>
#endif

#include "constants.h"
#include "structs.h"
#include "functions.h"


//void main_function(double x_lat,double y_long)
void main_function(double x_lat,double y_long, double depth, calculation_log *CALCULATION_LOG, velo_mod_1d_data *VELO_MOD_1D_DATA, nz_tomography_data *NZ_TOMOGRAPHY_DATA, global_surfaces *GLOBAL_SURFACES, basin_data *BASIN_DATA, qualities_vector *QUALITIES_VECTOR)
{

// ****************************************************************************
//    int main(void)
//    {
//    int argc = 2;
//    char *argv[2];
//    argv[1] = "Generate_QSlices.txt";


//    argv[1] = "Sample_Input_Text_Files/GENERATE_MULTIPLE_PROFILES.txt";
//    argv[1] = "Sample_Input_Text_Files/GENERATE_VELOCITY_MOD.txt";
//    argv[1] = "Sample_Input_Text_Files/GENERATE_PROFILE.txt";
//    argv[1] = "Sample_Input_Text_Files/GENERATE_THRESHOLD.txt";
//    argv[1] = "Sample_Input_Text_Files/GENERATE_VELOCITY_SLICES.txt";
//    argv[1] = "Sample_Input_Text_Files/GENERATE_MULTIPLE_PROFILES(constant_spacing_example).txt";
//    argv[1] = "Sample_Input_Text_Files/GENERATE_VELOCITIES_ON_GRID.txt";
// **********************************************************************************



// *********************************************************************************

    //initializations 

    // set call type flags to zero (0)
    int EXTRACT_VELOCITY_SLICES = 0;
    int GENERATE_VELOCITY_MOD = 0;
    int GENERATE_VELOCITY_SLICES = 0;
    int GENERATE_PROFILE = 0;
//    int EXTRACT_THRESHOLD = 0;
    int GENERATE_THRESHOLD = 0;
//    int EXTRACT_MULTIPLE_GRIDPOINT_VS = 0;
    int GENERATE_VELOCITIES_ON_GRID = 0;
    int GENERATE_MULTIPLE_PROFILES = 0;
    char *CALL_TYPE = NULL;
    char *MODEL_VERSION;
    char *OUTPUT_DIR;
    char *parametersTextFile = (char*) malloc(MAX_FILENAME_STRING_LEN*sizeof(char));
    char *inputFName;
    // double lat;
    // double lon; 
    // double depth;
    // generate structs to house parameters for each call type
    gen_extract_velo_mod_call GEN_EXTRACT_VELO_MOD_CALL;
    gen_velo_slices_call GEN_VELO_SLICES_CALL;
    gen_profile_call GEN_PROFILE_CALL;
    gen_extract_multi_gridpoint_vs_call GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL;
    gen_multi_profiles_call GEN_MULTI_PROFILES_CALL;




// *************************************************************************************

    global_model_parameters *GLOBAL_MODEL_PARAMETERS;






  

        CALL_TYPE = "GENERATE_VELOCITIES_ON_GRID";
        MODEL_VERSION= "1.65";
        OUTPUT_DIR = "Vs_At_Gridpoints";
        GLOBAL_MODEL_PARAMETERS = getGlobalModelParameters(MODEL_VERSION);


    


        if (strcmp(CALL_TYPE, "GENERATE_VELOCITIES_ON_GRID") == 0)
        {
            GENERATE_VELOCITIES_ON_GRID = 1;
            GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL.TOPO_TYPE = "BULLDOZED";
            GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL.MIN_VS = 0.500;
            GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL.COORDINATES_TEXT_FILE = "SecondaryInputFiles/GridpointCoords.txt";
            fprintf(stderr, "Done with getting the file names of input file\n");
        }


//    }
  



    // check if the output directory exists, exit if necessary
    if (GENERATE_VELOCITY_MOD == 1 || GENERATE_VELOCITY_SLICES == 1 || GENERATE_PROFILE == 1 || GENERATE_THRESHOLD == 1 || GENERATE_VELOCITIES_ON_GRID == 1 || GENERATE_MULTIPLE_PROFILES == 1)
    {
        struct stat st;

        // if (stat(OUTPUT_DIR, &st) != -1)
        // {
        //     printf("Output directory must not exist for this call type. See readme.\n");
        //     exit(EXIT_FAILURE);
        // }
        // else
        // {
            createAllOutputDirectories(OUTPUT_DIR, CALL_TYPE);
        // }

    }
    


    // generate the log file struct

//    calculation_log *CALCULATION_LOG;
    //CALCULATION_LOG = initializeCalculationLog(argc, argv);

    // run the routines associated with each calltype
    
     if (GENERATE_VELOCITIES_ON_GRID == 1)
    {   
        printf("Running load data from main.\n");
        // lat=lat_point;
        // lon=lon_point;
        // depth=depth_point;

        convert_program (100.0,200.0);
        runGenerateMultipleVSonGrid(GLOBAL_MODEL_PARAMETERS , VELO_MOD_1D_DATA, NZ_TOMOGRAPHY_DATA, GLOBAL_SURFACES, BASIN_DATA, OUTPUT_DIR, GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL, CALCULATION_LOG, x_lat,y_long, depth, QUALITIES_VECTOR);
        printf("Done with the first one.\n");
        // lat=-43.00;
        // lon=172.00;
        // depth=-2000;        
        // runGenerateMultipleVSonGrid(GLOBAL_MODEL_PARAMETERS , VELO_MOD_1D_DATA, NZ_TOMOGRAPHY_DATA, GLOBAL_SURFACES, BASIN_DATA, OUTPUT_DIR, GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL, CALCULATION_LOG, lat, lon, depth);
        // lat=-43.50;
        // lon=173.00;
        // depth=-1000;         
        // runGenerateMultipleVSonGrid(GLOBAL_MODEL_PARAMETERS , VELO_MOD_1D_DATA, NZ_TOMOGRAPHY_DATA, GLOBAL_SURFACES, BASIN_DATA, OUTPUT_DIR, GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL, CALCULATION_LOG, lat, lon, depth);

        // printf("==========================================\n");
        // printf("Running GENERATE_VELOCITIES_ON_GRID.\n");
        // printf("==========================================\n");
        // runGenerateMultipleVSonGrid(MODEL_VERSION, OUTPUT_DIR, GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL, CALCULATION_LOG);
        // printf("==========================================\n");
        // printf("Completed running GENERATE_VELOCITIES_ON_GRID.\n");
        // printf("==========================================\n");
    }






}




