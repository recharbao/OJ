思路:
可以看到温度的数值没任何作用，所需要的仅仅是大于等于0还是小于0，得出判断后，将连续的大于等于0的
和小于0的绑定一块，算出数值，然后排个序，如果冰轮胎可用的天数小于零下的天数，那么返回-1，否则减去小于0的天数，
然后将剩余的冰轮胎跑夏天，能跑到哪里算哪里，需要换轮胎的次数等于，剩下的没跑的天数 * 2，注意处理边界。
