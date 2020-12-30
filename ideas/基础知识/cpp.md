# c/c++基础
## 1 const
### 1.1 作用
1. 修饰变量，说明该变量不可以被改变；  
2. 修饰指针

## 面向对象
### 封装
抽象类，包含成员变量和成员函数，可以设置访问权限public、private、potected  
public：公有成员  
private：私有成员，只能在类的成员函数中访问  
protected：保护成员，可以在派生类中访问（继承过来的，this指针指向的那个成员函数可以访问）

### 继承
基类和派生类
### 多态
静态多态在编译期，动态多态在运行期
1. 重载多态：编译期，（函数重载、运算符重载）
2. 参数多态：编译期，（类模板、函数模板）
3. 子类型多态：运行期，（虚函数）
4. 强制多态：编译期/运行期：（基本类型转换、自定义类型转换）

## 构造函数不能是虚函数
1. 构造函数不能是虚函数，因为虚函数表指针cptr需要调用构造函数完成初始化，而虚函数的调用需要通过虚函数表来查找，而此时vptr还没有初始化。（鸡生蛋问题）
2. 析构函数往往是虚函数（基类），防止内存泄漏。
3. 默认虚构函数不是虚函数，因为有的类没有派生类，虚函数有虚指针续表的额外开销。

## 虚函数、纯虚函数
1. 虚函数是实现的，哪怕是空实现，它能让这个函数在它的子类里面可以被覆盖(override)。
2. 虚函数在子类中可以不重写，但纯虚函数必须在子类中实现才可以实例化子类。
3. 带纯虚函数的类叫抽象类，这种类不能生成对象，而只能被继承，并重写其虚函数后才能使用。
4. 虚继承用于解决多继承条件下的菱形继承问题（浪费存储空间、存在二义性）
5. 模板类中可以使用虚函数
6. 一个类（无论是普通类还是类模板）的成员模板（本事是模板的成员函数）不能是虚函数

## 内存分配和管理
1. malloc：申请置指定字节数的内存。初始值不确定。
2. calloc：为指定长度的对象，分配能容纳指定个数的内存。每一位（bit）都初始化为0
3. realloc：更改以前分配的内存长度。
4. mallco和free：
```cpp
// 判断是否申请成功
char *str = (char*) malloc(100);
assert(str != nullptr);
// 释放内存后指针置空
free(p); 
p = nullptr;
```
5. new和delete
new：先底层调用malloc分配内存，然后调用构造函数（创建对象）  
delete：先调用析构函数（清理资源），然后底层调用free释放对象  
new在申请内存时会自动计算所需字节数，而malloc需要我们自己输入申请内存空间的字节数。
```cpp
int main(){
    T* t = new T();     // 先内存分配 ，再构造函数
    delete t;           // 先析构函数，再内存释放
    return 0;
}
```

