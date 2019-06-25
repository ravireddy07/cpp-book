class Solution:
    def superEggDrop(self, K, N):
        floors = [0] + [1] * K
        move = 1
        while floors[-1] < N:
            move += 1
            for i in range(K, 0, -1):
                floors[i] = 1 + floors[i] + floors[i - 1]
        return move
