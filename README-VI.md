# DesignPatterns

## Introduction
Đây là repository phục vụ mục đích nghiên cứu và thiết kế hệ thống phần mềm. Nhằm giúp đỡ các kỹ sư có thêm nhiều thông tin để phân tích hiệu quả, lựa chọn các pattern phù hợp, hạn chế sai lầm trong quá trình thiết kế hệ thống.

# I. Creational Patterns (Mẫu tạo đối tượng):

- **Singleton:** Khi chỉ muốn có một đối tượng duy nhất trong toàn bộ ứng dụng. Ví dụ: Một lớp Logger để ghi log trong ứng dụng. Chỉ cần một đối tượng Logger duy nhất để ghi log từ các thành phần khác nhau trong ứng dụng.
- **Factory:** Khi cần tạo đối tượng mà không tiết lộ logic tạo ra đối tượng đó cho client. Ví dụ: Một Factory Pattern để tạo các đối tượng Database Connector cho các loại cơ sở dữ liệu khác nhau, như MySQLConnector, OracleConnector, PostgreSQLConnector.
- **Abstract Factory:** Khi cần tạo đối tượng trong một họ đối tượng có liên quan.

# II. Structural Patterns (Mẫu cấu trúc):

- **Adapter:** Khi cần kết nối giữa hai thành phần không tương thích.
- **Decorator:** Khi muốn mở rộng chức năng của một đối tượng mà không thay đổi cấu trúc ban đầu.
- **Composite:** Khi muốn xử lý một nhóm đối tượng như một đối tượng đơn lẻ.

# III. Sequencing Patterns (Mẫu chuỗi thực hiện):

- **Double Buffer:** Khi cần làm mịn hoạt động bằng cách sử dụng hai bộ nhớ đệm song song.
- **Game Loop:** Khi cần xử lý logic chính của trò chơi vòng lặp liên tục.
- **Update Method:** Khi muốn cho phép các đối tượng tự cập nhật mình trong một hệ thống.

# IV. Behavioral Patterns (Mẫu hành vi):

- **Command:** Khi muốn đóng gói một hành động vào một đối tượng riêng biệt.
- **Observer:** Khi một đối tượng thay đổi, các đối tượng quan sát nó cần được thông báo.
- **Strategy:** Khi cần chọn một trong nhiều thuật toán tương đương dựa trên tình huống.

# V. Decoupling Patterns (Mẫu tách rời):

- **Component:** Khi muốn xây dựng một cấu trúc tách rời, linh hoạt cho các thành phần.
- **Event Queue:** Khi muốn gửi và xử lý các sự kiện trong hệ thống theo trình tự.
- **Service Locator:** Khi muốn tìm kiếm và cung cấp các dịch vụ trong ứng dụng.

# VI. Optimization Patterns (Mẫu tối ưu hóa):

- **Data Locality:** Khi cần tối ưu việc truy cập dữ liệu liên tục trong bộ nhớ.
- **Dirty Flag:** Khi muốn theo dõi sự thay đổi của dữ liệu để tối ưu hoá việc cập nhật.
- **Object Pool:** Khi cần tái sử dụng các đối tượng đã được tạo trước đó để tối ưu việc tạo/phiên bản.
- **Spatial Partition:** Khi cần tổ chức và xử lý dữ liệu không gian hiệu quả.

# VII. Architectural Patterns (Mẫu kiến trúc):

- **MVC (Model-View-Controller):** Khi muốn phân tách logic ứng dụng thành ba phần riêng biệt: Model (dữ liệu), View (giao diện) và Controller (điều khiển).
- **MVP (Model-View-Presenter):** Khi muốn phân tách logic ứng dụng thành ba phần riêng biệt: Model (dữ liệu), View (giao diện) và Presenter (trung gian điều khiển).
- **MVVM (Model-View-ViewModel):** Khi muốn phân tách logic ứng dụng thành ba phần riêng biệt: Model (dữ liệu), View (giao diện) và ViewModel (trung gian điều khiển).

_Lưu ý rằng việc chọn một design pattern phụ thuộc vào nhiều yếu tố như đặc điểm của vấn đề, kiến trúc của hệ thống, yêu cầu cụ thể của dự án và sự hiểu biết của lập trình viên về các mẫu thiết kế. Sử dụng một design pattern phù hợp có thể giúp tăng tính mở rộng, tái sử dụng và dễ bảo trì của mã nguồn._



-------------------------------------
## II. Design Patterns Revisited
Command
Flyweight
Observer
Prototype
Singleton
State
Factory
Abstract Factory
Adapter
Decorator 
Composite
Strategy

## III. Sequencing Patterns

Double Buffer
Game Loop
Update Method

## IV. Behavioral Patterns

Bytecode
Subclass Sandbox
Type Object

## V. Decoupling Patterns

Component
Event Queue
Service Locator

## VI. Optimization Patterns

Data Locality
Dirty Flag
Object Pool
Spatial Partition

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