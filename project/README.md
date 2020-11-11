# C Project: Entities control simulator

## Context

The goal is to implement a simulator of an appartment, which consists of two rooms. Additionally, an aquarium is placed in room 2. They are two external variables: luminosity and temperature. We will have to compute the variation of the temperature and luminosity inside of the rooms. Based on these "measurements", the temperature of the rooms will have to be controlled in order to ensure it is comfortable. The luminosity in room 2 will affect the algea in the aquarium, and therefore the amount of oxygen in the water, and the PH. Again, the PH ought to be controlled.

The simulated measurements of the luminosity and temperature should be stored in order to manipulate this data and produce statistics. We will first store the data in arrays, then, we will learn to store it in external files, which are permanent. This will allow the statistics to be computed after the completion of the simulation.

Each function of the program is called at different times, but some can run "simultaneously". In other words, we will simulate some multithreading. To achieve that in C, we will have to implement a super-function called the `Scheduler`, which handles the functions calls.

Throuought the project, a top-down approach is prefered.

# Phase 1 (11-18.11.2020)

Implementation of the general structure of the program. The prototypes and definitions of the functions are written. The scheduler is implemented, and it calls all the functions at the appropriate TICs. The TIC is the time unit. It is defined by the user at the beginning of the program. The length of the simulation is also defined by the user. The frequency at which each function is called is defined using a modulo.