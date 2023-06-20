# Design Patterns In Game

## Introduction

This repository is used to study and apply the Design Pattern in game and software development.

They're grouped into four categories: Sequencing Patterns, Behavioral Patterns, Decoupling Patterns, and Optimization Patterns.

Each of these patterns is described using a consistent structure so that you can use this repo as a reference and quickly find what you need.

## How to use

• The **Intent** section provides a <ins>snapshot description of the pattern in terms of the problem it intends to solve</ins>. This is first so that you can hunt through the book quickly to find a pattern that will help you with your current struggle.

• The **Motivation** section describes an <ins>example problem that we will be applying the pattern to</ins>. Unlike concrete algorithms, a pattern is usually formless unless applied to some specific problem. Teaching a pattern without an example is like teaching baking without mentioning dough. This section provides the dough that the later sections will bake.

• The **Pattern** section <ins>distills the essence of the pattern out of the previous example</ins>. If you want a dry textbook description of the pattern, this is it. It’s also a good refresher if you’re familiar with a pattern already and want to make sure you don’t forget an ingredient.

• So far, the pattern has only been explained in terms of a single example. But **how do you know if the pattern will be good for your problem?**

- The **When to Use It** section provides some guidelines on when the pattern is useful and when it’s best avoided.
- The **Keep in Mind** section points out consequences and risks when using the pattern.

• If, like me, you need concrete examples to really get something, then **Sample Code** is your section. It walks <ins>step by step through a full implementation of the pattern</ins> so you can see exactly how it works.

• Patterns differ from single algorithms because they are <ins>open-ended</ins>. Each time you use a pattern, <ins>you’ll likely implement it differently</ins>. **Design Decisions**, <ins>explores that space and shows you different options to consider when applying a pattern.</ins>

• To wrap it up, there’s a short **See Also** section that shows how this pattern relates to others and points you to real-world open source code that uses it.

## II. Design Patterns

### [1. Command](http://gameprogrammingpatterns.com/command.html)

- **Intent:** A command is a reified method call.

- **Motivation:** Commands are an object-oriented replacement for callbacks.

- **The Pattern:** Encapsulate a request as an object, thereby letting users parameterize clients with different requests, queue or log requests, and support undoable operations.

