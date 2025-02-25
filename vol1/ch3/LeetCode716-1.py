class MaxStack:
    def __init__(self):				#构造函数
        self.valst=[]                          #val栈 
        self.maxst=[]                          #max栈

    def push(self, x: int) -> None:		#进栈x
        self.valst.append(x)
        if len(self.maxst)==0:
            self.maxst.append(x)          #将x进maxval栈
        else:
            self.maxst.append(max(x,self.maxst[-1]))

    def pop(self) -> int:					#出栈
        self.maxst.pop()
        e=self.valst[-1]; self.valst.pop()
        return e

    def top(self) -> int:			#取栈顶元素
        return self.valst[-1]        #返回val栈顶元素

    def peekMax(self) -> int: 		#取栈中最大元素
        return self.maxst[-1]        #返回max栈顶元素

    def popMax(self) -> int:		#出栈最大元素
        e=self.maxst[-1]        #e为max栈顶元素
        tmp=[]            #临时栈
        while self.valst[-1]!=e:
            tmp.append(self.valst[-1])
            self.valst.pop()
            self.maxst.pop()
        self.valst.pop()
        self.maxst.pop()
        while len(tmp)>0:
            self.push(tmp[-1])
            tmp.pop()
        return e
