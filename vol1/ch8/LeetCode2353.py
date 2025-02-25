from sortedcontainers import SortedSet
class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.foodhmap={}
        self.cuishmap=defaultdict(SortedSet)
        for f,c,r in zip(foods,cuisines,ratings):
            self.foodhmap[f]=[r,c]
            self.cuishmap[c].add((-r,f))

    def changeRating(self, food: str,newRating:int) -> None:
        r,c=self.foodhmap[food]
        s=self.cuishmap[c]
        s.remove((-r,food))
        s.add((-newRating, food))
        self.foodhmap[food][0]=newRating

    def highestRated(self, cuisine: str) -> str:
        return self.cuishmap[cuisine][0][1]
