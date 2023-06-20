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

#### **1. Command (Behavioral Patterns)**

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

- **Subclass Sandbox pattern**: 

_Define behavior in a subclass using a set of operations provided by its base class._

Có thể hiểu nôm na nó là việc sử dụng một lớp cơ sở cụ thể (concrete base class) có các phương thức cấp cao (high-level methods) để các lớp dẫn xuất (derived classes) có thể kế thừa và sử dụng để định nghĩa hành vi của chúng. Điều này giúp tạo ra một môi trường an toàn và hỗ trợ cho việc triển khai các lớp con.

```cpp
//Đầu tiên, chúng ta sẽ tạo lớp cơ sở Command có một phương thức cấp cao là execute():
class Command {
public:
    virtual void execute() = 0;
};
//Sau đó, chúng ta sẽ tạo các lớp con kế thừa từ lớp Command và triển khai phương thức execute() cho mỗi lệnh cụ thể:
class MoveCommand : public Command {
public:
    void execute() override {
        // Logic để thực hiện lệnh di chuyển
    }
};

class AttackCommand : public Command {
public:
    void execute() override {
        // Logic để thực hiện lệnh tấn công
    }
};

class UseItemCommand : public Command {
public:
    void execute() override {
        // Logic để thực hiện lệnh sử dụng vật phẩm
    }
};
//Bây giờ, chúng ta tạo một lớp cơ sở CommandHandler có các phương thức cấp cao để xử lý các lệnh:
class CommandHandler {
public:
    void handleCommand(Command* command) {
        // Logic chung để xử lý các lệnh
        command->execute();
    }
};
//Cuối cùng, chúng ta sử dụng mô hình này trong game:
int main() {
    CommandHandler handler;

    // Tạo các lệnh cụ thể
    Command* moveCommand = new MoveCommand();
    Command* attackCommand = new AttackCommand();
    Command* useItemCommand = new UseItemCommand();

    // Xử lý các lệnh
    handler.handleCommand(moveCommand);
    handler.handleCommand(attackCommand);
    handler.handleCommand(useItemCommand);

    // Giải phóng bộ nhớ
    delete moveCommand;
    delete attackCommand;
    delete useItemCommand;

    return 0;
}
//Trong ví dụ này, chúng ta đã tạo một lớp cơ sở CommandHandler có phương thức handleCommand() để xử lý các lệnh. Các lớp lệnh cụ thể (MoveCommand, AttackCommand, UseItemCommand) kế thừa từ lớp Command và triển khai phương thức execute() để thực hiện hành vi riêng của từng lệnh.

//Khi chúng ta gọi phương thức handleCommand() trên một đối tượng CommandHandler, nó sẽ chuyển lệnh cho lớp lệnh tương ứng và thực hiện hành vi của nó.
```

- **Chain of Responsibility pattern (Xử lý lệnh theo chuỗi):** Giả sử bạn đang phát triển một trò chơi máy tính nơi người chơi có thể điều khiển nhân vật chính để thực hiện các hành động như đi, nhảy, tấn công. Tuy nhiên, hành động của người chơi có thể phụ thuộc vào vị trí của nhân vật trong mô hình đối tượng của trò chơi. Thay vì xác định một đối tượng cụ thể để xử lý các hành động, bạn có thể tạo ra một chuỗi các đối tượng xử lý lệnh, như XửlýDiChuyển, XửLýNhay, XửLýTấnCông. Mỗi đối tượng sẽ kiểm tra xem nó có thể xử lý lệnh hay không. Nếu không thể, nó sẽ chuyển lệnh cho đối tượng tiếp theo trong chuỗi cho đến khi lệnh được xử lý hoặc đến đối tượng cuối cùng. Điều này cho phép linh hoạt trong việc xử lý các hành động và giúp tách biệt trách nhiệm xử lý giữa các đối tượng.

