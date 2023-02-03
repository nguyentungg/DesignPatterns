// The Chain of Responsibility pattern is a design pattern in which objects can be linked together to form a chain of processing elements, where each element can process a request, or pass it on to the next element in the chain.
#include <iostream>

class Request {
 public:
  Request(int value) : value_(value) {}
  int GetValue() const { return value_; }

 private:
  int value_;
};

class Handler {
 public:
  virtual ~Handler() = default;
  virtual void HandleRequest(const Request &request) = 0;
  virtual void SetSuccessor(Handler *successor) = 0;
};

class ConcreteHandlerA : public Handler {
 public:
  void HandleRequest(const Request &request) override {
    if (request.GetValue() >= 0 && request.GetValue() < 10) {
      std::cout << "ConcreteHandlerA: Handle request " << request.GetValue()
                << std::endl;
    } else {
      if (successor_ != nullptr) {
        successor_->HandleRequest(request);
      }
    }
  }
  void SetSuccessor(Handler *successor) override { successor_ = successor; }

 private:
  Handler *successor_;
};

class ConcreteHandlerB : public Handler {
 public:
  void HandleRequest(const Request &request) override {
    if (request.GetValue() >= 10 && request.GetValue() < 20) {
      std::cout << "ConcreteHandlerB: Handle request " << request.GetValue()
                << std::endl;
    } else {
      if (successor_ != nullptr) {
        successor_->HandleRequest(request);
      }
    }
  }
  void SetSuccessor(Handler *successor) override { successor_ = successor; }

 private:
  Handler *successor_;
};

int main() {
  ConcreteHandlerA handlerA;
  ConcreteHandlerB handlerB;

  handlerA.SetSuccessor(&handlerB);

  for (int i = 0; i < 30; ++i) {
    handlerA.HandleRequest(Request(i));
  }

  return 0;
}
// This code defines the Request and Handler classes, with a concrete implementation of the ConcreteHandlerA and ConcreteHandlerB classes. The ConcreteHandlerA and ConcreteHandlerB classes each process a Request object and, if they can't process it, pass it on to the next Handler in the chain, which is set by the SetSuccessor method. In the main function, the ConcreteHandlerA and ConcreteHandlerB objects are created and linked together to form a chain of responsibility. A series of Request objects is then processed by the first Handler in the chain.