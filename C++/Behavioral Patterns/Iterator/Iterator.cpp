// The Iterator pattern is a design pattern that provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
#include <iostream>
#include <vector>

class Iterator {
 public:
  virtual ~Iterator() = default;
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() const = 0;
  virtual int CurrentItem() const = 0;
};

class ConcreteIterator : public Iterator {
 public:
  ConcreteIterator(const std::vector<int> &data) : data_(data), index_(0) {}
  void First() override { index_ = 0; }
  void Next() override { ++index_; }
  bool IsDone() const override { return index_ >= data_.size(); }
  int CurrentItem() const override { return data_[index_]; }

 private:
  std::vector<int> data_;
  std::size_t index_;
};

class Aggregate {
 public:
  virtual ~Aggregate() = default;
  virtual Iterator *CreateIterator() = 0;
};

class ConcreteAggregate : public Aggregate {
 public:
  Iterator *CreateIterator() override {
    return new ConcreteIterator(data_);
  }
  void Add(int item) { data_.push_back(item); }

 private:
  std::vector<int> data_;
};

int main() {
  ConcreteAggregate aggregate;
  aggregate.Add(1);
  aggregate.Add(2);
  aggregate.Add(3);

  auto *iterator = aggregate.CreateIterator();
  for (iterator->First(); !iterator->IsDone(); iterator->Next()) {
    std::cout << iterator->CurrentItem() << std::endl;
  }

  delete iterator;

  return 0;
}

// This code defines an Iterator interface with First, Next, IsDone, and CurrentItem methods, and a ConcreteIterator class that implements the Iterator interface. The Aggregate interface defines the CreateIterator method, and the ConcreteAggregate class implements the Aggregate interface and creates an instance of the ConcreteIterator. In the main function, the ConcreteAggregate instance is used to demonstrate the usage of the Iterator.