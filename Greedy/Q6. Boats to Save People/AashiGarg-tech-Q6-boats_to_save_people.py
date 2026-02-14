class Solution:
    def numRescueBoats(self, people, limit):
        people.sort()
        i = 0
        j = len(people)-1
        boats = 0

        while i<=j:
            if people[i] + people[j] <= limit:
                i+=1
            j-=1
            boats+=1

        return boats