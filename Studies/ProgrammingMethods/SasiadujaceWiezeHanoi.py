class Adjacent_Hanoi:
    def __init__ (self, n):
        self.A = [0] * n
        self.B = [0] * n
        self.C = [0] * n

        self.Height_A = n
        self.Height_B = 0
        self.Height_C = 0
        self.n = n

        for i in range(0, n):
            self.A[i] = n - i
        return



    def display (self):
        print("==================")
        for i in range(self.n - 1, -1, -1):
            print("A: ", self.A[i], "B: ", self.B[i], "C: ", self.C[i])
        print("==================")
        return



    def adj_hanoi(self, n, source, target):
        pegs = ['A', 'B', 'C']

        def is_neighbor(x, y):
            return abs(pegs.index(x) - pegs.index(y)) == 1

        if n == 0:
            return

        if n == 1:
            if is_neighbor(source, target):
                if source == 'A' and target == 'B':
                    self.move_right(source)
                if source == 'B' and target == 'C':
                    self.move_right(source)
                
                if source == 'C' and target == 'B':
                    self.move_left(source)
                if source == 'B' and target == 'A':
                    self.move_left(source)
            else:
                if source == 'A' and target == 'C':
                    self.move_right(source)
                    self.move_right('B')
                
                if source == 'C' and target == 'A':
                    self.move_left(source)
                    self.move_left('B')
            return

        if is_neighbor(source, target):
            if source == 'A' and target == 'B':
                aux = 'C'
            if source == 'B' and target == 'C':
                aux = 'A'

            self.adj_hanoi(n-1, source, aux)

            if source == 'A' and target == 'B':
                self.move_right(source)
            if source == 'B' and target == 'C':
                self.move_right(source)
            
            if source == 'C' and target == 'B':
                self.move_left(source)
            if source == 'B' and target == 'A':
                self.move_left(source)

            self.adj_hanoi(n-1, aux, target)
            return
        else:
            self.adj_hanoi(n-1, source, target)

            if source == 'A' and target == 'C':
                self.move_right(source)
            if source == 'C' and target == 'A':
                self.move_left(source)

            self.adj_hanoi(n-1, target, source)

            if source == 'A' and target == 'C':
                self.move_right('B')
            if source == 'C' and target == 'A':
                self.move_left('B')
            
            self.adj_hanoi(n-1, source, target)
            return
    


    def move_right (self, tower_id):
        if tower_id == 'A':
            if self.Height_A == 0:
                print ("Wieża A nie posiada żadnego dysku")
            else:
                self.B[self.Height_B] = self.A[self.Height_A - 1]
                self.A[self.Height_A - 1] = 0
                self.Height_B += 1
                self.Height_A -= 1

        if tower_id == 'B':
            if self.Height_B == 0:
                print ("Wieża B nie posiada żadnego dysku")
            else:
                self.C[self.Height_C] = self.B[self.Height_B - 1]
                self.B[self.Height_B - 1] = 0
                self.Height_C += 1
                self.Height_B -= 1

        if tower_id == 'C':
            print ("Nie można przesunąć z C w prawo")
        
        self.display()
        return



    def move_left (self, tower_id):
        if tower_id == 'A':
            print ("Nie można przesunąć z A w lewo")

        if tower_id == 'B':
            if self.Height_B == 0:
                print ("Wieża B nie posiada żadnego dysku")
            else:
                self.A[self.Height_A] = self.B[self.Height_B - 1]
                self.B[self.Height_B - 1] = 0
                self.Height_A += 1
                self.Height_B -= 1
        if (tower_id == "C"):
            if self.Height_C == 0:
                print ("Wieża C nie posiada żadnego dysku")
            else:
                self.B[self.Height_B] = self.C[self.Height_C - 1]
                self.C[self.Height_C - 1] = 0
                self.Height_B += 1
                self.Height_C -= 1

        self.display()
        return


n = int(input ("Wysokość wieży Hanoi: "))
WiezaHanoi = Adjacent_Hanoi(n)

WiezaHanoi.display()
WiezaHanoi.adj_hanoi(n, 'A', 'C')