```cpp
class Command {
public:
    virtual void execute() = 0;
};

class GameCommand : public Command {
public:
    virtual void execute() = 0;
};

class MoveCommand : public GameCommand {
private:
    int playerID;
    int destinationX;
    int destinationY;

public:
    MoveCommand(int id, int x, int y) : playerID(id), destinationX(x), destinationY(y) {}

    void execute() override {
        std::cout << "Player " << playerID << " is moving to (" << destinationX << ", " << destinationY << ")." << std::endl;
    }
};

class AttackCommand : public GameCommand {
private:
    int playerID;
    int targetID;

public:
    AttackCommand(int id, int target) : playerID(id), targetID(target) {}

    void execute() override {
        std::cout << "Player " << playerID << " is attacking target " << targetID << "." << std::endl;
    }
};

class CommandHandler {
private:
    CommandHandler* nextHandler;
    std::vector<GameCommand*> supportedCommands;

public:
    CommandHandler() : nextHandler(nullptr) {}

    void setNextHandler(CommandHandler* handler) {
        nextHandler = handler;
    }

    void addSupportedCommand(GameCommand* command) {
        supportedCommands.push_back(command);
    }

    void handleCommand(GameCommand* command) {
        bool isSupported = false;

        for (GameCommand* supportedCommand : supportedCommands) {
            if (dynamic_cast<const MoveCommand*>(command) && dynamic_cast<const MoveCommand*>(supportedCommand)) {
                // Nếu là MoveCommand và đối tượng xử lý cũng hỗ trợ MoveCommand
                isSupported = true;
                break;
            } else if (dynamic_cast<const AttackCommand*>(command) && dynamic_cast<const AttackCommand*>(supportedCommand)) {
                // Nếu là AttackCommand và đối tượng xử lý cũng hỗ trợ AttackCommand
                isSupported = true;
                break;
            }
        }

        if (isSupported) {
            command->execute();
        } else if (nextHandler) {
            nextHandler->handleCommand(command);
        } else {
            std::cout << "Unsupported command." << std::endl;
        }
    }
};

int main() {
    // Tạo các đối tượng Command
    GameCommand* moveCommand = new MoveCommand(1, 10, 20);
    GameCommand* attackCommand = new AttackCommand(2, 3);

    // Tạo các đối tượng xử lý yêu cầu
    CommandHandler* moveHandler = new CommandHandler();
    CommandHandler* attackHandler = new CommandHandler();

    // Thiết lập chuỗi Chain of Responsibility
    moveHandler->setNextHandler(attackHandler);

    // Thêm các Command mà xử lý yêu cầu hỗ trợ
    moveHandler->addSupportedCommand(moveCommand);
    attackHandler->addSupportedCommand(attackCommand);

    // Gửi yêu cầu
    moveHandler->handleCommand(moveCommand);
    moveHandler->handleCommand(attackCommand);

    // Giải phóng bộ nhớ
    delete moveCommand;
    delete attackCommand;
    delete moveHandler;
    delete attackHandler;

    return 0;
}

```

#### **2. Flyweigh (Structural Patterns)**

_Forest for the Trees_

**Flyweight** is a structural design pattern that lets you fit more objects into the available amount of RAM by sharing common parts of state between multiple objects instead of keeping all of the data in each object.

Flyweight pattern được sử dụng để giảm bớt việc sử dụng bộ nhớ khi có nhiều đối tượng có phần dữ liệu chung. Thay vì mỗi đối tượng giữ toàn bộ dữ liệu của nó, các dữ liệu chung được chia sẻ giữa các đối tượng thông qua các đối tượng Flyweight. Điều này giúp giảm tải bộ nhớ và tăng hiệu suất của ứng dụng. Mẫu thiết kế này tách dữ liệu thành hai loại: intrinsic state (trạng thái bản chất) và extrinsic state (trạng thái bên ngoài).

**Terrain và World**
- Intrinsic state: Đây là dữ liệu chung cho mỗi loại địa hình, bao gồm các thuộc tính như chi phí di chuyển, tính năng nước, và texture. Các giá trị này không thay đổi từng ô địa hình.
- Extrinsic state: Đây là dữ liệu đặc thù cho từng ô địa hình trong thế giới, ví dụ như vị trí x và y của ô địa hình.

_**Ví dụ:**_

Giả sử bạn đang phát triển một trò chơi video với hàng ngàn đối tượng quân lính. Mỗi quân lính có các thuộc tính như tên, hình ảnh, sức mạnh, tốc độ di chuyển, v.v. Tuy nhiên, rất nhiều quân lính có các thuộc tính giống nhau, chẳng hạn như quân lính cùng loại có cùng hình ảnh và tốc độ di chuyển.

