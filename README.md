# Castle Adventure Game 

## Overview
The Castle Adventure Game is a text-based exploration and adventure game set in a castle filled with various creatures. 
Players navigate through multiple rooms in the castle, encountering monsters such as dragons and goblins. The game relies 
on random generation for the castle layout and monster appearances, providing a different experience each time the game 
is played.

## Game Structure

### 1. Castle
The castle is the central environment where the player explores. It consists of 15 to 20 rooms, each containing monsters 
or other encounters. The rooms are generated randomly when the game starts, ensuring a dynamic and varied gameplay experience.

- **Castle Generation**: The `castle.cpp` file manages the creation of rooms. When the castle is generated, it creates a random 
  number of rooms (between 15 and 20). Each room may contain different types of monsters.
- **Castle Saving**: The game allows saving the castle's state using the `save` function. This feature helps in saving 
  progress so players can continue their adventure later.

### 2. Rooms
Rooms are individual segments within the castle, each identified by a room number. Rooms can contain monsters, and the player 
must decide how to interact with these creatures. The `room.cpp` file manages the creation and behavior of rooms.

- **Monster Generation**: The number of monsters in each room is based on the room number. The higher the room number, 
  the greater the chance of encountering monsters. Monsters are added using the Monster Factory method, which generates 
  a random monster (e.g., dragon, goblin) in the room.
- **Room Interaction**: Players receive information about each room as they enter, including details about any monsters present.

### 3. Creatures
The game features several types of creatures, each derived from a base class (`creature.h`). Specific monster types include:
- **Dragon** (`dragon.h`): A powerful monster that may pose a significant challenge.
- **Goblin** (`goblin.h`): A smaller, less dangerous monster compared to the dragon.

The monsters have unique properties and behaviors. When a player encounters them, they must choose to fight or take other actions.

### 4. Game Mechanics
The `game.cpp` file coordinates the game’s mechanics. This includes initializing the game, managing player input, and ensuring 
smooth progression. The player interacts with the game through console-based prompts, responding to events and making decisions 
such as:
- **Inspecting rooms** to gather information.
- **Fighting monsters** or avoiding combat when possible.
- **Navigating** between rooms to explore the castle.

### 5. Combat System
The combat system engages the player when they encounter monsters. The outcome may depend on random values or probabilities, 
determined using the functionality provided in `random.cpp`. For example, the player's actions and luck determine success 
when fighting a monster.

### 6. Randomization
The `random.cpp` file handles random number generation, which is central to the game. It controls the following aspects:
- The number of rooms in the castle.
- The types and numbers of monsters in each room.
- The outcome of combat or other chance-based events.

### 7. Console and Visual Effects
The game enhances the text-based interface using ANSI escape codes (managed in `ansi_color.cpp`). This adds colors to the 
console output, making it easier to distinguish between different game elements like room descriptions, monster encounters, 
and player actions.

## How to Play

1. **Setup**:
   - Ensure you have a C++ compiler installed, such as GCC (`g++`) or MinGW.
   - Compile the game using the following command:
     
     “g++ -o castle_game ansi_color.cpp castle.cpp game.cpp monster.cpp random.cpp room.cpp -std=c++11”
     

2. **Running the Game**:
   - Execute the compiled file:
     
      "castle_game.exe"

3. **Game Controls**:
   - Players interact through console prompts. They can choose options such as:
     - Moving between rooms.
     - Inspecting rooms for monsters or other elements.
     - Engaging in combat with monsters or attempting to avoid them.

4. **Objective**:
   - Explore the castle, survive encounters with monsters, and progress through all the rooms. The ultimate objective may 
     vary based on how the game is set up, but it generally involves surviving and completing the exploration.

## Tips
- **Save Progress**: Use the game's save feature to save your progress at key points.
- **Experiment**: Since the game is based on random generation, each playthrough may offer different challenges and opportunities.

Enjoy your adventure through the mysterious castle!

