from collections import deque
class Checkout:
	def __init__(self):
		self.qu=deque()          #普通队列
		self.dq=deque()          #单调队列
	def get_max(self) -> int:
		if len(self.qu)==0:return -1
		return self.dq[0]
	def add(self,val:int) -> None:
		self.qu.append(val)
		while len(self.dq)>0 and self.dq[-1]<val:
			self.dq.pop()
		self.dq.append(val)
	def remove(self) -> int:
		if len(self.qu)==0:return -1
		x=self.qu[0]
		if self.dq[0]==x:
			self.dq.popleft()
		self.qu.popleft()
		return x