- **When to Use It:**
  - Configuring Input
  - Directions for Actors
  - Undo and Redo

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [2. Flyweight](http://gameprogrammingpatterns.com/flyweight.html)

- **Intent:** Forest for the Trees

- **Motivation:**

- **The Pattern:** The pattern solves that by separating out an object’s data into two kinds. The first kind of data is the stuff that’s not specific to a single instance of that object and can be shared across all of them

- **When to Use It:**
  - A thousand instances: Tree, grass, river, rock, tile

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [3. Observer](http://gameprogrammingpatterns.com/observer.html)

- **Intent:** It lets one piece of code announce that something interesting happened without actually caring who receives the notification.

- **Motivation:**

- **How it Works:**
  - The observer: The nosy class that wants to know when another object does something interesting
  - The subject: The notification method is invoked by the object being observed called "subject". It has two jobs: 
    - First, it holds the list of observers that are waiting oh-so-patiently for a missive from it.
    - Second, it's sending notifications.
  - Observable physics: Now, we just need to hook all of this into the physics engine so that it can send notifications and the achievement system can wire itself up to receive them.

- **When to Use It:**
  - Achievements System
  - Mission
  - Audio

- **Keep in Mind:**
  - Linked observers
  - A pool of list nodes
  - Destroying subjects and observers
  - Don’t worry, I’ve got a GC

- **Design Decisions:**

- **Sample Code:**

### [4. Prototype](http://gameprogrammingpatterns.com/prototype.html)

- **Intent:** The key idea is that an object can spawn other objects 
similar to itself. If you have one ghost, you can make more ghosts from it. If you have a demon, you can make other demons. Any monster can be treated as a prototypal monster used to generate other versions of itself.

- **Motivation:**

- **How well does it work:**
  - Spawn functions
  - Templates
  - First-class types

- **When to Use It:**
  - Ghost, Demon, Sorcerer, etc.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [5. Singleton](http://gameprogrammingpatterns.com/singleton.html)

- **Intent:** 

- **Motivation:**
  - Providing a global point of access

- **The Pattern:** Ensure a class has one instance, and provide a global point of access to it.

- **When to Use It:**

- **Keep in Mind:**
  - Poorly designed singletons are often “helpers” that add functionality to another class.
  - If you can, just move all of that behavior into the class it helps.
  - OOP is about letting objects take care of themselves.
  - We may want to restrict access to certain areas of the code or even make it private to a single class. In those cases, providing a public global point of access weakens the architecture.
  - To provide convenient access to an instance: 
    - Pass it in.
    - Get it from the base class.
    - Get it from something already global.
    - Get it from a Service Locator.

- **Design Decisions:**
  - Why We Use It
    - It doesn’t create the instance if no one uses it.
    - It’s initialized at runtime.
    - You can subclass the singleton.
  - Why We Regret Using It: "_It’s a global variable_"
    - They make it harder to reason about code.
    - They encourage coupling.
    - They aren’t concurrency-friendly.
    - It solves two problems even when you just have one.
    - Lazy initialization takes control away from you.

- **Sample Code:**

### [6. State](http://gameprogrammingpatterns.com/state.html)

- **Intent:** Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

- **Motivation:**
  - Finite State Machines (FSM)
  - Enums and Switches

- **The Pattern:** Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

- **How it Works:**
  - A state interface
  - Classes for each state
  - Delegate to the state
  - Static states/Instantiated states

- **When to Use It:**

- **Keep in Mind:**
  - Concurrent State Machines
  - Hierarchical State Machines
  - Pushdown Automata

- **Design Decisions:**

- **Sample Code:**

## III. Sequencing Patterns

### [7. Double Buffer](http://gameprogrammingpatterns.com/double-buffer.html)

- **Intent:** Cause a series of sequential operations to appear instantaneous or simultaneous.

- **Motivation:** (Rendering problem)
  - When the game draws the world the users see, it does so one piece at a time — the mountains in the distance, the rolling hills, the trees, each in its turn. If the user watched the view draw incrementally like that, the illusion of a coherent world would be shattered. The scene must update smoothly and quickly, displaying a series of complete frames, each appearing instantly (Khi trò chơi vẽ thế giới mà người dùng nhìn thấy, nó thực hiện một phần một lần - những ngọn núi xa, những đồi trải dài, cây cối, mỗi thứ theo lượt của nó. Nếu người dùng quan sát cảnh nhìn được vẽ theo từng phần như vậy, ảo tưởng về một thế giới mạch lạc sẽ tan biến. Cảnh phải được cập nhật mượt mà và nhanh chóng, hiển thị một loạt các khung hình hoàn chỉnh, mỗi khung hiện lên ngay lập tức).

  - Double buffering solves this problem. During rendering, we write to the framebuffer not being read by the video driver. When the rendering is complete, we switch between the two framebuffers for the video driver to read the new framebuffer.( Trong quá trình vẽ, chúng ta ghi vào framebuffer không được đọc bởi video driver. Khi vẽ xong, chúng ta chuyển đổi giữa hai framebuffer để video driver đọc framebuffer mới).

  - Using double buffering ensures that the entire image appears on the screen cohesively without _tearing_.(Việc sử dụng double buffering đảm bảo rằng toàn bộ hình ảnh xuất hiện trên màn hình một cách đồng nhất và không có tearing).

  - Process: As one scene ends on stage A, the lights are immediately switched to stage B, allowing the next scene to begin. Meanwhile, the stagehands prepare stage A for the following scene. Once the second scene ends, the lights return to stage A. This seamless process continues throughout the play, ensuring smooth scene transitions without any visible disruptions (Khi một cảnh kết thúc trên sân khấu A, đèn trên sân khấu A sẽ được tắt và đèn trên sân khấu B sẽ được bật, cho phép cảnh tiếp theo bắt đầu ngay lập tức. Đồng thời, những người hỗ trợ sân khấu sẽ làm việc trên sân khấu đã tắt để chuẩn bị cho cảnh tiếp theo).

- **The Pattern:**
  - A **buffered class** encapsulates a **buffer**: a piece of state that can be modified. This buffer is edited incrementally, but we want all outside code to see the edit as a single atomic change. To do this, the class keeps two instances of the buffer: a **next buffer** and a **current buffer.**

  - When information is read from a buffer, it is always from the current buffer. When information is written to a buffer, it occurs on the next buffer. When the changes are complete, a **swap** operation swaps the next and current buffers instantly so that the new buffer is now publicly visible. The old current buffer is now available to be reused as the new next buffer.

- **How does it work:**

- **When to Use It:**
  - This pattern is one of those ones where you’ll know when you need it. If you have a system that lacks double buffering, it will probably look visibly wrong (tearing, etc.) or will behave incorrectly. But saying, “you’ll know when you need it” doesn’t give you much to go on. More specifically, this pattern is appropriate when all of these are true:

    - We have some state that is being modified incrementally.

    - That same state may be accessed in the middle of modification.

    - We want to prevent the code that’s accessing the state from seeing the work in progress.

  - We want to be able to read the state and we don’t want to have to wait while it’s being written.

  - When the code doing the modification is accessing the same state that it’s modifying. This can manifest in a variety of places, especially physics and AI where you have entities interacting with each other. Double-buffering is often helpful here too.

- **Keep in Mind:**
  - The swap itself takes time
  - We have to have two buffers

- **Design Decisions:**
  - How are the buffers swapped?
    - Swap pointers or references to the buffer:
      - It’s fast.
      - Outside code cannot store persistent pointers to the buffer.
      - Existing data on the buffer will be from two frames ago, not the last frame.
    - Copy the data between the buffers:
      - Data on the next buffer is only a single frame old.
      - Swapping can take more time.
  - What is the granularity of the buffer?
    - If the buffer is monolithic.
    - If many objects have a piece of data: Swapping is slower.

- **Sample Code:**

```cpp
class Framebuffer
{
public:
  Framebuffer() { clear(); }

  void clear()
  {
    for (int i = 0; i < WIDTH * HEIGHT; i++)
    {
      pixels_[i] = WHITE;
    }
  }

  void draw(int x, int y)
  {
    pixels_[(WIDTH * y) + x] = BLACK;
  }

  const char* getPixels()
  {
    return pixels_;
  }

private:
  static const int WIDTH = 160;
  static const int HEIGHT = 120;

  char pixels_[WIDTH * HEIGHT];
};
// The Scene Class
class Scene
{
public:
  Scene()
  : current_(&buffers_[0]),
    next_(&buffers_[1])
  {}

  void draw()
  {
    next_->clear();

    next_->draw(1, 1);
    // ...
    next_->draw(4, 3);

    swap();
  }

  Framebuffer& getBuffer() { return *current_; }

private:
  void swap()
  {
    // Just switch the pointers.
    Framebuffer* temp = current_;
    current_ = next_;
    next_ = temp;
  }

  Framebuffer  buffers_[2];
  Framebuffer* current_;
  Framebuffer* next_;
};

```

Another example:
```cpp
class Actor
{
public:
  Actor() : currentSlapped_(false) {}

  virtual ~Actor() {}
  virtual void update() = 0;

  void swap()
  {
    // Swap the buffer.
    currentSlapped_ = nextSlapped_;

    // Clear the new "next" buffer.
    nextSlapped_ = false;
  }

  void slap()       { nextSlapped_ = true; }
  bool wasSlapped() { return currentSlapped_; }

private:
  bool currentSlapped_;
  bool nextSlapped_;
};

void Stage::update()
{
  for (int i = 0; i < NUM_ACTORS; i++)
  {
    actors_[i]->update();
  }

  for (int i = 0; i < NUM_ACTORS; i++)
  {
    actors_[i]->swap();
  }
}

```

### [8. Game Loop](http://gameprogrammingpatterns.com/game-loop.html)

- **Intent:** Decouple the progression of game time from user input and processor speed.

- **Motivation:**

- **The Pattern:**
A **game loop** runs continuously during gameplay. Each turn of the loop, it **processes user input** without blocking, **updates the game state**, and **renders the game**. It tracks the passage of time to **control the rate of gameplay.**

- **How does it work:**

- **When to Use It:**

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

```cpp
while (true)
{
  processInput();
  update();
  render();
}
```
Play catch up
```cpp
double previous = getCurrentTime();
double lag = 0.0;
while (true)
{
  double current = getCurrentTime();
  double elapsed = current - previous;
  previous = current;
  lag += elapsed;

  processInput();

  while (lag >= MS_PER_UPDATE)
  {
    update();
    lag -= MS_PER_UPDATE;
  }

  render();
}

```

### [9. Update Method](http://gameprogrammingpatterns.com/update-method.html)

- **Intent:** Simulate a collection of independent objects by telling each to process one frame of behavior at a time.

- **Motivation:**

- **The Pattern:** The **game world** maintains a **collection of objects.** Each object implements an **update method** that **simulates one frame** of the object’s behavior. Each frame, the game updates every object in the collection.

- **How does it work:**

- **When to Use It:**
If the Game Loop pattern is the best thing since sliced bread, then the Update Method pattern is its butter.
  - If the game has space marines, dragons, Martians, ghosts, or athletes, there’s a good chance it uses this pattern.
  - If the game is more abstract and the moving pieces are less like living actors and more like pieces on a chessboard, this pattern is often a poor fit.
  - Your game has a number of objects or systems that need to run simultaneously.
  - Each object’s behavior is mostly independent of the others.
  - The objects need to be simulated over time.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

## IV. Behavioral Patterns

### [10. Bytecode](http://gameprogrammingpatterns.com/bytecode.html)

- **Intent:** Give behavior the flexibility of data by encoding it as instructions for a virtual machine.

- **Motivation:**

- **The Pattern:** An **instruction set** defines the low-level operations that can be performed. A series of instructions is encoded as a **sequence of bytes**. A **virtual machine** executes these instructions one at a time, using a **stack for intermediate values.** By combining instructions, complex high-level behavior can be defined.

- **How does it work:**

- **When to Use It:**
  - This is the most complex pattern, and it’s not something to throw into your game lightly. Use it when you have a lot of behavior you need to define and your game’s implementation language isn’t a good fit because:
    - It’s too low-level, making it tedious or error-prone to program in.
    - Iterating on it takes too long due to slow compile times or other tooling issues.
    - It has too much trust. If you want to ensure the behavior being defined can’t break the game, you need to sandbox it from the rest of the codebase.
  - However, that doesn’t come for free. Bytecode is slower than native code, so it isn’t a good fit for performance-critical parts of your engine.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [11. Subclass Sandbox](http://gameprogrammingpatterns.com/subclass-sandbox.html)

- **Intent:** Define behavior in a subclass using a set of operations provided by its base class.

- **Motivation:**

- **The Pattern:** A **base class** defines an abstract **sandbox method** and several **provided operations.** Marking them protected makes it clear that they are for use by derived classes. Each derived **sandboxed subclass** implements the sandbox method using the provided operations.

- **How does it work:**

- **When to Use It:**
  - You have a base class with a number of derived classes.
  - The base class is able to provide all of the operations that a derived class may need to perform.
  - There is behavioral overlap in the subclasses and you want to make it easier to share code between them.
  - You want to minimize coupling between those derived classes and the rest of the program.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

```cpp
class Superpower
{
public:
  virtual ~Superpower() {}

protected:
  virtual void activate() = 0;

  void move(double x, double y, double z)
  {
    // Code here...
  }

  void playSound(SoundId sound, double volume)
  {
    // Code here...
  }

  void spawnParticles(ParticleType type, int count)
  {
    // Code here...
  }

  double getHeroX()
  {
    // Code here...
  }

  double getHeroY()
  {
    // Code here...
  }

  double getHeroZ()
  {
    // Code here...
  }

  // Existing stuff...
};

class SkyLaunch : public Superpower
{
protected:
  virtual void activate()
  {
    if (getHeroZ() == 0)
    {
      // On the ground, so spring into the air.
      playSound(SOUND_SPROING, 1.0f);
      spawnParticles(PARTICLE_DUST, 10);
      move(0, 0, 20);
    }
    else if (getHeroZ() < 10.0f)
    {
      // Near the ground, so do a double jump.
      playSound(SOUND_SWOOP, 1.0f);
      move(0, 0, getHeroZ() + 20);
    }
    else
    {
      // Way up in the air, so do a dive attack.
      playSound(SOUND_DIVE, 0.7f);
      spawnParticles(PARTICLE_SPARKLES, 1);
      move(0, 0, -getHeroZ());
    }
  }
};


```

### [12. Type Object](http://gameprogrammingpatterns.com/type-object.html)

- **Intent:** Allow the flexible creation of new “classes” by creating a single class, each instance of which represents a different type of object.

- **Motivation:**

- **The Pattern:**
  - Define a **type object** class and a **typed object** class. Each type object instance represents a different logical type. Each typed object stores a **reference to the type object that describes its type.**

  - Instance-specific data is stored in the typed object instance, and data or behavior that should be shared across all instances of the same conceptual type is stored in the type object. Objects referencing the same type object will function as if they were the same type. This lets us share data and behavior across a set of similar objects, much like subclassing lets us do, but without having a fixed set of hard-coded subclasses.

- **How does it work:**

- **When to Use It:**
  - You don’t know what types you will need up front. (For example, what if our game needed to support downloading content that contained new breeds of monsters?)
  - You want to be able to modify or add new types without having to recompile or change code.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

## V. Decoupling Patterns

### [13. Component](http://gameprogrammingpatterns.com/component.html)

- **Intent:** Allow a single entity to span multiple domains without coupling the domains to each other.

- **Motivation:**

- **The Pattern:** A **single entity spans multiple domains**. To keep the domains isolated, the code for each is placed in its own **component class**. The entity is reduced to a simple **container of components.**

- **How does it work:**

- **When to Use It:**
  - You have a class that touches multiple domains which you want to keep decoupled from each other.
  - A class is getting massive and hard to work with.
  - You want to be able to define a variety of objects that share different capabilities, but using inheritance doesn’t let you pick the parts you want to reuse precisely enough.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [14. Event Queue](http://gameprogrammingpatterns.com/event-queue.html)

- **Intent:** Decouple when a message or event is sent from when it is processed.

- **Motivation:**

- **The Pattern:** A **queue** stores a series of **notifications or requests** in first-in, first-out order. Sending a notification **enqueues the request and returns**. The request **processor then processes items from the queue** at a later time. Requests can be **handled directly** or **routed to interested parties**. This **decouples the sender from the receiver** both **statically** and **in time.**

- **How does it work:**

- **When to Use It:**
  - If you only want to decouple who receives a message from its sender, patterns like Observer and Command will take care of this with less complexity. You only need a queue when you want to decouple something in time.
  - I think of it in terms of pushing and pulling. You have some code A that wants another chunk B to do some work. The natural way for A to initiate that is by pushing the request to B.
  - Meanwhile, the natural way for B to process that request is by pulling it in at a convenient time in its run cycle. When you have a push model on one end and a pull model on the other, you need a buffer between them. That’s what a queue provides that simpler decoupling patterns don’t.
  - Queues give control to the code that pulls from it — the receiver can delay processing, aggregate requests, or discard them entirely. But queues do this by taking control away from the sender. All the sender can do is throw a request on the queue and hope for the best. This makes queues a poor fit when the sender needs a response.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [15. Service Locator](http://gameprogrammingpatterns.com/service-locator.html)


- **Intent:** Provide a global point of access to a service without coupling users to the concrete class that implements it.

- **Motivation:**

- **The Pattern:** A **service** class defines an abstract interface to a set of operations. A concrete **service provider** implements this interface. A separate **service locator** provides access to the service by finding an appropriate provider while hiding both the provider’s concrete type and the process used to locate it.

- **How does it work:**

- **When to Use It:**

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

## VI. Optimization Patterns

### [16. Data Locality](http://gameprogrammingpatterns.com/data-locality.html)

- **Intent:** Accelerate memory access by arranging data to take advantage of CPU caching.

- **Motivation:**

- **The Pattern:** Modern CPUs have **caches to speed up memory access**. These can access memory **adjacent to recently accessed memory much quicker**. Take advantage of that to improve performance by **increasing data locality** — keeping data in **contiguous memory in the order that you process it.**

- **How does it work:**

- **When to Use It:**
  - With this pattern specifically, you’ll also want to be sure your performance problems are caused by cache misses. If your code is slow for other reasons, this won’t help.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [17. Dirty Flag](http://gameprogrammingpatterns.com/dirty-flag.html)

- **Intent:** Avoid unnecessary work by deferring it until the result is needed.

- **Motivation:**

- **The Pattern:** A set of **primary data** changes over time. A set of **derived data** is determined from this using some **expensive process**. A **“dirty” flag** tracks when the derived data is out of sync with the primary data. It is **set when the primary data changes**. If the flag is set when the derived data is needed, then **it is reprocessed and the flag is cleared**. Otherwise, the previous **cached derived data** is used.

- **How does it work:**

- **When to Use It:**
  - Dirty flags are applied to two kinds of work: calculation and synchronization.
  - The primary data has to change more often than the derived data is used.
  - It should be hard to update incrementally.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [18. Object Pool](http://gameprogrammingpatterns.com/object-pool.html)

- **Intent:** Improve performance and memory use by reusing objects from a fixed pool instead of allocating and freeing them individually.

- **Motivation:**

- **The Pattern:** Define a **pool** class that maintains a collection of **reusable objects**. Each object supports an **“in use” query** to tell if it is currently “alive”. When the pool is initialized, it creates the entire collection of objects up front (usually in a single contiguous allocation) and initializes them all to the “not in use” state.

When you want a new object, ask the pool for one. It finds an available object, initializes it to “in use”, and returns it. When the object is no longer needed, it is set back to the “not in use” state. This way, objects can be freely created and destroyed without needing to allocate memory or other resources.

- **How does it work:**

- **When to Use It:** Use Object Pool when:
  - You need to frequently create and destroy objects.
  - Objects are similar in size.
  - Allocating objects on the heap is slow or could lead to memory fragmentation.
  - Each object encapsulates a resource such as a database or network connection that is expensive to acquire and could be reused.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**

### [19. Spatial Partition](http://gameprogrammingpatterns.com/spatial-partition.html)

- **Intent:** Efficiently locate objects by storing them in a data structure organized by their positions.

- **Motivation:**

- **The Pattern:** For a set of **objects**, each has a **position in space**. Store them in a **spatial data structure** that organizes the objects by their positions. This data structure lets you **efficiently query for objects at or near a location**. When an object’s position changes, **update the spatial data structure** so that it can continue to find the object.

- **How does it work:**

- **When to Use It:**
  - This is a common pattern for storing both live, moving game objects and also the static art and geometry of the game world. Sophisticated games often have multiple spatial partitions for different kinds of content.

  - The basic requirements for this pattern are that you have a set of objects that each have some kind of position and that you are doing enough queries to find objects by location that your performance is suffering.

- **Keep in Mind:**

- **Design Decisions:**

- **Sample Code:**