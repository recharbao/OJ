思路:非常好的一个题目，只想出了k == 0 和 k >= 2的情况， k == 1的情况比较tricky, 参考了一下解答。
k == 0, 非常简单，遍历整个链， 寻找最优解；
k == 2, 我们可以将E{n - 1}  = 1， 并且在 j 处断开， 令 E{j - 1} = n, 1 <= j < n 这样会发现可以通过一次激活([1, n - 1]中的元素)，便可以获得全部的能量， 注意与最后的原子n比较；
k > 2， 其实是与 k == 2 的情况是一样的， 我们可以假设前 k - 2 次的 change 都是对 E{n - 1} 的乱排， 只有最后两次是按 k == 2 时的做法， 这样就是 k == 2 的情况了；

k == 1, 这种情况不太好想，答案细分好几种情况， 不过这些情况我发现可以 absorbed 归结为一下两种情况:

1、 改变E{j} to 1, (1 <= j < n, 虽然题目说不可以连接自己，但是我们可以将E{1} to n, 这样等价于 E{1} to 1) 然后贪心选择最优激活。
2、 改变E{j - 1} to j + 1, (2 <= j <= n - 1) , 然后贪心选择最优解， 注意: 最后要看一下是否可以激活 j。

最后， 该问题在编程的时候注意选择恰当的数据结构， 采用 后缀和 记忆后缀能量和 以及 记忆位于各个原子前面的 激活所需最小能量的原子。