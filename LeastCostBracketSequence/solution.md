思路:
首先，使用一个变量记录，遇到左括号时+1，然后当遇到右括号时 -1，
当遇到 ? 时就-1，并且将其变为右括号，然后判断左括号是否不足，当左括号不足时
，将一部分原来 ? 位置的右括号变为左括号，在这个过程中通过维护一个最大根堆(右括号的花费-左括号的花费)
来进行选择，最终判断变量是否==0 和 在此过程中的 组成括号的条件进行判断，并且输出修改后的括号字符串。