Trong trường hợp này, bạn có thể sử dụng Flyweight pattern. Bạn sẽ tạo ra một lớp Flyweight để đại diện cho các thuộc tính chung (intrinsic state) của quân lính như hình ảnh và tốc độ di chuyển. Mỗi quân lính sẽ giữ một tham chiếu đến Flyweight tương ứng của nó.

```cpp
// Flyweight Interface
class SoldierFlyweight {
public:
    virtual void render(const std::string& name, int x, int y) = 0;
};

// Concrete Flyweight
class Soldier : public SoldierFlyweight {
private:
    std::string image;
    int movementSpeed;

public:
    Soldier(const std::string& image, int movementSpeed) : image(image), movementSpeed(movementSpeed) {}

    void render(const std::string& name, int x, int y) override {
        // Vẽ quân lính tại vị trí (x, y) với tên và hình ảnh từ flyweight
        std::cout << "Rendering soldier: " << name << " at position (" << x << ", " << y << ") with image: " << image << std::endl;
    }
};

// Flyweight Factory
class SoldierFactory {
private:
    std::unordered_map<std::string, SoldierFlyweight*> soldiers;

public:
    SoldierFlyweight* getSoldier(const std::string& key) {
        if (soldiers.find(key) == soldiers.end()) {
            // Tạo một SoldierFlyweight mới nếu chưa tồn tại
            if (key == "infantry") {
                soldiers[key] = new Soldier("infantry_image.png", 5);
            } else if (key == "archer") {
                soldiers[key] = new Soldier("archer_image.png", 7);
            }
            // Thêm các SoldierFlyweight khác vào đây...
        }
        return soldiers[key];
    }
};
int main() {
    SoldierFactory factory;

    // Lấy hoặc tạo các SoldierFlyweight
    SoldierFlyweight* infantry = factory.getSoldier("infantry");
    SoldierFlyweight* archer = factory.getSoldier("archer");

    // Sử dụng các SoldierFlyweight
    infantry->render("John", 10, 20);
    archer->render("Alice", 15, 30);

    return 0;
}
```

Trong ví dụ này, SoldierFlyweight đại diện cho các thuộc tính chung của quân lính như hình ảnh và tốc độ di chuyển. Soldier là một lớp Concrete Flyweight cụ thể thực hiện việc vẽ quân lính dựa trên các thuộc tính flyweight. SoldierFactory đảm bảo rằng chỉ có một SoldierFlyweight duy nhất cho mỗi loại quân lính.

Khi chạy, các quân lính được vẽ với tên, vị trí và hình ảnh từ SoldierFlyweight tương ứng. Nhờ sử dụng Flyweight pattern, chúng ta tiết kiệm được bộ nhớ bằng cách chia sẻ các thuộc tính chung giữa các quân lính có cùng loại.

#### **3. Observer (Behavioral Patterns)**

Model-View-Controller (MVC) là một kiến trúc phần mềm phổ biến được sử dụng rộng rãi trong việc xây dựng ứng dụng. Nó bao gồm ba thành phần chính: Model (Mô hình), View (Giao diện) và Controller (Bộ điều khiển). Kiến trúc MVC được phát minh bởi các nhà phát triển trong cộng đồng Smalltalk vào những năm 1970.

Observer pattern (Mẫu quan sát) là một mẫu thiết kế phần mềm phổ biến, và nó là nền tảng của kiến trúc MVC. Trong Observer pattern, có một đối tượng gọi là Subject (Chủ thể) và một hoặc nhiều đối tượng gọi là Observer (Người quan sát). Subject giữ một danh sách các Observer và thông báo cho chúng khi có sự thay đổi. Java có thư viện java.util.Observer và C# tích hợp Observer trực tiếp vào ngôn ngữ (keyword event).

**What it use for**

- Achievements System
- Mission
- Audio

**How it Works**

- 1. The observer

```cpp
class Observer
{
public:
  virtual ~Observer() {}
  virtual void onNotify(const Entity& entity, Event event) = 0;
};

```

