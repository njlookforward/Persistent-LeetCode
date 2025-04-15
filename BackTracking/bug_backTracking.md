Bug1: 返回值应该是enum signal，不要忘记enum，返回值类型是枚举类型，是不是名称有冲突，需要加上enum进行区分？
Bug2: 忘记写返回值，多次犯这种错误了
key: 对于不变量应该声明为const
Bug3: 没有考虑到digits为空的情况，逻辑有问题
key：对于明确要求k个数字的组合，剪枝操作就是n-(k-path.size())+1;如果还有sum值的话
        && sum + candidates[i] <= target，这样的前提是candidates是有序的