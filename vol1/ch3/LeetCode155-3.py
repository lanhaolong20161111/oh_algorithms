class MinStack:
    def __init__(self):
        self.st=[]
        self.minval=-1

    def push(self, val: int) -> None:
        if len(self.st)>0:              #st非空
            d=val-self.minval
            self.st.append(d)
            if d<0: self.minval=val
        else:                           #st为空
            self.st.append(0)
            self.minval=val

    def pop(self) -> None:
        d=self.st.pop()
        if d<0:
            self.minval=self.minval-d

    def top(self) -> int:
        if self.st[-1]<0:return self.minval
        else:return self.st[-1]+self.minval

    def getMin(self) -> int:
        if len(self.st)==0: return -1
        else: return self.minval
