#C语言课程设计   
   
##设计   
   
###功能部分   
数据   
1. 参赛俱乐部的维护   
2. 参赛选手的信息维护   
3. 围棋对局的基本信息的维护   

查询   
1. 参赛俱乐部数据查询   
 1. 以俱乐部名称中所包含的字符子串为条件查询参赛俱乐部基本信息   
 2. 列出所有俱乐部基本信息   
2. 参赛棋手的数据查询   
 1. 以棋手姓名为条件查找并显示满足条件的参赛棋手基本信息   
 2. 以所属俱乐部和胜局数为条件查找并显示满足条件的参赛棋手基本信息   
3. 围棋对局基本信息查询   
 1. 以场次和执黑或执白棋手为条件查找并显示满足条件的围棋对局基本信息   
 2. 以参赛棋手胜负情况为条件查找并显示满足条件的所有围棋对局基本信息   
   
数据统计   
1. 分别统计各俱乐部的场分、局分、胜局数、负局数，按场分和局分对统计结果按降序排序(先按场分降序排序，对场分相同的俱乐部再按局分降序排序)，排序后输出每个俱乐部名称、教练、场分、局分、胜局数、负局数。   
2. 分别统计各棋手的参赛局数、胜局数、负局数、胜率(胜局数比参赛局数)，按胜率降序排序后，输出棋手姓名、所属俱乐部、参赛局数、胜局数、负局数、胜率。   
3. 按段位统计参赛棋手中九段、八段至初段(对应段位为：'9'、'8'、...、'1')等各段位棋手的人数，输出统计结果。   
4. 分别统计各俱乐部主将局胜局数、快棋局胜局数、棋手执黑对局数及黑胜局数、棋手执白对局数及白胜局数，输出统计结果。   
5. 有关围甲比赛其他方面的数据统计。   
   
###数据结构   
文件存储   
俱乐部、参赛选手、棋局分三个文件存储   
文件名   
俱乐部`club`   
参赛选手`player`   
棋局`game`   
**数据类型**   
分两种数据类型,引号引起来表示字符串,没有引号表示数字   
**俱乐部**   
第一行表示存储的条数   
后面的每行表示一个俱乐部信息   
"俱乐部名字","教练名字"   
   
**参赛选手**   
第一行表示存储的条数   
后面每行表示一个选手的信息   
"选手姓名","所属俱乐部名字",段位   
   
**棋局比赛**   
第一行表示存储的条数   
后面每行表示一盘棋局的信息   
场次,局别,"执黑棋手","执白棋手",胜负   
   
