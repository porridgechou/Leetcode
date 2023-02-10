C/C++刷题注意指南

```c++
#include<iostream>
using namespace std;
```

# 字符串

关于字符串导入<string>库

## 字符串长度

```c++
int len = s.size();
int len = s.length();
```

## 查找字符串t是否是s的子串

如果t是s的子串则返回首次匹配的位置，否则返回 string::npos 或 -1

```c++
s.find(t);
```

`begin` 和 `end` 方法

begin()函数返回一个迭代器,指向字符串的第一个元素.返回值是字符串的首地址，取值为*

end()函数返回一个迭代器,指向字符串的最后一个元素.返回值是字符串的首地址，取值为*

```c++
string s1 = "hello";
string s2 = " world";
s1.append(s2);
cout<<*s1.begin()<<endl;
cout<<*s1.end()<<endl;
```

## 反转字符串

reverse函数需要引入\#include <algorithm>头文件。

```c++
string s = "hello world";
reverse(s.begin(), s.end());
cout<<s<<endl;
//结果
dlrow olleh
```

## 截取某个字符串中的子串

substr 这个函数在处理字符串的题目很常用，当然，用这个方法很多时候会 TLE

```c++
string s = "hello world";
string s1 = s.substr(6);//下标6开始到结束
string s2 = s.substr(0, 11);//下标0开始，截取11个字符
cout<<s1<<endl;
cout<<s2<<endl;
//结果
world
hello world
```

# 栈

使用标准库的栈和队列时，先包含相关的头文件

```c++
stack<int> s;
s.empty()               如果栈为空返回true，否则返回false
s.size()                返回栈中元素的个数
s.pop()                 删除栈顶元素但不返回其值
s.top()                 返回栈顶的元素，但不删除该元素
s.push()                在栈顶压入新元素
```

```c++
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> s; // 定义⼀个空栈s
    for (int i = 0; i < 6; i++) {
        s.push(i); // 将元素i压⼊栈s中
    }
    cout << s.top() << endl; // 访问s的栈顶元素
    cout << s.size() << endl; // 输出s的元素个数
    s.pop(); // 移除栈顶元素
    return 0;
}
```

# 队列

```c++
q.push(x):将x元素接到队列的末端；
q.pop() 弹出队列的第一个元素，并不会返回元素的值；
q.front()访问队首元
q.back()访问队尾元素
q.size()访问队中的元素个数
```

## 优先队列

默认情况创建大堆



优先队列至少需要支持下述操作：

插入带优先级的元素（insert_with_priority）
取出具有最高优先级的元素（pull_highest_priority_element）
查看最高优先级的元素（peek）：O(1) 时间复杂度
其它可选的操作：

检查优先级高的一批元素
清空优先队列
批插入一批元素
合并多个优先队列
调整一个元素的优先级

```c++
priority_queue<node> q;

q.empty()          如果队列为空，则返回true，否则返回false
 
q.size()           返回队列中元素的个数
 
q.pop()            删除队首元素，但不返回其值
 
q.top()            返回具有最高优先级的元素值，但不删除该元素
 
q.push()       在基于优先级的适当位置插入新元素
```

# 集合

`set`是集合，⼀个`set`⾥⾯的各元素是各不相同的，⽽且`set`会按照元素进⾏从⼩到⼤排序以下是`set`的常⽤⽤法：

```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    s.insert(2);//向集合添加元素
    s.insert(3);//向集合添加元素
    cout << *(s.begin()) << endl; //输出第一个元素
    for (int i = 0; i < 10; i++) {//插入0 - 9
        s.insert(i);
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";//集合的遍历，it是一个迭代的指针
    }
    cout << endl << (s.find(2) != s.end()) << endl;//查找，元素
    s.erase(3);//删除元素
    cout << (s.find(3) != s.end()) << endl;
    return 0;
}
```

# map/字典/映射

