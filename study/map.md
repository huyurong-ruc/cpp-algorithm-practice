# map<string,int> m{{"a",1}}
map<key,value> m;
O(log(n))，高效


# count
m.count(key)

# find(返回指针/迭代器，count返回有几个)
auto iter = m.find(10)
(*iter).first=key;
(*iter).second=value;
m.end()是m的结尾的指针，找不到时iter=m.end()

cout << m[100] << endl;
找不到m[100]就默认创建了到0的一百，因为m默认的就是0。

m[100]; if(m[100])
也会创建

for (const string &s : strs)
<->for(int i=0;i<strs.length();i++){
    s=strs[i];
}