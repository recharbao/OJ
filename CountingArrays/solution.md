思路:
将所给的x进行质因数分解，然后算出每种质因数的个数，然后将每种质因数模拟放球(箱子不同允许空箱的情况，采用隔板法计算组合数)，
每种球放法之间相乘，最后加上负号:只能加入 0， 2， 4偶数个负号，算出组合数为2^(n - 1),最后将它们相乘。

