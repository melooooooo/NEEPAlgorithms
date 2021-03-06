/**
* map：翻译为映射，也是常用的STL容器
*      可以将任何基本类型（包括STL容器）映射到任何基本类型（包括STL容器）
**/
#include <cstdio>
#include <map>
using namespace std;


//map的定义
map<typename1, typename2> mp; //键 值
map<string, int> mp; //字符串到整型的映射，必须使用string而不能使用char数组
map<set<int>, string> mp;


//map容器内元素的访问
//(1)通过下标访问
{
    map<char, int> mp;
    mp['c'] = 20;
    mp['c'] = 30; //20被覆盖
    printf("%d\n", mp['c']); // 30
}
//(2)通过迭代器访问
{
    map<char, int> mp;
    mp['m'] = 20;
    mp['r'] = 30;
    mp['a'] = 40;
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
        printf("%c %d\n", it->first, it->second); // a 40  m 20  r 30 (map会以键从小到大的顺序自动排序)
}


//map常用函数实例解析
//find()
{
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    map<char, int>::iterator it = mp.find('b');
    printf("%c %d\n", it->first, it->second); // b 2
}
//erase()
//删除单个元素 法一：mp.erase(it)  O(1)
{
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    map<char, int>::iterator it = mp.find('b');
    mp.erase(it); //删除 b 2
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
        printf("%c %d\n", it->first, it->second); // a 1  c 3
}
//删除单个元素 法二：mp.erase(key)  O(logN)
{
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    map<char, int>::iterator it = mp.find('b');
    mp.erase('b'); //删除键为b的映射，即b 2
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
        printf("%c %d\n", it->first, it->second); // a 1  c 3
}
//删除一个区间内的所有元素
{
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    map<char, int>::iterator it = mp.find('b'); //令it指向键为b的映射
    mp.erase(it, mp.end()); //删除it之后所有的映射，即b 2和c 3
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
        printf("%c %d\n", it->first, it->second); // a 1
}
//size()
{
    map<char, int> mp;
    mp['a'] = 10;
    mp['b'] = 20;
    mp['c'] = 30;
    printf("%d\n", mp.size()); // 3
}
//clear()
{
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp.clear(); //清空map
    printf("%d\n", map.size()); // 0
}


//map的常见用途
// (1) 需要建立字符（或字符串）与整数之间映射的题目，使用map可以减少代码量
// (2) 判断大整数或者其他类型数据是否存在的题目，可以把map当bool数组使用
// (3) 字符串和字符串的映射也有可能会遇到
//延伸：map的键和值是唯一的，如果一个键需要对应多个值，只能用multimap
//      另外C++11标准中还增加了unordered_map，以散列代替map内部的红黑树实现，用来处理只映射而不按key排序的需求，速度比map快得多
