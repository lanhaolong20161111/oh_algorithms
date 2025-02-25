class MinStack:
    def __init__(self):                             #构造函数
        self.valst=[]                          #val栈 
        self.minst=[]                          #min栈

    def push(self, val: int) -> None:               #进栈val
        self.valst.append(val)
        if len(self.minst)==0 or val<=self.minst[-1]:
            self.minst.append(val)          #将val进minval栈

    def pop(self) -> None:                      #出栈
        e=self.valst[-1]; self.valst.pop()    #出栈元素e
        if e==self.minst[-1]:            #e为当前最小元素
            self.minst.pop()             #将e从min栈出栈

    def top(self) -> int:           #取栈顶元素
        return self.valst[-1]        #返回val栈顶元素

    def getMin(self) -> int:        #取栈中最小元素
        return self.minst[-1]        #返回min栈顶元素 
