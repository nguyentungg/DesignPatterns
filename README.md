# DesignPatterns

Design Pattern in multiple programing languages.
Like any arms dealer, I have wares for sale to all combatants.

### Introduction

This repository is used to study and apply the Design Pattern in game and software development.

They're grouped into four categories: Sequencing Patterns, Behavioral Patterns, Decoupling Patterns, and Optimization Patterns.

Each of these patterns is described using a consistent structure so that you can use this repo as a reference and quickly find what you need.

1. Architecture, Performance, and Games

## II. Design Patterns Revisited

2. Command
3. Flyweight
4. Observer
5. Prototype
6. Singleton
7. State

## III. Sequencing Patterns

8. Double Buffer
9. Game Loop
10. Update Method

## IV. Behavioral Patterns

11. Bytecode
12. Subclass Sandbox
13. Type Object

## V. Decoupling Patterns

14. Component
15. Event Queue
16. Service Locator

## VI. Optimization Patterns

17. Data Locality
18. Dirty Flag
19. Object Pool
20. Spatial Partition

## How to use

• The **Intent** section provides a <ins>snapshot description of the pattern in terms of the problem it intends to solve</ins>. This is first so that you can hunt through the book quickly to find a pattern that will help you with your current struggle.

• The **Motivation** section describes an <ins>example problem that we will be applying the pattern to</ins>. Unlike concrete algorithms, a pattern is usually formless unless applied to some specific problem. Teaching a pattern without an example is like teaching baking without mentioning dough. This section provides the dough that the later sections will bake.

• The **Pattern** section <ins>distills the essence of the pattern out of the previous example</ins>. If you want a dry textbook description of the pattern, this is it. It’s also a good refresher if you’re familiar with a pattern already and want to make sure you don’t forget an ingredient.

• So far, the pattern has only been explained in terms of a single example. But **how do you know if the pattern will be good for your problem?**

- The **When to Use It** section provides some guidelines on when the pattern is useful and when it’s best avoided.
- The **Keep in Mind** section points out consequences and risks when using the pattern.

• If, like me, you need concrete examples to really get something, then **Sample Code** is your section. It walks <ins>step by step through a full implementation of the pattern</ins> so you can see exactly how it works.

• Patterns differ from single algorithms because they are <ins>open-ended</ins>. Each time you use a pattern, <ins>you’ll likely implement it differently</ins>. The next section, **Design Decisions**, <ins>explores that space and shows you different options to consider when applying a pattern.</ins>

• To wrap it up, there’s a short **See Also** section that shows how this pattern relates to others and points you to real-world open source code that uses it.

### What is good software architecture?
>
> “Just write your code so that changes don’t disturb its placid surface.” Robert Nystrom.

The first key piece is that architecture is about change. The measure of a design is how easily it accommodates changes.

## Design Patterns

---------------------------

### I. Behavioral Patterns

### II. Creational Patterns

### III. Structural Patterns

---------------------------

#### 1. Command (Behavioral Patterns)

Instead of invoking a method directly, the command pattern allows you to encapsulate one or more method calls as a “command object ”

- Commands are an object-oriented replacement for callbacks

**Context:**
Command pattern usually used for:

- Configuring Game Input
- Directions for Actors
- Undo and Redo

**Practice:**

- Configuring Game Input:

```cpp
// We define a base class that represents a triggerable game command:
class Command
{
public:
virtual ~Command() {}
virtual void execute() = 0;
};

// Then we create subclasses for each of the different game actions
class JumpCommand : public Command
{
public:
virtual void execute() { jump(); }
};
class FireCommand : public Command
{
public:
virtual void execute() { fireGun(); }
};

//In our input handler, we store a pointer to a command for each button
class InputHandler
{
public:
void handleInput();

// Methods to bind commands...
private:
Command* buttonX_;
Command* buttonY_;
Command* buttonA_;
Command* buttonB_;
};

// Now the input handling just delegates to those:
void InputHandler::handleInput()
{
if (isPressed(BUTTON_X)) buttonX_->execute();
else if (isPressed(BUTTON_Y)) buttonY_->execute();
else if (isPressed(BUTTON_A)) buttonA_->execute();
else if (isPressed(BUTTON_B)) buttonB_->execute();
}
```

- Directions for Actors

```cpp
// Instead of calling functions that find the commanded object themselves, we’ll pass in the object that we want to order around
class Command
{
public:
virtual ~Command() {}
virtual void execute(GameActor& actor) = 0;
};

//Here, GameActor is our “game object” class that represents a character in the game world. We pass it in to execute() so that the derived command can invoke methods on an actor of our choice, like so:
class JumpCommand : public Command
{
public:
virtual void execute(GameActor& actor)
{
actor.jump();
}
};
//Now, we can use this one class to make any character in the game hop around. We’re just missing a piece between the input handler and the command that takes the command and invokes it on the right object. First, we change handleInput() so that it returns commands:

Command* InputHandler::handleInput()
{
if (isPressed(BUTTON_X)) return buttonX_;
if (isPressed(BUTTON_Y)) return buttonY_;
if (isPressed(BUTTON_A)) return buttonA_;
if (isPressed(BUTTON_B)) return buttonB_;
// Nothing pressed, so do nothing.
return NULL;
}

//It can’t execute the command immediately since it doesn’t know what actor to pass in. 
// Here’s where we take advantage of the fact that the command is a reified call — we can delay when the call is executed.
// Then, we need some code that takes that command and runs it on the actor representing the player. Something like:
Command* command = inputHandler.handleInput();
if (command)
{
command->execute(actor);

//Assuming actor is a reference to the player’s character, this correctly drives him based on the user’s input, so we’re back to the same behavior we had in the first example. But adding a layer of indirection between the command and the actor that performs it has given us a neat little ability: we can let the player control any actor in the game now by changing the actor we execute the commands on.
```

- Undo and Redo

```cpp
class Command
{
public:
virtual ~Command() {}
virtual void execute() = 0;
virtual void undo() = 0;
};

//An undo() method reverses the game state changed by the corresponding execute() method. Here’s our previous move command with undo support:
class MoveUnitCommand : public Command
{
public:
MoveUnitCommand(Unit* unit, int x, int y)
: unit_(unit),
xBefore_(0),
yBefore_(0),
x_(x),
y_(y)
{}
virtual void execute()
{
// Remember the unit's position before the move
// so we can restore it.
xBefore_ = unit_->x();
yBefore_ = unit_->y();
unit_->moveTo(x_, y_);
}
virtual void undo()
{
unit_->moveTo(xBefore_, yBefore_);
}
private:
Unit* unit_;
int xBefore_, yBefore_;
int x_, y_;
};
// Note that we added some more state to the class. When a unit moves, it forgets where it used to be. If we want to be able to undo that move, we have to remember the unit’s previous position ourselves, which is what xBefore_ and yBefore_ do.
// This seems like a place for the Memento pattern, but I haven’t found it to work well. Since commands tend to modify only a small part of an object’s state, snapshotting the rest of its data is a waste of memory. It’s cheaper to manually store only the bits you change.
```
