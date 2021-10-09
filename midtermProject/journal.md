# Midterm Project documentation

### October 2

Idea:
- My idea for this project is to create a robot that is able to draw with a viewers response after pressing a button.
- I am still not sure as to how this will be done but I am thinking of adding 2 buttons that the viewer can interact with the robot. Different buttons will have different responses and the drawing would look different.
- **Actuators** that will be used: 2 DC motors, 2 Servo motors, Neopixel matrix, (maybe an LED).

Initial Design:

<img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/sketch.png" width=400 align=center>

Process 1:
- I built the initial structure of the robot (it looks like a house from the inside)
- I tried my best to make it more organized so that I can easily adjust the wires and other things.
- I added the 2 DC motors, 2 Servo motors (which will act as the hands to hold the pen),and the 9v battery to make it wireless.
- Next step would be to start working on the code (and also maybe adding the neopixel matrix or the LED).

<img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/p2.png" width=300 align=center> <img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/p1.png" width=300 align=center> <img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/p3.png" width=300 align=center>


### October 3 and 4

- Today I worked on some part of the code but came across a problem.
- The DC motors were working fine when I tested them but after I attatched the wheels it stopped working and I can hear a sound from them.
- I also tested the servo motors and they are working fine but I am having trouble figuring out how to put everything in one code (the DC and Servo motors)
- It took a while to figure out the problem. I thought that there was something wrong with the wires, circuit or the motors, but Professor helped me and it turned out that the battery was dead so I had to replace it and it is working now.
[video of the problem](https://youtu.be/OIgIS6wNWHI)


### October 5

- Today I worked on the code for the motors. There will be 2 sequences which will be performed by the robot when 1 of the buttons is pressed. I started working on the first which will be the "fast" sequence. A pen will be attatched to the robot so when it moves, it will be drawing on the paper under it. The idea is to have the performance and the drawing result to be different when pressing a different button. 
- One button will be "fast". The other "slow", where the robot will be drawing slowly.

This is the button circuit:

<img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/p4.png" width=300 align=center>


### October 6

- I had a lot of trouble trying to make the servo motors work but they would sometimes not turn properly. One would turn then the other wouldn't and the robot would not stay balanced. So I thought that the problem was that my robot was too big and heavy so I decided to buid a smaller one. But it had the exact same problem, one motor would not turn.

<img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/p5.png" width=300 align=center>


### October 7

- I came up with a solution to keep the robot balanced. Which is placing a marble inside of a bottle cap that is acting as a third wheel so that the marble would roll and the robot would move more smoothly. This worked to keep the robot balanced but I was still having trouble with one of the motors that would not turn.
- When I hold the robot in my hand and test it out. both motors turn. But when it is placed on the floor one motor does not turn.

<img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/p6.png" width=300 align=center> <img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/midtermProject/p7.png" width=300 align=center>
