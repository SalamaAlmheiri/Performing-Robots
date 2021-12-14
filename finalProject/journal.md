# Final Project Documentation 
## Happy and Bashful robot (by Salama and Amina)
Initial idea and design are [here](https://github.com/SalamaAlmheiri/Performing-Robots/blob/874bc9346d5aed8b5ae2174b336bc6d59bdcae05/finalProject/README.md)

### Week 1 (Nov 28- Dec 4)
- Amina and I divided the work into 2 parts: the body and the head
- I worked on the body but we would also help each other in both part.

**Body:**
(4 DC motors, 1 Servo motor)
- I started by building the body of the robot and attaching the 4 DC motors (with the H-bridge).
- I tested that they all work with this [code](https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/finalProject/2_Motors_Switch.ino).  
- I also built a hand, which is attatched to a string on the servo motor, so that when the servo turns it would pull the string and make the hand movement. (for the mining scene with the axe)
- I tested the servo with this [code](https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/finalProject/ServoTest1.ino).  

This is what it looked like at first:

<img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/finalProject/robot1.png" width=340 align=center><img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/finalProject/robot2.png" width=300 align=center><img src="https://github.com/SalamaAlmheiri/Performing-Robots/blob/main/finalProject/robot3.png" width=300 align=center>

**With the radio:**
- Next I worked on the transmitter and receiver code to put everything together in one code and to be able control the robot with the buttons.
- The up, down and left buttons worked and the robot is moving forward and backwards correctly when pressing the buttons.

**Problems:**
1. Right button
- I receive the serial information when I press the right button, but the motors are not turning. (it might be a problem with my transmitter code but I am not sure)

2. Turning right and left
- Another problem was making the robot turn. When I press the left button, the robot would not turn.
- First I tried making 1 motor on the right to turn while the other are still. But the robot would not move (maybe because it is too heavy to move with 1 motor). [video]()
- So I tried making both motors on the right to turn, but the robot would go straight and not turn left. [video]()

**Initial code:**

[Transmitter]() 

[Receiver]() 

### Week 2 (Dec -)