## 智能指针
shared_ptr：多个智能指针可以共享同一个对象，对象的最后一个拥有着摧毁对象的责任，并清理该对象相关的所有资源。  
weak_ptr：允许共享对象但不拥有对象，一旦最后一个拥有该对象的智能指针失去所有权，任何weak_ptr都会自动置空。因此，在默认构造函数和拷贝构造函数之外，weak_ptr只提供接受一个shared_ptr的构造函数。  
unique_ptr：是一种在异常时可以帮助避免资源泄漏的智能指针。采用独占式拥有，确保一个对象和其相应的资源同一时间只被一个pointer拥有。一旦拥有着被销毁或者置空，或开始拥有另一个对象，先前拥有的对象会被销毁，其任何相应的资源会被释放。  
1. 默认构造函数，内部指针未指向任务资源，引用计数为0
2. 构造函数，只要指向一个资源，则引用计数+1
3. 析构函数，引用计数-1，当为0时，释放资源
4. 赋值操作，当左值被赋值，表示它不再指向所指资源，引用计数-1，之后指向新的资源，对应这个资源的引用计数+1  
```cpp
template<class T>
class SharedPointer{
public:
    //默认构造函数，内部指针，未指向任何资源，引用计数为0,因为它未与任何资源绑定
    SharedPointer() :m_refCount(nullptr), m_pointer(nullptr) {}
    //构造函数，初始化时，指向一个已经分配好的资源
    SharedPointer(T* adoptTarget) :m_refCount(nullptr), m_pointer(adoptTarget){
        addReference();
    }
    //构造函数，使用其它对象创建新对象
    SharedPointer(const SharedPointer<T>& copy):m_refCount(copy.m_refCount), m_pointer(copy.m_pointer){
        addReference();
    }
    //析构函数，引用计数递减，当为0时，释放资源
    virtual ~SharedPointer(){
        removeReference();
    }
    //赋值操作
    //当左值被赋值时，表明它不再指向所指的资源，故引用计数减一
    //之后，它指向了新的资源，所以对应这个资源的引用计数加一
    SharedPointer<T>& operator=(const SharedPointer<T>& that){
        if (this != &that){
            removeReference();
            this->m_pointer = that.m_pointer;
            this->m_refCount = that.m_refCount;
            addReference();
        }
        return *this;
    }
    //判断是否指向同一个资源
    bool operator==(const SharedPointer<T>& other){
        return m_pointer == other.m_pointer;
    }
    bool operator!=(const SharedPointer<T>& other){
        return !operator==(other);
    }
    //指针解引用
    T& operator*() const{
        return *m_pointer;
    }
    //调用所知对象的公共成员
    T* operator->() const{
        return m_pointer;
    }
    //获取引用计数个数
    int GetReferenceCount() const{
        if (m_refCount){
            return *m_refCount;
        }
        else{
            return -1;
        }
    }
protected:
    //当为nullpter时，创建引用计数资源，并初始化为1
    //否则，引用计数加1。
    void addReference(){
        if (m_refCount){
            (*m_refCount)++;
        }
        else{
            m_refCount = new int(0);
            *m_refCount = 1;
        }
    }
    //引用计数减一，当变为0时，释放所有资源
    void removeReference(){
        if (m_refCount){
            (*m_refCount)--;
            if (*m_refCount == 0){
                delete m_refCount;
                delete m_pointer;
                m_refCount = 0;
                m_pointer = 0;
            }
        }
    }
private:
    int* m_refCount;
    T* m_pointer;
};
```

## 强制类型转换运算符  
static_cast：
- 用于非多态类型转化  
- 不执行运行时类型检查  
- 通常用于转换数值数据类型  
- 可以在整个类层次中移动指针，子类转化为父类是安全的，但是父类转化为子类是不安全的  
dynamic_cast：
- 用于多态类型的转换
- 执行运行时类型检查
- 只是用与指针或引用  
- 对不明确的指针的转化将失败（返回nullptr），但部印发异常  
- 可以在整个类层次中移动指针，子类转化为父类是安全的，但是父类转化为子类是不安全的  
const_cast:
- 用于删除const、volatile和————unaligned特性（如将const int类型转化为int类型）
reinterpret_cast：
- 用于位的简单重新解释
- 允许将任何指针转换为任何其他类型指针
- 也允许将任何整数类型转化为任何指针类型以及反向转换  
- 不能丢掉const、volatile和————unaligned特性  
- 一个实际用途是在哈希函数中。即通过让两个不同的值几乎不以相同的索引结尾的方式将值映射到索引。  
bad_cast：
- 由于将至转换为引用类型失败，会引发bad_cast异常  
```cpp
try {  
    Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);   
}  
catch (bad_cast b) {  
    cout << "Caught: " << b.what();  
} 
```

## 运行时类型信息（RTTI）
dynamic_cast：用于多态类型转换  
typeid：
- 允许在运行时确定对象的类型  
- 返回一个type_info对象的引用  
- 如果想通过基类指针获得派生类的数据类型，基类必须带有虚函数  
- 只能获取对象的实际类型  
type_info:
- 在程序中生成的类型信息。此类的对象可以邮箱存储指向类型的名称和指针，还可以存储判断两个类型是否相对或比较排列顺序的编码值。

