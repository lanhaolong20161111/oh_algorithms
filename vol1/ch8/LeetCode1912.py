from sortedcontainers import SortedList
class MovieRentingSystem:
    def __init__(self, n:int,entries:List[List[int]]):
        self.n=n
        self.mvset=defaultdict(SortedList)
        self.shopset=defaultdict(dict)
        self.rentset=SortedList([])
        for shop, movie, price in entries:
            self.mvset[movie].add((price,shop))
            self.shopset[shop][movie]=price 

    def search(self, movie: int) -> List[int]:
        return [me[1] for me in list(self.mvset[movie].islice(stop=5))]

    def rent(self, shop: int, movie: int) -> None:
        price=self.shopset[shop][movie]
        self.mvset[movie].discard((price,shop))
        self.rentset.add((price,shop,movie))

    def drop(self, shop: int, movie: int) -> None:
        price=self.shopset[shop][movie]
        self.mvset[movie].add((price,shop))
        self.rentset.discard((price,shop,movie))

    def report(self) -> List[List[int]]:
        return [[x,y] for _,x,y in self.rentset.islice(stop=5)]
