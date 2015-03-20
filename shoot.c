#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define v 140
//#define E -0.0882721 /* E/V0 */
#define out_file "output.dat"

void euler(double u[], double dudt[], double h, int theta, double E){
    dudt[0]=u[1];
    dudt[1]=-(E+theta)*v*u[0];
    u[0]+=dudt[0]*h;
    u[1]+=dudt[1]*h;
    // u[0] corresponds to u, u[1] corresponds to w
}

int main(int argc, char *argv[]){
    double h=0.0001,E;
    double u[2],dudt[2];
    int i,theta;
    
    // Read in user-supplied energy
    E=atoi(argv[1]);
    
    // Initial conditions
    u[0]=0.0;
    u[1]=1.0;
    
    // Create pointer to output file
    FILE *fp=fopen(out_file,"w");
    
    // Print initial conditions to output file
    fprintf(fp,"%lf %lf\n",0.0,u[0]);
    
    for(i=1;i<2e4;i++) {
        /* Step function */
        if(i*h<=1.0){
            theta=1.0;
        }
        if(i*h>1.0){
            theta=0.0;
        }
        // Integrate
        euler(u,dudt,h,theta,E);
        // Print results to output file as r/a u
        fprintf(fp,"%lf %lf\n",i*h,u[0]);
    }
}