```c++
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    map<string, string> m;
    m["hello"] = "world"; // 存储键为 "hello" 值为 "world"的键值对
    cout << m["hello"] << endl; // 访问map中key为"hello"的value,
    cout << m["world"] << endl;// 如果key不存在，则返回0或空
    m["world"] = "test"; // 将"world"键对应的值修改为3
    m["key"] = "value"; // 设置键为 "key" 值为"value" 的键值对
    //迭代器遍历，输出map中所有的元素，键it->first获取，值it->second获取
    for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << m.begin()->first << " " << m.begin()->second << endl;
    // 访问map的第一个元素，输出它的键和值

    cout << m.rbegin()->first << " " << m.rbegin()->second << endl;
    // 访问map的最后一个元素，输出它的键和值

    cout << m.size() << endl;
    // 输出map的元素个数
    return 0;
}
```

# 向量

**在c++中，vector是一个十分有用的容器。**

作用：它能够像容器一样存放各种类型的对象，简单地说，vector是一个能够**存放任意类型的动态数组**，能够**增加和压缩数据。**

新建一个向量存储`int`类型

```c++
vector<int>test; // 定义的时候不指定vector的⼤⼩
vector<int>test2(6); // 定义的时候指定vector的⼤⼩，默认test2⾥⾯元素都是0
vector<int>test3(6, 3); // 定义的时候指定vector的⼤⼩，默认test3⾥⾯元素都是3
```

尾部添加两个元素，0的位置存储5， 1 的位置存储8

```c++
test.push_back(5);
test.push_back(8);
```

插入元素 `insert`

```c++
test.insert(test.begin()+i,value);//在第i+1个元素前面插入value;
```

删除元素

```c++
test.erase(test.begin() + 5);//删除第6个元素
```

清空向量

```c++
test.clear();//clear
```

获取向量的大小

```c++
test.size();
```

获取起始地址或结束地址

```c++
test.begin();//起始地址
test.end();//结束地址
```

遍历向量

```c++
for (vector<int>test::iterator it = m.begin(); it != m.end(); it++) {
        cout << *it << endl;
    }
```

反转元素，逆序

```c++
reverse(test.begin(),test.end());//反转
```

使用`sort`排序，可以自定义排序规则

```c++
sort(test.begin(),test.end());
```



