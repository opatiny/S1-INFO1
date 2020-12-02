# C Project: Entities control simulator

## Context

The goal is to implement a simulator of an appartment, which consists of two rooms. Additionally, an aquarium is placed in room 2. They are two external variables: luminosity and temperature. We will have to compute the variation of the temperature and luminosity inside of the rooms. Based on these "measurements", the temperature of the rooms will have to be controlled in order to ensure it is comfortable. The luminosity in room 2 will affect the algea in the aquarium, and therefore the amount of oxygen in the water, and the PH. Again, the PH ought to be controlled.

The simulated measurements of the luminosity and temperature should be stored in order to manipulate this data and produce statistics. We will first store the data in arrays, then, we will learn to store it in external files, which are permanent. This will allow the statistics to be computed after the completion of the simulation.

Each function of the program is called at different times, but some can run "simultaneously". In other words, we will simulate some multithreading. To achieve that in C, we will have to implement a super-function called the `Scheduler`, which handles the functions calls.

Throuought the project, a top-down approach is prefered.

## Phase 1 (11-18.11.2020)

Implementation of the general layout of the program. The prototypes and definitions of the functions are written. The scheduler is implemented, and it calls all the functions at the appropriate TICs. The TIC defines how many times the simulation must run. It is defined by the user at the beginning of the program. The length of the simulation is also defined by the user. The frequency at which each function is called is defined using a modulo.

__Remark:__ We decided to set the project time unit to **one second**. Every function using the time expects a time in seconds.

## Phase 2.a (19.11.2020-01.12.2020)

- Defining the structures that will contain the data
    - weather, which contains temperature and luminosity
    - rooms
- Implementing the weather temperature model
- Implementing the room temperature model
- Created test infrastructure

## Phase 2.b (02.12.2020)

### Weather luminosity model

- the model will be made of five segments:
    - constant luminosity at night/morning
    - luminosity going up
    - luminosity constant during the day
    - luminosity decreasing
    - luminosity constant during evening/night
- we need a structure containing all the luminosity data:
    - current weather luminosity
    - array of ints defining the intervals where we change of segment
    - minimal luminosity value
    - maximal luminosity value
    - slope when luminosity is increasing
    - slope when luminosity is decreasing

#### Luminosity data 

Source: https://en.wikipedia.org/wiki/Daylight

- typical midday clear sky luminosity: 20'000 lux
- typical bright sun luminosity: 100'000 lux
- typical night luminosity (with moonlight): 0.25 lux

#### Sunset and sunrise data for Lausanne

Source: https://www.timeanddate.com/sun/switzerland/lausanne

We consider sunrise and sunset as nautical twilight + civil twilight. 

- 21 June sunrise time:
    - start: 04:07
    - end: 05:40
- 21 June sunset time:
    - start: 21:30
    - end: 23:02
- 21 Desember sunrise time:
    - start: 7:01
    - end: 8:14
- 21 December sunset time:
    - start: 16:48
    - end: 18:02

### Room luminosity model

- pretty easy -> the weather luminosity has a nearly direct impact on room luminosity, we just have a factor from 0 to 1 (curtains, blinds, tinted windows, ...)


### Aquarium PH model

- structure for the PH data:
    - current PH
    - room luminosity
    - luminosity threshold
    - pump impact

### Aquarium PH control model

- PH control structure:
    - amount oxygen
    - target PH
    - proportionality factor (between amount of oxygen and PH difference)