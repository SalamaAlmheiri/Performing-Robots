# Final Project Documentation 
## Happy and Bashful robot (by Salama and Amina)

### Week 1 (Nov 28- Dec 4)
- Amina and I divided the work into 2 parts: the body, the head
- I worked on the body but we would also help each other in both part.

**Body:**
(4 DC motors, 1 Servo motor)
- I started by building the body of the robot and attaching the 4 DC motors (with the H-bridge).
- I tested that they all work with this [code]().  
- I also built a hand, which is attatched to a string on the servo motor, so that when the servo turns it would pull the string and make the hand movement.
- I tested the servo with this [code]().  

**With the radio:**
- Next I worked on the transmitter and receiver code to put everything together in one code and to be able control the robot with the buttons.
- The up, down and left buttons worked. 

**Problems:**
1. Right button
- I receive the serial information when I press the right button, but the motors are not turning. (it might be a problem with my transmitter code but I am not sure)

2. Turning right and left
- Another problem was making the robot turn. When I press the left button, the robot would not turn.
- First I tried with making 1 motor on the right to turn while the other are still. But the robot would not move (maybe because it is too heavy to move for 1 motor). [video]()
- So I tried making both motors on the right to turn, but the robot would go straight and not turn left. [video]()

Initial code:
[Transmitter]() 
[Receiver]() 
