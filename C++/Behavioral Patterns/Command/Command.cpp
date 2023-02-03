#include <iostream>
#include <vector>

class Command {
 public:
  virtual void Execute() = 0;
};

class Light {
 public:
  void On() {
    std::cout << "Light is On" << std::endl;
  }
};

class LightOnCommand : public Command {
 public:
  explicit LightOnCommand(Light& light) : light_(light) {}

  void Execute() override {
    light_.On();
  }

 private:
  Light& light_;
};

class RemoteControl {
 public:
  void SetCommand(Command* command) {
    command_ = command;
  }

  void ButtonWasPressed() {
    command_->Execute();
  }

 private:
  Command* command_;
};

int main() {
  Light light;
  LightOnCommand light_on_command(light);

  RemoteControl remote_control;
  remote_control.SetCommand(&light_on_command);
  remote_control.ButtonWasPressed();

  return 0;
}

// This example demonstrates how you can use the Command Pattern to turn on a light by pressing a button on a remote control. The RemoteControl class holds a reference to a Command object and invokes its Execute method when the button is pressed. The LightOnCommand class implements the Command interface and controls the Light object.