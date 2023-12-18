
# laughing-octo-fiesta


# EmoSynth: Feel, Create, Hear
## CPSC 334 Creative Embedded Systems: Final Project

In collaboration with Richard Corrente

## Artist Statement:
In this interactive work of art, participants modify blocks associated with abstract feelings such as "euphoric" and "tranquil." The height of each block represents the intensity of each emotion visually. Using OpenAI's MuseNet, the installation converts these levels into multi-part MIDI compositions with melody and harmony. The resulting MIDI compositions, which are indicative of the emotional environment, are played in real-time via a webpage that provides a visual platform for users to observe how musical components interact. This merging of the physical and digital domains offers a way to investigate the deep relationship between feelings and music, creating a link between the production of MIDI art and individual expression.


### Materials List:
1. 7 servo motors: $0
2. Wood: $0
3. Paint
4. Screws (for Enclosure)
5. Linear Actuators (3D printed): $0
6. LED Pin

### Linear Actuator mechanism:
Our linear actuator system is made using 3D printing and pushes blocks that represent emotions by converting continuous servo rotations into smooth linear movements. Despite difficulties with 3D printing, such as breakages, we improved the design by lengthening the actuator rods for better performance. The longer rods were also necessary, as we discovered from experimentation, for pushing our long wooden blocks out more for extended visibility/functionality of our enclosure.

### Visual Levels (Blocks and LED):
6 wooden blocks and a LED Pn compose the enclosure, representing visually and kinetically the gradients of user-submitted emotions, in which their heights and on/off states correlate with a value for that emotion expressed on the scale of 1-10.


Use the button to change which wooden block moves, altering the emotional gradient. Press it to toggle through the blocks. The switch changes the direction of block movement—up or down. Block levels rest when the button state is 0.

Press the button repeatedly to cycle through moving blocks 1-6 and the LED, adjusting their heights. On the 8th press, send the finalized data to your computer, translating the block positions and LED states into unique music expressions.

### Significant Challenges:
Initial Ambition:
Our original vision aimed to visualize sound waves in real time using servo motors. However, we encountered two major hurdles: First, the servo motors couldn't move fast enough to keep up with the constantly changing sound waves, posing a mechanical challenge. Second, the noisy servo motors interfered with the sounds they were meant to represent. This led us to pivot towards an interactive approach where users control motor movements to generate unique music, fostering creativity and overcoming the initial limitations.

Mechanical Engineering Hurdles:
It took a long time to fine-tune servo motors for accurate control. To achieve smooth motions while minimizing jitteriness, motor calibration had to be adjusted iteratively. We had difficulty decreasing friction and guaranteeing uniform performance across all motors.

AI Music Generation:
The challenge with AI music synthesis was synchronizing real-time user-controlled motor movements with AI compositions. We ran into problems when building an algorithm that dynamically adjusted music portions based on user input. Extensive testing and optimization were necessary to enable a smooth transition between user-driven creativity and AI-generated harmony, particularly in matching the immediacy of user inputs with the AI's reaction.

Lessons Learned:
To change the course of the project, we needed clear communication and a shared knowledge of our objectives. The AI integration gave firsthand knowledge with the hurdles of integrating new technology, in which we ran into many obstacles with setup while programming. Ultimately, this project challenged and thus strengthened our project-planning skills; we learned to maintain regular team check-ins and open conversation, both of which were critical in overcoming challenges and cultivating a communal problem-solving mentality. 