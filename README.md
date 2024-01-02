# Emotion Synthesizer: Feel, Create, Hear
## CPSC 334 Creative Embedded Systems: Final Project

In collaboration with Richard Corrente

![Front image of enclosure](https://i.imgur.com/oQsITTU.png)
![2nd Front image of enclosure](https://i.imgur.com/UT0SRK3.png)

## Overview

---

- An esp32-Python-powered sculpture relying on user interaction with 6 servo motors via a multi-state button and a switch.
- Users can compose a melody by moving wooden columns up and down. Each column represents an abstract emotion/feeling (in order): “Euphoric,” “Nostalgic,” “Melancholic,” “Jolliness,” “Ethereal,” “Tranquil.”
    - The positions of the columns are constantly recorded by OpenAI's MuseNet, which converts these levels into multi-part MIDI compositions with melody and harmony.
    - “Uplifting” is represented by the on/off state of an RGB LED
    
### Linear Actuator mechanism:
    
  - To accurately and consistently push an object in a straight line using servo motors, a linear actuator is needed. Linear actuators convert continuous servo rotations into smooth, linear movements.
  - To introduce a degree of randomness (and heighten user interaction), we made the actuators randomly nudge the columns up/down after some time.
    - Our linear actuator system is made of [3D-printed models](https://www.myminifactory.com/object/3d-print-77542) consisting of:
      - Gears
        - 150mm pusher rods
        - Micro servo brackets
        - **[FEETECH FS90R Micro Continuous Rotation Servo](https://www.pololu.com/product/2820)**
    - Implementing the linear actuators required a lot of experimentation. A model was never printed without any flaws, leading to some sanding and other physical adjustments to suit our purposes.
        - We went through many iterations of pusher rod lengths, from 50mm to 150mm. We finally settled on 150mm pusher rods as they provided better visibility and functionality when pushing the wooden columns out of the enclosure. We also went through many pusher rods…they are quite fragile.

![Image of linear actuator](https://i.imgur.com/oM3M0LA.jpg)
![2nd image of linear actuator](https://i.imgur.com/3e28rqF.jpg)


### Visual Elements (Blocks and LED):

- A black-and-white wooden box, 6 white wooden blocks and their corresponding emotions, and an RGB LED.
    - The columns visually and kinetically represent the gradients of user-submitted emotions, in which the columns’ heights and on/off states correlate with a value for that emotion expressed on a scale of 1-10.
    - The blocks are painted white as they represent piano keys 🎹
        - The box is painted black/white to also represent a piano

![Image of wooden cube](https://i.imgur.com/15HlKi6.jpg)


### User Interaction (Button and Switch):

- The user must press the button to change which wooden column moves, 
altering the emotional gradient.
    - Press the button repeatedly to cycle through columns 1-6 and the LED (7th state in our testing). On the 8th press, the user sends the finalized composition to the computer, translating the block positions and LED states into unique music expressions.
- The switch changes the direction of block movement—up or down. The user can use the button to immediately switch to the column even while the current column is moving.
- The switch turns on/off the RGB LED, turning on/off the presence of the  “Uplifting” emotion in the generation of a melody composition.

![Image of enclosure's top](https://i.imgur.com/G1WYuL2.jpg)


## Creative Process

---

### Artistic Statement

- In this interactive work of art, participants manipulate columns of wooden blocks representing abstract feelings such as "euphoric" and "tranquil." The height of each block represents the intensity of each emotion visually.
- Using OpenAI's MuseNet, the kinetic installation converts these levels into multi-part MIDI compositions with melody and harmony. The resulting MIDI compositions play in real-time via a webpage providing users a visual platform to observe how these physical and digital musical components interact.
- This merging of the physical and digital domains offers a way for users to investigate the deep relationship between their feelings and music, creating a link between the production of MIDI art and individual expression.

### Challenges

1. Initial ambitions:
    - Our original vision aimed to visualize sound waves in real time using servo motors. However, we encountered two major hurdles: First, the servo motors couldn't move fast enough to keep up with the constantly changing sound waves, posing a mechanical challenge. Second, the noisy servo motors interfered with the sounds they were meant to represent. This led us to pivot towards an interactive approach where users control motor movements to generate unique music, fostering creativity and overcoming the initial limitations.

2. Optimizing the movement of the servo motors: 
    - It took a long time to fine-tune servo motors for accurate control. To achieve smooth motions while minimizing jitteriness, we had to physically calibrate the motors’ potentiometers and iteratively adjust their movement through position/speed values in the Arduino IDE. We had difficulty decreasing friction and guaranteeing uniform performance across all motors. We fried a couple of them, sadly.
        - Each motor seemed to handle the 150mm pushers differently. The pushers weren’t sanded equally, as some were printed ready for implementation, and some others required extensive sanding and applications of WD-40. Richard broke a decent amount of them, as they would get mercilessly stuck in the servo brackets.
        - Some potentiometers were severely sensitive to adjustments. A motor could stop and move forward perfectly, but unable to move backward—and vice versa.

3. AI Music Generation:
    - The challenge with AI music synthesis was synchronizing real-time user-controlled motor movements with AI compositions. We ran into problems when building an algorithm that dynamically adjusted music portions based on user input. Extensive testing and optimization were necessary to enable a smooth transition between user-driven creativity and AI-generated harmony, particularly in matching the immediacy of user inputs with the AI's reaction.

4. Lessons Learned:
    - To change the course of the project, we needed clear communication and a shared knowledge of our objectives. The AI integration gave us firsthand knowledge of the hurdles of integrating new technology, in which we ran into many obstacles with setup while programming. Ultimately, this project challenged and thus strengthened our project-planning skills; we learned to maintain regular team check-ins and open conversation, both of which were critical in overcoming challenges and cultivating a communal problem-solving mentality.


## Materials List:
Total: $144.41 🫠

---

1. 10 Servo motors (fried 2, used 6, 2 ran away): $57.40
2. Wood for the enclosure: $14.10
3. Paint (black and white) + primer + paintbrush: $23.39
4. Screws (for the linear actuators): $26.13
5. 3D-printed linear actuators (3D-printing service provided): $0
6. Metal hinges (found + modified in the School of Architecture): $0
7. 50 1.5x1.5 inch Wooden blocks (used 24): $23.39
8. Small button (provided: $0
9. Switch (provided): $0
10. RGB LED (provided): $0
11. ESP32 (provided): $0


## Circuitry + Enclosure Photos:

---

![Image of total wiring](https://i.imgur.com/7QeeocQ.jpg)

![Image of breadboard circuitry](https://i.imgur.com/covs6Ci.jpg)

![Image of enclosure's back](https://i.imgur.com/fns3War.png)
  - Back panel with 2 metal hinges attached for easy access to circuitry and blocks.
