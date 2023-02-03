#include <iostream>
#include <vector>

class Observer {
 public:
  virtual void Update(int value) = 0;
};

class Subject {
 public:
  void Attach(Observer* observer) {
    observers_.push_back(observer);
  }

  void Detach(Observer* observer) {
    for (auto iter = observers_.begin(); iter != observers_.end(); ++iter) {
      if (*iter == observer) {
        observers_.erase(iter);
        break;
      }
    }
  }

  void Notify(int value) {
    for (auto observer : observers_) {
      observer->Update(value);
    }
  }

 private:
  std::vector<Observer*> observers_;
};

class ConcreteObserver : public Observer {
 public:
  explicit ConcreteObserver(Subject* subject) : subject_(subject) {
    subject_->Attach(this);
  }

  void Update(int value) override {
    std::cout << "ConcreteObserver received update: " << value << std::endl;
  }

 private:
  Subject* subject_;
};

int main() {
  Subject subject;
  ConcreteObserver observer1(&subject);
  ConcreteObserver observer2(&subject);

  subject.Notify(1);

  return 0;
}
// This implementation defines the classes Observer, Subject, and ConcreteObserver. The Subject class maintains a list of its observers and notifies them of any changes to its state by calling their Update method. The ConcreteObserver class implements the Observer interface and is notified by the subject when its state changes. The main function demonstrates how to use these classes to implement the observer pattern.