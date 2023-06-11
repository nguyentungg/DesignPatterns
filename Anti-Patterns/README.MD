# Anti-Patterns là gì?

Thuật ngữ "antipatterns" xuất hiện lần đầu tiên trong một cuốn sách mang tên AntiPatterns vào năm 1998.

Nó đề cập đến những giải pháp tái sử dụng mà ban đầu trông có vẻ hữu ích, _nhưng dần sau đó, chúng lại trở nên có hại hơn là lợi._
## Anti-Patterns
### 1. Hard-code, Magic String và Number
- Hard-code tức là… code cứng 1 số giá trị, 1 số logic cần thay đổi vào thẳng trong code (database connection, 1 số config).
- Magic string và magic number tức là code cứng 1 con số, 1 string ảo diệu nào đó, mà không ghi rõ số/string đó từ đâu ra, nó là gì

**- Context:** 
```js
// Hard code DB Connection
const DB_CONNECTION = 'localhost://4090;username=admin;password=test'
// Magic number: 4 là gì, tại sao dùng 4 mà không phải số khác?
DB.connect(DB_CONNECTION, 'db_test_blog', 4) 
```
**- Fix:**
> Anti Pattern này rất dễ xử lý. Chỉ cần không hardcode những giá trị config (mà đọc từ file config hoặc biết môi trường), tách các magic number ra thành biến riêng hoặc viết thêm comment là được.

### 2. God Class (The Blob) – Class siêu to không lồ
Gob Class tức là Class siêu to khổng lồ Thần Thánh, làm gì cũng được nên gọi là God. Tình trạng này xảy ra khi mấy ông dev gom quá nhiều tính năng vào 1 class.

**- Context:** 

> Class này có những cái tên như Helper, Utils, Controller, Main… và rất bự (có khi tới 3-5000 dòng code). Mỗi lần chỉnh sửa, thêm bớt tính năng là 1 cực hình.

**- Fix:**
> - Tuân thủ nguyên tắc Single Responsibility trong SOLID, mỗi class chỉ nên giữ 1 trách nhiệm
> - Refactor dần lại code, tách class thành các class nhỏ hơn, gom nhóm các function/data hay dùng chung thành 1 class riêng

### 3. Copy and Paste Programming

Đây là pattern theo kiểu viết code 1 lần, những lần sau cần dùng thì copy nguyên đoạn code cũ qua, sửa sửa lại 1 chút cho chạy được.

Về lâu dài, điều này sẽ làm số lượng code của dự án bị phình lên. Code lặp lại nhiều, những khi cần chỉnh sửa hoặc fix bug sẽ phải fix ở rất nhiều chỗ. Nếu quên hoặc sót sẽ để bị sót bug.

**- Context:** 
```js 
// Code bỏ kí tự đặc biệt và viết hoa
let input = 'abd4%$#@#';
input = input.trim().replace(/[^a-zA-Z ]/g, "").toUpperCase()

// Đoạn code khác …
// Copy lần 1
const username = 'ahihi-de-em-di'
const trimmedUsername = username.trim().replace(/[^a-zA-Z ]/g, "").toUpperCase()

// …Copy tiếp logic qua đoạn khác
const id = 'jro@091ksa'
return id.trim().replace(/[^a-zA-Z ]/g, "").toUpperCase()
```
**- Fix:**
- Cách đơn giản nhất vẫn là tách đoạn code cần sử dụng thành hàm riêng, library riêng để dùng
- Lưu ý: Có nhiều khi 3,4 hàm khác nhau quá thì đừng nên ráng viết thành 1 hàm rồi tái sử dụng, code sẽ còn… rối hơn tách riêng ra.

