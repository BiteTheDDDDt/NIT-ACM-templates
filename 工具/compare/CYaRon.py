from cyaron import * # 引入CYaRon的库

_n = ati([0, 10, 1000,10000,100000,100000,100000]) # ati函数将数组中的每一个元素转换为整形，方便您可以使用1E4一类的数来表示数据大小
_m = ati([0,2,5,5,100,10000,1000])

for i in range(1, 7): # 即在[1, 4)范围内循环，也就是从1到3
    print(i);
    test_data = IO(file_prefix="heat", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
    n = _n[i] # 点数
    m = _m[i] # 边数
    test_data.input_writeln(n, m) # 写入到输入文件里，自动以空格分割并换行
    seq = Sequence(lambda i, f: randint(1,1e9),[randint(1,1e9)]) 
    test_data.input_writeln(seq.get(1,n)) # 可以直接传递给IO库，写入14 16 18 20
    tree = Graph.tree(n,0.2,0.4) # 生成一棵n个节点的树，其中40%的节点呈现链状，35%的节点呈现菊花图状，剩余25%的节点随机加入
    test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge)) # 自动写入到输入文件里，默认以一行一组u v w的形式输出
    test_data.output_gen("C:\Progaming\ACM\ExePos\TmpCode0.exe") # 标程编译后的可执行文件，不需要freopen等，CYaRon自动给该程序输入并获得输出作为.out
