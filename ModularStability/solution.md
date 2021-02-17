思路:

array = [a_1, a_2, ... , a_k]

x mod a mod ba mod ca == x mod ba mod ca mod a == ....

假设a_1最小，并且不存在整数m st a_i = m * a_1 (1 < i <= k)

并且取 x = a_i, 则 x % a_i % a_1 % ... % a_k = 0
而 x % a_1 % a_2 % .... % a_k != 0

也就是说必须找到是最小数字的整数倍的k个a_i组成array才能满足要求， 这显然是个组合问题，

通过C(n, k)的方式算出组合数。 
