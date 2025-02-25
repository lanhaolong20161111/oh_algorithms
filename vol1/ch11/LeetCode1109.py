class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        diff=[0]*n
        for i in range(0,len(bookings)):
            low=bookings[i][0]-1;
            high=bookings[i][1]-1;
            c=bookings[i][2];
            diff[low]+=c
            if high+1<n:diff[high+1]-=c
        ans=[0]*n
        ans[0]=diff[0]
        for i in range(1,n):
            ans[i]=ans[i-1]+diff[i]
        return ans