```cpp
class Achievements : public Observer
{
public:
  virtual void onNotify(const Entity& entity, Event event)
  {
    switch (event)
    {
    case EVENT_ENTITY_FELL:
      if (entity.isHero() && heroIsOnBridge_)
      {
        unlock(ACHIEVEMENT_FELL_OFF_BRIDGE);
      }
      break;

      // Handle other events, and update heroIsOnBridge_...
    }
  }

private:
  void unlock(Achievement achievement)
  {
    // Unlock if not already unlocked...
  }

  bool heroIsOnBridge_;
};

```
- 2. The subject

The notification method is invoked by the object being observed. In Gang of Four parlance, that object is called the “subject”. It has two jobs. First, it holds the list of observers that are waiting oh-so-patiently for a missive from it:

```cpp
class Subject
{
private:
  Observer* observers_[MAX_OBSERVERS];
  int numObservers_;
};
```
The subject exposes a public API for modifying that list:
```cpp
class Subject
{
public:
  void addObserver(Observer* observer)
  {
    // Add to array...
  }

  void removeObserver(Observer* observer)
  {
    // Remove from array...
  }

  // Other stuff...
};

```
The other job of the subject is sending notifications:
```cpp
class Subject
{
protected:
void notify(const Entity& entity, Event event)
{
for (int i = 0; i < numObservers_; i++)
{
observers_[i]->onNotify(entity, event);
}
}
// Other stuff...
};
```

```cpp
class Physics : public Subject
{
public:
    void updateEntity(Entity& entity);
};

```

- **Linked observers**

Sử dụng linked list thay vì mảng:

- Lớp Subject sở hữu một danh sách con trỏ tới mỗi Observer đang theo dõi nó. Tuy nhiên, nếu chúng ta sẵn lòng đưa một chút trạng thái vào Observer, chúng ta có thể giải quyết vấn đề cấp phát bằng cách threading danh sách của subject qua các observers chính nó. Thay vì subject sở hữu một bộ sưu tập riêng biệt các con trỏ, các đối tượng observer trở thành các nút trong một danh sách liên kết.


```cpp
class Subject {
public:
    Subject() : head_(NULL) {}
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify(const Entity& entity, Event event);

private:
    Observer* head_;
};

class Observer {
    friend class Subject;
public:
    Observer() : next_(NULL) {}
    void onNotify(const Entity& entity, Event event);

private:
    Observer* next_;
};

void Subject::addObserver(Observer* observer) {
    observer->next_ = head_;
    head_ = observer;
}

void Subject::removeObserver(Observer* observer) {
    if (head_ == observer) {
        head_ = observer->next_;
        observer->next_ = NULL;
        return;
    }
    Observer* current = head_;
    while (current != NULL) {
        if (current->next_ == observer) {
            current->next_ = observer->next_;
            observer->next_ = NULL;
            return;
        }
        current = current->next_;
    }
}

void Subject::notify(const Entity& entity, Event event) {
    Observer* observer = head_;
    while (observer != NULL) {
        observer->onNotify(entity, event);
        observer = observer->next_;
    }
}

```


#### **4. Prototype (Creational Patterns)**

Ý tưởng là thay vì tạo mới các đối tượng từ các lớp cụ thể, chúng ta sẽ tạo ra một bản sao (prototype) của đối tượng ban đầu và sau đó sao chép nó để tạo ra các đối tượng mới.

**Use For:**

- Monster

#### **5. Singleton (Creational Patterns)**

Ensure a class has one instance, and provide a global point of access to it.

#### **6. State (Behavioral  Patterns)**

- Finite State Machines (FSMs)
- Enums and Switches
- A state interface.
- Classes for each state
- Delegate to the state
- Hierarchical State Machines

#### **7. Sequencing  (Sequencing  Patterns)**

Các mẫu thiết kế trong phần này cung cấp các công cụ để xử lý thời gian trong game. Một trong số đó là "Game Loop" (Vòng lặp trò chơi) là trục chính mà đồng hồ của trò chơi quay quanh. Các đối tượng nghe thấy sự tiến triển của thời gian thông qua các "Update Methods" (phương thức cập nhật). "Double Buffering" (đệm kép) giúp che giấu tính tuần tự của máy tính và tạo ra cảm giác rằng thế giới đang cập nhật đồng thời.

**The Patterns:**

- Double Buffer
- Game Loop
- Update Method

#### **8. Bytecode  (Sequencing  Patterns)**