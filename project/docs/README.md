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

## Phase 2.b (02.12.2020-27.12.2020)

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
- 21 December sunrise time:
    - start: 7:01
    - end: 8:14
- 21 December sunset time:
    - start: 16:48
    - end: 18:02

### Room luminosity model

- pretty easy -> the weather luminosity has a nearly direct impact on room luminosity, we just have a factor from 0 to 1 (curtains, blinds, tinted windows, ...).


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

## Phase 3.a (09.12.2020-27.12.2020)

### Modularization
Consists in **modularizing** the project -> place each function / set of functions in a different file in order to protect some variables. We must control whom has access to what data. This was actually pretty much done from the start in my case.

### Box-Muller noise
Implemented a function that returns a noise following a gaussian distribution (for weather temperature) using the Box-Muller function.

## Phase 3.b (09.12.2020-27.12.2020)

That phase consists in linking all the different units together.

## Phase 4a

The controllers should transmit their values to the server using a mailbox.

The mailbox has `get` and `set` functions, the `set` functions are used by the controllers, the `get` functions are used by the server.

The data transmitted to the mailbox (a message) has a unified format: a string of max __51 chars__ (`\0` included). Each message concatenates many informations. In case the data is shorter than the available space, __spaces__ are used to pad. The controllers will write the data to the mailbox, the server will extract the data and handle it.

### Messages types

We define three message types:
1. Message to identification the controller -> "Hello, I exist, my name is Blabla."
2. Message to specify data type -> "I will send you temperatures."
3. Message to transmit a measurement -> "The new temperature is 20°."

### Type 1 - Identification - MSG1

Number of chars for each part of the message:

- type (int): 1c -> type of message, __has to be 1__
- controller code (int): 4c -> controller ID
- address (char[]): 45c -> localisation of the controller

### Type 2 - Type of data - MSG2

Number of chars for each part of the message:

- type (int): 1c -> type of message, __has to be 2__
- controller code (int): 4c -> controller ID
- phenomenom code (int): 4c -> ID of the phenomenom type
- phenomenom name (char[]): 20c -> name of the given phenomenom type, the name could be different for different languages

### Type 3 - Measurement - MSG3

Number of chars for each part of the message:

- type: 1c -> type of message, __has to be 3__
- controller code: 4c -> controller ID
- phenomenom code: 4c -> ID of the phenomenom type
- timestamp (long long): 10c -> in seconds?
- measurement (float): 10c -> float with max value +99999.999 (sign -> 1c, whole part -> 5c, point -> 1c, decimal part -> 3c)

