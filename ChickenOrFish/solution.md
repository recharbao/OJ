思路:

  遇到不确定盘子的情况记录，确定盘子就拿走食物的原则进行。
  当出现第一个“I'm disappointed”时， 表示前面已经出现了空盘的情况，
在此之前要构造出一个空盘，在此之后如果再次出现“I'm disappointed”时，
就不用管他，反正已经构造出一个空盘。
  在出现第一个“I'm disappointed”之前选出所有可以使其变为空盘的盘子，接下来
将食物数量最少的盘子拿空，其余的记录或者直接拿走(按照第一条原则)。
  最后比较盘子剩余数目和所记录的大小关系，进而判断是否为空。
