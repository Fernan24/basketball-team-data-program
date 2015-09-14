//
//  main.c
//  equipo de baloncesto
//
//  Created by Fernando Rodriguez and Graciany Lebrón on 9/29/14.
//  Copyright (c) 2014 Fernando Rodriguez and Graciany Lebrón. All rights reserved.
//
//  Program will print the info of mayaguez basketball indians team

#include <stdio.h>
#include <math.h>

char* team_name ="Indios";
char* team_town ="Mayaguez";
char* team_owner="Eddie Casiano";
char* team_court="Palacio de recreacion y deportes\n";
char* team_address=" Palacio de Recreacion y Deportes,\n 87 Cll Miguel a Santin,\n Mayagüez, 00680";


int main(void) {
    
    printf("Este programa muestra la informacion del equipo de baloncesto de los Indios de Mayaguez:\n\n");
    
    printf("%s\n", team_name);
    printf("%s\n", team_town);
    printf("%s\n", team_owner);
    printf("%s\n", team_court);
    printf("%s\n", team_address);
    
    
    
    const int row = 12;
    int index1=0;  //index1 == row
    float indios_team[row][5];
    float intentos;  //shots taken
    float canastos;  //shots scored
    float player_effectivity;
    float team_average, percent_average;
    float sum_intentos=0;
    float sum_canastos=0;
    float sum_averages=0;
    float sum_medium=0;
    float standard_deviation;
    
    
    //makes a 12X5 array for team statistics
    for(index1=0; index1<row; index1++) {
        
        //players
        indios_team[index1][0] = index1+1;
        
        printf("\nEnter number of shots taken for player %i: ", index1+1);
        scanf("\n%f", &intentos);
       
        //shots taken cannot be less than 0
        while (intentos<0) {
            
            printf("\nError the number of shots taken cannot be less than 0.");
            printf("\nPlease enter a valid number of shots taken. ");
            scanf("\n%f", &intentos);
        }
        
        indios_team[index1][1] = intentos;
        
        printf("\nEnter number of shots scored for player %i: ", index1+1);
        scanf("\n%f", &canastos);
       
        //shots scored cannot be more thna shots taken per player
        
        while (canastos>intentos) {
            
            printf("\nError the number of shots scored cannot be more than the number of shots taken.");
            printf("\nPlease enter a valid number of shots scored based on those taken.");
            scanf("\n%f", &canastos);
            }
        
        
        while (canastos<0) {
            
            printf("\nError the number of shots scored cannot be less than 0.");
            printf("\nPlease enter a valid number of shots scored.");
            scanf("\n%f", &canastos);
        }
    
        indios_team[index1][2] = canastos;
        
        if (intentos==0) {
            player_effectivity = 0.00;
        }
        else {
            player_effectivity = (canastos/intentos)*100;
        }
        //calculates player effectiveness (pociento de effectividad)
        indios_team[index1][3] = player_effectivity;
        
        sum_intentos += indios_team[index1][1];
        sum_canastos += indios_team[index1][2];
        
        sum_averages += indios_team[index1][3];
    }
    
    //calculates the average field goal percent
    percent_average= sum_averages/row;
    
    //calculates the team average==medium for standard deviation
    team_average = sum_canastos/row;
    
    
    //sums variations to calculate standard deviation
    for(index1=0; index1<row; index1++)
    {
        indios_team[index1][4] = powf(team_average - indios_team[index1][2], 2);
        sum_medium += indios_team[index1][4];
    }
    
    //calculates standard deviation
    standard_deviation=sqrtf(sum_medium/(row-1));
    
    printf("\n");
    
    printf("                     Indios Team Stats");
    printf("\nPlayer | Shots taken | Shots scored | Field goal percent");
    
    //prints the table of the teams statistics
    for(index1=0; index1<row; index1++) {
        
        printf("\n");
        printf ("%4.0f", indios_team[index1][0]);
        printf ("%10.0f", indios_team[index1][1]);
        printf ("%17.0f", indios_team[index1][2]);
        printf ("%20.2f", indios_team[index1][3]);
        
    }
    
    printf("\n");
    
    printf("\ntotal:    %4.0f             %4.0f               %3.2f\n", sum_intentos, sum_canastos, percent_average);
    
    //prints the team average
    printf("\nThe team shots scored average is: %3.2f\n", team_average);
    
    //prints standard deviation
    printf("\nThe standard deviation of the team of the shots scored is: %2.2f\n", standard_deviation);
    
    //prints the team embers above average
    printf("\nThe team members above the team field goal percentage average are:");
    for(index1=0; index1<row; index1++){
        if (indios_team[index1][3]>percent_average) {
            printf("\nPlayer %2.0f",indios_team[index1][0]++);
        }
    }
    
    printf("\n");
    
    
}