## Effective C++
1. 视 C++ 为一个语言联邦（C、Object-Oriented C++、Template C++、STL）
2. 可以编译器替换预处理器（尽量以 const、enum、inline 替换 #define）
3. 尽可能使用 const  
4. 确定对象被使用前已先被初始化（构造时赋值（copy 构造函数）比 default 构造后赋值（copy assignment）效率高）
5. 了解 C++ 默默编写并调用哪些函数（编译器暗自为 class 创建 default 构造函数、copy 构造函数、copy assignment 操作符、析构函数）
6. 为多态基类声明 virtual 析构函数（如果 class 带有任何 virtual 函数，它就应该拥有一个 virtual 析构函数）
7. 以独立语句将 newed 对象存储于（置入）智能指针（如果不这样做，可能会因为编译器优化，导致难以察觉的资源泄漏）
8. 将成员变量声明为 private（为了封装、一致性、对其读写精确控制等）
9. 绝不要以多态（polymorphically）方式处理数组（多态（polymorphism）和指针算术不能混用；数组对象几乎总是会涉及指针的算术运算，所以数组和多态不要混用）

## 哈希函数
构造方法  
- 直接定址法
- 除留余数法
- 数字分析法
- 折叠法
- 平方取中法
处理冲突  
- 链地址法
- 开放定址法
    - 线性探测法
    - 二次探测法
    - 随机探测法

## 递归
### 递归与分治
### 递归与迭代

## 红黑树、B树、B+树的区别
- 红黑树深度比其他两个大
- B+树将数据保存在叶子节点中，同时用链表的方式将他们链接在一起。

## STL
### vector
### stack
1. stack：底层用的deque或list封闭头端开口，不用vector是因为容量大小有限制，扩容耗时
### queue
1. queue
2. deque
3. priority_queque：vector容器+heap处理规则
### set
1. set
2. multiset
3. unordered_set
4. unordered_multiset
### list
- list
- forward_list
### map
1. map
2. multimap
3. unordered_map
4. unordered_multimap：可重复、无序、底层是哈希表
### find
顺序查找
### sort
原地排序

## 排序
1. 冒泡排序
2. 选择排序
3. 插入排序
4. 快速排序
5. 堆排序
6. 归并排序
7. 希尔排序
8. 计数排序
9. 桶排序
10. 基数排序

## 查找
1. 顺序查找
2. 二分查找
3. 插值查找
4. 裴波那契查找
5. 哈希查找
6. 二叉查找树
7. 红黑树

## 分治法
1. 循环赛日程安排
2. 快速排序
3. 归并排序
TODO

## 动态规划
1. 背包问题
2. 斐波那契数列
TODO

## 贪心法
1. 旅行推销员问题（最短路径问题）
2. 最小生成树
3. 哈夫曼编码
TODO

## 其他问题
1. [棋盘覆盖问题](../算法/chessboard.cpp)
2. 背包问题
3. 冯诺依曼邻居问题
4. 循环赛日程安排问题
5. 输油管道问题
TODO

# 操作系统
## 进程和线程

## Linux内核同步方式

## 死锁

## 文件系统

## 主机字节序与网络字节序

## 页面置换算法

# 计算机网络
## OSI七层协议 
1. 物理层
2. 数据链路层
3. 网络层
4. 运输层
5. 会话层
6. 表示层
7. 应用层

## TCP/IP五层协议

## 物理层

## 链路层

## 网络层

## 传输层

## 应用层

# 网络编程

# 数据库
## 基本概念 

## 常用数据模型

## 常用SQL操作

## 关系型数据库

## 数据库完整性

## 关系数据理论

## 数据库恢复

## 并发控制

# 设计模式
## 单例设计模式

## 抽象工厂模式

## 适配器模式

## 桥接模式

## 观察者模式

## 设计模式的六大原则

# 链接装载库
## 内存、栈、堆
## 编译链接
## linux共享库
## Windows应用程序入口函数
## Windows冬天链接库
## 运行库

# 