```js
// Tách thành function riêng
// Trim and upper case
function chimUp(input) {
  // Có bug chỉ cần sửa 1 chỗ
  return input.trim().replace(/[^a-zA-Z ]/g, "").toUpperCase()
}

// Có thể dễ dàng dùng mà không cần copy paste
let input = chimUp('abd4%$#@#')

const username = 'ahihi-de-em-di'
const trimmedUsername = chimUp(username)

// …Copy tiếp logic qua đoạn khác
const id = 'jro@091ksa'
return chimUp(id)
```
### 4. Premature Optimization (Tối ưu sớm)
![Image Description](https://toidicodedao.files.wordpress.com/2020/12/slide_3-e1607677399462.jpg?w=365&h=228)

**- Context:** 

Đôi khi, việc optimize code quá sớm (chưa biết chạy chậm chỗ nào, otpimize đoạn nào) là hoàn toàn không cần thiết, nó còn làm code phức tạp hơn, khó đọc, khó debug hơn.

**- Fix:**

- Không optimize vội hay optimize quá sớm. Hãy hỏi xem code đó có cần, có đáng để optimize hay không
- Khi code chạy chậm, hãy dùng profiler để xác định đoạn code gây chậm, sau khi optimize thì dùng profiler để đo lại trước

### 5. Spaghetti Code
Spaghetti Code để chỉ code rối như rối như mấy cọng mì spaghetti. Đây là những dòng code móc nối nhiều module/class với nhau, flow đi vòng vèo, cực kì khó đọc và khó sửa.

**- Context:** 

Nguyên nhân là do team code mà không có design cụ thể, do developer lười nên code đại. Hoặc do requirement đổi liên tục, chồng chéo nhau, nhưng các module và design không được update, nên cũng gọi nhau chồng chéo luôn!

**- Fix:**
- Đây là Anti Pattern khó giải quyết triệt để nhất! Vì nó không chỉ liên quan tới code, mà còn liên quan tới thiết kế của các module trong hệ thống
- Cách dễ nhất là đập bỏ và viết lại khi đã hiểu rõ logic ban đầu, nhưng sẽ tốn nhiều thời gian, có thể thiếu requirement
- Nên refactor code dần dần, tách thành từng phần nhỏ. Có thể design lại các module nếu cần

### 6. Reinventing the Wheel (Tái phát minh bánh xe)
**- Context:** 

Reinventing the wheel Có thể hiểu nôm na là cái bánh xe nó đã được phát minh từ rất lâu rồi, và nó cũng rất tốt rồi, đừng có mất thời gian đi phát minh lại nó nữa.

**- Fix:**

Reinventing the wheel không chỉ gây ra lãng phí thời gian, mà còn những giải pháp tùy chọn, đặc biệt là những chức năng cơ bản hiếm khi tốt hơn những chuẩn mà nhiều nhà phát triển hay người dùng đã thử nghiệm rất kĩ rồi.

### 7. Dependency Hell
**- Context:** 

Nếu, thay vì cặm cụi viết mọi thứ từ đầu, chúng ta lại quá lạm dụng việc sử dụng thư viện bên thứ ba dựa trên những phiên bản cụ thể của những thư viện khác. Điều này sẽ khiến bạn dễ dàng phải đối mặt với những tình huống khó quản lý mỗi khi muốn cập nhật thư viện, vì đôi khi những dependencies này sau khi cập nhật lại không tương thích với những cái khác.

**- Fix:**

Dependency hell có thể được giải quyết bằng cách sử dụng các package managers có khả năng cập nhật thông minh các dependencies để chúng vẫn có thể tương thích được với nhau. Nếu chúng ta vấp phải quá nhiều vấn đề, việc refactoring cũng có thể là một ý tưởng hay.

### 8. Programming by Permutation
**- Context:** 

"Programming by Permutation" hay "programming by accident" xảy ra khi bạn cố gắng tìm giải pháp cho một vấn đề bằng cách thử nghiệm liên tục những thay đổi nhỏ (giống như kiểu hoán vị vậy), test và đánh giá từng sự thay đổi nhỏ và cuối cùng lựa chọn cách đầu tiên làm cho codes của bạn hoạt động đúng. Cách tiếp cận này đôi khi có vẻ hấp dẫn khi mà lập trình viên không hoàn toàn hiểu rõ về đoạn codes đó và họ tin rằng một hoặc nhiều sửa đổi nhỏ sẽ có thể làm cho codes của họ hoạt động đúng.

**- Fix:**

Programming by Permutation có thể dễ dàng gây phát sinh ra nhiều lỗi mới, tệ hơn nữa, những lỗi đó chúng ta khó có thể nhận ra ngay được. Trong nhiều trường hợp, tìm được giải pháp hiệu quả cho tất cả các tình huống có thể xảy ra là một nhiệm vụ bất khả thi.

### 9. Cargo-Cult Programming

**- Context:** 

- Antipattern này cũng có những biểu hiện tương tự như vậy. Ta sử dụng những frameworks, thư viện, giải pháp, hay các design patterns,...có lợi cho chúng ta, mà không thực sự hiểu tại sao chúng ta cần phải dùng đến chúng hay những công nghệ đó hoạt động ra sao.

- Sao chép những mã nguồn từ nơi này đến nơi khác trong ứng dụng mà hầu như ít hoặc không hiểu biết về ý nghĩa thật sự của chúng. Antipattern này không chỉ tệ vì làm cho ứng dụng của chúng ta bị "bơm căng phồng", mà còn có thể dễ dàng đưa những lỗi mới vào mã nguồn của chúng ta.

**- Fix:**

- Cách giải quyết thì ko có cách nào khác hơn là việc hiểu các pattern hoặc code bạn đang sử dụng trước khi đặt nó vào dự án.

### 10. Lava Flow
Cái tên của antipattern này thể hiện sự tương đồng với dung nham núi lửa, ban đầu thì di chuyển nhanh, trôi chảy khó phòng ngừa, nhưng sau đó thì cứng lại và khó loại bỏ.

**- Context:** 

- Mỗi khi cần phải xử lý những đoạn mã codes thừa hoặc có chất lượng thấp mà dường như không thể tách rời với ứng dụng, nhưng chúng ta không hoàn toàn hiểu được chúng có tác dụng gì hoặc ảnh hưởng của chúng đến toàn bộ ứng dụng như thế nào. Vì vậy, việc loại bỏ chúng là một việc rất rủi ro.
- Điều này thường xuyên xảy ra với những legacy codes, hoặc là khi đoạn codes này được viết bởi những người khác (thường thiếu tài liệu chính xác), hoặc là khi dự án được chuyển từ giai đoạn development sang production quá nhanh.

**- Fix:**

Trên lý thuyết, ta có thể loại bỏ lava flows sau khi đã kiểm tra và refactoring kĩ lưỡng, nhưng trong thực tế, việc thực hiện nó dường như rất khó khăn hoặc thậm chí là không thể. Do lava flows thường có chi phí thực hiện cao, nên tốt hơn hết để ngăn chặn chúng là ta thiết lập được kiến trúc thiết kế tốt và một workflow làm việc hiệu quả ngay từ ban đầu.

### 11. Soft Coding

Trong soft coding, chúng ta đưa những thứ mà đáng ra nó nên được để ở trong mã nguồn ứng dụng ra những tài nguyên bên ngoài.

**- Context:** 

- Ví dụ chúng ta lưu trữ business logic trong database. 

- Lý do phổ biến nhất mà chúng ta thường làm thế, là do lo lắng những business rules sẽ thay đổi trong tương lai, và lúc đó sẽ phải viết lại codes.

- Trong những trường hợp cực đoan, một ứng dụng với những soft coded có thể trở nên quá trừu tượng và phức tạp đến mức gần như không thể hiểu được nó (đặc biệt là đối với những thành viên mới vào team), và cực kỳ khó để debug và bảo trì.

**- Fix:**

Cách fix thì không có cách nào khác ngoài việc hiểu rõ và plaining kỹ architecture và business logic ở giai đoạn đầu của dự án.

_Nguồn: Toidicodedao, Viblo,..._