```c++
1、选择C++刷算法的理由
1.C++速度快（C不是更快么，java太慢了）
2.C++有STL（什么是STL）——使用很方便的类库
3.如何使用STL进行高效刷算法
4.好处：刷算法，学习成本极低
5.如何从C到C++（仅基础语法到刷算法程度）
俗话说：磨刀不误砍柴工
不会c++仍然可以做，但是效率低

2、输入输出
C++保留了C的scanf和printf，增加了额外的cin与cout

例子

2.1.C程序中输入输出
int a;
scanf("%d",&a);
printf("%d",a);

2.2.C++输入输出
int a;
cin>>a;
cout<<a;

2.3.连续输入输出变量
int a,b,c;
cin>>a>>b>>c;
cout<<a<<b<<c;

2.4.优雅地换行
cout<<1;
cout<<endl;
cout<<2;
cout<<3<<endl<<endl;

好处：

1.少写了很多东西

2.连续输入输出变量

3.换行优雅

注意：cin、cout比scanf、printf慢，有时候刷算法超时，可能因为使用了cin、cout

输入输出的数量(>1000)特别多，刷算法用cin，cout容易超时

3、STL(Standard Template Library)与algorithm头文件
STL是一些“容器”的集合，这些“容器”有list,vector,set,map等，STL也是算法和其他一些组件的集合。

algorithm是对容器继承的一些算法函数，辅助刷算法题

sort函数

概念：迭代器——理解为指针

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[]={2,1,5,0,-1,5,9};
    sort(a,a+7);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}

4、STL——string(*)
概念：相当于char*的封装，理解为字符串

4.1.简单使用
/**C中定义字符串以及打印*/
char *ch="asdkajbf";
for(int i=0;ch[i]!='\0';i++) cout<<*(ch+i);
/**C++中*/
string s="ssadaffw";
cout<<s<<endl;

4.2.获取一行字符串
我想获取一行字符串

hello world

C中：

scanf("%s",ch);//1.仅获取一个单词，空格结束 2.ch[100]得设置初始大小

C++中：

string s;
getline(cin,s);//获取一行数据
cout<<s;

4.3.+=运算符
+=对于字符串，字符有效，数字会转为asc码

string s;
s+="hello";
s+=" world";
s+='5';
s+=10;//10对应的asc码是换行
int a=5;//想把a加入字符串
s+=(a+'0');
cout<<s;

4.4.排序（使用algorithm）
string s="5418340";
sort(s.begin(),s.end());
cout<<s;

4.5.erase函数
/**begin是头迭代器，end是尾迭代器*/
string s="5418340";
s.erase(s.begin());//删除第一个
s.erase(--s.end());//删除最后一个
cout<<s;

4.6.substr函数
/**begin是头迭代器，end是尾迭代器*/
string s="5418340";
s=s.substr(1,3);//取418,取索引为1，往后截断3个
s=s.substr(1,-1);//索引为1，截断到最后
cout<<s;

4.7.循环(3种)
1.for循环

string s="5418340";
for(int i=0;i<s.length();i++) cout<<s[i];

2.迭代器

for(string::iterator it=s.begin();it!=s.end();it++) cout<<*it;

3.迭代器化简

for(auto it=s.begin();it!=s.end();it++) cout<<*it;

4.利用C++ 11新特性for循环

for(auto x:s) cout<<x;

5、STL——vector(*)
概念：vector相当于数组，模板类型相当于存放的内容

1.vector构造

vector<int> v;//定义一个空vector
vector<int> v2(4);//定义一个4个大小的vector，初始为0
vector<int> v3(4,6);//定义一个4个大小的vector，初始为6
vector<int> v{1,2,3,4,5};//定义一个vector，数字为1,2，3,4,5
for(auto x:v3) cout<<x;

2.用at或者[]获取元素

vector<int> v{1,2,3,4,5};
cout<<v[1];//取索引为1的
cout<<v.at(2);//取索引为2的

3.方法

push_back追加内容
vector<int> v;
v.push_back(5);
v.push_back(5);
v.push_back(5);
v.push_back(5);
v.push_back(6);
for(auto x:v) cout<<x;

resize进行重置大小
v.resize(10);//不赋值默认为0

erase删除元素，复杂度为O(n)
v.erase(v.begin());//删除第一个元素
v.erase(--v.end());//删除最后一个元素

获取第一个元素，获取最后一个元素
/**获取第一个元素*/
cout<<v.front();
cout<<v[0];
cout<<*v.begin();
/**获取最后一个元素*/
cout<<v.back();
cout<<v[v.size()-1];//size是获取大小
cout<<*--v.end();

4.排序

第三个参数为比较器，不写默认为less<int>()

vector<int> v{5,1,2,5,4,0,-1};
sort(v.begin(),v.end(),less<int>());//从小到大
sort(v.begin(),v.end(),greater<int>());//从大到小排序
for(auto x:v) cout<<x;

5.循环

vector<int> v{5,1,2,5,4,0,-1};
for(int i=0;i<v.size();i++) cout<<v[i];//for循环
cout<<endl;
for(vector<int>::iterator it=v.begin();it!=v.end();it++) cout<<*it;//迭代器循环
cout<<endl;
for(auto it=v.begin();it!=v.end();it++) cout<<*it;//迭代器简化循环
cout<<endl;
for(auto x:v) cout<<x;//c++11新特性

6、STL——stack(*)
概念：栈

构造
stack<int> s;

push、pop、size、empty
push 入栈一个元素
pop 出栈一个元素，pop无返回值
top 取栈顶元素
size 查看元素个数
s.push(2);
s.push(3);
cout<<s.top()<<endl;
s.pop();
cout<<s.top()<<endl;
cout<<s.size()<<endl;

进制转换(十进制转二进制)
int itob(int decimal){
    stack<int> s;int res=0;
    while(decimal!=0){
        s.push(decimal%2);
        decimal/=2;
    }
    while(!s.empty()){
        res=res*10+s.top();
        s.pop();
    }
    return res;
}

逆序单词（拓展sstream，stoi，itoa）
输入一行字符串，将字符串逆序打印

输入：hello world my name is steve yu

输出：yu steve is name my world hello

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main(){
    string str;
    stack<string> s;
    getline(cin,str);
    stringstream ss;
    ss<<str;
    while(ss>>str)
        s.push(str);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
        if(s.size()!=0) cout<<" ";
    }
    return 0;
}

字符串转数字
方法1:

 string s="1234";
 int i;
 stringstream ss;
 ss<<s;
 ss>>i;
 cout<<i;

方法2:

string s="1234";
int i=stoi(s);
cout<<i;

数字转字符串
方法1:

int a=1234;
string out;
stringstream ss;
ss<<a;
ss>>out;
cout<<out<<endl;

方法2:(c++ 11)

int a=1234;
cout<<to_string(a)<<endl;

7、STL——queue
概念：队列

构造
queue<int> q;

push、back
q.push(5);
q.push(6);
cout<<q.front()<<endl;
q.pop();
cout<<q.front()<<endl;
cout<<q.size()<<endl;

8、STL——map(unordered_map pair)
概念：映射（map为树状表，unorderedmap为哈希表）

map
map<int,int> m;//有序的，树状结构（底层）
m[6]=3;
m[5]=8;
m[4]=9;
for(auto it=m.begin();it!=m.end();it++)
	cout<<it->first<<" "<<it->second<<endl;
for(auto tmp:m){
	cout<<tmp.first<<" "<<tmp.second<<endl;
}

unordered_map
unordered_map<int,int> m;//无序的，哈希结构（底层）
m[6]=3;
m[5]=8;
m[4]=9;
for(auto it=m.begin();it!=m.end();it++)
	cout<<it->first<<" "<<it->second<<endl;
for(auto tmp:m){
	cout<<tmp.first<<" "<<tmp.second<<endl;
}

pair的用法(map转成vector进行排序)
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
int main(){
    unordered_map<int,int> m;//无序的，哈希结构（底层）
    m[6]=3;
    m[5]=8;
    m[4]=9;
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(auto tmp:v){
        cout<<tmp.first<<tmp.second<<endl;
    }
    return 0;
}

9、set(unordered_set)
概念：集合

应用计数、去重
set<int> s;//树状结构，有序
unordered_set<int> s2;//哈希结构，无序，快
s.insert(3);
s.insert(4);
s.insert(4);
s.insert(4);
cout<<s.size()<<endl;
for(auto tmp:s)
	cout<<tmp<<" ";
cout<<endl;
for(auto it=s.begin();it!=s.end();it++)
	cout<<*it<<" ";
cout<<endl;

10、STL——deque
概念：双端队列

deque<int> d;
// 4 9 1 2
d.push_back(1);
d.push_back(2);
d.push_front(9);
d.push_front(4);
d.pop_back();
d.pop_front();
for(auto tmp:d) cout<<tmp<<endl;
for(auto it=d.begin();it!=d.end();it++) cout<<*it<<endl;

排序
sort(d.begin(),d.end(),greater<int>());

11、STL——list
概念：双向链表

list<int> li;
li.push_back(6);
li.push_front(5);
li.emplace_front(9);
li.emplace_back(10);
li.insert(++li.begin(),2);
for(auto tmp:li) cout<<tmp<<endl;
for(auto it=li.begin();it!=li.end();it++) cout<<*it<<endl;
```

