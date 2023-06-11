# DesignPatterns
Design Pattern in multiple programing languages

### Introduction

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

## 1. Mẫu thiết kế khởi tạo

    Factory Method: Tạo các đối tượng không chỉ định lớp chính xác để tạo.
    Abstract Factory: Cho phép tạo các đối tượng không cần chỉ định loại cụ thể của chúng.
    Builder: Sử dụng để tạo các đối tượng phức tạp.
    Prototype: Tạo một đối tượng mới từ một đối tượng hiện có.
    Singleton: Đảm bảo chỉ một thể hiện của một đối tượng được tạo.

## 2. Mẫu thiết kế kiến trúc

    Adapter: Cho phép hai lớp không tương thích hoạt động cùng nhau. Bằng cách bao bọc một giao diện xung quanh một trong các lớp hiện có.
    Bridge: Tách một phần trừu tượng để hai lớp có thể khác nhau một cách độc lập.
    Composite: Đưa một nhóm đối tượng thành một đối tượng duy nhất.
    Facade: Cung cấp một giao diện đơn giản cho một đối tượng cơ bản phức tạp hơn.
    Flyweight: Giảm chi phí của các mô hình đối tượng phức tạp.
    Proxy: Cung cấp giao diện trình giữ chỗ cho đối tượng cơ bản. Để kiểm soát quyền truy cập, giảm chi phí hoặc giảm độ phức tạp.

## 3. Mẫu thiết kế hành vi

    Chain of Responsibility: Ủy quyền các lệnh cho một chuỗi các đối tượng xử lý.
    Command: Tạo các đối tượng đóng gói các hành động và tham số.
    Interpreter: Triển khai một ngôn ngữ chuyên biệt.
    Iterator: Truy cập tuần tự các phần tử của một đối tượng. Nhưng không để lộ phần biểu diễn cơ bản của nó.
    Mediator: Cho phép giao tiếp giữa các lớp khác nhau.
    Memento: Cung cấp khả năng khôi phục một đối tượng về trạng thái trước đó của nó.
    Observer: Là một mẫu xuất bản/ đăng ký. Cho phép một số đối tượng quan sát thấy một sự kiện.
    State: Cho phép một đối tượng thay đổi hành vi của nó khi trạng thái bên trong của nó thay đổi.
    Strategy: Cho phép một trong số các thuật toán được chọn nhanh chóng tại thời điểm thực thi.
    Template Method: Định nghĩa khung của thuật toán là một lớp trừu tượng. Cho phép các lớp con của nó cung cấp hành vi cụ thể.
    Visitor: Tách một thuật toán khỏi một cấu trúc đối tượng. Bằng cách di chuyển hệ thống phân cấp của các phương thức vào một đối tượng.
